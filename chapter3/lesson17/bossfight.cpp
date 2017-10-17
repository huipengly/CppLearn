#include <iostream>

using namespace std;

class Boss      //单例类
{
private:
    static Boss *cInstance;
    class GC    //防止内存泄漏，这个类用来清理内存
    {
    public:
        ~GC()
        {
            if(cInstance != NULL)
            {
                cout << "~GC()" << endl;
                delete cInstance;
                cInstance = NULL;
            }
        }

    };

    static GC gc;
public:
    // Boss()
    // {
    // }

    // ~Boss()
    // {
    //     cout << "~Boss()" << endl;
    //     delete cInstance;
    // }

    static Boss *GetInstance()
    {
        if(cInstance == NULL)
        {
            cInstance = new Boss;
        }

        return cInstance;
    }

    int bossfight()
    {
        cout << "bossfight()" << endl;
        return 10;
    }


};

Boss *Boss::cInstance;
Boss::GC Boss::gc; //防止内存泄漏，这个类用来清理内存，要声明

class Master
{
public:
    virtual int eightSwordKill()
    {
        cout << "Master::eightSwordKill()" << endl;
        return 8;
    }
};

class YoungMaster : public Master
{
public:
    virtual int eightSwordKill()
    {
        cout << "YoungMaster::eightSwordKill()" << endl;
        return Master::eightSwordKill() * 2;
    }
};

void fight(Master *master, Boss *boss)
{
    if(master->eightSwordKill() > boss->bossfight())
    {
        cout << "Boss is killed..." << endl;
    }
    else
    {
        cout << "Master is killed" << endl;
    }
}

int main()
{
    Boss *boss = Boss::GetInstance();
    Master master;

    fight(&master, boss);
    
    YoungMaster youngmaster;

    fight(&youngmaster, boss);

    return 0;
}