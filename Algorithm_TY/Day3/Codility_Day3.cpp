

//Lesson6
// #1. MaxProductOfThree
int solution(vector<int> &A)
{
	size_t inputSize = A.size();
	sort(A.begin(), A.end(), greater<int>());

	int sumPlus = A[0] * A[1] * A[2];
	int sumMinus = A[inputSize - 1] * A[inputSize - 2] * A[0];

	return max(sumPlus, sumMinus);
}

// #2. Triangle
int solution(vector<int> &A)
{
	size_t inputSize = A.size();
	sort(A.begin(), A.end(), greater<int>());

	if (inputSize < 3)
		return 0;

	for (size_t i = 0; i < inputSize - 2; ++i)
	{
		if (A[i] < 0)
			continue;
		for (size_t j = inputSize - 1; j > i + 1; --j)
		{
			if (A[j] < 0)
				continue;
			for (size_t k = j - 1; k > i; --k)
			{
				if (A[k] < 0)
					continue;

				size_t sum = size_t(A[j]) + size_t(A[k]);
				if (size_t(A[i])< sum)
					return 1;
			}
		}
	}
	return 0;
}

// #3. NumberOfDiscIntersections  // 81%
int solution(vector<int> &A)
{
	size_t inputSize = A.size();
	size_t count = 0;

	if (0 == inputSize)
		return 0;

	for (size_t i = 0; i < inputSize - 1; ++i)
	{
		for (size_t j = i + 1; j < inputSize; ++j)
		{
			if (j - i <= A[j] + A[i])
			{
				++count;
			}
		}
	}
	return count;
}


//Lesson7
// #1. Fish
int solution(vector<int>& A, vector<int>& B)
{
	stack<pair<int, int>> route;
	size_t fishSize = A.size();

	for (size_t i = 0; i < fishSize; ++i)
	{
		while (false == route.empty()
			&& 0 == B[i]
			&& 1 == route.top().second)
		{
			if (A[i] > route.top().first)
				route.pop();
			else
				break;
		}

		if (true == route.empty()
			|| (1 == route.top().second && 1 == B[i])
			|| 0 == route.top().second)
		{
			route.push(pair<int, int>(A[i], B[i]));
		}
	}

	return route.size();
}

// #2. StoneWall	
int solution(vector<int> &H)
{
	stack<int> parts;
	size_t count = 0;

	parts.push(H[0]);
	++count;

	for (int height : H)
	{
		// ������ ���̿� ���� ���
		if (parts.top() == height)
		{
			continue;
		} // ������ ���̺��� ū ���
		else if (parts.top() < height)
		{
			parts.push(height);
			++count;
			continue;
		} // ������ ���̺��� ���� ���
		else if (parts.top() > height)
		{
			while (1)
			{
				parts.pop();

				if (true == parts.empty())
				{
					parts.push(height);
					++count;
					break;
				}

				if (parts.top() == height)
				{
					break;
				}
				else if (parts.top() < height)
				{
					parts.push(height);
					++count;
					break;
				} 
				else if (parts.top() > height)
				{
					continue;
				}
			}
		}
	}

	return count;
}

//Lesson8
// #1. EquiLeader
