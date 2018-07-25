#include <iostream>
using namespace std;

void Matching(int iArr, int& iCount);

int main() {
	int n = 0;
	int iCount = 0;
	cin >> n;
	int *iArr;
	iArr = new int[n+1];
	for (int i = 0; i < n+1; i++) {
		//cin >> iArr[i];
		iArr[i] = i;
		Matching(iArr[i], iCount);
	}

	delete[] iArr;


	cout << iCount;

	system("Pause");
	return 0;
}


void Matching(int iArr, int& iCount) {
	bool check = false;

	if (iArr == 1 || iArr == 0)
		return;

	for (int i = 2; i < iArr; i++) {
		if (iArr%i == 0) {
			check = true;
			break;
		}
	}
	if (check == false)
		++iCount;

}