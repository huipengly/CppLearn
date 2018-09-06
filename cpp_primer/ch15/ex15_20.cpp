class Base
{
public:
    void pub_mem();
protected:
    int prot_mem;
private:
    char priv_mem;
};

struct Pub_Derv : public Base
{
    int f() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv : protected Base
{
    int f1() const  { return prot_mem; }
    void memfcn(Base &b) { b = *this; }         // 在类内部时，对base部分访问的特性和base相同，所以可以赋值
};

struct Priv_Derv : private Base
{
    int f1() const  { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv
{
    int use_base() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Protect : public Prot_Derv
{
    int use_base() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private : public Priv_Derv
{
    // pub_mem();
    // int use_base() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }         // X 上一个继承使成员均变为private，当前类无法访问base的prot_mem，所以无法完成赋值
};

int main()
{
    Pub_Derv  d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Protect dd3;

    Base *p = &d1;  // 1. √ public derive，成员访问级别和Base相同
    p = &d2;        // 2. X private derive，继承来的成员都是私有的，无法被访问。和Base不同，不能被转换
    p = &d3;        // 3. X protect derive，继承的非private都是protected，无法被外界访问。和Base不同，不能被转换
    p = &dd1;       // 4. √ 同1
    p = &dd2;       // 5. X 同2
    p = &dd3;       // 6. X 同3
}