#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//문제 5번. 행렬 회전
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

//문제 6번. 좌석예약
int Reserve(vector<vector<int>> seat)
{
	int answer = 0;
	int iSize = seat.size(); //인원수

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


// I -> 도로의 길이
/*

가로등기준 0.5씩


*/
//문제 4번. 도로 가로등
int LightBall(int I, vector<int> v)
{
	
	int answer = 0;
	int iSize = v.size(); //가로등 개수

	while (1)
	{



	}



	return answer;
}

//올바른 괄호(카탈란 수)
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