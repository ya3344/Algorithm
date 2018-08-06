
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;


// 문제 1. 123 나라의 숫자  (미해결)
string solution1(int n) {
	string answer = "";
	vector<int> vecNara = { 1, 2, 4 };
	list<int> listNumber = {};

	while (n > 3)
	{
		//listNumber.push_front(vecNara[(n %= 3]);
		//if ((n /= 3));
	}

	return answer;
}

// 문제 2. 올바른 괄호
bool solution2(string s)
{
	bool answer = false;
	int check = 0;


	if (')' == s[0])
		return false;

	for (size_t i = 0; i < s.size(); i++)
	{
		if ('(' == s[i])
			++check;

		if (')' == s[i])
		{
			if (check > 0)
				--check;
			else
				return answer;
		}
	}

	if (check == 0)
		answer = true;

	return answer;
}

// 문제 3. 땅따먹기  (미해결)
int solution3(vector<vector<int> > land)
{
	int answer = 0;
	int src = 0;
	int sum[2] = {};
	int index = 0;
	int dstIndex = 0;
	vector<int> vecCount = {};

	for (size_t i = 0; i < land.size(); i++)
	{
		src = land[i][0];

		for (size_t j = 1; j < 4; j++)
		{
			if (src <= land[i][j])
			{
				if (dstIndex == j)
				{
					vecCount.push_back(i);
					continue;
				}

				src = land[i][j];
				index = j;
			}
		}

		dstIndex = index;
		sum[0] += src;
	}


	if (!vecCount.empty())
	{
		for (int countIndex : vecCount)
		{
			int backIndex = 0;
			int frontIndex = 0;
			int maxIndex[4] = {};

			src = land[countIndex][0];

			for (int i = 1; i < 4; i++)
			{
				if (src <= land[countIndex][i])
				{
					src = land[countIndex][i];
					frontIndex = backIndex = i;
				}
			}

			sum[1] += src;

			for (size_t i = countIndex - 1; i >= 0; i--)
			{
				src = land[i][0];

				for (size_t j = 1; j < 4; j++)
				{
					if (src <= land[i][j])
					{
						if (backIndex == j)
							continue;

						src = land[i][j];
						index = j;
					}
				}

				backIndex = index;
				sum[1] += src;
				if (0 == i)
					break;
			}

			for (size_t i = countIndex + 1; i < land.size(); i++)
			{
				src = land[i][0];

				for (size_t j = 1; j < 4; j++)
				{
					if (src <= land[i][j])
					{
						if (frontIndex == j)
							continue;

						src = land[i][j];
						index = j;
					}
				}

				frontIndex = index;

				sum[1] += src;
			}
		}
	}


	if (sum[0] >= sum[1])
		answer = sum[0];
	else
		answer = sum[1];

	return answer;
}


void main()
{
	// 문제 1. 123 나라의 숫자  (미해결)
	cout << solution1(4) << endl;

	// 문제 2. 올바른 괄호
	cout << solution2("()())") << endl;

	// 문제 3. 땅따먹기  (미해결)
	vector<vector<int>> test = { { 1,2,3,5 },{ 5,6,7,8 },{ 4,3,2,1 },{ 6,5,4,7 },{ 8,1,2,5 } };
	cout << solution3(test) << endl;

}

