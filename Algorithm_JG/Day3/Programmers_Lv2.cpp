#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;


//�Ǻ���ġ  �ð��ʰ�
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

//JadenCase ���ڿ� �����
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


	//�ڱ��ڽ� == 1 �̰�
	if (board[i][j] == 1)
	{	
		(*iSizeCount)++;

		if (j + 1 >= iRawSize || i + 1 >= iColumnSize)
			return ;

		//�Ʒ� 3���� �� 1�̸� ���簢��
		if (board[i][j + 1] == 1 && board[i + 1][j] == 1 && board[i + 1][j + 1] == 1)
		{
			//������ �˻�
			CheckNeighbor(i, j + 1, iRawSize, iColumnSize, iSizeCount, board);

			//�Ʒ� �˻�
			CheckNeighbor(i + 1, j, iRawSize, iColumnSize, iSizeCount, board);

			//�����ʾƷ� �˻�
			CheckNeighbor(i + 1, j + 1, iRawSize, iColumnSize, iSizeCount, board);
		}
	}





	return ;
}

//���� ū ���簢�� ã��
int solution(vector<vector<int>> board)
{
	int iResult = 0;

	int iRawSize = board[0].size();		//��(����) ����
	int iColumnSize = board.size();		//��(����) ����

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
	��ͷ� Ǯ���
	�ϳ��˻��ؼ� �� �ϳ��� �Ʒ�, ������ �����ʾƷ��� O�̸� Count++
	�� �ڽĵ��� �Ʒ�, ������ �����ʾƷ��� ���δ� 0�̸� Count ++
	�� �� �ڽĵ��� �ڽĵ��� �˻��ؼ� �Ʒ�, ������, �����ʾƷ� ���δ� 0�̸� Count++
	�ϳ��� 0�� �ƴϰų� �ε����� ����� return count;
	*/


	return iMaxSize;

}

//���� ū ����
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

////������ ǥ��
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

//�ּڰ� �����
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