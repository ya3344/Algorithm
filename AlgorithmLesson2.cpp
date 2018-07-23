#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//A non - empty zero - indexed array A consisting of N integers is given.The array contains an odd number of elements, and each element of the array can be paired with another element that has the same value, except for one element that is left unpaired.
//
//For example, in array A such that :
//
//A[0] = 9  A[1] = 3  A[2] = 9
//A[3] = 3  A[4] = 9  A[5] = 7
//A[6] = 9
//the elements at indexes 0 and 2 have value 9,
//the elements at indexes 1 and 3 have value 3,
//the elements at indexes 4 and 6 have value 9,
//the element at index 5 has value 7 and is unpaired.
//Write a function :
//
//int solution(vector<int> &A);
//that, given an array A consisting of N integers fulfilling the above conditions, returns the value of the unpaired element.
//
//For example, given array A such that :
//
//A[0] = 9  A[1] = 3  A[2] = 9
//A[3] = 3  A[4] = 9  A[5] = 7
//A[6] = 9
//the function should return 7, as explained in the example above.
//
//Assume that :
//
//N is an odd integer within the range[1..1, 000, 000];
//each element of array A is an integer within the range[1..1, 000, 000, 000];
//all but one of the values in A occur an even number of times.
//Complexity:
//
//expected worst - case time complexity is O(N);
//expected worst - case space complexity is O(1), beyond input storage(not counting the storage required for input arguments).

//int OddOccurrencesInArray(vector<int> &A) {
//
//	unordered_set<int> noOverlapSet;
//	noOverlapSet.clear();
//	unordered_set<int>::iterator iterPos;
//	
//	// write your code in C++14 (g++ 6.2.0)
//	for (int i = 0; i < A.size(); ++i)
//	{
//		if (noOverlapSet.find(A[i]) == noOverlapSet.end())
//			noOverlapSet.insert(A[i]);
//		else
//			noOverlapSet.erase(A[i]);
//	}
//
//	iterPos = noOverlapSet.begin();
//
//	return *iterPos;
//}

int OddOccurrencesInArray(vector<int> &A) 
{
	// write your code in C++14 (g++ 6.2.0)
	int result = 0;

	for (int i = 0; i < A.size(); ++i)
	{
		result ^= A[i];
	}



	return result;
}

/*

A zero-indexed array A consisting of N integers is given. Rotation of the array means that each element is shifted right by one index, and the last element of the array is moved to the first place. For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7] (elements are shifted right by one index and 6 is moved to the first place).

The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.

Write a function:

vector<int> solution(vector<int> &A, int K);
that, given a zero-indexed array A consisting of N integers and an integer K, returns the array A rotated K times.

For example, given

A = [3, 8, 9, 7, 6]
K = 3
the function should return [9, 7, 6, 3, 8]. Three rotations were made:

[3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
[6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
[7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]
For another example, given

A = [0, 0, 0]
K = 1
the function should return [0, 0, 0]

Given

A = [1, 2, 3, 4]
K = 4
the function should return [1, 2, 3, 4]

Assume that:

N and K are integers within the range [0..100];
each element of array A is an integer within the range [−1,000..1,000].
*/
vector<int> CyclicRotation(vector<int> &A, int K)
{
	int lastIndex = A.size() - 1;
	int index = 0;
	vector<int> shiftSpace;
	shiftSpace.clear();
	//result[(i + K) % A.length] = A[i]; // 수식 쉬프트
	if (A.size() <= 1)
	{
		return A;
	}
	// write your code in C++14 (g++ 6.2.0)
	for (int i = 0; i < K; ++i)
	{
		for (int j = 0; j < A.size(); ++j)
		{
			index = lastIndex - (lastIndex*j);
			if (index < 0)
				index = j - 1;
			shiftSpace.push_back(A[index]);
		}
		
		if (i < K - 1)
		{
			for (int j = 0; j < A.size(); ++j)
			{
				A[j] = shiftSpace[j];
			}
			shiftSpace.clear();
		}

	}
	
	return shiftSpace;
}
void main()
{
	int result = 0;
	vector<int> sample = { 9, 3, 9, 3, 9, 7, 9 };

	/*result = OddOccurrencesInArray(sample);
	cout << "결과를 출력하세요: " << result << endl;*/

	/*vector<int> sampleTest = { -4, 3, 2, 1, 5, 4, 0, 0, 3, 4, 2, 1, 5, 17, 18 };
	vector<int> sample2 = CyclicRotation(sampleTest, 15);*/

	
}