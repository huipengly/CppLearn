#include <string>
using std::string;
#include <iostream>
using std::cout; using std::endl;

void replace_string(string &s, const string &old_val, const string &new_val)
{
	for (auto it = s.begin(); it != s.end() - old_val.size(); ++it)
	{
		string s2 = string(it, it + old_val.size());
		if (s2 == old_val)
		{
			it = s.erase(it, it + old_val.size());
			it = s.insert(it, new_val.begin(), new_val.end());		// 插入后it位置不确定，需要重新赋值。插入函数返回插入新值的首元素迭代器
			// it += new_val.size();								// 跳过新字符串，节省时间。
																	// 放弃这个节省时间的方法。这个地方会引发bug，如果插入新元素之后的元素到end的长度小于old_val的话，for无法终止，会无限循环。
		}
	}
}

int main()
{
	string s1{ "i tho thru aa!" };
	cout << s1 << endl;
	replace_string(s1, "tho", "though");
	cout << s1 << endl;
	replace_string(s1, "thru", "through");
	cout << s1 << endl;
	return 0;
}