#include "Array.h"
#include <stdio.h>
//my
Array::Array(int length)
{
    if(length < 0)
    {
        mLength = 0;
    }
    mLength = length;
    mSpace = new int[mLength];
}

Array::Array(const Array& obj)
{
    mLength = obj.mLength;
    mSpace = new int[mLength];

    for(int i = 0; i < mLength; i++)
    {
        mSpace[i] = obj.mSpace[i];
    }
}

void Array::setArray(int index, int value)
{
    mSpace[index] = value;
}

int Array::showArray(int index)
{
    return mSpace[index];
}

int Array::length()
{
    return mLength;
}

Array::~Array()
{
    printf("void Array::~Array()\n");
    mLength = -1;
    delete[] mSpace;
}