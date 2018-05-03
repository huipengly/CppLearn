class Operator
{
private:
    char mOp;
    int mP1;
    int mP2;

public:
    bool setOperator(char op)
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
    void setParameter(int p1, int p2)
    {
        mP1 = p1;
        mP2 = p2;
    }
    bool result(double& r)
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
                if ( (mP2 > -1E-10) && (mP2 < 1E10))
                {

                }
                else
                {
                    ret = true;
                    r = mP2 / mP1;
                }
                break;
            default:
                break;
        }
        return ret;
    }
};