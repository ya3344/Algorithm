/*
Chocolates by Numbers
*/

int GCD(int n, int m)
{
	if (n%m == 0)
	{
		return m;
	}
	else
	{
		return GCD(m, n%m);
	}
}

long long solution(int N, int M)
{
	int gcd = GCD(N, M);
	long long lcm = (long long)M * N / gcd;

	return lcm / M;
}

/*
Fib Frog
*/

#include <limits>

int solution(vector<int> &A)
{
	vector<int> fibo;
	fibo.emplace_back(0);
	fibo.emplace_back(1);
	int N = A.size();

	int n = 0;
	for (int i = 2; n <= N; i++)
	{
		n = fibo[i - 1] + fibo[i - 2];
		fibo.emplace_back(n);
	}


	vector<int> dp;

	dp.resize(N + 1, 0);

	for (int i = 0; i <= N; i++)
	{
		if (i < N && A[i] != 1)
		{
			continue;
		}
		int minJump = numeric_limits<int>::max();
		for (int j = 1; j<(int)fibo.size(); j++)
		{
			if (i - fibo[j] == -1)
			{
				minJump = 1;
				break;
			}
			else if (i - fibo[j] < -1)
			{
				break;
			}
			else if (dp[i - fibo[j]] > 0)
			{
				int jump = dp[i - fibo[j]] + 1;
				if (jump < minJump)
				{
					minJump = jump;
				}
			}
		}
		if (minJump != numeric_limits<int>::max())
		{
			dp[i] = minJump;
		}
	}

	return (dp[N] != 0) ? dp[N] : -1;
}


/*
Max NonOverlapping Segments
*/

int solution(vector<int> &A, vector<int> &B)
{
	int N = A.size();
	if (N == 0)
	{
		return 0;
	}

	int count = 1;
	int last = B[0];

	for (int i = 1; i<N; i++)
	{
		if (A[i] > last)
		{
			last = B[i];
			count++;
		}
	}

	return count;
}


/*
Number Solitaire
*/

int maxSum(const vector<int>& sum, int n)
{
	//n-6 ~ n-1
	int max = sum[n - 1];
	for (int i = n - 2; i > n - 7; i--)
	{
		if (max < sum[i])
		{
			max = sum[i];
		}
	}
	return max;
}

int solution(vector<int> &A)
{
	vector<int> sum;
	sum.resize(A.size(), 0);

	sum[0] = A[0];
	for (int i = 1; i<6; i++)
	{
		int tempSum = A[0];
		for (int j = 1; j<i; j++)
		{
			if (A[j] > 0)
			{
				tempSum += A[j];
			}
		}
		tempSum += A[i];
		sum[i] = tempSum;
		if ((int)A.size() - 1 == i)
		{
			return sum[i];
		}
	}

	for (size_t i = 6; i<A.size(); i++)
	{
		sum[i] = A[i] + maxSum(sum, i);
	}

	return sum[A.size() - 1];
}