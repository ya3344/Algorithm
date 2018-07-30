

// #1. 문자열 내림차순으로 배치하기 
string solution(string s) {
	size_t len = s.length();

	for (size_t i = 0; i < len - 1; ++i)
	{
		char tmp = s[i];
		for (size_t j = i + 1; j < len; ++j)
		{
			if (tmp < s[j])
			{
				s[i] = s[j];
				s[j] = tmp;
				tmp = s[i];
			}
		}
	}

	return s;
}


// #2. 시저 암호
string solution(string s, int n) {
	size_t strLen = s.length();
	int maxSize = 'z' - 'a' + 1;
	char beforeA;

	for (size_t i = 0; i < strLen; ++i)
	{
		if (s[i] == ' ')
			continue;

		if ('a' <= s[i] && s[i] <= 'z')
		{
			beforeA = ('a' - 1);
			if (0 == (s[i] + n - beforeA) % maxSize)
				s[i] = beforeA + maxSize;
			else
				s[i] = beforeA + (s[i] + n - beforeA) % maxSize;
		}
		else if ('A' <= s[i] && s[i] <= 'Z')
		{
			beforeA = ('A' - 1);
			if (0 == (s[i] + n - beforeA) % maxSize)
				s[i] = beforeA + maxSize;
			else
				s[i] = beforeA + (s[i] + n - beforeA) % maxSize;
		}
	}

	return s;
}


// #3. 약수의 합
int solution(int n) {
	if (0 == n)
		return 0;
	else if (1 == n)
		return 1;

	int answer = 0;

	for (size_t i = 1; i < n; ++i)
	{
		if (0 == n%i)
		{
			int divide = n / i;

			if (divide == i) // 제곱수일 경우
				answer += i;
			else if (divide < i) // 이미 연산한 약수가 다시 등장할 경우
				break;
			else
				answer += i + divide;
		}
	}

	return answer;
}


// #4. 최대공약수와 최소공배수
vector<int> solution(int n, int m) {
	vector<int> answer;

	int big = max(n, m);
	int small = min(n, m);

	// 최대공약수 구하기
	for (int i = small; i > 0; --i)
	{
		if (0 == small%i)
		{
			if (0 == big%i)
			{
				answer.emplace_back(i);
				break;
			}
		}
	}

	//최대공배수 구하기
	int sRemain = small / answer[0];
	int bRemain = big / answer[0];

	int max = sRemain*bRemain*answer[0];
	answer.emplace_back(max);

	return answer;
}


// #5. 하샤드 수 
bool solution(int x) {

	int divide = 10;
	int sum = x % divide;

	while (x % divide != x)
	{
		divide *= 10;
		sum += (x%divide - x % (divide / 10)) / (divide / 10);
	}

	return x%sum == 0;
}


// #6. 정수제곱근 판별
long long solution(long long n) {
	long long answer = sqrt(n);

	if (answer * answer == n)
		return pow(answer + 1, 2);

	return -1;
}