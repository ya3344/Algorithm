#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Q1. 2016년
string solution1(int a, int b) {

	// 1월 1일은 금요일

	// 1월, 3월, 5월, 7월, 8월, 10월, 12월  (31일) 
	// 4월, 6월, 9월, 11월 (30일)
	// 2월 (29일)

	int monthDays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char* SevenDays[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	int dayNum = b;

	for (int i = 0; i < a - 1; ++i)
	{
		dayNum += monthDays[i];
	}

	string answer = SevenDays[(dayNum + 4)% 7 ];

	return answer;
}


// Q2. 같은 숫자는 싫어
vector<int> solution2(vector<int> arr)
{
	vector<int> answer;

	int arrSize = arr.size();
	int preNum = 0;

	if (0 == arrSize)
		return answer;

	preNum = -1;

	answer.reserve(arrSize);
	for (int i = 0; i < arrSize; ++i)
	{
		if (preNum != arr[i])
		{
			answer.push_back(arr[i]);
			preNum = arr[i];
		}
	}


	return answer;
}


// Q3. 두 정수 사이의 합
long long solution3(int a, int b) {
	if (a == b)
		return a;

	if (a < b)
		return (a + b) * (long long)(b - a + 1) / 2;
	else
		return (a + b) * (long long)(a - b + 1) / 2;
}


// Q4. 문자열 내 p와 y의 개수
bool solution4(string s)
{
	// P : 80, p : 112, Y : 89, y : 121

	int cnt = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		char tmp = s[i];
		if (tmp == 80 || tmp == 112)
			++cnt;
		else if (tmp == 89 || tmp == 121)
			--cnt;
	}

	return !bool(cnt);
}

// Q5. 문자열 다루기 기본
bool solution5(string s) 
{
	// 숫자 ASCII 48 ~ 57
	int len = s.length();

	if (len != 4 && len != 6)
		return false;

	for (int i = 0; i < len; ++i)
	{
		if (s[i] < 48 || s[i] > 57)
			return false;
	}

	return true;
}


// Q6. 소수 찾기
int solution(int n) {
	int answer = 0;
	bool bDecimal = false;

	vector<int> vecDecimal;

	for (int i = 2; i <= n; ++i)
	{
		bDecimal = true;
		for (int decimal : vecDecimal)
		{
			if (i%decimal == 0)
			{
				bDecimal = false;
				break;
			}
		}

		if (bDecimal)
			vecDecimal.emplace_back(i);
	}

	return vecDecimal.size();
}


