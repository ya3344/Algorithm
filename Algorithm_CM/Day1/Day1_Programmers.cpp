
#include <iostream>

#include <string>
#include <vector>
#include <math.h>

using namespace std;

//// 문제 6. 소수 찾기
//int solution(int n) {
//
//	vector<int>  vecPrime = { 2, 3 };
//	int answer = 2;
//
//	if (1000000 < n)
//		return 0;
//
//	if (2 == n)
//		return 1;
//	else if (3 == n)
//		return 2;
//
//	for (int i = 3; i <= n; i += 2)
//	{	
//		auto iter_begin = vecPrime.begin();
//		auto iter_end = vecPrime.end();
//
//		int size = sqrt(vecPrime.size());
//
//		for (int j = 0; j <= size; j++, iter_begin++)
//		{
//			if (0 == i % *iter_begin)
//				break;
//
//			if (j == size)
//			{
//				vecPrime.push_back(i);
//				break;
//			}
//		}
//	}
//
//	return vecPrime.size();
//}

//// 문제 5. 문자열 다루기 기본
//bool solution(string s) {
//	
//	bool answer = false;
//	int	stringCnt = 0;
//
//	if(1 > s.size() || 8 < s.size())
//		return answer;
//
//	if (4 == s.size() || 6 == s.size())
//	{
//		for (size_t i = 0; i < s.size(); i++)
//		{
//			if ((s[i] >= 48 && s[i] <= 57))
//				++stringCnt;
//		}
//
//		if (4 == stringCnt || 6 == stringCnt)
//			answer = true;
//	}
//
//	return answer;
//}

//// 문제 4. 문자열 내 p와 y의 개수
//
//bool solution(string s)
//{
//	// s : 80, 112 , y : 89, 121
//	bool answer = true;
//
//	short countP = 0;
//	short countY = 0;
//
//	for (size_t i = 0; i < s.size(); i++)
//	{
//		if (80 == s[i] || 112 == s[i])
//			++countP;
//		else if (89 == s[i] || 121 == s[i])
//			++countY;
//	}
//
//	if (0 == countP && 0 == countY)
//		return true;
//
//	if (countP == countY)
//		answer = true;
//	else
//		answer = false;
//
//	return answer;
//}

//// 문제 3. 두 정수 사이의 합
//
//long long solution(int a, int b) {
//	
//	long long answer = 0;
//
//	if ((-10000000 > a || a > 10000000) ||
//		(-10000000 > b || b > 10000000))
//		return answer;
//
//	if (a == b)
//		return a;
//	else if (a < b)
//	{
//		while (true)
//		{
//			answer += a++;
//
//			if (a == b)
//			{
//				answer += a;
//				break;
//			}
//		}
//	}
//	else
//	{
//		while (true)
//		{
//			answer += b++;
//
//			if (a == b)
//			{
//				answer += b;
//				break;
//			}
//		}	
//	}
//
//	return answer;
//}

//// 문제 2. 같은 숫자는 싫어
//
//vector<int> solution(vector<int> arr)
//{
//	vector<int> answer;
//
//	answer.reserve(arr.size());
//
//	for (int iNumber : arr)
//	{
//		if (answer.empty())
//			answer.push_back(iNumber);
//		
//		if (answer.back() != iNumber)
//			answer.push_back(iNumber);
//	}
//
//	return answer;
//}


//// 문제 1. 2016년
//
//string solution(int a, int b) {
//	
//	vector<int> vecMonth= {};
//	string answer = "";
//	int week = 0;
//
//	for (size_t i = 1; i < 12; i++)
//	{
//		if (4 == i || 6 == i || 9 == i || 11 == i)
//			vecMonth.push_back(30 + vecMonth[i - 2]);
//		else if (3 == i || 5 == i || 7 == i || 8 == i || 10 == i)
//			vecMonth.push_back(31 + vecMonth[i - 2]);
//		else if(1 == i)
//			vecMonth.push_back(31);
//		else if (2 == i)
//			vecMonth.push_back(29 + vecMonth[i - 2]);
//	}
//
//	for (size_t i = 1; i < 13; i++)
//	{
//		if (i == a)
//		{
//			if (1 == i)
//				week = b % 7;
//			else
//				week = (vecMonth[i - 2] + b) % 7;
//
//			if (1 == week)
//				answer = "FRI";
//			else if (2 == week)
//				answer = "SAT";
//			else if (3 == week)
//				answer = "SUN";
//			else if (4 == week)
//				answer = "MON";
//			else if (5 == week)
//				answer = "TUE";
//			else if (6 == week)
//				answer = "WED";
//			else if (0 == week)
//				answer = "THU";
//		}
//	}
//	return answer;
//}

void main()
{
	//// 문제 6. 소수 찾기
	//cout << solution(30) << endl;

	//// 문제 5. 문자열 다루기 기본
	//cout << solution("123456") << endl; 

	//// 문제 4. 문자열 내 p와 y의 개수
	//cout << solution("pPoooyY") << endl;

	//// 문제 3. 두 정수 사이의 합
	//cout << solution(3, 3) << endl;

	//// 문제 2. 같은 숫자는 싫어
	//cout << solution(vector<int>({ 1, 1, 3, 3, 0, 1, 1 })) << endl;

	//// 문제 1. 2016년
	//cout << solution(11, 9) << endl;

	return;
}