/*
행렬의 곱셈
*/

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
	vector<vector<int>> answer;

	int col1 = arr1[0].size();
	int row1 = arr1.size();

	int col2 = arr2[0].size();
	int row2 = arr2.size();

	for (int i = 0; i< row1; i++)
	{
		answer.emplace_back(vector<int>());
		for (int j = 0; j<col2; j++)
		{
			answer[i].emplace_back(0);
			for (int m = 0; m<col1; m++)
			{
				answer[i][j] += arr1[i][m] * arr2[m][j];
			}
		}
	}

	return answer;
}

/*
N개의 최소 공배수
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int GCD(int m, int n) //Euclidean Algorithm
{
	while (n != 0)
	{
		int temp = n;
		n = m % n;
		m = temp;
	}

	return m;
}

int solution(vector<int> arr)
{
	int lcm = arr[0];
	for (int i = 0; i<arr.size(); i++)
		lcm = arr[i] * lcm / GCD(arr[i], lcm);

	return lcm;
}

/*
가장 긴 팰린드롬
*/

#include <iostream>
#include <string>

using namespace std;
int solution(string s)
{
	int len = 0;
	int max = 0;

	for (int i = 0; i<s.length(); i++)
	{
		len = 0;
		while (true)
		{
			if (i - len < 0 || i + len > s.length() - 1)
				break;
			if (s[i - len] != s[i + len])
				break;
			len++;
		}
		len--;
		if (max < len * 2 + 1)
			max = len * 2 + 1;
	}
	for (int i = 0; i<s.length() - 1; i++)
	{
		len = 0;
		if (s[i] != s[i + 1])
			continue;
		while (true)
		{
			if (i - len < 0 || i + 1 + len > s.length() - 1)
				break;
			if (s[i - len] != s[i + 1 + len])
				break;
			len++;
		}
		if (max < len * 2)
			max = len * 2;
	}

	return max;
}