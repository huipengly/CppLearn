#ifndef _EX16_2_H_
#define _EX16_2_H_

template <typename T>
int compare(const T &v1, const T &v2)       //Hints: 要有返回值
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

#endif