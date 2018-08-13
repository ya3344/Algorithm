

// #1. Lv2. 행렬의 곱셈
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
	size_t row = arr1.size();
	size_t col = arr2[0].size();
	size_t common = arr1[0].size();

	vector<vector<int>> answer;
	answer.resize(row);


	for (size_t i = 0; i < row; ++i)
	{
		answer[i].resize(col);
		for (size_t j = 0; j < col; ++j)
		{
			answer[i][j] = 0;
			for (size_t k = 0; k < common; ++k)
			{
				answer[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}

	return answer;
}



// #2. Lv2. N개의 최소공배수
int GetGDC(int a, int b);

int solution(vector<int> arr)
{
	size_t inputSize = arr.size();

	int prevNum = arr[0];
	for (size_t i = 1; i < inputSize; ++i)
	{
		prevNum = GetGDC(prevNum, arr[i]);
		prevNum = (arr[i - 1] * arr[i]) / prevNum;
		arr[i] = prevNum;
	}

	return prevNum;
}

int GetGDC(int a, int b)
{
	return (0 == a%b ? b : GetGDC(b, a%b));
}



// #3. Lv3. 가장 긴 팰린드롬
bool IsPalindrom(string& s, bool bEven, size_t init, size_t num);

int solution(string s) {

	size_t len = s.length();
	string str = s;

	for (size_t i = 0; i < len; ++i)
	{
		bool bEven = 0 == (len - i) % 2;
		for (size_t j = 0; j <= i; ++j)
		{
			if (IsPalindrom(str, bEven, j, len - i))
				return len - i;
		}
	}

	return 1;
}

bool IsPalindrom(string & sub, bool bEven, size_t init, size_t num)
{
	size_t subLen = num / 2;
	bool bPelin = false;

	for (size_t k = 1; k <= subLen; ++k)
	{
		if (bEven)
		{
			if (true == (sub[init + subLen - k] == sub[init + subLen + k - 1]))
				bPelin = true;
			else
				return false;
		}
		else
		{
			if (true == (sub[init + subLen - k] == sub[init + subLen + k]))
				bPelin = true;
			else
				return false;
		}
	}

	return bPelin;
}



// #4. Lv3. 거스름돈
int GetMoney(int sum, int* moneyArr, int size);

int solution(int n, vector<int> money) {

	int sum = n;
	int size = money.size();

	int* arr = new int[size];

	for (size_t i = 0; i < size; ++i)
	{
		arr[i] = money[i];
	}

	return GetMoney(sum, arr, size);
}

int GetMoney(int sum, int* moneyArr, int size)
{
	if (0 == sum)
	{
		return 1;
	}
	else if (0 > sum)
		return 0;

	if (0 == size)
		return 0;

	int top = moneyArr[size - 1];
	int quotient = sum / top;

	int* tmpArr = new int[size - 1];
	memcpy(tmpArr, moneyArr, sizeof(int) * (size - 1));

	int count = 0;
	for (size_t i = 0; i <= quotient; ++i)
	{
		count += GetMoney(sum - top*i, tmpArr, size - 1);
	}
	return count;
}