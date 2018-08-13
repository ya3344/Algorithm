

// #1. Lesson9 MaxDoubleSliceSum




// #2. Lesson10 CountFactors
int solution(int N)
{
	size_t endIdx = sqrt(N);
	size_t count = 0;

	for (size_t i = 1; i <= endIdx; ++i)
	{
		if (0 == N%i)
			count += 2;
	}

	if (pow(int(sqrt(N)), 2) == N)
		--count;

	return count;
}


// #3. Lesson11 CountSemiprimes

bool IsPrime(int num)
{
	int maxIdx = int(sqrt(num));
	for (int i = 2; i <= maxIdx; ++i)
	{
		if (num%i == 0)
			return false;
	}
	return true;
}

vector<int> solution(int N, vector<int> &P, vector<int> &Q)
{
	unordered_set<int> primeNum;
	primeNum.reserve(int(N));

	for (int i = 2; i <= N; ++i)
	{
		if (IsPrime(i))
			primeNum.emplace(i);
	}

	vector<int> semiCnt;
	semiCnt.resize(N + 1, 0);
	int accCnt = 0;
	for (int i = 4; i <= N; ++i)
	{
		for (int divide : primeNum)
		{
			if (int(sqrt(i)) < divide)
				break;

			if (0 == i%divide)
			{
				if (primeNum.end() != primeNum.find(i / divide))
					++accCnt;
				break;
			}
		}
		semiCnt[i] = accCnt;
	}


	size_t maxInput = P.size();
	vector<int> answer;
	answer.reserve(maxInput);

	for (size_t i = 0; i < maxInput; ++i)
	{
		answer.emplace_back(semiCnt[Q[i]] - semiCnt[P[i] - 1]);
	}

	return answer;
}