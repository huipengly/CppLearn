/**
 * @brief StrBlob类头文件
 * 
 * @file str_blob.h
 * @author huipengly
 * @date 2018-08-22
 */
#include <memory>
using std::shared_ptr; using std::make_shared;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <initializer_list>
using std::initializer_list;
#include <stdexcept>
using std::out_of_range;

class StrBlob
{
public:
    typedef vector<string>::size_type size_type;
    StrBlob() : data(make_shared<vector<string>>()) {}
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
    size_type size() { return data->size(); }
    bool empty() { return data->size(); }
    void push_back(const string &s) { data->push_back(s); }
    void pop_back();
    string& front();
    const string& front() const;        // 两个const。对于const的StrBlob，需要返回const string&
    string& back();
    const string& back() const;

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const; // const的只需要一个，不需要有一个没有const的。如果this非const，当作const使用。
};

void StrBlob::pop_back()
{ 
    check(0, "pop on empty StrBlob");
    data->pop_back(); 
}

string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

const string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

const string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
    {
        throw out_of_range(msg);
    }
}