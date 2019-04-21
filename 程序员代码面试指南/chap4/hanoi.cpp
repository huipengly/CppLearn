#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 数学方法递归改循环
int hanoi4(const vector<int> &target)
{
    if (target.empty())
        return -1;
    int from = 1, mid = 2, to = 3;
    int step = 0;
    for (int i = target.size() - 1; i >= 0; --i) {
        if (target[i] == mid)
            return -1;
        if (target[i] == from)
        {
            swap(mid, to);
        }
        if (target[i] == to)
        {
            step += 1 << i;
            swap(from, mid);
        }
    }
    return step;
}

// 数学方法求解的
int hanoi3(const vector<int> &target, int i, const int from, const int mid, const int to)
{
    if (i == -1)
        return 0;

    if (target[i] == mid)
        return -1;

    if (target[i] == from)
    {
        return hanoi3(target, i - 1, from, to, mid);
    }
    else
    {
        auto rest = hanoi3(target, i - 1, mid, from, to);
        if (rest == -1) {
            return -1;
        }
        return (1 << i) + rest;
    }
}

int hanoi3(const vector<int> &target)
{
    if (target.empty())
        return -1;
    return hanoi3(target, target.size() - 1, 1, 2, 3);
}

// 暴力求解
bool hanoi2(vector<int> &arr, const vector<int> &target, int &counter, int n, const int &from, const int &des, const int &mid)
{
    bool ret = false;
    if (n > 1)
        ret = hanoi2(arr, target, counter, n - 1, from, mid, des);
    if (ret)
        return ret;
    cout << "move " << n << " from " << from << " to " << des << endl;
    ++counter;
    arr[n - 1] = des;
    if (equal(arr.begin(), arr.end(), target.begin(), target.end()))
        return true;
    if (n > 1)
        ret = hanoi2(arr, target, counter, n - 1, mid, des, from);
    return ret;
}

int hanoi2(const vector<int> &target)
{
    int counter = 0;
    vector<int> arr(target.size(), 1);
    return (hanoi2(arr, target, counter, arr.size(), 1, 3, 2) ? counter : -1);
}

void hanoi(int n, const string &from, const string &des, const string &mid)
{
    if (n <= 0)
        return;
    hanoi(n - 1, from, mid, des);
    cout << "move " << n << " from " << from << " to " << des << endl;
    hanoi(n - 1, mid, des, from);
}

int main()
{
    vector<int> target{1, 3, 3};
    cout << hanoi4(target) << endl;
    return 0;
}