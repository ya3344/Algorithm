/*
Lesson3. Frog Jump
*/

#include <math.h>

int solution(int X, int Y, int D)
{
	return int(ceil((double)(Y - X) / D));
}

/*
Lesson3. Permutation Missing Element
*/

int solution(vector<int> &A)
{
	long long size = A.size();
	long long sum = (size + 1) * (size + 2) / 2;

	for (int n : A)
	{
		sum -= n;
	}

	return (int)sum;

}