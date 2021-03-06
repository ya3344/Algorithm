#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;


//Lesson 12. ChocolatesByNumbers
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

int gcd2(int a, int b, int iRest)
{
	if (a == b)
		return iRest * a; //1
	else if (a % 2 == 0 && b % 2 == 0)
		return gcd2(a / 2, b / 2, 2 * iRest); //2
	else if (a % 2 == 0)
		return gcd2(a / 2, b, iRest); //3
	else if (b % 2 == 0)
		return gcd2(a, b / 2, iRest); //4
	else if (a > b)
		return gcd2(a - b, b, iRest); //5
	else
		return gcd2(a, b - a, iRest); //6
}

int ChocolatesByNumbers(int N, int M)
{
	if (N == M)
		return 1;
	if (M == 1)
		return N;

	int iResult = 0;
	int igcd = 0;
	int iRest = 1;
	igcd = gcd2(N, M, iRest);


	int iAcc = 1;
	while (1)
	{
		if (iAcc > N)
			break;

		iAcc += igcd;
		iResult++;
	}



	return iResult;
}


//Lesson 16. MaxNonoverlappingSegments
int MaxNonoverlappingSegments(vector<int> &A, vector<int> &B)
{
	int iResult = 1;
	int iSize = A.size();

	if (iSize < 1)
		return 0;

	int iPrev_end = B[0];

	//다음 인덱스에있는 선의 시작점이 현재 선의 끝점보다 크면 카운트++
	for (int i = 1; i < iSize; i++)
	{
		if (A[i] > iPrev_end)
		{
			iResult++;
			iPrev_end = B[i];
		}
	}




	return iResult;
}

/*
최대 구간합의 최소값은 배열 내 가장 큰 원소의 값이고
최대 구간합의 최대값은 배열 내 모든 원소의 합이다
즉 이 두 값을 Lower/Upper Bound로 사용하여 최대 구간합을 이진 탐색으로 찾아낸다.
*/
//Lesson 14. MinMaxDivision

int check(vector<int> &A, int k)
{
	int n = A.size();
	int boards = 0;
	int last = -1;

	for (int i = 0;i < n; i++)
	{
		if (A[i] == 1 && last < i)
		{
			boards += 1;
			last = i + k - 1;
		}

	}

	return boards;
}

int binarySearch(vector<int> &A, int x)
{
	int n = A.size();
	int beg = 0;
	int end = n - 1;
	int result = -1;

	while (beg <= end)
	{
		int mid = (beg + end) / 2;
		if (A[mid] <= x)
		{
			beg = mid + 1;
			result = mid;
		}
		else
			end = mid - 1;
	}

	return result;
}

//K -> 나누는 묶음 수, M -> 최댓값
int MinMaxDivision(int K, int M, vector<int> &A)
{
	int iResult = 0;
	//sort(A.begin(), A.end());
	
	iResult = binarySearch(A, K);



	return iResult;
}


//Lesson 13. FibFrog
int Fibonacci(int n)
{
	if (n <= 1)
		return n;

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

void Fibonacci2(int n, vector<int> &Fibo)
{
	Fibo.push_back(0);
	Fibo.push_back(1);

	//for (int i = 2; i < n + 1; i++)
	//{
	//	Fibo.push_back(Fibo[i - 1] + Fibo[i - 2]);
	//}

	int i = 2;
	while (1)
	{
		if (Fibo[i - 1] + Fibo[i - 2] >= n)
			break;
		Fibo.push_back(Fibo[i - 1] + Fibo[i - 2]);
		i++;
	}

}

int FibFrog(vector<int> &A)
{
	int iResult = 0;
	int iSize = A.size();
	vector<int> B = {};
	Fibonacci2(iSize, B);
	int iBSize = B.size();

	int iCurrPoint = 0;


	while (1)
	{



	}


	return iResult;
}


void main()
{
	vector<int> A = { 0,0,0,1,1,0,1,0,0,0,0 };

	int iResult = 0;

	iResult = FibFrog(A);

	cout << iResult << endl;

	system("Pause");

	return ;
}