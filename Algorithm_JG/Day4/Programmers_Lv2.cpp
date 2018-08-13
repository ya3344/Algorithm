#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;


//행렬의 곱셈
vector<vector<int>> Multiplication(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;
	int iarr1_Row = arr1.size(); //arr1 열싸이즈
	int iarr2_Row = arr2.size(); // arr1 행싸이즈 == arr2 열싸이즈
	int iarr2_Column = arr2[0].size();

	for (int i = 0; i < iarr1_Row; i++)
	{
		vector<int> Temp;
		for (int p = 0; p < iarr2_Column; p++)
		{
			int iResult = 0;
			for (int j = 0; j < iarr2_Row; j++)
			{
				iResult += arr1[i][j] * arr2[j][p];
			}
			Temp.emplace_back(iResult);
		}
		answer.emplace_back(Temp);
	}


	return answer;
}


//N개의 최소공배수
int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int LCM(vector<int> arr) {

	int answer = 0;
	int iSize = arr.size();
	vector<int> vecLcm;

	if (iSize == 1)
		return arr[0];
	else if (iSize == 2)
		return lcm(arr[0], arr[1]);


	for (int i = 0; i < iSize - 1; i++)
	{
		vecLcm.emplace_back(lcm(arr[i], arr[i + 1]));
	}

	while (1)
	{
		vector<int> vecTemp;
		for (int i = 0; i < vecLcm.size() - 1; i++)
		{
			vecTemp.emplace_back(lcm(vecLcm[i], vecLcm[i + 1]));
		}

		if (vecTemp.size() == 1)
		{
			vecLcm = vecTemp;
			break;
		}
		vecLcm = vecTemp;
	}


	return vecLcm[0];

}
