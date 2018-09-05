#include "../ch13/StrBlob.h"
class StrBlobPtrPtr
{
public:
    StrBlobPtrPtr(StrBlobPtr *sbp) : p(sbp) {}
    StrBlobPtr& operator*() const
    {
        return *p;
    }
    StrBlobPtr* operator->() const
    {
        return p;
    }
private:
    StrBlobPtr* p;
};

int main(int argc, char const *argv[])
{
    StrBlob sb({"a", "b", "c"});
    StrBlobPtr sbp(sb);
    StrBlobPtrPtr p(&sbp);
    (*p)->size();
    // 下面这个用不了。感觉跟书上说的一直解->不一样
    // p->szie();
    
    return 0;
}
