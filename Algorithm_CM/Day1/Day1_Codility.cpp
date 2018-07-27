
#include <iostream>

using namespace std;

//1. BinaryGap
//Find longest sequence of zeros in binary representation of an integer.

int solution(int N) {
	// write your code in C++14 (g++ 6.2.0)

	int		countSrc = 0;
	int		countDst = 0;
	bool	compare = false;
	bool	beginCheck = false;

	while (1)
	{
		if (0 == N % 2)
			countSrc++;
		else
		{
			if (0 == countDst)
			{
				if (false == beginCheck && 0 < countSrc)
					countDst = 0;
			
				else
				{
					countDst = countSrc;
					compare = true;
				}

				beginCheck = true;
			}
			else
			{
				countDst = countDst > countSrc ? countDst : countSrc;
				compare = false;
			}

			countSrc = 0;
		}

		if (2 > (N /= 2))
		{
			if((true == beginCheck || true == compare) && 0 < countSrc)
				countDst = countDst > countSrc ? countDst : countSrc;
			break;
		}
	}

	return countDst;
}

void main()
{
	

	//1. BinaryGap
	//Find longest sequence of zeros in binary representation of an integer.
	cout << solution(20) << endl;
}