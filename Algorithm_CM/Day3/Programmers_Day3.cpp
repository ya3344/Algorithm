#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;


// 문제 1. 피보나치 수
int solution1(int n) {

	int answer = 0;
	vector<int>	vecFibonacci = { 0x0, 0x1 };

	if (1 == n)
		return 1;
	else if (1 > n && 100000 < n)
		return n;

	for (int i = 0; i <= n - 2; i++)
	{
		int tempNumber = vecFibonacci[i] + vecFibonacci[i + 1];

		if (tempNumber >= 1234567)
			tempNumber %= 1234567;

		vecFibonacci.push_back(tempNumber);
	}
	
	answer = vecFibonacci[n];

	return answer ;
}

// 문제 2. Jaden
string solution2(string s) {

	string answer = s;

	if ('9' < answer[0] && ('a' <= answer[0] && 'z' >= answer[0]))
		answer[0] -= 32;

	for (size_t i = 1; i < s.size(); i++)
	{	
		if (('9' >= answer[i]) && ('0' <= answer[i]))
			continue;

		if (' ' == answer[i - 1])
		{
			if ('a' <= answer[i] && 'z' >= answer[i])
				answer[i] -= 32;
		}
		else
		{
			if ('A' <= answer[i] && 'Z' >= answer[i])
				answer[i] += 32;
		}
	}

	return answer;
}

// 문제 3. 가장 큰 정사각형 찾기 (미해결)
int solution3(vector<vector<int>> board)
{
	int answer = 0;
	int rowSize = board.size();
	int columnSize = board[0].size();

	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < columnSize; j++)
		{
			if (1 == board[i][j])
			{
				int k = 1;

				while (true)
				{
					if (j + k == columnSize || i + k == rowSize)
						break;

					if (1 == board[i + k][j] && 1 == board[i][j + k])
						++k;
					else
						break;
				}

				if(1 == k)
					answer = answer >= 1 ? answer : 1;
				else
				{

				}
			}
		}
	}
	
	return answer;
}

// 문제 4. 다음 큰 숫자
int solution4(int n) {

	int answer = 0;
	int srcCount = 0;
	int dstCount = 0;
	int srcNumber = n;
	int dstNumber = n + 1;
	int tempNumber = n + 1;

	while (true)
	{
		if (1 == srcNumber % 2)
			++srcCount;

		if (2 > (srcNumber /= 2))
		{
			++srcCount;
			break;
		}
	}

	while (true)
	{
		if (1 == tempNumber % 2)
			++dstCount;

		if (2 > (tempNumber /= 2))
		{
			++dstCount;

			if (srcCount == dstCount)
			{
				answer = dstNumber;
				break;
			}
			else
			{
				tempNumber = ++dstNumber;
				dstCount = 0;
			}
		}
	}

	return answer;
}

// 문제 5. 숫자의 표현
int solution5(int n) {

	int answer = 0;
	int size = 0;
	int lastNumber = 0;
	int tempNumber = 0;
	int dstNumber = 0;
	bool check = false;

	if (0 == n % 2)
		size = n / 2;
	else
		size = n / 2 + 1;

	for (int i = 1; i < size; i++)
	{
		lastNumber = i;
		tempNumber = 0;
		while (true)
		{
			if (n < (tempNumber += lastNumber))
				break;
			else
			{
				if (n == tempNumber)
				{
					check = true;
					++answer;
					break;
				}

				++lastNumber;
			}
		}

		if (true == check)
			break;
	}

	if (true == check)
	{
		for (int i = ++lastNumber; i <= size; i++)
		{
			tempNumber = i;
			dstNumber = 0;
			while (true)
			{
				if (n < (dstNumber += tempNumber))
					break;
				else
				{
					if (n == dstNumber)
					{
						++answer;
						break;
					}

					--tempNumber;
				}
			}
		}
	}

	return ++answer;
}

// 문제 6. 최솟값 만들기
int solution6(vector<int> A, vector<int> B)
{
	int answer = 0;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	for (size_t i = 0; i < A.size(); i++)
		answer += A[i] * B[i];
	
	return answer;
}

void main()
{
	// 문제 1. 피보나치 수
	cout << solution1(10) << endl;

	// 문제 2. JadenCase
	cout << solution2(" 3or t3e 3ast week") << endl;

	// 문제 3. 가장 큰 정사각형 찾기 (미해결)
	cout << solution3(vector<vector<int>>{ { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 0, 0, 1, 0 }}) << endl;
	 
	// 문제 4. 다음 큰 숫자
	cout << solution4(78) << endl;

	// 문제 5. 숫자의 표현
	cout << solution5(77) << endl;

	// 문제 6. 최솟값 만들기
	cout << solution6(vector<int>({ 1, 4, 2 }), vector<int>({ 5, 4, 4 })) << endl;
}

