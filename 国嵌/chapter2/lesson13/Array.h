#ifndef ARRAY_H_
#define ARRAY_H_
//my
class Array
{
private:
    int mLength;
    int *mSpace;

public:
    Array(int length);
    Array(const Array& obj);
    int length();
    ~Array();
    // []
    int &operator[](int length);
    // 重载=
    Array &operator=(const Array &obj);
    // ==
    bool operator==(const Array &obj);
    bool operator!=(const Array &obj);
    //++A
    //A++
};

#endif //ARRAY_H_
