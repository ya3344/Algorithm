

// #1. 피보나치 수
int solution(int n) {

	unordered_map<int, unsigned int> table;
	size_t answer = fibonacci(n, &table);

	return int(answer);
}

size_t int fibonacci(int n, unordered_map<int, unsigned int>* table)
{
	if (0 == n || 1 == n)
		return n;

	size_t num1 = 0;
	size_t num2 = 0;
	size_t divide = 1234567;

	auto iter = (*table).find(n - 2);
	if ((*table).end() != iter)
	{
		num1 = (*iter).second % divide;
	}
	else
	{
		num1 = fibonacci(n - 2, table) % divide;
	}

	iter = (*table).find(n - 1);
	if ((*table).end() != iter)
	{
		num2 = (*iter).second % divide;
	}
	else
	{
		num2 = fibonacci(n - 1, table) % divide;
	}

	unsigned int sum = (num1 + num2) % divide;
	(*table).emplace(n, sum);

	return  sum;
}


// #2. JadenCase문자열 만들기
string solution(string s) {

	bool bEnd = true;

	for (char& c : s)
	{
		if (' ' == c)
		{
			bEnd = true;
			continue;
		}

		if (true == bEnd)
		{
			bEnd = false;
			if (c >= 'a')
				c -= ('a' - 'A');
		}
		else if (false == bEnd)
		{
			if (c <= 'Z')
				c += ('a' - 'A');
		}
	}

	return s;
}

// #3. 가장 큰 정사각형 찾기


// #4. 다음 큰 숫자
int solution(int n) {

	int answer = n;
	int oneCount = 0;

	oneCount = Get_NumberOne(n);

	while (1)
	{
		++answer;

		if (oneCount == Get_NumberOne(answer))
			return answer;
	}

	return 0;
}

int Get_NumberOne(int input)
{
	int quotient = input;
	int count = 0;

	do
	{
		int remainder = quotient % 2;
		if (1 == remainder)
			++count;
		quotient /= 2;

		if (1 == quotient)
			++count;
	} while (1 != quotient);

	return count;
}

// #5. 숫자의 표현
int solution(int n)
{
	size_t count = 0;
	size_t max = n / 2 + 1;

	for (size_t i = 1; i <= max - 1; ++i)
	{
		for (size_t j = i + 1; j <= max; ++j)
		{
			size_t sum = size_t((j*j - i*i + i + j) * 0.5f);
			if (sum > n)
				break;
			if (n == sum)
				++count;
		}
	}

	return count + 1;
}

// #6. 최솟값 만들기
int solution(vector<int> A, vector<int> B)
{
	int sum = 0;
	size_t inputSize = A.size();

	sort(A.begin(), A.end(), greater<int>());
	sort(B.begin(), B.end(), less<int>());

	for (size_t i = 0; i<inputSize; ++i)
	{
		sum += A[i] * B[i];
	}

	return sum;
}