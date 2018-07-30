

//Lesson3
// #1. FrogJmp
int solution(int X, int Y, int D)
{
	if (X >= Y)
		return 0;

	if ((Y - X) % D == 0)
		return (Y - X) / D;
	else
		return (Y - X) / D + 1;
}


// #2. PermMissingElem // 80%
int solution(vector<int> &A)
{
	int inputSize = A.size();
	unsigned long long realSum = ((inputSize + 2) * (inputSize + 1)) / 2;

	if (0 == inputSize)
		return 1;
	else if (1 == inputSize)
		return A[0] == 1 ? 2 : 1;

	for (int input : A)
	{
		realSum -= input;
	}


	return realSum;
}



//Lesson4
// #1. FrogRiverOne // 81%
int solution(int X, vector<int>& A)
{
	if (1 == X)
		return 0;

	int* position = new int[X];
	memset(position, 0, sizeof(int) * X);
	int maxTime = A.size();

	for (int i = 0; i < maxTime; ++i)
	{
		position[A[i] - 1] = 1;

		bool complete = true;
		for (int i = 0; i < X; ++i)
		{
			if (false == position[i])
			{
				complete = false;
				break;
			}
		}

		if (complete)
		{
			delete[] position;
			return i;
		}
	}

	delete[] position;

	return -1;
}


// #2. maxCounters // 77%
vector<int> solution(int N, vector<int> &A);
void SetMaxNum_Arr(vector<int>& A, int max);

vector<int> solution(int N, vector<int> &A)
{
	vector<int> answer;
	answer.reserve(N);
	for (int i = 0; i < N; ++i)
		answer.emplace_back(0);

	int maxNum = 0;

	for (int i = 0; i<A.size(); ++i)
	{
		if (A[i] - 1 >= N)
		{
			SetMaxNum_Arr(answer, maxNum);
		}
		else
		{
			++answer[A[i] - 1];

			if (maxNum < answer[A[i] - 1])
				maxNum = answer[A[i] - 1];
		}
	}

	return answer;
}

void SetMaxNum_Arr(vector<int>& A, int max)
{
	for (int& num : A)
		num = max;
}


//Lesson5
// #1. GenomicRangeQuery // 62%
vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{
	// ACGT = 1234
	string ACGT = "ACGT";
	vector<int> num_ACGT;
	num_ACGT.reserve(S.length());

	for (char& c : S)
	{
		switch (c)
		{
		case 'A':
			num_ACGT.emplace_back(1);
			break;
		case 'C':
			num_ACGT.emplace_back(2);
			break;
		case 'G':
			num_ACGT.emplace_back(3);
			break;
		case 'T':
			num_ACGT.emplace_back(4);
			break;
		}
	}


	size_t pqSize = P.size();
	vector<int> answer;
	answer.reserve(pqSize);

	for (size_t i = 0; i < pqSize; ++i)
	{
		if (P[i] == Q[i])
			answer.emplace_back(num_ACGT[P[i]]);
		else // p랑 q랑 다를 경우 그 사이의 숫자들의 num_acgt를 비교해서 가장 작은 값을 넣어주자
		{
			int interval = Q[i] - P[i];
			int min = 5;
			for (int j = P[i]; j <= P[i] + interval; ++j)
			{
				if (min > num_ACGT[j])
					min = num_ACGT[j];
			}
			answer.emplace_back(min);
		}
	}
	return answer;
}

// #2. MinAvgTwoSlice // 못 품