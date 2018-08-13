#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*

(a,b,c) 인덱스3개가 있고 

3개인덱스사이의 숫자들을 다 더한값이 최대값이 되는값 리턴
*/
//Lesson9. MaxDoubleSliceSum
int MaxDoubleSliceSum(vector<int> &A) {

	int iResult = 0;
	int iSize = A.size();

	if (iSize == 3)
		return 0;

	int max_ending = 0, max_slice = 0;

	for (auto a : A)
	{
		max_ending = 0 > max_ending + a ? 0 : max_ending + a;
		max_slice = max_slice > max_ending ? max_slice : max_ending;
	}

	return max_slice;

	//-----------------------
	int iResult = 0;
	int iSize = A.size();

	vector<int> vecTemp1;
	vector<int> vecTemp2;


	if (iSize == 3)
		return 0;




}
/*
인수 개수 구하는거
*/
//Lesson10. CountFactors // 92점
int CountFactors(int N)
{
	int iResult = 0;
	int i = 1;

	while (i*i < N)
	{
		if (N % i == 0)
			iResult += 2;

		i += 1;

	}
	if (i*i == N)
		iResult += 1;

	return iResult;

}


//Lesson11. CountSemiprimes
void EratosTennes2(int* arr, int iEnd)
{

	for (int i = 2; i <= iEnd; i++)
		arr[i] = i;

	for (int i = 2; i <= sqrt(iEnd); i++)
	{
		if (arr[i] == 0)
			continue;

		for (int j = i + i; j <= iEnd; j += i)
		{
			arr[j] = 0;
		}
	}

}

vector<int> CountSemiprimes(int N, vector<int> &P, vector<int> &Q)
{
	int* arr = new int[N+1];


	vector<int> vecResult;
	int iSize = P.size();

	EratosTennes2(arr, N / 2);


	for (int i = 0; i < iSize; i++)
	{
		vector<int> vecTemp;
		vecTemp.reserve(Q[i] - P[i]);
		int iCount = 0;
		for (int j = 0; j <= Q[i]/2; j++)	//큰수의 반보다 크면 안된다.
		{
			if (arr[j] == 0 || arr[j] == 1)
				continue;
			else
				vecTemp.emplace_back(arr[j]);
		}
		int ivecTempSize = vecTemp.size();

		for (int p = 0; p < ivecTempSize; p++)
		{
			for (int q = p; q < ivecTempSize; q++)
			{
				int iTemp = vecTemp[p] * vecTemp[q];

				if (iTemp <= Q[i] && iTemp >= P[i])
				{
					iCount++;
				}

			}
		}

		vecResult.emplace_back(iCount);

	}


	return vecResult;
}



void main()
{

	int N = 26;
	vector<int> P = {1, 4, 16};
	vector<int> Q = {26, 10, 20};

	vector<int> iResult = CountSemiprimes(N, P, Q);

	for (int i = 0; i < iResult.size(); i++)
		cout << iResult[i] << endl;


	system("Pause");

	return;
}