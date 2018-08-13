#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;


//����� ����
vector<vector<int>> Multiplication(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;
	int iarr1_Row = arr1.size(); //arr1 ��������
	int iarr2_Row = arr2.size(); // arr1 ������� == arr2 ��������
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


//N���� �ּҰ����
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


//���� �� �Ӹ����   18�� �׽�Ʈ���̽�, ���̰� 0�϶� ����0 �ϴ°� ����ȵ�
int Palindrome2(string s)
{

	int iSize = s.size();
	int iMax = 0;

	if (iSize == 0)
		return 0;
	else if (iSize == 1)
		return 1;
	else if (iSize == 2)
	{
		if (s[0] == s[1])
			return 1;
		else
			return 0;
	}


	for (int i = 1; i < iSize - 1;i++)
	{
		int iCount = 0;
		int j = 1;
		if (s[i - j] == s[i + j])
		{
			iCount += 3;
			while (1)
			{
				j++;
				if (i - j < 0 || i - j == iSize)
				{
					if (iCount > iMax)
						iMax = iCount;
					break;
				}
				if (s[i - j] == s[i + j])
					iCount += 2;
				else
				{
					if (iCount > iMax)
						iMax = iCount;
					break;
				}
			}

		}
	}


	for (int i = 1; i < iSize; i++)
	{
		int iCount = 0;
		int a = 1;
		int b = i;
		if (s[i - a] == s[b])
		{
			iCount += 2;
			while (1)
			{
				a++;
				b++;
				if (i - a < 0 || b == iSize)
				{
					if (iCount > iMax)
						iMax = iCount;
					break;
				}
				if (s[i - a] == s[b])
					iCount += 2;
				else
				{
					if (iCount > iMax)
						iMax = iCount;
					break;
				}

			}
		}
	}

	return iMax;
}

/*
ū������ �ϳ��� ��ӳ������

*/

//�Ž�����
int Change(int n, vector<int> money) {
	int answer = 0;

	int iSize = money.size();
	vector<int> iDivisionCount;
	iDivisionCount.reserve(iSize);


	for (int i = 0;i < iSize; i++)
	{
		int iMoneyTemp = n;
		int iCount = 0;
		while (1)
		{
			if (money[i] == 1)
			{
				iDivisionCount.emplace_back(iMoneyTemp);
				break;
			}

			if (iMoneyTemp < money[i])
			{
				iDivisionCount.emplace_back(iCount);
				break;
			}
			iMoneyTemp /= money[i];
			iCount++;
		}

	}


	for (int i = 0; i < iSize; i++)
	{
		for (int j = iDivisionCount[i]; j > 0; j--)
		{

		}


	}




	return answer;
}


void main()
{

	//vector<int> arr = { 2, 6, 8, 14 };
	vector<int> arr = { 6,8,14 };
	int iResult = LCM(arr);



	cout << iResult << endl;


	system("Pause");
	return;
}