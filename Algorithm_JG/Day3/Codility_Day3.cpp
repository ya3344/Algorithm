#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
using namespace std;


//Lesson5. MinAvgTwoSlice
//int solution(vector<int> &A)
//{
//	int iResult = 0;
//	int iSize = A.size();
//	float iMinAvrg = (A[0] + A[1]) / 2;
//
//	for (int i = 0; i < iSize; i++)
//	{
//		int j = i + 1;
//		if (j == iSize)
//			break;
//
//		float iMinAvrgTemp = float(A[i] + A[j]) / 2;
//		if (iMinAvrg > iMinAvrgTemp)
//		{
//			iMinAvrg = iMinAvrgTemp;
//			iResult = i;
//		}
//	}
//
//	for (int i = 0; i < iSize; i++)
//	{
//		int j = i + 2;
//		if (j == iSize)
//			break;
//
//		float iMinAvrgTemp = float(A[i] + A[i+1]+A[j]) / 3;
//		if (iMinAvrg > iMinAvrgTemp)
//		{
//			iMinAvrg = iMinAvrgTemp;
//			iResult = i;
//		}
//	}
//
//	return iResult;
//}

//Lesson6. MaxProductOfThree 가장큰수3개곱해서 값리턴
//int solution(vector<int> &A)
//{
//	int iResult = 0;
//	int iSize = A.size();
//
//	sort(A.begin(), A.end());
//
//
//	int iAdd1 = A[iSize - 1] * A[iSize - 2] * A[iSize - 3];
//	int iAdd2 = A[0] * A[1] * A[iSize - 1];
//
//
//	if (iAdd1 > iAdd2)
//		iResult = iAdd1;
//	else
//		iResult = iAdd2;
//
//	return iResult;
//
//}

//Lesson6. Triangle	회전값이없으면 리턴0 있으면 리턴1 
//int solution(vector<int> &A) {
//	
//	int iSize = A.size();
//
//	sort(A.begin(), A.end());
//
//	for (int i = 2; i < iSize; i++)
//	{
//		if ((double)A[i - 2] + (double)A[i - 1] > A[i])
//			return 1;
//	}
//
//	return 0;
//}


//Lesson6. NumberOfDiscIntersections // 68%
//int solution(vector<int> &A) {
//
//	int iResult = 0;
//	int iSize = A.size();
//
//	queue<int> QueueA;
//
//	for (int i = 0; i < iSize; i++)
//		QueueA.emplace(A[i]);
//
//
//	for (int i = 0; i < iSize; i++)
//	{
//		if (QueueA.empty() == true)
//			break;
//
//		int iCurrNum = QueueA.front();
//		QueueA.pop();
//
//		queue<int> QueueTemp;
//		long long iCompareIndex = 0;
//		while (QueueA.empty() == false)
//		{
//			long long iCompare = QueueA.front();
//			iCompareIndex++;
//			QueueA.pop();
//
//			int PointDis = iCompareIndex;
//
//
//			long long iRadius_Add = iCurrNum + iCompare;
//
//			if (PointDis <= iRadius_Add)
//				iResult++;
//
//			QueueTemp.emplace(iCompare);
//		}
//
//		QueueA = QueueTemp;
//
//	}
//
//	return iResult;
//}

//Lesson7. Fish		
//int solution(vector<int> &A, vector<int> &B)
//{
//	int iResult = 0;
//	int iFishAlive = 0;
//	stack<int> StackTemp;
//
//
//	for (int i = 0; i < A.size(); i++)
//	{
//		if (B[i] == 0)	//업피쉬
//		{
//			iFishAlive++;
//			if (StackTemp.empty() == true)
//				continue;
//
//			int iDownFish = StackTemp.top();
//
//			while (true)
//			{
//				iFishAlive--;
//
//				if (A[i] > A[iDownFish])
//				{
//					StackTemp.pop();
//					if (StackTemp.empty() == true)
//						break;
//					iDownFish = StackTemp.top();
//				}
//				else
//					break;
//			}
//
//		}
//		else //다운피쉬
//		{
//			StackTemp.push(i);
//			iFishAlive++;
//		}
//
//	}
//	
//	return iFishAlive;
//}

//Lesson7. StoneWall
//int solution(vector<int> &H) {
//
//	int iResult = 0;
//	int iSize = H.size();
//	stack<int> stackTemp;
//	
//	if (iSize == 1)
//		return 1;
//
//	stackTemp.push(H[0]);
//	iResult++;
//	int i = 1;
//	while(i < iSize)
//	{
//		if (H[i] > stackTemp.top())
//		{
//			stackTemp.push(H[i]);	//큰수가나오면 넣고 다시돌린다.
//			++iResult;
//		}
//		else if (H[i] < stackTemp.top())	//작은수가 나올경우 pop한다.
//		{
//			stackTemp.pop();
//			if (stackTemp.size() > 0)	//0이아니면 그냥 계속돌림
//				continue;
//
//			stackTemp.push(H[i]);	//0일경우 지금 작은수 추가하고 ++해줌
//			iResult++;
//		}
//		i++;
//	}
//
//
//	return iResult;
//}

//Lesson8. EquiLeader	
/*
리더는 제일많은 숫자가 리더이고
이 리더가 나올수있는 경우의 수를 구해서 리턴하면됨
예제에서 리더는 4이고
(4) / (3,4,4,2) 에서 리더가 4가 나올수있고
(4,3,4) / (4,4,2) 에서 리더가 4가 나올수 있음
2가지 경우이므로 2를리턴
*/
//long long FindLeader(vector<int> &A)
//{
//	long long iLeader = -1;
//
//
//
//	return iLeader;
//}
//
//int solution(vector<int> &A) 
//{
//	long long iResult = 0;
//
//
//
//
//
//	return iResult;
//}
//


void main()
{

	system("Pause");
	return;
}