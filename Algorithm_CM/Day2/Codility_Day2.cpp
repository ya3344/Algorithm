
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;


// 문제 1. FrogJmp
int solution1(int X, int Y, int D) {

	int answer = Y - X;
	int temp = 0;

	if (0 != answer % D)
		++temp;

	answer /= D;
	answer += temp;

	return answer;
}


void main()
{
	// 문제 1. FrogJmp
	cout << solution1(10, 85, 30) << endl;

}