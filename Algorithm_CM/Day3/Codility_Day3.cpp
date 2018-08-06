
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


// // 문제 1. MaxProduct Of Three
int solution1(vector<int> &A) {
	
	int size = A.size();
	int answerA = 0;
	int answerB = 0;

	if (3 > size || 100000 < size)
		return 0;

	sort(A.begin(), A.end(), greater<int>());

	answerA = A[0] * A[1] * A[2];
	answerB = A[0] * A[size - 2] * A[size - 1];

	return (answerA >= answerB ? answerA : answerB);
}

// 문제 2. Training task
int solution2(vector<int> &A) {
	
	sort(A.begin(), A.end());

	if (A.size() < 3)
		return 0;

	for (size_t i = 0; i <= A.size() - 3; i++)
	{
		if (A[i] < (long long)A[i + 1] + (long long)A[i + 2] &&
			A[i + 1] < (long long)A[i] + (long long)A[i + 2] &&
			A[i + 2] < (long long)A[i] + (long long)A[i + 1])
			return 1;
	}

	return 0;
}

// 문제 3. Number Of DiscIntersections (미해결)
int solution3(vector<int> &A) {

	return 0;
}

// 문제 4. Fish
int solution4(vector<int> &A, vector<int> &B) {
	
	int size = A.size();
	int position = A.size() - 1;
	int compare = 0;
	bool search = false;

	if (1 >= size)
		return size;

	auto iter_beginA = A.begin();
	auto iter_beginB = B.begin();

	while (true)
	{
		if (true == search)
		{
			if (compare == size)
			{
				search = false;
				--position;
				continue;
			}

			if (1 == B[compare] && 0 == position)
				break;

			else if (1 == B[compare])
			{
				search = false;
				--position;
				continue;
			}

			if (*iter_beginA > A[compare])
			{
				A.erase(A.begin() + compare);
				B.erase(B.begin() + compare);
				iter_beginA = A.begin() + position;
				iter_beginB = B.begin() + position;

				--size;	
			}
			else
			{
				A.erase(iter_beginA);
				B.erase(iter_beginB);
				--size;
				--position;
				search = false;
			}
		}
		else
		{
			if (-1 == position)
				break;

			if (1 == B[position])
			{
				iter_beginA = A.begin() + position;
				iter_beginB = B.begin() + position;
				compare = position + 1;
				search = true;
				continue;
			}
			else
				--position;
		}
	}

	return size;

}

// 문제 5. Stone Wall (미해결 : 44%)
int solution5(vector<int> &H) {

	int count = 0;
	vector<int> vecMax = {};

	auto iter_begin = H.begin();
	auto iter_end = H.end();

	for (; iter_begin != iter_end; iter_begin++)
	{
		if (0 == count)
		{
			vecMax.push_back(*iter_begin);
			++count;
		}
		else
		{
			if (*(iter_begin - 1) == *iter_begin)
				continue;
			else if (*(iter_begin - 1) < *iter_begin)
			{
				vecMax.push_back(*iter_begin);
				++count;
			}
			else
			{
				int dst = vecMax.size() - 1;
				while (true)
				{
					if (-1 == dst || vecMax[dst] < *iter_begin)
					{
						vecMax.push_back(*iter_begin);
						++count;
						break;
					}

					if (vecMax[dst] == *iter_begin)
						break;

					--dst;
				}
			}
		}
	}

	return count;
}

// 문제 6. EquiLeader (미해결)
int solution6(vector<int> &A) {
	
	return 0;
}


void main()
{
	// 문제 1. MaxProduct Of Three
	cout << solution1(vector<int>({-5, 5, -5, 4})) << endl;

	// 문제 2. Training task
	cout << solution2(vector<int>({ 10, 2, 5, 1, 8, 20 })) << endl;

	// 문제 3. Number Of DiscIntersections (미해결)
	cout << solution3(vector<int>({ 1,5,2,1,4,0 })) << endl;

	// 문제 4. Fish
	cout << solution4(vector<int>({ 4, 8, 2, 6, 3, 1, 5}), vector<int>({ 1, 1, 1, 1, 1, 1, 1})) << endl;

	// 문제 5. Stone Wall (미해결 : 44%)
	cout << solution5(vector<int>({ 8,8,5,7,9,8,7,4,8 })) << endl;

	// 문제 6. EquiLeader (미해결)
	cout << solution6(vector<int>({ 4,3,4,4,4,2 })) << endl;
}