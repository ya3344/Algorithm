

// #1. 124 나라의 숫자
string solution(int n) {

	int numArr[3] = { 1, 2, 4 };
	size_t quotient = (n - 1) / 3;
	size_t remainder = (n - 1) % 3;
	string answerNum = "";

	if (0 == quotient)
		return to_string(numArr[remainder]);

	while (0 < quotient)
	{

		answerNum = to_string(numArr[remainder]) + answerNum;

		remainder = (quotient - 1) % 3;
		quotient = (quotient - 1) / 3;

	}

	if (0 == quotient)
	{
		answerNum = to_string(numArr[remainder]) + answerNum;
	}

	return answerNum;
}


// #2. 올바른 괄호
bool solution(string s)
{
	int checkNum = 0;
	bool answer = true;

	for (char& c : s)
	{
		if ('(' == c)
			++checkNum;
		else if (')' == c && checkNum > 0)
			--checkNum;
		else if (')' == c && checkNum == 0)
			return false;
	}

	return checkNum == 0;
}


// #3. 땅따먹기 // 못품
int solution(vector<vector<int> > land)
{
	int rowSize = land.size();
	int sum[4] = { land[0][0], land[0][1] , land[0][2] , land[0][3] };


	for (int initCol = 0; initCol < 4; ++initCol)
	{
		int exceptCol = initCol;

		for (int row = 1; row < rowSize; ++row)
		{
			int max = 0;
			int maxIdx = 0;
			for (int col = 0; col < 4; ++col)
			{
				if (col == exceptCol)
					continue;

				if (max <= land[row][col])
				{
					max = land[row][col];
					maxIdx = col;
				}
			}

			sum[initCol] += max;
			exceptCol = maxIdx;
		}
	}

	int max = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (max <= sum[i])
			max = sum[i];
	}

	return max;
}


// #4. 최댓값과 최솟값 // 못품
string solution(string s) {
	string answer = "";

	int max = s[0];
	int min = s[0];
	int minus = 1;
	int curNum = 0;

	for (int i = 0; i<s.length(); ++i)
	{
		if (' ' == s[i])
			continue;

		if ('-' == s[i])
		{
			minus = -1;
			continue;
		}

		if (i > 0
			&& (' ' != s[i - 1] || '-' != s[i - 1]))
		{
			curNum = curNum * 10 + (s[i] - '0') * minus;
		}
		else if (i == 0 || ' ' == s[i - 1] || '-' == s[i - 1])
		{
			curNum = (s[i] - '0') * minus;
		}

		if (i < s.length() - 1 && (s[i + 1] != ' '))
			continue;

		if (curNum > max)
			max = curNum;
		if (curNum < min)
			min = curNum;
		minus = 1;
	}

	string minStr = to_string(min);
	string maxStr = to_string(max);

	return minStr + ' ' + maxStr;
}
