namespace Exercise {
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}
int ivar = 0;
//位置1
// using声明，在全局命名空间下又引入一个ivar的声明，冲突了
// error: ‘ivar’ is already declared in this scope
// using Exercise::ivar;

// using Exercise::ivar;
// using Exercise::dvar;
// using Exercise::limit;

// using声明，在全局命名空间中引入三个新的变量，导致ivar冲突，二义性。
// error: reference to ‘ivar’ is ambiguous

// using namespace Exercise;

void manip() {
	//位置2
    // 造成dvar多次声明，冲突
    // error: redeclaration of ‘double dvar’
    // using Exercise::ivar;
    // using Exercise::dvar;
    // using Exercise::limit;

    // using声明，在全局命名空间中引入三个新的变量，导致ivar冲突，二义性。
    // error: reference to ‘ivar’ is ambiguous
    // using namespace Exercise;

	double dvar = 3.1416;
	int iobj = limit + 1;
	++ivar;
	++::ivar;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
