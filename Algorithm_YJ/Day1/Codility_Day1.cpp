/*
Lesson 1. Binary Gap
*/

#include <math.h>

int solution(int N)
{
	int length = 0;
	int counter = -1;

	int temp = 1;
	int index = 0;

	index = log2(N);
	temp = pow(2, index);

	while (N>0)
	{
		while (temp > N)
		{
			temp /= 2;
			index--;
		}
		N -= temp;

		if (counter == -1)
			counter = index;
		else
		{
			int tempLength = counter - index - 1;
			if (length < tempLength)
				length = tempLength;
			counter = index;
		}
	}

	return length;
}


/*
Lesson2. Cyclic Rotation
*/

vector<int> solution(vector<int> &A, int K)
{
	vector<int> B;
	int size = A.size();
	if (size > 0)
		K = K % size;

	for (int i = 0; i<size; i++)
	{
		int index = i - K;
		if (index < 0)
			index += size;
		B.push_back(A[index]);
	}

	return B;
}

/*
Lesson2. OddOccurence
*/

#include <unordered_map>

int solution(vector<int> &A)
{
	unordered_map<int, int> count;

	for (int i : A)
	{
		if (count.end() == count.find(i))
			count.emplace(i, 1);
		else
			count[i]++;
	}

	for (pair<int, int> p : count)
	{
		if (p.second & 1)
			return p.first;
	}


	return -1;
}