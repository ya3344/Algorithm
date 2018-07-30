#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

/*
���ڿ� ������������ ��ġ�ϱ�
*/
string solution1(string s) {
	string answer = "";

	sort(s.begin(), s.end(), greater<char>());
	answer = s;
	
	return answer;
}

/*
������ȣ
*/
string solution2(string s, int n) {

	string answer = "";
	int ASCIIcode = 0;
	char alphabet;

	for (size_t i = 0; i < s.size(); i++)
	{
		ASCIIcode = (int)s[i];

		if (ASCIIcode != 32) // 32 ����
		{
			if (ASCIIcode >= 65 && ASCIIcode <= 90)
			{
				ASCIIcode -= 65;
				ASCIIcode += n;
				ASCIIcode %= 26;

				ASCIIcode = ASCIIcode + 65;
			}
			else if (ASCIIcode >= 97 && ASCIIcode <= 122)
			{
				ASCIIcode -= 97;
				ASCIIcode += n;
				ASCIIcode %= 26;

				ASCIIcode = ASCIIcode + 97;
			}
		}
		
		alphabet = (char)ASCIIcode;
		answer += alphabet;
	}
	return answer;
}

/*
����� ��
*/
int solution3(int n)
{
	int answer = 0;

	for (int i = 1; i <= n; i++)
	{
		if (n%i == 0)
		{
			answer += i;
		}
	}
	return answer;
}

/*
�ִ������� �ּҰ����
*/

int GCD(int a, int b)
{
	int remainder = 0;
	int tempA = 0;

	while (b%a != 0)
	{
		remainder = b % a;

		tempA = a;
		a = remainder;
		b = tempA;
	}

	return a;
};

int LCM(int a, int b)
{
	return a*b / GCD(a, b);
}

vector<int> solution4(int n, int m) {
	vector<int> answer;

	answer.emplace_back(GCD(n, m));
	answer.emplace_back(LCM(n, m));

	return answer; 
}

/*
�ϻ��� ��
*/
bool solution5(int x) {

	bool answer = true;
	int sum = 0;
	int posNum = x;
	
	while (posNum != 0)
	{
		sum += posNum % 10;
		posNum /= 10;
	}
	
	cout << sum << endl;
	if (x % sum == 0)
	{
		answer = true;
	}
	else
	{
		answer = false;
	}

	return answer;
}

/*
���� ������ �Ǻ�
*/
long long solution6(long long n) {
	long long answer = 0;

	double num = 0;
	double quotient = 0;

	num = (double)sqrt(n);

	quotient = (int)num;
	quotient = num - quotient;

	if (quotient == 0.0)
	{
		answer = (num + 1) * (num + 1);
	}
	else
	{
		answer = -1;
	}


	return answer;
}


void main()
{
	//string s = "Zbcdefg";
	//cout << solution1(s).c_str() << endl;
	//string answer =  solution2("zzz", 1);

	/*for (char a : answer)
	{
		cout << a;
	}*/
	//solution4(3, 12);
	//solution5(9999);
	cout << solution6(3) << endl;

}