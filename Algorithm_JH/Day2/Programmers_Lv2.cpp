#include <iostream>
#include <vector>
#include <stack>
#include <limits>
#include <bitset>
using namespace std;

string solution(int n) {
	string answer = "";

	int remainder = 0;

	stack<int> numSpace;

	while (true)
	{
		if (n == 0)
			break;

		remainder = n % 3;
		n = n / 3;
		
		if (remainder == 0)
		{
			remainder = 3;
			n -= 1;
		}

		numSpace.emplace(remainder);

		if (n <= 3)
		{
			numSpace.emplace(n);
		}
		
		if (n <= 3)
			break;
	}

	while (!numSpace.empty())
	{
		switch (numSpace.top())
		{
		case 1:
			answer += '1';
			break;
		case 2:
			answer += '2';
			break;
		case 3:
			answer += '4';
			break;
		}
		numSpace.pop();
	}

return answer;
}

bool solution2(string s)
{
	bool answer = true;

	int leftCount = 0;
	int rightCount = 0;

	for (size_t i = 0; i < s.size(); i++)
	{
		if (*s.begin() == ')')
			return false;
		else if (*(s.end() - 1) == '(')
			return false;

		if (s.size() >= 3)
		{
			if (s[1] == ')' && s[2] == ')')
				return false;
			else if (*(s.end() - 2) == '(' && *(s.end() - 3) == '(')
				return false;
		}


		if (s[i] == ')')
			++leftCount;
		else
			++rightCount;
	}

	if (leftCount == rightCount)
	{
		answer = true;
	}
	else
	{
		answer = false;
	}

	return answer;

}

int solution3(vector<vector<int>> land)
{
	int answer = 0;
	int maxNum = 0;
	int colIndex = -1;
	int col_FixIndex = -1;
	bool bMax = false;

	for (size_t i = 0; i < land.size(); i++)
	{
		maxNum = 0;
		bMax = false;
		for (size_t j = 0; j < land[i].size(); j++)
		{
			if (land[i][j] > maxNum && col_FixIndex != j)
			{
				maxNum = land[i][j];
				colIndex = j;
				bMax = true;
			}
		}
		if (bMax)
		{
			col_FixIndex = colIndex;
		}
		else
		{
			col_FixIndex = -1;
		}

		answer += maxNum;

	}

	return answer;
}

/*
ÃÖ´ñ°ª°ú ÃÖ¼Ú°ª
*/

string solution4(string s)
{
	string answer = "";

	int maxNum = numeric_limits<int>::lowest();
	int minNum = numeric_limits<int>::max();
	int begin = 0;
	int end = 0;
	int size = s.size();

	for (size_t i = 0; i < s.size();)
	{
		if (s[i] == ' ')
		{
			++i;
			begin = i;
		}

		while (s[i] != ' ')
		{
			if (i < size)
			{
				++i;
			}
			else
			{
				break;
			}
			
		}

		if (maxNum < atoi(s.substr(begin, i).c_str()))
		{
			maxNum = atoi(s.substr(begin, i).c_str());
		}
		if (minNum > atoi(s.substr(begin, i).c_str()))
		{
			minNum = atoi(s.substr(begin, i).c_str());
		}
	}

	answer += to_string(minNum);
	answer += ' ';
	answer += to_string(maxNum);

	return answer;
}
void main()
{
	//string temp  = solution(15);
	//cout << solution2("()()") << endl;
	//cout << temp.c_str() << endl;

	//vector<vector<int>> vLand = 
	//{
	//	{1, 2, 3, 5},
	//	{5, 6, 7, 8},
	//	{4, 3, 9, 5}, // 17
	//	{12,3, 9, 5}, // 29
	//	{100,100, 9, 5 }, //129
	//	{ 9, 1, 3, 5 },
	//};
	//cout << solution3(vLand) << endl;

	string s = "-555 -2 3 -4 99";
	cout << solution4(s).c_str() << endl;
	
}