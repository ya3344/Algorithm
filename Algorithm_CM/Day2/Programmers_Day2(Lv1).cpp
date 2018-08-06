#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;


// 문제 1. 문자열 내림차순으로 배치하기
string solution1(string s) {
	
	string answer = "";

	for (size_t i = 0; i < s.size(); i++)
	{
		for (size_t j = i; j < s.size(); j++)
		{
			if (s[i] == s[j])
				continue;

			if (s[i] < s[j])
			{
				char temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
			
		}
	}

	answer = s;

	return answer;
}

// 문제 2. 시저 암호
string solution2(string s, int n) {

	string answer = "";

	for (int i = 1; i <= n; i++)
	{
		for (size_t j = 0; j < s.size(); j++)
		{
			if ((s[j] >= 65 && s[j] <= 90) ||
				(s[j] >= 97 && s[j] <= 122))
				s[j] = s[j] + 1;

			if (s[j] == 123 || s[j] == 91)
				s[j] -= 26;
		}
	}

	answer = s;

	return answer;
}

// 문제 3. 약수의 합
int solution3(int n) {

	int answer = 0;

	for (int i = 1; i <= n; i++)
	{
		if (0 == n % i)
			answer += i;
	}

	return answer;
}

// 문제 4. 최대공약수와 최소공배수
vector<int> solution4(int n, int m) {

	vector<int> answer;
	int size = 0;

	if (n == m)
	{
		answer.push_back(n);
		answer.push_back(1);
		return answer;
	}

	if (n < m)
	{
		if (0 == m % n)
			size = m;
		else
			size = (m * n) / (m % n);
	}
	else
	{
		if (0 == n % m)
			size = n;
		else
			size = (m * n) / (n % m);
	}


	for (int i = 1; i <= size; i++)
	{
		if (0 == n % i && 0 == m % i)
		{
			if (!answer.empty())
				answer.pop_back();
			answer.push_back(i);
		}
	}

	answer.push_back((m * n) / answer.back());

	return answer;
}

// 문제 5. 하샤드 수
bool solution5(int x) {

	bool answer = false;
	list<int> vecNumber = {};
	int src = x;
	int dst = 0;

	if (x < 10)
		return true;

	while (src >= 10)
	{
		vecNumber.push_front(src % 10);

		if ((src /= 10) < 10)
			vecNumber.push_front(src);
	}

	for (int num : vecNumber)
		dst += num;

	if (0 == x % dst)
		answer = true;

	return answer;
}

// 문제 6. 정수 제곱근 판별
#define squareX(x) (x) * (x)
long long solution6(long long n) {

	long long answer = -1;

	for (size_t i = 1; i <= n; i++)
	{
		if (0 == n % i && n == squareX(i))
		{
			answer = squareX(i + 1);
			break;
		}
	}
	return answer;
}



// 문제 0. 문자열 내 마음대로 정렬하기 (미해결)
vector<string> solution0(vector<string> strings, int n) {

	vector<string> answer;

	for (string& str : strings)
	{
		for (string& str2 : strings)
		{
			if (str == str2)
				continue;

			if (str[n] < str2[n])
			{
				string temp = str;
				str = str2;
				str2 = temp;
			}

			if (str[n] == str2[n])
			{
				int strCnt = str.size() <= str2.size() ? str.size() : str2.size();

				for (int i = 0; i < strCnt; i++)
				{
					if (str[i] < str2[i])
					{
						string temp = str;
						str = str2;
						str2 = temp;
						break;
					}
				}
			}
		}
	}
	
	answer = strings;

	return answer;
	
}

void main()
{
	// 문제 1. 문자열 내림차순으로 배치하기
	cout << solution1("Zbcdefg") << endl;

	// 문제 2. 시저 암호
	cout << solution2("a B z", 4) << endl;

	// 문제 3. 약수의 합
	cout << solution3(5) << endl;

	// 문제 4. 최대공약수와 최소공배수
	vector<int> answer = solution4(12, 38);
	cout << answer.front() << " ";
	cout << answer.back() << endl;

	// 문제 5. 하샤드 수
	cout << solution5(7534) << endl;

	// 문제 6. 정수 제곱근 판별
	cout << solution6(121) << endl;


	// 문제 0. 문자열 내 마음대로 정렬하기 (미해결)
	vector<string> vecString = solution0(vector<string>({ "abce", "abcd", "cdx" }), 2);
	for (string str : vecString)
		cout << str << " ";
}