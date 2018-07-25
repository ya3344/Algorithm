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

