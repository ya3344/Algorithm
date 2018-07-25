#include <iostream>
#include <string>
#include <vector>
using namespace std;

void main()
{
	int N = 0;
	cin >> N;
	int num = N;

	int result[20];
	int ilengthtemp = 0;
	for (int i = 0; 0 < num; i++)
	{
		result[i] = num % 2;
		num = num / 2;
		ilengthtemp++;
	}
	ilengthtemp--;

	for (int i = ilengthtemp; i >= 0; i--)
	{
		cout << result[i];
	}
	cout << endl;

	vector<int> vecTemp;

	while (ilengthtemp >= 0)
	{
		vecTemp.push_back(result[ilengthtemp]);
		ilengthtemp--;
	}

	int ivecTempLength = vecTemp.size();
	int iCount = 0;
	int iCountTemp = 0;
	bool bCountStart = false;

	for (auto iter = vecTemp.begin(); iter != vecTemp.end(); )
	{
		if (*iter == 0 && bCountStart == false)
		{
			//iter = vecTemp.erase(iter);
			++iter;
			continue;
		}
		else if (*iter == 1 && bCountStart == false)
		{
			bCountStart = true;
			iter++;
			continue;
		}

		if (*iter == 0 && bCountStart == true)
		{
			iCount++;
		}
		else if (*iter == 1 && bCountStart == true)
		{
			if (iCount > 0) //카운팅을 하고있는 도중에 1이 나오면
			{
				if (iCount > iCountTemp)//기존에 카운팅한것보다 더 많으면
				{
					iCountTemp = iCount;
					iCount = 0;
					//카운팅하던거 저장하고 초기화
				}
			}
			//카운팅하던중이 아니면 그냥넘어감

		}
		iter++;
	}

	cout << iCountTemp << endl;




	system("pause");
	return;
}

