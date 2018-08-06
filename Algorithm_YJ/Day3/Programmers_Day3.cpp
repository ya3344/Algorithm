/*
피보나치 수
*/

#include <string>
#include <vector>
#include <math.h>

using namespace std;

//double fibo = 1 / sqrt(5) * (pow(((1+sqrt(5))/2.f), n) - pow(((1-sqrt(5))/2.f), n));

int solution(int n)
{
	int answer = 0;
	vector<int> fibo;
	fibo.resize(n + 1, 0);

	fibo[0] = 0;
	fibo[1] = 1;
	fibo[2] = 1;

	for (int i = 3; i <= n; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		if (fibo[i] >= 1234567)
			fibo[i] -= 1234567;
	}
	answer = fibo[n];

	return answer;
}


/*
JadenCase 문자열
*/

#include <string>
#include <vector>

using namespace std;

void LowertoUpper(char& c)
{
	if ('a' <= c && c <= 'z')
		c += 'A' - 'a';
}

void UppertoLower(char& c)
{
	if ('A' <= c && c <= 'Z')
		c += 'a' - 'A';
}

string solution(string s)
{
	for (int i = 0; i<s.length(); i++)
	{
		if (i == 0)
		{
			LowertoUpper(s[i]);
			continue;
		}

		if (s[i - 1] == ' ')
		{
			LowertoUpper(s[i]);
			continue;
		}

		UppertoLower(s[i]);
	}

	return s;
}

/*
가장 큰 정사각형
*/

#include <vector>
#include <math.h>
using namespace std;

int solution(vector<vector<int>> board)
{
	int height = board.size();
	int width = board[0].size();
	int maxArea = 0;

	for (int i = 0; i<height; i++)
	{
		for (int j = 0; j<width; j++)
		{
			if (i - 1 <0 || j - 1 <0)
			{
				if (maxArea == 0 && board[i][j] == 1)
					maxArea = 1;
				continue;
			}

			if (board[i][j] == 1)
			{
				int minLength = min(min(board[i - 1][j - 1], board[i - 1][j]), board[i][j - 1]);
				board[i][j] = minLength + 1;
				if (maxArea < (minLength + 1)*(minLength + 1))
					maxArea = (minLength + 1)*(minLength + 1);
			}
		}
	}

	return maxArea;
}

/*
다음 큰 수
*/

#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int solution(int n)
{
	int answer = 0;

	string binary = "";
	while (n>0)
	{
		if (n & 1)
			binary = '1' + binary;
		else
			binary = '0' + binary;
		n = n >> 1;
	}
	binary = "0" + binary;

	int counter = 0;
	for (int i = binary.length() - 1; i >= 0; i--)
	{
		if (binary[i] == '1')
			counter++;
		else
		{
			if (counter > 0)
			{
				binary[i] = '1';
				counter--;
				for (int j = binary.length() - 1; j > i; j--)
				{
					if (counter>0)
					{
						binary[j] = '1';
						counter--;
					}
					else
						binary[j] = '0';
				}
				break;
			}
		}
	}

	int mul = 1;
	for (int i = binary.length() - 1; i >= 0; i--)
	{
		if (binary[i] == '1')
		{
			int index = binary.length() - 1 - i;
			answer += mul;
		}
		mul *= 2;
	}

	return answer;
}

/*
숫자의 표현
*/

#include <string>
#include <vector>

using namespace std;

//홀수 개수의 연속된 정수의 평균 : 정수
//짝수 개수의 연속된 정수의 평균 : 정수 + 0.5

int solution(int n)
{
	int count = 0;
	int length = 1;

	while (true)
	{
		int sum = length*(length + 1) / 2;
		if (sum > n)
			break;
		else
		{
			int temp = n - sum;
			if (temp % length == 0)
				count++;
		}
		length++;
	}

	return count;
}


/*
최솟값 만들기
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;

	sort(A.begin(), A.end(), greater<int>());
	sort(B.begin(), B.end(), less<int>());

	for (int i = 0; i<A.size(); i++)
		answer += A[i] * B[i];

	return answer;
}