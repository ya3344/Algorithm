#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

////문자열 내림차순으로 배치하기
//string stringLower(string s)
//{
//	sort(s.begin(), s.end());
//	reverse(s.begin(), s.end());
//
//	return s;
//}

////시저암호
//string Sizer(string s, int n)
//{
//	int iSize = s.size();
//	for (int i = 0; i < iSize; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			if (s[i] == ' ')
//				break;
//
//			if (s[i] == 'Z')
//			{
//				s[i] = 'A';
//				continue;
//			}
//			else if (s[i] == 'z')
//			{
//				s[i] = 'a';
//				continue;
//			}
//			s[i]++;
//		}
//	}
//	return s;
//}

/*
1-2-3- 4- 5- 6-7- 8- 9 -10-11-12-13 -14 -15  -16... 를
1-2-4-11-12-14-21-22-24-41-42-44-111-112-114-121...
이런식으로 이어나가면된다.

1의자리수는 3으로 나누어서 
나머지가 0이면 4
나머지가 1이면 1
나머지가 2이면 2

10의자리수
1-2-3 / 0
4-5-6 / 1
7-8-9 / 2
10-11-12 / 4

13-14-15 / 1
16-17-18 / 2
19-20-21 / 4

위에 루트를 3번돌고 4번째엔 1자리수 더하기
이런식으로해야하나 아닌듯하다


-----
3으로 나눈다음에 해보자
1-2-4 이게 한 싸이클, 한싸이클을돌때마다 자리수 +1

*/

////124나라의 숫자
//int Add(int n)
//{
//	int answer = 0;
//	int iIndex = 0;
//
//	while (1)
//	{
//		int iAcc = 0;
//
//		if (n == iAcc)
//			break;
//
//		iAcc++;
//
//	}
//
//
//
//	return answer;
//}

/*
약수구해서 다 더하면됨
약수 -> 나누어서 딱떨어지는값
*/
////약수의합
//int Add(int n) 
//{
//	int answer = 0;
//	
//	for (int i = 1; i <= n; i++)
//	{
//		if (n%i == 0)
//			answer += i;
//	}
//	
//	
//	return answer;
//}

////하샤드수
//bool CheckHashad(int x)
//{
//	int first = x;
//	int iRest;
//	int iAcc = 0;
//
//	while (0 < x)
//	{
//		iRest = x % 10;
//		iAcc += iRest;
//		x = x / 10;
//	}
//
//	if (first % iAcc == 0)
//		return true;
//	else
//		return false;
//
//}

//최대공약수 최소공배수
//최대공약수(gcd) -> 유클리드 알고리즘
//최소공배수(lcm) -> 두수의 배중에 가장 작은값, 
//두수를 곱한 부분에서 최대 공약수를 나누어 준 값
//void swap(int &ia, int &ib)
//{
//	int itemp = ia;
//	ia = ib;
//	ib = itemp;
//
//}
//
//int gcd(int ia, int ib)
//{
//	if (ia < ib)
//		swap(ia, ib);
//
//	while (ib != 0)
//	{
//		int itemp = ia % ib;
//		ia = ib;
//		ib = itemp;
//	}
//	return ia;
//}
//
//int lcm(int &ia, int &ib)
//{
//	return (ia * ib) / gcd(ia, ib);
//}
//
//vector<int> gcdlcm(int a, int b)
//{
//	vector<int> vecAnswer;
//	vecAnswer.push_back(gcd(a, b));
//	vecAnswer.push_back(lcm(a, b));
//	return vecAnswer;
//}

////올바른 괄호
//bool solution(string s)
//{
//	int iTemp = 0;
//	for (int i = 0;i< s.length();i++)
//	{
//		if (s[0] == ')'&&s[s.length()] == '(')
//		{
//			return false;
//		}
//		if (s[i] == '(')
//		{
//			iTemp++;
//		}
//		else
//		{
//			iTemp--;
//			if (iTemp < 0)
//			{
//				return false;
//			}
//		}
//	}
//
//	if (iTemp == 0) {
//		return true;
//	}
//
//	return false;
//}

////124나라의 숫자 -> 인터넷도움을받았다...
//string Country124(int n)
//{
//	string strAnswer = "";
//
//	char nums[3] = { '1', '2', '4' };
//	int quotient = -1, iRest;
//
//	while (quotient != 0)
//	{
//		quotient = (n - 1) / 3;
//		iRest = (n - 1) % 3;
//		strAnswer = nums[iRest] + strAnswer;
//		n = quotient;
//	}
//
//	return strAnswer;
//}

////제곱근판별 
//입력 받은 n 의 제곱근을 구한다. 
//제곱근을 제곱하여 n 과 같다면(n + 1) * (n + 1) 을 반환 한다.
//다르다면 - 1을 반환 한다.
//long long solution(long long n) {
//	long long answer = 0;
//
//	long long num = sqrt(n);
//	if (num * num == n) {
//		answer = (num + 1)  * (num + 1);
//	}
//	else {
//		answer = -1;
//	}
//
//	return answer;
//}

//최대수 최소수
//string solution(string s) 
//{
//	string answer = "";
//
//	vector<int> vecArr = {};
//
//	int iSize = s.size();
//
//	for (int i = 0;i < iSize; i++)
//	{
//		if (s[i] == ' ')
//			continue;
//		else
//		{
//			int a =  s[i] - '0';
//			vecArr.push_back(a);
//		}
//	}
//	
//	sort(vecArr.begin(), vecArr.end());
//	
//	//strcat(answer, (char*)vecArr[0]);
//	
//	string a = to_string(vecArr[0]);
//	string b = to_string(vecArr[vecArr.size()-1]);
//	a = a + " " + b;
//	answer = a;
//
//	return answer;
//}

void main()
{
	

	system("Pause");
	return ;
}