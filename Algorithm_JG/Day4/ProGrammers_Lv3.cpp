#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;



//°¡Àå ±ä ÆÓ¸°µå·Ò  
int Palindrome2(string s)
{

	int iSize = s.size();
	int iMax = 0;

	if (iSize == 1)
		return 1;
	else if (iSize == 2)
	{
		if (s[0] == s[1])
			return 1;
		else
			return 0;
	}

	//È¦¼öÀÏ¶§
	for (int i = 1; i < iSize;i++)
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

	//Â¦¼öÀÏ¶§
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

//°Å½º¸§µ·
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
	string s = "aaaaa";
	int iResult = Palindrome2(s);



	cout << iResult << endl;


	system("Pause");
	return;
}