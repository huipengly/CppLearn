#include "Array.h"
#include <stdio.h>
//my
Array::Array(int length)
{
    if (length < 0)
    {
        mLength = 0;
    }
    mLength = length;
    mSpace = new int[mLength];
}

Array::Array(const Array &obj)
{
    mLength = obj.mLength;
    mSpace = new int[mLength];

    for (int i = 0; i < mLength; i++)
    {
        mSpace[i] = obj.mSpace[i];
    }
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

int &Array::operator[](int length)
{
    return mSpace[length];
}

Array &Array::operator=(const Array &obj)
{
    mLength = obj.mLength;
    
    delete[] mSpace;
    mSpace = new int[mLength];
    
    for(int i = 0; i < mLength; i++)
    {
        mSpace[i] = obj.mSpace[i];
    }

    return *this;
}

bool Array::operator==(const Array &obj)
{
    bool ret = true;

    if(mLength == obj.mLength)
    {
        for(int i = 0; i < mLength; i++)
        {
            if(mSpace[i] != obj.mSpace[i])
            {
                ret = false;
                break;
            }
        }
    }
    else
    {
        ret = false;
    }

    return ret;
}

bool Array::operator!=(const Array &obj)
{
    if(*this == obj)
    {
        return false;
    }
    else
    {
        return true;
    }
}