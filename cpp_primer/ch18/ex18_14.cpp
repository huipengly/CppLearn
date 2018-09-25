namespace mathLib {
	namespace MatrixLib {
		class matrix { /* ... */ };
		matrix operator* (const matrix &lhs, const matrix &rhs){ return lhs; }
		// ...
	}
}
using mathLib::MatrixLib::matrix;
using mathLib::MatrixLib::operator*;

int main(int argc, char const *argv[])
{
    matrix m;
    m = m * m;
    return 0;
}
