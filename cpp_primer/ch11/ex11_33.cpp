/**
* @brief c++ primer 5th 练习11.33
*
* @file ex11_33.cpp
* @author huipengly
* @date 2018-08-21
*/
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

void word_transform(ifstream &map_file, ifstream &input);
map<string, string> build_map(ifstream &map_file);
string transform(const string &s, const map<string, string> &map);

int main()
{
	ifstream input_file("input_file.txt");
	ifstream map_file("map_file.txt");

	if (!input_file && !map_file)
	{
		cerr << "open file error!" << endl;
		return -1;
	}

	word_transform(map_file, input_file);
	// getchar();
	return 0;
}

void word_transform(ifstream &map_file, ifstream &input)
{
	auto map_rule = build_map(map_file);
	string text;
	while (getline(input, text))
	{
        cout << "text:" << endl;
        cout << text << endl;
		istringstream stream(text);
		bool first_word = true;
		string word;
		while (stream >> word)
		{
            cout << '"' << word << '"';
			if (first_word)
			{
				first_word = false;
			}
			else
			{
				cout << " ";
			}
			cout << transform(word, map_rule);
		}
		cout << endl;
	}
}

map<string, string> build_map(ifstream &map_file)
{
	string key, value;
	map<string, string> map_rule;
	while (map_file >> key, getline(map_file, value))
	{
		if (value.size() > 1)
		{
			map_rule[key] = value.substr(1);
		}
		else
		{
			cout << "no rule for" << key << endl;
		}
	}

    // for (const auto &m : map_rule)
    // {
    //     cout << m.first << ", " << m.second << endl;
    // }

	return map_rule;
}

string transform(const string &s, const map<string, string> &map)
{
	auto map_it = map.find(s);
	if (map_it != map.cend())
	{
		return map_it->second;
	}
	else
	{
		return s;
	}
}