#include <iostream>
using namespace std;

void turnOn(unsigned long long &value, int index)
{
	value |= (1UL << index);
}
void turnOff(unsigned long long &value, int index)
{
	value &= ~(1UL << index);
}


int f1, s1, f0, s0;
int main(void)
{
	unsigned long long n;
	cin >> n;

	int k;
	for (k = 0 ; k < 64 ; ++k)
		if (n & (1ULL << k))
		{
			f1 = k;
			break;
		}
	for (; k < 64 ; ++k)
		if (!(n & (1ULL << k)))
		{
			s1 = k - 1;
			break;
		}

	for (k = 0 ; k < 64 ; ++k)
		if (!(n & (1ULL << k)))
		{
			f0 = k;
			break;
		}
	
	for (; k < 64 ; ++k)
		if (n & (1ULL << k))
		{
			s0 = k - 1;
			break;
		}
	
	unsigned long long findSmallN = n;
	if (!(n & (n + 1)))
		findSmallN = 0;
	else
	{
		turnOn(findSmallN, s0);
		turnOff(findSmallN, s0 + 1);
		int k = s0 - 1;
		while (f0--)
			turnOn(findSmallN, k--);
		while (k >= 0)
			turnOff(findSmallN, k--);
	}
	
	unsigned long long  findBigN = n;
	turnOff(findBigN, s1);
	turnOn(findBigN, s1 + 1);
	k = s1 - 1;
	while (f1--)
		turnOff(findBigN, k--);
	while (k >= 0)
		turnOn(findBigN, k--);
	cout << findSmallN <<' ' << findBigN;
}