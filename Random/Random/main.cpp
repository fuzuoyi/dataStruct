#include <iostream>

using namespace std;


static unsigned long Seed = 1;

#define A 48271L
#define M 2147483647L


double Random_0(void);


#define Q (M / A)
#define R (M % A)
double Random(void);

void initialize(unsigned long initVal);


int main()
{
	initialize(1);

	for (int i = 0; i < 10; i++)
	{
		cout << Random_0() << "  ";
	}
	cout << endl;


	initialize(1);
	for (int i = 0; i < 10; i++)
	{
		cout << Random() << "  ";
	}

	cout << endl;
	system("pause");
	return 0;
}



double Random_0(void)
{
	// 乘法可能导致溢出

	Seed = (A * Seed) % M;
	return (double)Seed / M;
}


double Random(void)
{
	// 改进计算过程（还是线性同余原理），不会溢出

	long tempSeed;

	tempSeed = A * (Seed % Q) - R * (Seed / Q);

	if (tempSeed >= 0)
		Seed = tempSeed;
	else
		Seed = tempSeed + M;

	return (double)Seed / M;
}

void initialize(unsigned long initVal)
{
	Seed = initVal;
}