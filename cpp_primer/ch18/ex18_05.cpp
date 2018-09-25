#include <cstdlib>
#include <stdexcept>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    try{
        throw bad_alloc();
    }catch (exception &e){
        cout << e.what() << endl;
        abort();
    }
    return 0;
}
