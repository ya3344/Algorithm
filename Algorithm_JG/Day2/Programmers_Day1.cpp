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

//최대공약수와 최소공배수
vector<int> solution(int n, int m) 
{
	vector<int> answer;
	return answer;
}

void main()
{
	

	system("Pause");
	return ;
}