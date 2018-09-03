#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//���� 5��. ��� ȸ��
vector<vector<int>> Rotate_Matrix(vector<vector<int>> matrix, int r)
{
	vector<vector<int>> a = matrix;
	vector<vector<int>> b = matrix;

	int iSize = matrix.size();

	int p = 0;
	for (int z = 0; z < r; z++)
	{
		for (int i = 0; i < iSize; i++)
		{
			for (int j = 0; j < iSize;j++)
			{
				b[j][iSize - 1 - i] = a[i][j];
			}
		}
		a = b;
	}


	return b;
}

//���� 6��. �¼�����
int Reserve(vector<vector<int>> seat)
{
	int answer = 0;
	int iSize = seat.size(); //�ο���

	vector<vector<bool>> SeatMap;
	

	int maxX = 0;
	for (int i = 0; i < iSize; i++)
	{
		int maxTemp = *max_element(seat[i].begin(), seat[i].end());
		if (maxTemp > maxX)
			maxX = maxTemp;
	}
	SeatMap.resize(maxX + 1);
	for (int i = 0; i < maxX + 1; i++)
		SeatMap[i].resize(maxX + 1);

	for (int i = 0; i < iSize; i++)
	{
		if (SeatMap[seat[i][0]][seat[i][1]] == false)
		{
			answer++;
			SeatMap[seat[i][0]][seat[i][1]] = true;
		}

	}

	return answer;
}


// I -> ������ ����
/*

���ε���� 0.5��


*/
//���� 4��. ���� ���ε�
int LightBall(int I, vector<int> v)
{
	
	int answer = 0;
	int iSize = v.size(); //���ε� ����

	while (1)
	{



	}



	return answer;
}

//�ùٸ� ��ȣ(īŻ�� ��)
vector<vector<int> > cache;
int parenthesisCase(int n)
{
	int answer = 0;
	if (n != 0) {
		for (int i = 0; i <= n; i++) cache[0][i] = 1;

		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				cache[i][j] = (cache[i - 1][j] + cache[i][j - 1]) % 10007;
			}
		}
		answer = cache[n][n];
	}

	return answer;

}

void main()
{

	int iInput = 2;
	
	cache = vector<vector<int> >(iInput + 1, vector<int>(iInput + 1));
	
	int iResult = parenthesisCase(iInput);


	cout << iResult << endl;

	system("Pause");
	return;
}