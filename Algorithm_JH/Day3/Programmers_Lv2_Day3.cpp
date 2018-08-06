#include <iostream>
#include <vector>
#include <limits>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;

/*
LV2 피보나치 수
*/
int* g_pFibonachi = nullptr;

int Fibonachi(int n)
{
	int answer = 0;

	if (n <= 2)
		return 1;

	g_pFibonachi = new int[n+1];

	for (int i = 0; i <= n; i++)
	{
		if (i <= 2)
		{
			g_pFibonachi[i] = 1;
		}
		else
		{
			g_pFibonachi[i] = (int)(g_pFibonachi[i - 2] % 1234567) + (int)(g_pFibonachi[i - 1] % 1234567);
		}
	}
	answer = (int)(g_pFibonachi[n] % 1234567);

	return answer;
}

/*
Lv2. JadenCase 문자열 만들기
*/
string JadenCase(string s)
{
	string answer = "";
	size_t size = s.size();
	bool bCheck = false;

	for (size_t i = 0; i < size; i++)
	{
		if (bCheck || i == 0)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
			{
				s[i] -= 32;
			}
			if (s[i] != ' ')
			{
				bCheck = false;
			}
		}
		else
		{
			if (s[i] == ' ')
			{
				bCheck = true;
			}
			else
			{
				if (s[i] >= 'A' && s[i] <= 'Z')
				{
					s[i] += 32;
				}
			}
		}
	}

	answer = s;
	return answer;
}

/*
Lv2. 가장큰정사각형
*/
int solution(vector<vector<int>> board)
{
	int answer = 1234;

	stack<int> squareSpace;

	int colCount = 0;
	int minColCount = 1001;
	int rowCount = 0;

	for (size_t i = 0; i < board.size(); i++)
	{
		colCount = 0;
		for (size_t j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == 1)
			{
				++colCount;
			}
			else
			{
				colCount = 0;
			}
		}

		if (colCount < minColCount)
		{
			minColCount = colCount;
		}

		if (colCount >= minColCount)
		{
			++rowCount;
		}

		if (rowCount >= minColCount)
		{
			if (!squareSpace.empty())
			{
				if (squareSpace.top() < minColCount)
				{
					squareSpace.pop();
					squareSpace.push(minColCount);
				}
			}
			else
			{
				squareSpace.push(minColCount);
			}

		}
	}

	if (!squareSpace.empty())
	{
		answer = squareSpace.top() * squareSpace.top();
		if (answer < 4)
		{
			answer = 0;
		}
	}
	else
	{
		answer = rowCount * rowCount;
	}

	return answer;
}

/*
Lv2. 다음 큰 숫자
*/
int NextBigNumber(int n) 
{
	int answer = 0;
	int remainder = 0;
	int compareNum = n;
	int originNum = n;
	vector<int> binarySpace;

	int srcSize = 0;
	int destSize = 0;

	while (n != 0)
	{
		remainder = n % 2;
		if (remainder == 1)
		{
			binarySpace.emplace_back(remainder);
		}
		n = n / 2;
	}
	srcSize = binarySpace.size();

	while (srcSize != destSize)
	{
		++originNum;
		compareNum = originNum;
		binarySpace.clear();
		while (compareNum != 0)
		{
			remainder = compareNum % 2;
			if (remainder == 1)
			{
				binarySpace.emplace_back(remainder);
			}
			compareNum = compareNum / 2;
		}
		destSize = binarySpace.size();
	}

	answer = originNum;

	return answer;
}

/*
Lv2. 숫자의 표현
*/

int RepresentationOfNumber(int n) 
{
	int count = 0;
	int tempNum = 0;
	int sum = 0;
	int answer = 0;

	for (int i = 1; i <= n; i++)
	{
		tempNum = i;
		sum = 0;

		while (sum < n)
		{
			sum += tempNum;
			tempNum = tempNum + 1;
		}

		if (sum == n)
		{
			++count;
		}
	}

	answer = count;

	return answer;
}

/*
최솟값 만들기
*/

int MinNumCreate(vector<int> A, vector<int> B)
{
	int result = 0;
	size_t size = A.size();
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	for (size_t i = 0; i < size; i++)
	{
		result += A[i] * B[i];
	}

	return result;
}

void main()
{
	//cout << Fibonachi(5) << endl;
	//delete[] g_pFibonachi;
	//g_pFibonachi = nullptr;
	//cout << NextBigNumber(15) << endl;

	//cout << RepresentationOfNumber(15) << endl;
	//cout << JadenCase("3PEople u  nFollowed me").c_str() << endl;;
	vector<int> A = { 1, 2 };
	vector<int> B = { 3, 4 };

	cout << MinNumCreate(A, B) << endl;

}