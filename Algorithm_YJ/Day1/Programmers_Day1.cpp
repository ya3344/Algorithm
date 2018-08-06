/*
Lv1. 2016
*/

#include <string>
#include <vector>

using namespace std;

string solution(int a, int b)
{
	string answer = "";

	int daysMonth[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	string day[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	enum Day { SUN, MON, TUE, WED, THU, FRI, SAT };

	const Day firstDay = FRI;
	int days = 0;

	for (int i = 0; i<a - 1; i++)
	{
		days += daysMonth[i];
	}
	days += b - 1;

	Day targetDay = Day((firstDay + days) % 7);
	answer = day[targetDay];

	return answer;
}

/*
Lv1. 같은 숫자는 싫어
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;

	vector<int>::iterator iter = arr.begin();
	int firstNum = *iter;
	answer.push_back(*iter);
	iter++;

	for (; iter != arr.end(); iter++)
	{
		if (*iter != firstNum)
		{
			firstNum = *iter;
			answer.push_back(*iter);
		}
	}

	return answer;
}

/*
Lv1. 두 정수 사이의 합
*/

#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
	long long answer = 0;

	if (a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	for (int i = a; i <= b; i++)
		answer += i;

	return answer;
}

/*
Lv1. 문자열 내 P Y 개수
*/
#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	bool answer = true;

	int pCount = 0;
	int yCount = 0;

	for (int i = 0; i<s.length(); i++)
	{
		if (s[i] == 'p' || s[i] == 'P')
			pCount++;
		else if (s[i] == 'y' || s[i] == 'Y')
			yCount++;
	}

	answer = (pCount == yCount) ? true : false;

	return answer;
}

/*
Lv1. 문자열 다루기 기본
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s)
{
	bool answer = true;

	if (s.length() != 4 && s.length() != 6)
		return false;

	for (int i = 0; i<s.length(); i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return false;
	}

	return answer;
}

/*
Lv1. 소수 찾기
*/
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
	int answer = 0;

	vector<int> prime;
	for (int i = 2; i <= n; i++)
	{
		bool check = true;
		int sqrtCut = sqrt(i);

		for (int j : prime)
		{
			if (j > sqrtCut)
				break;
			if (i%j == 0)
			{
				check = false;
				break;
			}
		}

		if (check == true)
		{
			prime.push_back(i);
			answer++;
		}
	}

	return answer;
}