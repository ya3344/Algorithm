
// ##############################  Answer.1

// ##############################  Answer.2

// ##############################  Answer.3





// ##############################  Answer.4

	//void main()
	//{
	// Test Case 1
	//int i = 15;
	//vector<int> v;
	//v.emplace_back(15);
	//v.emplace_back(5);
	//v.emplace_back(3);
	//v.emplace_back(7);
	//v.emplace_back(9);
	//v.emplace_back(14);
	//v.emplace_back(0);

	// Test Case 2
	//int i = 5;
	//vector<int> v;
	//v.emplace_back(2);
	//v.emplace_back(5);

	// Test Case 3 // 답 : 1
	//int i = 10;
	//vector<int> v;
	//v.emplace_back(10);
	//v.emplace_back(9);
	//v.emplace_back(8);
	//v.emplace_back(7);
	//v.emplace_back(6);
	//v.emplace_back(5);
	//v.emplace_back(4);
	//v.emplace_back(3);
	//v.emplace_back(2);
	//v.emplace_back(1);
	//v.emplace_back(0);

	// Test Case 4 // 답 : 15
	//	int i = 30;
	//	vector<int> v;
	//	v.emplace_back(25);
	//	v.emplace_back(27);
	//	v.emplace_back(18);
	//	v.emplace_back(20);
	//	v.emplace_back(23);
	//	v.emplace_back(15);
	//	v.emplace_back(16);
	//	v.emplace_back(29);
	//	v.emplace_back(30);
	//}


int solution(int i, vector<int> v)
{
	sort(v.begin(), v.end(), less<int>()); // 오름차순

	size_t inputSize = v.size();
	vector<int> dist;
	dist.reserve(inputSize - 1);

	int initDist = v[0];
	int endDist = i - v[inputSize - 1];

	if (inputSize == 1)
	{
		return max(initDist, endDist);
	}
	else
	{
		for (size_t i = 0; i < inputSize - 1; ++i)
		{
			dist.emplace_back(v[i + 1] - v[i]);
		}
	}

	int interDist = *max_element(dist.begin(), dist.end());

	if (0 == interDist % 2)
		interDist = interDist / 2;
	else
		interDist = interDist / 2 + 1;

	int initEnd = max(initDist, endDist);

	return max(initEnd, interDist);
}





// ##############################  Answer.5

	//void main()
	//{
	//	vector<vector<int>> input;

	// Test Case 1 
	// 3차원 배열
	//input.resize(3);
	//input[0].emplace_back(4);
	//input[0].emplace_back(1);
	//input[0].emplace_back(2);
	//input[1].emplace_back(7);
	//input[1].emplace_back(3);
	//input[1].emplace_back(4);
	//input[2].emplace_back(3);
	//input[2].emplace_back(5);
	//input[2].emplace_back(6);

	// Test Case 2
	// 2차원 배열
	//	input.resize(2);
	//	input[0].emplace_back(1);
	//	input[0].emplace_back(2);
	//	input[1].emplace_back(3);
	//	input[1].emplace_back(4);
	//
	//}



vector<vector<int>> solution(vector<vector<int>> matrix, int r)
{
	size_t lineNum = matrix.size(); // 행의 개수 == 열의 개수

	size_t maxCnt = r % 4;

	vector<vector<int>> buffer = matrix;

	for (size_t cnt = 0; cnt < maxCnt; ++cnt)
	{
		for (size_t col = 0; col < lineNum; ++col)
		{
			for (size_t row = 0; row < lineNum; ++row)
			{
				buffer[row][(lineNum - 1) - col] = matrix[col][row];
			}
		}

		matrix = buffer;
	}

	return matrix;
}





// ##############################  Answer.6

	//void main()
	//{
	//	vector<vector<int>> input;

	// Test Case 1
	//input.resize(6);
	//input[0].emplace_back(1);
	//input[0].emplace_back(1);
	//input[1].emplace_back(2);
	//input[1].emplace_back(1);
	//input[2].emplace_back(1);
	//input[2].emplace_back(2);
	//input[3].emplace_back(3);
	//input[3].emplace_back(4);
	//input[4].emplace_back(2);
	//input[4].emplace_back(1);
	//input[5].emplace_back(2);
	//input[5].emplace_back(1);

	// Test Case 2
	//input.resize(3);
	//input[0].emplace_back(1);
	//input[0].emplace_back(1);
	//input[1].emplace_back(2);
	//input[1].emplace_back(2);
	//input[2].emplace_back(3);
	//input[2].emplace_back(3);

	// Test Case 3 // 답 : 4
	//input.resize(6);
	//input[0].emplace_back(100);
	//input[0].emplace_back(100);
	//input[1].emplace_back(200);
	//input[1].emplace_back(200);
	//input[2].emplace_back(500);
	//input[2].emplace_back(500);
	//input[3].emplace_back(200);
	//input[3].emplace_back(200);
	//input[4].emplace_back(100);
	//input[4].emplace_back(100);
	//input[5].emplace_back(700);
	//input[5].emplace_back(700);


	// Test Case 4 // 답 : 10
	//input.resize(10);
	//input[0].emplace_back(1);
	//input[0].emplace_back(3);
	//input[1].emplace_back(3);
	//input[1].emplace_back(1);
	//input[2].emplace_back(5);
	//input[2].emplace_back(2);
	//input[3].emplace_back(2);
	//input[3].emplace_back(5);
	//input[4].emplace_back(8);
	//input[4].emplace_back(8);
	//input[5].emplace_back(2);
	//input[5].emplace_back(3);
	//input[6].emplace_back(4);
	//input[6].emplace_back(3);
	//input[7].emplace_back(6);
	//input[7].emplace_back(3);
	//input[8].emplace_back(7);
	//input[8].emplace_back(3);
	//input[9].emplace_back(8);
	//input[9].emplace_back(3);

	// Test Case 5 // 답 : 1
	//	input.resize(10);
	//	input[0].emplace_back(1);
	//	input[0].emplace_back(1);
	//	input[1].emplace_back(1);
	//	input[1].emplace_back(1);
	//	input[2].emplace_back(1);
	//	input[2].emplace_back(1);
	//	input[3].emplace_back(1);
	//	input[3].emplace_back(1);
	//	input[4].emplace_back(1);
	//	input[4].emplace_back(1);
	//	input[5].emplace_back(1);
	//	input[5].emplace_back(1);
	//	input[6].emplace_back(1);
	//	input[6].emplace_back(1);
	//	input[7].emplace_back(1);
	//	input[7].emplace_back(1);
	//	input[8].emplace_back(1);
	//	input[8].emplace_back(1);
	//	input[9].emplace_back(1);
	//	input[9].emplace_back(1);
	//}

int solution(vector<vector<int>> seat)
{
	sort(seat.begin(), seat.end(),
		[](auto iterFirst, auto iterSecond) {
		if (iterFirst[0] < iterSecond[0])
			return true;
		else if (iterFirst[0] == iterSecond[0])
		{
			return iterFirst[1] < iterSecond[1];
		}
		return false;
	});

	int count = 1;
	size_t inputSize = seat.size();
	for (size_t i = 0; i < inputSize - 1; ++i)
	{
		if (seat[i][0] == seat[i + 1][0] && seat[i][1] == seat[i + 1][1])
			continue;
		++count;
	}

	return count;
}