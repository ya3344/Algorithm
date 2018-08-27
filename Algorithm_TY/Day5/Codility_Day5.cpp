

// #1. Lesson12 ChocolateByNumbers
int GetGCD(int n, int m);
int solution(int N, int M)
{
	int gcd = GetGCD(N, M);

	return (N / gcd);
}

int GetGCD(int n, int m)
{
	if (0 == n%m)
		return m;

	return GetGCD(m, n%m);
}

// #2. Lesson13 FibFrog
int solution(vector<int> &A)
{
	A.emplace_back(1);
	size_t inputSize = A.size();
	vector<int> fibNum;
	fibNum.emplace_back(1);
	fibNum.emplace_back(1);

	int dist = 0;
	int distBuffer = 0;
	int jumpNum = 0;

	for (size_t i = 0; i < inputSize; ++i)
	{
		if (i >= 2)
		{
			fibNum.emplace_back(fibNum[i - 2] + fibNum[i - 1]);
		}

		++dist;
		if (1 == A[i])
		{
			for (int fib : fibNum)
			{
				if (0 != distBuffer && fib == dist + distBuffer)
				{
					distBuffer = dist + distBuffer;
					dist = 0;
					break;
				}
				else if (fib == dist)
				{
					++jumpNum;
					distBuffer = dist;
					dist = 0;
					break;
				}
			}

			if (inputSize - 1 == i && 0 != dist)
				return -1;
		}
	}

	return jumpNum;
}

// #3. Lesson14 MinMaxDivision
int solution(int K, int M, vector<int> &A)
{
	size_t inputSize = A.size();
	vector<int> partialSum;
	partialSum.reserve(inputSize);

	int acc = 0;
	for (int num : A)
	{
		acc += num;
		partialSum.emplace_back(acc);
	}


	size_t begin = 0;
	size_t end = inputSize - 1;

	for (size_t i = 0; i < inputSize - 1; ++i)
	{
		int preSum = partialSum[i];
		int postSum = partialSum[inputSize - 1] - partialSum[i];

		if (preSum > postSum)
		{

		}
		else if (preSum < postSum)
		{
		}
		else if (preSum == postSum)
		{

		}
	}
}

// #4. Lesson16 MaxNonoverlappintSements
typedef struct lineInfo
{
	explicit lineInfo(int init, int end)
	{
		this->init = init;
		this->end = end;
	}

	int init = 0;
	int end = 0;
}LINE;

int solution(vector<int> &A, vector<int> &B)
{
	stack<LINE> lineStack;
	size_t lineNum = A.size();
	if (0 == lineNum)
		return 0;

	LINE firstLine(A[0], B[0]);
	lineStack.emplace(firstLine);

	for (size_t i = 1; i < lineNum; ++i)
	{

		LINE TopLine = lineStack.top();
		LINE curLine(A[i], B[i]);

		// 현재 라인이 밖에 있는 경우
		if (TopLine.end < curLine.init)
		{
			lineStack.emplace(curLine);
		}
	}

	return lineStack.size();
}

// #5. Lesson17 NumberSolitaire
int solution(vector<int> &A)
{
	int sum = 0;

	size_t inputSize = A.size();
	if (1 == inputSize)
		return A[0];

	sum += A[0];
	sum += A[inputSize - 1];
	for (size_t i = 1; i < inputSize - 1; ++i)
	{
		if (A[i] > 0)
			sum += A[i];
	}

	return sum;
}


