template <typename T> T calc(T, int);
template <typename T> T fcn(T, T);
double d;    float f;    char c;
calc(c, 'c');   
calc(d, f);     
fcn(c, 'c');    
// fcn(d, f);      
int main()
{
    return 0;
}