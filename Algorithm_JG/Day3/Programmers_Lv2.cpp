#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;


//피보나치  시간초과
//int fibonacci(int n) {
//	if (n <= 1) {
//		return n;
//	}
//	else {
//		return fibonacci(n - 1) + fibonacci(n - 2) % 1234567;
//	}
//}
//
//
//int solution(int n) {
//	int answer = 0;
//
//	int iPibo = fibonacci(n);
//
//	answer = iPibo;
//
//
//	return answer;
//}

//JadenCase 문자열 만들기
//string solution(string s) {
//
//	int iSize = s.size();
//	bool bChange = false;
//
//	for (int i = 1; i < iSize; i++)
//		s[i] = tolower(s[i]);
//
//
//	s[0] = toupper(s[0]);
//
//	for (int i = 1; i < iSize; i++)
//	{
//
//		if (bChange == true)
//		{
//			s[i] = toupper(s[i]);
//			bChange = false;
//		}
//
//		if (s[i] == ' ')
//			bChange = true;
//	}
//
//	return s;
//}

void CheckNeighbor(int i, int j, int iRawSize, int iColumnSize, int *iSizeCount, vector<vector<int>> board)
{
	if (j >= iRawSize)
	{
		return ;
	}
	else if (i >= iColumnSize)
	{
		return ;
	}


	//자기자신 == 1 이고
	if (board[i][j] == 1)
	{	
		(*iSizeCount)++;

		if (j + 1 >= iRawSize || i + 1 >= iColumnSize)
			return ;

		//아래 3개가 다 1이면 정사각형
		if (board[i][j + 1] == 1 && board[i + 1][j] == 1 && board[i + 1][j + 1] == 1)
		{
			//오른쪽 검사
			CheckNeighbor(i, j + 1, iRawSize, iColumnSize, iSizeCount, board);

			//아래 검사
			CheckNeighbor(i + 1, j, iRawSize, iColumnSize, iSizeCount, board);

			//오른쪽아래 검사
			CheckNeighbor(i + 1, j + 1, iRawSize, iColumnSize, iSizeCount, board);
		}
	}





	return ;
}

//가장 큰 정사각형 찾기
int solution(vector<vector<int>> board)
{
	int iResult = 0;

	int iRawSize = board[0].size();		//행(가로) 길이
	int iColumnSize = board.size();		//열(세로) 길이

	int i = 0;
	int j = 0;
	int iMaxSize = 0;
	while (1)
	{
		int iSizeCount = 0;

		CheckNeighbor(i, j, iRawSize, iColumnSize, &iSizeCount, board);
		if (iSizeCount > iMaxSize)
			iMaxSize = iSizeCount;

		if (j < iRawSize)
		{
			j++;
		}
		else
		{
			if (i < iColumnSize)
			{
				i++;
				j = 0;
			}
			else
			{
				break;
			}
		}



	}

	/*
	재귀로 풀어볼까
	하나검사해서 그 하나의 아래, 오른쪽 오른쪽아래가 O이면 Count++
	그 자식들의 아래, 오른쪽 오른쪽아래가 전부다 0이면 Count ++
	또 그 자식들의 자식들을 검사해서 아래, 오른쪽, 오른쪽아래 전부다 0이면 Count++
	하나라도 0이 아니거나 인덱스를 벗어나면 return count;
	*/


	return iMaxSize;

}

//다음 큰 숫자
//int CountOne(int n)
//{
//	int i = 0;
//	int nTemp = n;
//	for (i = 0; nTemp != 0; i++)
//	{
//		nTemp &= (nTemp - 1);
//	}
//	return i;
//
//}
//
//int solution(int n) 
//{
//	int iResult = 0;
//	int iNextNum = n + 1;
//	int nNum = CountOne(n);
//
//	while (1)
//	{
//		int NnNum = CountOne(iNextNum);
//
//		if (nNum == NnNum)
//			return iNextNum;
//		else
//			iNextNum++;
//	}
//	return iResult;
//}

////숫자의 표현
//int solution(int n) {
//	int answer = 0;
//	int iHalf = n / 2;
//
//	for (int i = 1; i <= iHalf; i++)
//	{
//		int iTemp = 0;
//		int iadd = i;
//		while (iTemp <= n)
//		{
//			iTemp += iadd++;
//			if (iTemp == n)
//				answer++;
//		}
//	}
//	answer++;
//
//	return answer;
//}

//최솟값 만들기
//bool desc(int a, int b)
//{
//	return a > b;
//}
//
//int solution(vector<int> A, vector<int> B)
//{
//	int answer = 0;
//	int iVecSize = A.size();
//
//	int AMax = *max_element(A.begin(), A.end());
//	int BMax = *max_element(B.begin(), B.end());
//
//	if (AMax > BMax)
//	{
//		sort(A.begin(), A.end(), desc);
//		sort(B.begin(), B.end());
//	}
//	else
//	{
//		sort(B.begin(), B.end(), desc);
//		sort(A.begin(), A.end());
//	}
//
//	for (int i = 0; i < iVecSize; i++)
//	{
//		answer += (A[i] * B[i]);
//	}
//
//	return answer;
//}

void main()
{

	vector<vector<int>> A = { {0,1,1,1},{1,1,1,1},{1,1,1,1}, {0,0,1,0} };
	//vector<vector<int>> A = { { 0,0,1,1 },{ 1,1,1,1 } };

	int iResult = solution(A);

	std::cout << iResult << endl;

	std::system("Pause");
	return;

}