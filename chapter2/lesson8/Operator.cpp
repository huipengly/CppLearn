#include "Operator.h"

bool Operator::setOperator(char op)
{
    bool ret = false;

    if (('+' == op) || ('-' == op) || ('*' == op) || ('/' == op))
    {
        ret = true;
        mOp = op;
    }
    else
    {
        mOp = '\0';
    }

    return ret;
}

void Operator::setParameter(int p1, int p2)
{
    mP1 = p1;
    mP2 = p2;
}

bool Operator::result(double& r)
{
    bool ret = false;

    switch(mOp)
    {
        case '+':
            ret = true;
            r = mP1 + mP2;
            break;
        case '-':
            ret = true;
            r = mP1 - mP2;
            break;
        case '*':
            ret = true;
            r = mP1 * mP2;
            break;
        case '/':
            if ( (-1E-10 < mP2) && (mP2 < 1E-10) )
            //if ( (-1E-10 < mP2) && (mP2 < 1E10) ) 1e10，错了
            //if( (-0.000000001 < mP2) && (mP2 < 0.000000001) )
            {

            }
            else
            {
                ret = true;
                r = mP1 / mP2;
            }
            break;
        default:
            break;
    }
    return ret;
}