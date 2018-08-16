#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

//Lesson 16. MaxNonoverlappingSegments
int MaxNonoverlappingSegments(vector<int> &A, vector<int> &B)
{
	int iResult = 1;
	int iSize = A.size();

	if (iSize < 1)
		return 0;

	int iPrev_end = B[0];

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


void main()
{

	vector<int> A = { 1,3,7,9,9 };
	vector<int> B = { 5,6,8,9,10 };
	int iResult = 0;

	iResult = MaxNonoverlappingSegments(A, B);

	cout << iResult << endl;

	system("Pause");

	return ;
}