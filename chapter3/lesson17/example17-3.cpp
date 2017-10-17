#include <cstdlib>
#include <iostream>

using namespace std;

class Boss
{
private:
    static Boss* cInstance;
    
    Boss()
    {
    }
public:
    static Boss* GetInstance()
    {
        if( cInstance == NULL )
        {
             cInstance = new Boss();
        }
        
        return cInstance;
    }
    
    int fight()
    {
        cout<<"Boss::fight()"<<endl;
        return 10;
    }
};

Boss* Boss::cInstance = NULL;

class Master
{
public:
    virtual int eightSwordKill()
    {
        cout<<"Master::eightSwordKill()"<<endl;
        return 8;
    }
};

class NewMaster : public Master
{
public:
    virtual int eightSwordKill()
    {
        cout<<"NewMaster::eightSwordKill()"<<endl;
        return Master::eightSwordKill() * 2;
    }
};

void fieldPK(Master* master, Boss* boss)
{
    int k = master->eightSwordKill();
    int b = boss->fight();
    
    if( k < b )
    {
        cout<<"Master is killed..."<<endl;
    }
    else
    {
        cout<<"Boss is killed..."<<endl;
    }
}

int main(int argc, char *argv[])
{
    Boss* boss = Boss::GetInstance();
    
    cout<<"Master vs Boss"<<endl;
    
    Master master;
    
    fieldPK(&master, boss);
    
    cout<<"New Master vs Boss"<<endl;
    
    NewMaster newMaster;
    
    fieldPK(&newMaster, boss);
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
