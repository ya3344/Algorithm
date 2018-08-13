#include <iostream>
#include <vector>
#include <string>
using namespace std;


/*
Lv3. ÆÓ¸°µå·Ò
*/
using namespace std;

int A[2501];

inline int Min(int a, int b)
{
	return a > b ? b : a;
}

inline int Max(int a, int b)
{
	return a > b ? a : b;
}

void manachers(string S, int N)
{
	int r = 0, p = 0;

	for (int i = 0; i < N; i++)
	{
		if (i <= r)
			A[i] = Min(A[2 * p - i], r - i);
		else
			A[i] = 0;

		while (i - A[i] - 1 >= 0 && i + A[i] + 1 < N && S[i - A[i] - 1] == S[i + A[i] + 1])
			A[i]++;

		if (r < i + A[i])
		{
			r = i + A[i];
			p = i;
		}
	}
}

int solution(char* s)
{
	string tempStr = s;
	string str = "";

	size_t length = tempStr.size();

	for (int i = 0; i < length; i++)
	{
		str += '#';
		str += tempStr[i];
	}
	str += '#';

	manachers(str, str.size());

	size_t finalLength = str.size();
	int longNum = -1;

	for (int i = 0; i < finalLength; i++)
		longNum = Max(longNum, A[i]);

	return longNum;
}



/*
Lv3. °Å½º¸§µ·
*/

int Change(int n, vector<int> money)
{
	int answer = 0;
	return answer;
}

void main()
{

}