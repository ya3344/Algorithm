#include "Header.h"


/*
2. 올바른 괄호
*/


void Progress(string currentString, int leftRemain, int rightRemain, vector<string>* answer)
{
	if (leftRemain > rightRemain)
	{
		cout << "error" << endl;
	}

	else if (leftRemain == rightRemain)
	{
		if (leftRemain == 0)
		{
			answer->emplace_back(currentString);
			return;
		}
		else
		{
			string nextString;
			nextString = currentString + "(";
			leftRemain--;
			Progress(nextString, leftRemain, rightRemain, answer);
		}
	}

	else
	{
		string nextString;

		if (leftRemain > 0)
		{
			nextString = currentString + "(";
			int nextLeft = leftRemain - 1;
			Progress(nextString, nextLeft, rightRemain, answer);
		}

		if (rightRemain > 0)
		{
			nextString = currentString + ")";
			int nextRight = rightRemain - 1;
			Progress(nextString, leftRemain, nextRight, answer);
		}
	}
}

void main()
{
	int N = 3; // 1 ~ 12
	int left = N;
	int right = N;
	vector<string> answer;

	Progress("", N, N, &answer);

	sort(answer.begin(), answer.end());
	for (string& s : answer)
		cout << s << endl;

	int end;
	cout << endl;
	cout << "Enter any key to finish." << endl;
	cin >> end;
}


/*
4. 도로 & 가로등
*/

void main()
{
	int l = 5;
	vector<int> v = { 2, 5 };


	sort(v.begin(), v.end());
	int maxLength = 0;

	for (size_t i = 1; i < v.size(); i++)
	{
		int length = v[i] - v[i - 1] - 1;
		if (maxLength < length)
			maxLength = length;
	}
	int d = maxLength / 2 + 1;

	if (v[0]> d)
		d = v[0];
	if (l - v[v.size() - 1] > d)
		d = l - v[v.size() - 1];

	cout << d << endl;

	int end;
	cout << endl;
	cout << "Enter any key to finish." << endl;
	cin >> end;
}


/*
5. 배열 회전
*/

void RotateMatrix(vector<vector<int>>* matrix, int rotateCount)
{
	rotateCount %= 4;

	for (int k = 0; k < rotateCount; k++)
	{
		vector<vector<int>> tempMatrix = *matrix;
		int N = matrix->size();

		for (int i = N - 1; i >= 0; i--)
		{
			for (int j = 0; j < N; j++)
			{
				(*matrix)[j][N - 1 - i] = tempMatrix[i][j];
			}
		}
	}
}

void main()
{
	vector<vector<int>> matrix = { {1,2}, {3,4} };

	RotateMatrix(&matrix, 3);

	for (vector<int>& row : matrix)
	{
		for (int col : row)
		{
			cout << col << " ";
		}
		cout << endl;
	}

	int end;
	cout << endl;
	cout << "Enter any key to finish." << endl;
	cin >> end;
}



/*
6. 공연장
*/

void main()
{
	int N = 100000;
	vector<vector<int>> seat = { {1,1}, {2,2}, {3,3}, {1,1} };
	int count = 0;

	unordered_set<long long> sold;


	for (vector<int>& vec : seat)
	{
		long long index = vec[0] * N + vec[1];
		if (sold.end() == sold.find(index))
		{
			sold.emplace(index);
			count++;
		}
	}

	cout << count << endl;

	int end;
	cout << endl;
	cout << "Enter any key to finish." << endl;
	cin >> end;
}