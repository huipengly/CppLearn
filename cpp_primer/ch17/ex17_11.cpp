#include <bitset>
#include <iostream>
using namespace std;

class quiz
{
public:
    quiz(const string &s) : answer(s) {}
    void update(int num, bool ans) { answer.set(num, ans); }
    int grade(const string &s) const
    {
        bitset<10> student_answer(s);
        int ret = 0;
        for (auto i = 0; i != 10; ++i)
            if (answer[i] == student_answer[i])
                ++ret;
        return ret;
    }
private:
    bitset<10> answer;
};

int main(int argc, char const *argv[])
{
    quiz q("0000000000");
    q.update(1, true);
    cout << q.grade("0000000000") << endl;
    return 0;
}
