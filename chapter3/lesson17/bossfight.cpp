#include <iostream>

using namespace std;

class Boss      //单例类
{
protected:
    static Boss *cInstance;

    Boss()
    {

    }
public:
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