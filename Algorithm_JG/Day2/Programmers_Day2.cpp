#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

////���ڿ� ������������ ��ġ�ϱ�
//string stringLower(string s)
//{
//	sort(s.begin(), s.end());
//	reverse(s.begin(), s.end());
//
//	return s;
//}

////������ȣ
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
1-2-3- 4- 5- 6-7- 8- 9 -10-11-12-13 -14 -15  -16... ��
1-2-4-11-12-14-21-22-24-41-42-44-111-112-114-121...
�̷������� �̾����ȴ�.

1���ڸ����� 3���� ����� 
�������� 0�̸� 4
�������� 1�̸� 1
�������� 2�̸� 2

10���ڸ���
1-2-3 / 0
4-5-6 / 1
7-8-9 / 2
10-11-12 / 4

13-14-15 / 1
16-17-18 / 2
19-20-21 / 4

���� ��Ʈ�� 3������ 4��°�� 1�ڸ��� ���ϱ�
�̷��������ؾ��ϳ� �ƴѵ��ϴ�


-----
3���� ���������� �غ���
1-2-4 �̰� �� ����Ŭ, �ѽ���Ŭ���������� �ڸ��� +1

*/

////124������ ����
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
������ؼ� �� ���ϸ��
��� -> ����� ���������°�
*/
////�������
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

////�ϻ����
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

//�ִ����� �ּҰ����
//�ִ�����(gcd) -> ��Ŭ���� �˰���
//�ּҰ����(lcm) -> �μ��� ���߿� ���� ������, 
//�μ��� ���� �κп��� �ִ� ������� ������ �� ��
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

////�ùٸ� ��ȣ
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

////124������ ���� -> ���ͳݵ������޾Ҵ�...
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

////�������Ǻ� 
//�Է� ���� n �� �������� ���Ѵ�. 
//�������� �����Ͽ� n �� ���ٸ�(n + 1) * (n + 1) �� ��ȯ �Ѵ�.
//�ٸ��ٸ� - 1�� ��ȯ �Ѵ�.
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

//�ִ�� �ּҼ�
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