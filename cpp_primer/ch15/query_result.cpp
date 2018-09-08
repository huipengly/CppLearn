//@note: 只有建立cpp文件，将实现和定义分离，才能避免multiple definition错误。这个错误加了ifndef也不行
#include "query_result.h"

/**
 * @brief 打印QueryResult
 * 
 * @param os 输出流类的引用，例如cout
 * @param qr 需要打印的QueryResult
 * @return std::ostream& 返回输出流
 */
std::ostream& print(std::ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << std::endl;
    for (auto num : *(qr.lines))                               // 指针解引用之后是map<std::string, std::set<int>>
    {
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;     // 行从1开始，vector从0开始
    }
    return os;      // 记得返回
}

/**
 * @brief 根据个数，判断是否加复数
 * 
 * @param ctr 个数
 * @param word 单词
 * @param ending 单词负数词根
 * @return std::string 处理后的单词
 */
std::string make_plural(size_t ctr, const std::string &word, const std::string &ending)
{
    return (ctr > 1) ? word + ending : word;
}