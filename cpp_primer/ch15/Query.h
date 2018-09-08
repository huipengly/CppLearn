#ifndef _QUERY_H_
#define _QUERY_H_
#include "text_query.h"
#include "query_result.h"
#include <memory>
#include <string>

/**
 * @brief 抽象基类
 * 
 */
class QueryBase
{
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~QueryBase() {}         // Hints:虚析构函数需要定义，而不仅仅是声明。（错误的：virtual ~QueryBase();）
private:
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual std::string rep() const = 0;
};

/**
 * @brief 接口类
 * 
 */
class Query
{
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const std::string &);
    QueryResult eval(const TextQuery &t) const 
        { return q->eval(t); }
    std::string rep() const
        { return q->rep(); }
private:
    // Query(const QueryBase& qb) : q(new QueryBase(qb)) {}     // error.对的在下面
    Query(std::shared_ptr<QueryBase> query) : q(query) {}       // Hints:这里传指针才可以实现动态绑定，上面的new只会调用基类的构造函数
    std::shared_ptr<QueryBase> q;
};

class WordQuery : public QueryBase
{
    friend class Query;
    WordQuery(const std::string &s) : query_word(s) {}
    QueryResult eval(const TextQuery &tq) const 
        { return tq.query(query_word); }
    std::string rep() const
        { return query_word; }
    std::string query_word;
};

inline
Query::Query(const std::string &s) : q(new WordQuery(s)) {}     // q(s)是错的，需要申请使用对应的类申请内存

class NotQuery : public QueryBase
{
    friend Query operator~(const Query&);
    // friend class Query;   // 不需要设置为友元
    NotQuery(const std::string &s) : query(s) {}
    QueryResult eval(const TextQuery &) const;
    std::string rep() const 
        { return "~(" + query.rep() + ")"; }
    Query query;
    // std::string s;       // Hints:这里不需要再放一个string来存放查找的单词，已经存在query里了
};

inline
Query operator~(const Query &query)
{
    return std::shared_ptr<QueryBase>(new NotQuery(query.rep()));
    // return std::make_shared<QueryBase>(NotQuery(query.rep()));
    // TODO:上下两句一样么？
}

class BinaryQuery : public QueryBase
{
protected:      // Hints:这里要设置为protected，因为派生类需要使用函数和成员
    BinaryQuery(const Query &l, const Query &r, const std::string &s) :
        lhs(l), rhs(r), opSym(s) {}
    std::string rep() const 
        { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
    std::string opSym;
    Query lhs, rhs;
};

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &l, const Query &r) :
        BinaryQuery(l, r, "&") {}
    QueryResult eval(const TextQuery &) const;      // Hints:这里返回的应该是QueryResult
};

inline          // Hints:这里使用inline避免调用开销
Query operator&(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));     // Hints:这里新建的指针类型应该为QueryBase，不是Query
}

class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &l, const Query &r) :
        BinaryQuery(l, r, "|") {}
    QueryResult eval(const TextQuery &) const;
};

inline
Query operator|(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

#endif