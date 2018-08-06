#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;


// ���� 1. ���ڿ� ������������ ��ġ�ϱ�
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

// ���� 2. ���� ��ȣ
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

// ���� 3. ����� ��
int solution3(int n) {

	int answer = 0;

	for (int i = 1; i <= n; i++)
	{
		if (0 == n % i)
			answer += i;
	}

	return answer;
}

// ���� 4. �ִ������� �ּҰ����
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

// ���� 5. �ϻ��� ��
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

// ���� 6. ���� ������ �Ǻ�
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



// ���� 0. ���ڿ� �� ������� �����ϱ� (���ذ�)
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
	// ���� 1. ���ڿ� ������������ ��ġ�ϱ�
	cout << solution1("Zbcdefg") << endl;

	// ���� 2. ���� ��ȣ
	cout << solution2("a B z", 4) << endl;

	// ���� 3. ����� ��
	cout << solution3(5) << endl;

	// ���� 4. �ִ������� �ּҰ����
	vector<int> answer = solution4(12, 38);
	cout << answer.front() << " ";
	cout << answer.back() << endl;

	// ���� 5. �ϻ��� ��
	cout << solution5(7534) << endl;

	// ���� 6. ���� ������ �Ǻ�
	cout << solution6(121) << endl;


	// ���� 0. ���ڿ� �� ������� �����ϱ� (���ذ�)
	vector<string> vecString = solution0(vector<string>({ "abce", "abcd", "cdx" }), 2);
	for (string str : vecString)
		cout << str << " ";
}