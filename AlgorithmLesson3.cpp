﻿#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
A small frog wants to get to the other side of the road. The frog is currently located at position X and wants to get to a position greater than or equal to Y. The small frog always jumps a fixed distance, D.

Count the minimal number of jumps that the small frog must perform to reach its target.

Write a function:

int solution(int X, int Y, int D);
that, given three integers X, Y and D, returns the minimal number of jumps from position X to a position equal to or greater than Y.

For example, given:

X = 10
Y = 85
D = 30
the function should return 3, because the frog will be positioned as follows:

after the first jump, at position 10 + 30 = 40
after the second jump, at position 10 + 30 + 30 = 70
after the third jump, at position 10 + 30 + 30 + 30 = 100
Assume that:

X, Y and D are integers within the range [1..1,000,000,000];
X ≤ Y.
Complexity:

expected worst-case time complexity is O(1);
expected worst-case space complexity is O(1).
*/
int FrogJump(int X, int Y, int D) {
	// write your code in C++14 (g++ 6.2.0)

	int count = 0;

	if (X == Y)
		return 0;

	count = (Y - X) / D;

	if ((Y - X) % D != 0)
	{
		count += 1;
	}
	
	return count;
}

/*
A zero-indexed array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

Your goal is to find that missing element.

Write a function:

int solution(vector<int> &A);

that, given a zero-indexed array A, returns the value of the missing element.

For example, given array A such that:

A[0] = 2
A[1] = 3
A[2] = 1
A[3] = 5
the function should return 4, as it is the missing element.

Assume that:

N is an integer within the range [0..100,000];
the elements of A are all distinct;
each element of array A is an integer within the range [1..(N + 1)].
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).
*/

int PermMissingElem(vector<int> &A)
{
	// write your code in C++14 (g++ 6.2.0)
	bool bCheck = false;
	int distance = 0, result = 0;
	int index = 0;

	sort(A.begin(), A.end());

	for (int i = 1; i <= A.size()+1; ++i)
	{
		if (i == A.size() + 1)
			return A.size() + 1;

		if (i == A[i-1])
		{
			bCheck = true;
			continue;
		}
		else
			bCheck = false;
		
		if (bCheck == false)
			return i;
	}

	return result;
}

/*
A non-empty zero-indexed array A consisting of N integers is given. Array A represents numbers on a tape.

Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].

The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|

In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

For example, consider array A such that:
A[0] = 3
A[1] = 1
A[2] = 2
A[3] = 4
A[4] = 3
We can split this tape in four places:

•P = 1, difference = |3 − 10| = 7

•P = 2, difference = |4 − 9| = 5

•P = 3, difference = |6 − 7| = 1

•P = 4, difference = |10 − 3| = 7


Write a function:

int solution(vector<int> &A);


that, given a non-empty zero-indexed array A of N integers, returns the minimal difference that can be achieved.

For example, given:
A[0] = 3
A[1] = 1
A[2] = 2
A[3] = 4
A[4] = 3
the function should return 1, as explained above.

Assume that:

•N is an integer within the range [2..100,000];
•each element of array A is an integer within the range [−1,000..1,000].

Complexity:

•expected worst-case time complexity is O(N);
•expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).

*/

int TapeEquilibrium(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int minResult = 0, result = 0;
	int aSum = 0, totalSum = 0;
	bool bInitCheck = false;

	for (int i = 1; i < A.size(); ++i)
	{
		totalSum += A[i];
	}

	for (int i = 0; i < A.size()-1; ++i)
	{
		aSum += A[i];
		result = abs(totalSum - aSum);
		totalSum -= A[i + 1];

		if (bInitCheck == false)
		{
			minResult = result;
			bInitCheck = true;
		}
		else if (minResult > result)
			minResult = result;
	}

	return minResult;
}


void main()
{
	int result = 0;
	//result = FrogJump(10, 1000, 100);
	//cout << "결과값: " << result << endl;

	//vector<int> A = {  };
	//result = solution(A);

	vector<int> A = { 1, 3};
	result = TapeEquilibrium(A);
	cout << "결과값: " << result << endl;
}