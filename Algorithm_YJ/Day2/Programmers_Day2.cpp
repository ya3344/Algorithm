/*
Lv1. 약수의 합
*/
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n)
{
	int answer = 0;

	float squareRoot = sqrt(n);

	for (int i = 1; i <= squareRoot; i++)
	{
		if (n%i == 0)
		{
			answer += i + n / i;
			if (i == squareRoot)
				answer -= i;
		}
	}

	return answer;
}

/*
Lv1. 문자열 내림차순 배치
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(string s)
{
	string answer = "";

	unordered_map<char, int> counter;

	for (char c : s)
	{
		if (counter.find(c) == counter.end())
			counter.emplace(c, 1);
		else
			counter[c]++;
	}

	for (char c = 'z'; c >= 'A'; c--)
	{
		if (counter.find(c) != counter.end())
		{
			for (int i = 0; i<counter[c]; i++)
				answer += c;
		}
	}


	return answer;
}

/*
Lv1. 시저 암호 
*/
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n)
{
	string answer = "";

	for (char& ch : s)
	{
		int c = ch;
		if (c == ' ')
			continue;
		else if ('A' <= c && c <= 'Z')
		{
			c = c + n;
			if (c > 'Z')
				c -= ('Z' - 'A' + 1);
		}
		else if ('a' <= c && c <= 'z')
		{
			c = c + n;
			if (c > 'z')
				c -= ('z' - 'a' + 1);
		}
		ch = c;
	}
	answer = s;

	return answer;
}

/*
Lv1. 정수 제곱근 판별
*/
#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
	long long answer = 0;

	long long a = sqrt(n);

	if (a * a == n)
		return (a + 1)*(a + 1);

	return -1;
}

/*
Lv1. GCD LCM
*/
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(int n, int m)
{
	vector<int> answer;
	int gcd, lcm;
	gcd = 1;

	if (m < n)
	{
		int temp = n;
		n = m;
		m = temp;
	}

	while (true)
	{
		bool finish = true;
		for (int i = 1; i <= sqrt(n); i++)
		{
			if (n%i != 0)
				continue;
			if (n / i != 1 && m % (n / i) == 0)
			{
				gcd *= n / i;
				m /= n / i;
				n /= n / i;
				finish = false;
				break;
			}
			else if (i != 1 && m%i == 0)
			{
				gcd *= i;
				m /= i;
				n /= i;
				finish = false;
				break;
			}
		}
		if (finish)
			break;
	}

	lcm = gcd * n * m;

	answer.push_back(gcd);
	answer.push_back(lcm);

	return answer;
}

/*
Lv1. 하샤드 수
*/

#include <string>
#include <vector>

using namespace std;

bool solution(int x)
{
	int original = x;

	int sum = 0;
	while (x > 0)
	{
		sum += x % 10;
		x /= 10;
	}

	if (original % sum == 0)
		return true;
	else
		return false;
}


/*
Lv2. 124 나라의 숫자
*/
#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

string solution(int n)
{
	string answer = "";

	int index = n;
	int temp = 0;
	int length = 1;
	while (n > temp)
	{
		temp += pow(3, length);
		index -= pow(3, length);
		length++;
	}
	length--;

	index += pow(3, length);

	while (length > 0)
	{
		int num = ceil((float)index / pow(3, length - 1));
		index -= pow(3, length - 1) * (num - 1);
		switch (num)
		{
		case 1:
			answer += '1';
			break;
		case 2:
			answer += '2';
			break;
		case 3:
			answer += '4';
			break;
		}
		length--;
	}


	return answer;
}

/*
Lv2. 올바른 괄호
*/
#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
	bool answer = true;

	int counter = 0;

	for (char ch : s)
	{
		if (ch == '(')
			counter++;
		else
		{
			if (counter <= 0)
				return false;
			else
				counter--;
		}
	}

	if (counter != 0)
		return false;

	return answer;
}

/*
Lv2. 땅따먹기
*/
#include <iostream>
#include <vector>
using namespace std;

int Progress(vector<vector<int>>& land)
{
	for (int i = 1; i<land.size(); i++)
	{
		land[i][0] += max(land[i - 1][1], max(land[i - 1][2], land[i - 1][3]));
		land[i][1] += max(land[i - 1][0], max(land[i - 1][2], land[i - 1][3]));
		land[i][2] += max(land[i - 1][0], max(land[i - 1][1], land[i - 1][3]));
		land[i][3] += max(land[i - 1][0], max(land[i - 1][1], land[i - 1][2]));
	}

	return max(land[land.size() - 1][0], max(land[land.size() - 1][1], max(land[land.size() - 1][2], land[land.size() - 1][3])));
}

int solution(vector<vector<int>> land)
{
	int answer = 0;

	answer = Progress(land);

	return answer;
}

/*
Lv2. 최댓값, 최솟값
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s)
{
	string answer = "";
	int min, max;
	bool init = true;

	for (int i = 0; i<s.size();)
	{
		string numString = "";
		int num;
		int sign = 1;
		if (s[i] == '-')
		{
			sign = -1;
			i++;
		}

		while (i < s.size() && s[i] != ' ')
		{
			numString = numString + s[i];
			i++;
		}
		i++;

		num = stoi(numString) * sign;

		if (init)
		{
			min = num;
			max = num;
			init = false;
		}
		else
		{
			if (max < num)
				max = num;
			if (min > num)
				min = num;
		}
	}

	answer = to_string(min) + " " + to_string(max);

	return answer;
}