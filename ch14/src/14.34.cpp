class Test {
public:
	int operator()(bool test, int i1, int i2)
	{
		return test ? i1 : i2;
	}
};