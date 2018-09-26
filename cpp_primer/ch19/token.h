#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <string>

class Token{
public:
    Token() : tok(INT), ivar(0) {}
    Token(const Token& t) : tok(t.tok) { copyUnion(t); }
    Token &operator=(const Token&);
    ~Token() { if (tok == STR) svar.std::string::~string(); }   // Hints: 析构函数要这么写

    Token &operator=(char);
    Token &operator=(int);
    Token &operator=(double);        // Hints: 基础类型不用常量引用
    Token &operator=(const std::string&);

private:
    enum {INT, CHAR, DBL, STR} tok;
    union{
        char cvar;
        int ivar;
        double dvar;
        std::string svar;
    };
    void copyUnion(const Token&);
};

#endif