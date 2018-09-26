#include "text_query.h"
/**
 * @brief Construct a new Text Query:: Text Query object
 * 
 * @param is 输入文件流
 * @note 根据文件流，存储文本，统计单词出现次数，出现行号
 */
TextQuery::TextQuery(std::ifstream &is): 
        file(std::make_shared<std::vector<std::string>>())
{
    std::string text;
    // 按行读取文件流
    while(getline(is, text))
    {
        file->push_back(text);
        int n = file->size() - 1;               // 记录当前读取行号
        std::istringstream line(text);
        std::string word;
        while (line >> word)
        {
            auto &lines = wm[word];
            if (!lines)     // 第一次遇到这个单词时，此指针为空
            {
                lines.reset(new std::set<line_no>);  // 分配一个新的set
            }
            lines->insert(n);                   // 将此行号插入
        }
    }
}

/**
 * @brief 查询单词
 * 
 * @param sought 单词
 * @return QueryResult 查询结果
 */
QueryResult TextQuery::query(const std::string& sought) const       // Hints:这里要加const，因为可能使静态对象调用
{
    static std::shared_ptr<std::set<line_no>> nodata(std::make_shared<std::set<line_no>>());     // 定义成静态的，这种nodata只需要一个
    auto loc = wm.find(sought);                            // Hints:这里需要单独将迭代器定义出来，不然下面word_number[sought]将报错，因为这个操作可能在set里添加东西，不满足const的要求
    if (loc != wm.end())
    {
        return QueryResult(sought, loc->second, file);
    }
    else
    {
        return QueryResult(sought, nodata, file);
    }
}
