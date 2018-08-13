#include <iostream>
#include <vector>
using namespace std;

/*
Lv2. 행렬의 곱셈
*/

inline int Max(int a, int b)
{
	return a > b ? a : b;
}

vector<vector<int>> MatrixMul(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
	int rowSizeA = arr1.size();
	int colSizeB = arr2[0].size();

	vector<vector<int>> answer;
	vector<int> row;
	int mul = 0;
	int col = 0;
	int colCount = 0;

	for (size_t i = 0; i < rowSizeA; i++)
	{
		answer.emplace_back(row);
		
		colCount = 0;
		while (colCount < colSizeB)
		{
			col = 0;
			for (size_t j = 0; j < arr1[i].size(); j++)
			{
				mul = arr1[i][j] * arr2[j][colCount];
				col += mul;
			}
			answer[i].emplace_back(col);
			++colCount;
		}
	}

	return answer;
}

/*
Lv2. N개의 최소공배수
*/

int GCD(int a, int b)
{
	int remainder = 0;
	int temp = 0;

	while (a%b != 0)
	{
		remainder = a % b;
		a = b;
		b = remainder;
	}

	return b;
}

int LCM(int a, int b)
{
	return (a*b) / GCD(a, b);
}

int LeastCommonMultiple(vector<int> arr)
{
	if (arr.size() == 1)
		return arr[0];

	int LCMNum = 0;

	LCMNum = LCM(arr[0], arr[1]);

	for (size_t i = 2; i < arr.size(); i++)
	{
		LCMNum = LCM(LCMNum, arr[i]);
	}

	return LCMNum;
}

void main()
{
	/*vector<vector<int>> arr1 = 
	{
		{1, 4},
		{3, 2},
		{4, 1}
	};
	vector<vector<int>> arr2 =
	{
		{3, 3},
		{3, 3},
	};

	MatrixMul(arr1, arr2);*/

	vector<int> test = { 2, 6, 8, 14 };
	cout << LeastCommonMultiple(test) << endl;
}
