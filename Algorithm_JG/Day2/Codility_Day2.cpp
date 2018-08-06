#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;


/*
X값 시작 점프 포지션
Y값 보다 같거나 커질때 점프횟수 리턴
D값 한번점프할때 건너는 횟수
*/
////FrogJmp
//int FrogJmp(int X, int Y, int D)
//{
//
//	int iTemp = 0;
//	iTemp = Y - X;
//
//	if (iTemp == 0)
//		return 0;
//	if (iTemp%D != 0)
//	{
//		iTemp = iTemp / D;
//		iTemp++;
//	}else
//		iTemp = iTemp / D;
//
//	return iTemp;
//}

/*
입력된 숫자(1~100,000)중 빠진숫자 찾아내는거
*/
//int PermMissingElem(vector<int> &A)
//{
//	int answer = 0;
//	
//	
//	sort(A.begin(), A.end());
//	
//	auto iBegin = A.begin();
//
//	//맨처음숫자가 1이아니면 1이빠진것
//	if (*iBegin != 1)	
//		return 1;
//
//	while (1)
//	{
//		auto iter = A.begin();
//		auto jter = ++A.begin();
//
//		if (iter == A.end())
//			return *iter;
//		else if (jter == A.end())
//			return ++(*iter);
//
//		int iFirst = *iter;
//		int iSecond = *jter;
//
//		if (++iFirst == iSecond)
//		{
//			A.erase(iter);
//			continue;
//		}
//		else
//			return ++(*iter);
//	}
//
//	return answer;
//}

/*
건널수 없으면 -1리턴
각숫자가 하나씩떨어져서 X까지 다 떨어지면 그떄의 인덱스 리턴
*/
//FrogRiverOne
//bool Check(vector<bool>&vecBool) 
//{
//	int iVecSize = vecBool.size();
//	for (int i = 0; i < iVecSize;i++)
//	{ 
//		if (false == vecBool[i])
//			return false;
//	}
//	return true;
//}
//
//int FrogRiverOne(int X, vector<int> &A)
//{
//	int max = *max_element(A.begin(), A.end());
//
//	if (X > max)	//아예 못건너는케이스 리턴 -1
//		return -1;
//
//	vector<bool> vecBool;
//	for (int i = 0; i < max; i++)//여기서 벡터안의 제일 큰 수만큼 인자를 만들어야함
//		vecBool.push_back(false);
//
//	int iASize = A.size();
//
//	for (int i = 0; i < iASize; i++)
//	{
//		int iNum = A[i];
//		vecBool[iNum -1] = true;
//		if (true == Check(vecBool))
//			return i;
//	}
//
//	return -1;
//}

/*
consecutive - 연속적인
배열안의 숫자가 N의 개수보다 작으면 해당인덱스의 수를 ++
배열안의 숫자가 N+1일경우 모든인덱스의 수를 인덱스중 가장 큰수로
*/
//vector<int> MaxCounters(int N, vector<int> &A)
//{
//	vector<int>Result = {};
//	int iASize = A.size();
//
//	for (int i = 0; i < N; i++)
//		Result.push_back(0);
//
//	//N보다 큰수인가부터 먼저 검사하자
//	for (int i = 0; i < iASize; i++)
//	{
//		if (N + 1 == A[i])
//		{
//			//모두다 인덱스중 가장 큰 수로
//			int max = *max_element(Result.begin(), Result.end());
//			for (int i = 0; i < N; i++)
//				Result[i] = max;
//		}
//		else
//		{
//			//해당 인덱스만 +1
//			Result[A[i] - 1]++;
//		}
//	}
//	return Result;
//}

/*
A,C,G,T  ->  1,2,3,4
P[a],Q[a] 사이에 있는 영어중 가장작은수를 뱉어내라

62점

*/
////GenomicRangeQuery 
//vector<int> GenomicRangeQuery(string &S, vector<int> &P, vector<int> &Q)
//{
//	vector<int> vecAnswer;
//
//	int iArrSize = P.size();
//
//	for (int i = 0; i < iArrSize; i++)
//	{
//		int iP = P[i];
//		int iQ = Q[i];
//
//		//같은수일 경우
//		if (iP == iQ)
//		{
//			switch (S[iP])
//			{
//			case 'A':
//				vecAnswer.push_back(1);
//				break;
//			case 'C':
//				vecAnswer.push_back(2);
//				break;
//			case 'G':
//				vecAnswer.push_back(3);
//				break;
//			case 'T':
//				vecAnswer.push_back(4);
//				break;
//			default:
//				break;
//			}
//		}
//		else  //같은수가 아닐경우
//		{
//			vector<char> VecTemp;
//			bool bA = false;
//			bool bC = false;
//			bool bG = false;
//			bool bT = false;
//
//			//여기서 알파벳을 다넣는것보단 하나씩넣는게 어떨까
//			for (int i = iP; i <= iQ; i++)
//			{
//				//VecTemp.push_back(S[i]);
//				if (false == bA && S[i] == 'A')
//				{
//					VecTemp.push_back(S[i]);
//					bA = true;
//					break;
//				}
//				else if (false == bC && S[i] == 'C')
//				{
//					VecTemp.push_back(S[i]);
//					bC = true;
//				}
//				else if (false == bG && S[i] == 'G')
//				{
//					VecTemp.push_back(S[i]);
//					bG = true;
//				}
//				else if (false == bT && S[i] == 'T')
//				{
//					VecTemp.push_back(S[i]);
//					bT = true;
//				}
//			}	
//			if(VecTemp.size() != 1)
//				sort(VecTemp.begin(), VecTemp.end());
//
//			if (VecTemp.front() == 'A')
//				vecAnswer.push_back(1);
//			else if (VecTemp.front() == 'C')
//				vecAnswer.push_back(2);
//			else if (VecTemp.front() == 'G')
//				vecAnswer.push_back(3);
//			else if (VecTemp.front() == 'T')
//				vecAnswer.push_back(4);
//		}
//	}
//
//
//	return vecAnswer;
//}
/*

인덱스들을 순서대로 더해서 가장 작은 평균이나오는 경우의 슬라이스(a, b)의 스타트(a)를 리턴

*/
int MinAvgTwoSlice(vector<int> &A)
{

	int iMinFirst = 0, iMinAvrg = 0;
	int iSize = A.size();

	for (int i = 0; i <= iSize; i++)
	{
		int j = i + 1;
		if (j >= iSize)
			break;



	}




	return iMinAvrg;
}


void main()
{
	vector<int> A = { 4, 2, 2, 5, 1, 5, 8 };
	int iResult = 0;

	iResult = MinAvgTwoSlice(A);

	cout << iResult << endl;

	system("Pause");
	return;
}