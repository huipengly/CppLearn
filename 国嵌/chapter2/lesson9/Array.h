#ifndef ARRAY_H_
#define ARRAY_H_
//my
class Array
{
private:
    int mLength;
    int* mSpace;

public:
    Array(int length);
    Array(const Array& obj);
    void setArray(int index, int value);
    int showArray(int index);
    int length();
    ~Array();
};

#endif //ARRAY_H_
