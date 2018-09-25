#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // (a)
    class exceptionType {};
    exceptionType *et;
    try{
        throw et;
    } catch (exceptionType *pet){
        cout << "catch(exceptionType *pet)" << endl;
    }

    // (b)
    try{
        throw 1;
    } catch (...){
        cout << "catch(...)" << endl;
    }

    // (c)
    typedef int EXCEPTYPE;
    int a;
    try{
        throw a;
    } catch (EXCEPTYPE){
        cout << "catch(EXCEPTYPE)" << endl;
    }
    return 0;
}
