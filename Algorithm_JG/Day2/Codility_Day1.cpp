#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;


/*
X�� ���� ���� ������
Y�� ���� ���ų� Ŀ���� ����Ƚ�� ����
D�� �ѹ������Ҷ� �ǳʴ� Ƚ��
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
�Էµ� ����(1~100,000)�� �������� ã�Ƴ��°�
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
//	//��ó�����ڰ� 1�̾ƴϸ� 1�̺�����
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
�ǳμ� ������ -1����
�����ڰ� �ϳ����������� X���� �� �������� �׋��� �ε��� ����
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
//	if (X > max)	//�ƿ� ���ǳʴ����̽� ���� -1
//		return -1;
//
//	vector<bool> vecBool;
//	for (int i = 0; i < max; i++)//���⼭ ���;��� ���� ū ����ŭ ���ڸ� ��������
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
consecutive - ��������
�迭���� ���ڰ� N�� �������� ������ �ش��ε����� ���� ++
�迭���� ���ڰ� N+1�ϰ�� ����ε����� ���� �ε����� ���� ū����
*/
//vector<int> MaxCounters(int N, vector<int> &A)
//{
//	vector<int>Result = {};
//	int iASize = A.size();
//
//	for (int i = 0; i < N; i++)
//		Result.push_back(0);
//
//	//N���� ū���ΰ����� ���� �˻�����
//	for (int i = 0; i < iASize; i++)
//	{
//		if (N + 1 == A[i])
//		{
//			//��δ� �ε����� ���� ū ����
//			int max = *max_element(Result.begin(), Result.end());
//			for (int i = 0; i < N; i++)
//				Result[i] = max;
//		}
//		else
//		{
//			//�ش� �ε����� +1
//			Result[A[i] - 1]++;
//		}
//	}
//	return Result;
//}

/*
A,C,G,T  ->  1,2,3,4
P[a],Q[a] ���̿� �ִ� ������ ������������ ����

62��

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
//		//�������� ���
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
//		else  //�������� �ƴҰ��
//		{
//			vector<char> VecTemp;
//			bool bA = false;
//			bool bC = false;
//			bool bG = false;
//			bool bT = false;
//
//			//���⼭ ���ĺ��� �ٳִ°ͺ��� �ϳ����ִ°� ���
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

�ε������� ������� ���ؼ� ���� ���� ����̳����� ����� �����̽�(a, b)�� ��ŸƮ(a)�� ����

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