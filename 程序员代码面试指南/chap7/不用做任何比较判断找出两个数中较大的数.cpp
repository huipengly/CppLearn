// ��ת�����nΪ1����0��0����1
int flip(int n)
{
	return n ^ 1;
}

int sign(int n)
{
	return (n >> 31 & 1);
}

int max_without_compare(int a, int b)
{
	int c = a - b;
	int sa = sign(a);
	int sb = sign(b);
	int sc = sign(c);
	int difSab = sa ^ sb;			// ���Ϊ1
	int sameSab = flip(difSab);		// ͬ��Ϊ1
	int returnA = difSab * sa + sameSab * sc;	// �����ţ���saΪ��������ͬ�ţ�scΪ��������a
	int returnB = flip(returnA);
	return a * returnA + b * returnB;
}