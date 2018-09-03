#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <chrono>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*
문제2. 올바른 괄호
카탈란 수
def p(n):
if n < 2:
return 1
return p(n-1) * 3 - 1
*/
int CatalanNum(size_t n, size_t r)
{
	size_t num = 1;
	size_t select = 1;

	for (size_t i = 0; i < r; i++)
	{
		num *= 2 * n - i;
		select *= r - i;
	}

	return num / select;
}

void Catalan(vector<string>& answerStr, string& bracketStr, int openBracket, int closeBracket, int bracketNum)
{
	if (openBracket == 0 && closeBracket == 0)
	{
		answerStr.emplace_back(bracketStr);
		bracketStr.clear();
		return;
	}

	// 열린 괄호의 수가 괄호의 개수 무조건 작아야함
	if (openBracket > 0)
	{
		Catalan(answerStr, bracketStr += '(', openBracket - 1, closeBracket +1, bracketNum);
	}

	// 열린괄호 만큼 닫힌괄호도 존재해야함.
	if (closeBracket > 0)
	{
		Catalan(answerStr, bracketStr += ')', openBracket, closeBracket - 1, bracketNum);
	}
}

vector<string> CorrectBracket(int N)
{
	vector<string> answer = {};
	answer.clear();
	string bracketStr;
	bracketStr.clear();
	int bracketCount = 0;

	Catalan(answer, bracketStr, 2, 0, 2);

	for (size_t i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << endl;
	}

	return answer;
}

inline int Max(int a, int b)
{
	return a > b ? a : b;
}


/*
문제4. 전등문제
testcase:
l = 5 v = 1,2
l = 5 v = 2,3
l = 5 v = 4,5
l = 5 v = 1,5
*/
int Light(int l, vector<int> v)
{
	size_t size = v.size();
	int answer = 0;
	int maxDistance = 0;
	int distnace = 0;

	sort(v.begin(), v.end());

	for (size_t i = 0; i < size - 1; i++)
	{
		distnace = v[i + 1] - v[i];

		maxDistance = Max(maxDistance, distnace);
	}

	if (maxDistance % 2 > 0.f)
	{
		maxDistance = (maxDistance + 1) / 2;
	}
	else
	{
		maxDistance = maxDistance / 2;
	}

	if (v[0] > maxDistance)
	{
		maxDistance = Max(maxDistance, v[0] - 0);
	}
	if (l - v[size - 1] > maxDistance)
	{
		maxDistance = Max(maxDistance, l - v[size - 1]);
	}

	answer = maxDistance;

	return answer;
}


/*
문제5. 행렬회전 문제
*/
vector<vector<int>> MatrixRotation(vector<vector<int>> matrix, int r)
{
	vector<vector<int>> answer;
	size_t size = matrix.size();
	answer.resize(size);

	size_t colCount = 0;

	for (size_t i = 0; i < size; i++)
	{
		answer[i].resize(size);
	}

	for (size_t c = 0; c < r; c++)
	{
		for (size_t i = 0; i < size; i++)
		{
			colCount = 0;
			for (int j = size - 1; j >= 0; j--)
			{
				answer[i][colCount] = matrix[j][i];
				++colCount;
			}
		}

		matrix = answer;
	}

	return answer;
}

/*
문제6. 좌석배치 문제
*/
int SeatArray(vector < vector<int>> seat)
{
	int answer = -1;
	size_t seatSize = seat.size();

	set<vector<int>> seatSpace;
	chrono::system_clock::time_point startTime = chrono::system_clock::now();
	for (size_t i = 0; i < seatSize; i++)
	{
		seatSpace.emplace(seat[i]);
	}
	chrono::system_clock::time_point endTime = chrono::system_clock::now();

	chrono::nanoseconds millSecond = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);

	answer = seatSpace.size();

	return answer;
}

void main()
{
	/*vector<vector<int>> seat = { {1,1}, {2,2}, {3,3} };
	cout << SeatArray(seat) << endl;*/
	//CorrectBracket(3);
	vector<int> v = { 25, 27, 18, 20 , 23, 15, 16, 29, 30 };
	cout <<Light(30, v) << endl;
}