////2016년
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(int a, int b) {
//
//	string arr[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
//
//	int iarrNum = 0;
//	switch (a)
//	{
//	case 1:
//	{
//		iarrNum = 5;
//		for (int i = 1; i < b; i++)
//		{
//			iarrNum++;
//			if (iarrNum > 6)
//				iarrNum = 0;
//		}
//	}
//	break;
//	case 2:
//	{
//		iarrNum = 1;
//		for (int i = 1; i < b; i++)
//		{
//			iarrNum++;
//			if (iarrNum > 6)
//				iarrNum = 0;
//		}
//	}
//	break;
//	case 3:
//	{
//		iarrNum = 2;
//		for (int i = 1; i < b; i++)
//		{
//			iarrNum++;
//			if (iarrNum > 6)
//				iarrNum = 0;
//		}
//	}
//	break;
//
//	case 4:
//	{
//		iarrNum = 5;
//		for (int i = 1; i < b; i++)
//		{
//			iarrNum++;
//			if (iarrNum > 6)
//				iarrNum = 0;
//		}
//	}
//	break;
//	case 5:
//	{
//		iarrNum = 0;
//		for (int i = 1; i < b; i++)
//		{
//			iarrNum++;
//			if (iarrNum > 6)
//				iarrNum = 0;
//		}
//	}
//	break;
//	case 6:
//	{
//		iarrNum = 3;
//		for (int i = 1; i < b; i++)
//		{
//			iarrNum++;
//			if (iarrNum > 6)
//				iarrNum = 0;
//		}
//	}
//	break;
//	case 7:
//	{
//		iarrNum = 5;
//		for (int i = 1; i < b; i++)
//		{
//			iarrNum++;
//			if (iarrNum > 6)
//				iarrNum = 0;
//		}
//	}
//	break;
//	case 8:
//	{
//		iarrNum = 1;
//		for (int i = 1; i < b; i++)
//		{
//			iarrNum++;
//			if (iarrNum > 6)
//				iarrNum = 0;
//		}
//	}
//	break;
//	case 9:
//	{
//		iarrNum = 4;
//		for (int i = 1; i < b; i++)
//		{
//			iarrNum++;
//			if (iarrNum > 6)
//				iarrNum = 0;
//		}
//	}
//	break;
//	case 10:
//	{
//		iarrNum = 6;
//		for (int i = 1; i < b; i++)
//		{
//			iarrNum++;
//			if (iarrNum > 6)
//				iarrNum = 0;
//		}
//	}
//	break;
//	case 11:
//	{
//		iarrNum = 2;
//		for (int i = 1; i < b; i++)
//		{
//			iarrNum++;
//			if (iarrNum > 6)
//				iarrNum = 0;
//		}
//	}
//	break;
//	case 12:
//	{
//		iarrNum = 4;
//		for (int i = 1; i < b; i++)
//		{
//			iarrNum++;
//			if (iarrNum > 6)
//				iarrNum = 0;
//		}
//	}
//	break;
//	default:
//		break;
//	}
//	string answer = arr[iarrNum];
//	return answer;
//}


//같은 숫자는 싫어
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//void roop(vector<int>::iterator iter, vector<int>::iterator temp, vector<int>* arr)
//{
//	if (*temp == *iter)
//	{
//		temp = arr->erase(temp);
//		if (temp == arr->end())
//			return;
//
//		roop(iter, temp, arr);
//	}
//}
//
//vector<int> solution(vector<int> arr)
//{
//	vector<int> answer;
//
//	for (auto iter = arr.begin(); iter != arr.end(); iter++)
//	{
//		auto temp = iter;
//
//
//		temp++;
//		if (temp == arr.end())
//			break;
//
//		roop(iter, temp, &arr);
//
//	}
//
//
//	return arr;
//}

//두정수 사이의 합
//#include <string>
//#include <vector>
//
//using namespace std;
//
//long long solution(int a, int b) {
//	long long answer = 0;
//
//
//	if (a < b)
//	{
//		for (int i = a; i <= b; i++)
//		{
//			answer += i;
//		}
//	}
//	else if (a >= b)
//	{
//		for (int i = b; i <= a; i++)
//		{
//			answer += i;
//		}
//	}
//	return answer;
//}



////문자열 내 P와 Y의 개수
//#include <string>
//#include <iostream>
//using namespace std;
//
//bool solution(string s)
//{
//	bool answer = true;
//
//	int iPCount = 0;
//	int iYCount = 0;
//
//	int iLength = s.length();
//
//	for (int i = 0;i < iLength;i++)
//	{
//		if (s[i] == 'P' || s[i] == 'p')
//		{
//			iPCount++;
//			continue;
//		}
//		if (s[i] == 'Y' || s[i] == 'y')
//		{
//			iYCount++;
//			continue;
//		}
//	}
//	if (iPCount == iYCount)
//		answer = true;
//	else
//		answer = false;
//
//	return answer;
//}


////문자열 다루기 기본
//#include <string>
//#include <vector>
//
//using namespace std;
//
//bool solution(string s) {
//	bool answer = true;
//
//	int iLength = 0;
//	iLength = s.length();
//	if (iLength != 4 && iLength != 6)
//	{
//		answer = false;
//	}
//
//
//	for (int i = 0; i < iLength; i++)
//	{
//		//cout << s[i] << endl;
//		if ('0' == s[i] || '1' == s[i] || '2' == s[i] || '3' == s[i] || '4' == s[i]
//			|| '5' == s[i] || '6' == s[i] || '7' == s[i] || '8' == s[i] || '9' == s[i])
//		{
//		}
//		else
//			answer = false;
//
//	}
//
//	return answer;
//}




//소수찾기
//#include <string>
//#include <vector>
//
//using namespace std;
//
//void Matching(int iArr, int& iCount);
//
//
//int solution(int n) {
//	int answer = 0;
//
//	int iCount = 0;
//	int *iArr;
//	iArr = new int[n + 1];
//	for (int i = 0; i < n + 1; i++) {
//		iArr[i] = i;
//		Matching(iArr[i], iCount);
//	}
//
//	delete[] iArr;
//
//	return iCount;
//}
//
//
//void Matching(int iArr, int& iCount) {
//	bool check = false;
//
//	if (iArr == 1 || iArr == 0)
//		return;
//
//	for (int i = 2; i < iArr; i++) {
//		if (iArr%i == 0) {
//			check = true;
//			break;
//		}
//	}
//	if (check == false)
//		++iCount;
//
//}