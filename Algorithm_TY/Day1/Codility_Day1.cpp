#include <iostream>
#include <vector>

using namespace std;

// Q
//Q1. BinaryGap
int solution1(int N)
{
	int input = N;
	vector<int> binary;
	int maxCnt = 0;

	while (1 != input)
	{
		int remainder = input % 2;
		input = input / 2;

		// 첫 숫자로 1이 들어올 경우
		if (0 == binary.size())
		{
			if (0 == remainder)
				continue;
			else if (1 == remainder)
			{
				binary.emplace_back(remainder);
			}
		}
		else
		{
			if (0 == remainder)
			{
				binary.emplace_back(remainder);

				if (1 == input) // binary 전체 종료!
				{
					int zeroNum = binary.size() - 1;
					if (maxCnt < zeroNum)
						maxCnt = zeroNum;
					return maxCnt;
				}
			}
			else if (1 == remainder) // binary 한 그룹이 종료!
			{
				int zeroNum = binary.size() - 1;
				if (maxCnt < zeroNum)
					maxCnt = zeroNum;
				binary.clear();
				binary.emplace_back(1);
			}
		}
	}

	return maxCnt;
}


//Q1. CyclicRotation
vector<int> solution2(vector<int>& A, int K)
{
	vector<int> answer;
	int inputSize = A.size();

	// 예외처리
	if (0 == inputSize)
		return answer;

	if (inputSize < K)
		K = K%inputSize;

	answer.reserve(inputSize);

	for (int j = 0; j < K; ++j)
		answer.emplace_back(A[inputSize - K + j]);

	for (int j = 0; j < inputSize - K; ++j)
		answer.emplace_back(A[j]);

	return answer;
}


//Q2. OddOccurrencesInArray
int solution3(vector<int>& A)
{
	unsigned long tmp = 0;

	for (int num : A)
		tmp = tmp ^ num;

	return tmp;
}
