#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
1. Double Size
* n = vector size
- Sort : O(nlogn)
- Progress : O(n)
*/

long DoubleSize(vector<long> a, long b)
{
	sort(a.begin(), a.end());
	
	for (int n : a)
	{
		if (b == n)
			b <<= 1;
	}
	return b;
}

void main()
{
	vector<long> a = { 2,5,4,6,8 };
	cout << DoubleSize(a, 2) << endl;

	int exit;
	cin >> exit;
}



/*
2. Crossing The Street
* n = number of cars
- Sort : O(nlogn)
- Progress : O(n)
*/

struct PathInfo
{
	PathInfo(int start, int end)
	{
		this->start = start;
		this->end = end;
	}

	int start; 
	int end;
};

int WidestGap(int n, vector<int> start, vector<int> end)
{
	vector<PathInfo> CarPath;
	CarPath.reserve(start.size());
	for (size_t i = 0; i < start.size(); i++)
		CarPath.emplace_back(PathInfo(start[i], end[i]));

	sort(CarPath.begin(), CarPath.end(), [](PathInfo a, PathInfo b) -> bool
	{
		return a.start < b.start;
	});

	int position = 1;
	int carIndex = 0;
	int gap = 0;
	int maxGap = 0;
	int endPoint;

	while (carIndex < start.size())
	{
		gap = CarPath[carIndex].start - position;
		if (gap > maxGap)
			maxGap = gap;

		endPoint = CarPath[carIndex].end;
		carIndex++;
		if (carIndex >= start.size())
		{
			position = endPoint + 1;
			break;
		}
		while (CarPath[carIndex].start <= endPoint)
		{
			if (endPoint < CarPath[carIndex].end)
				endPoint = CarPath[carIndex].end;
			carIndex++;
			if (carIndex >= start.size())
				break;
		}
		position = endPoint + 1;
	}

	gap = n - position;
	if (gap > maxGap)
		maxGap = gap;

	return maxGap;
}

void main()
{
	vector<int> start = { 3, 8 };
	vector<int> end = { 4, 9 };
	int n = 10;

	cout << WidestGap(n, start, end) << endl;

	int exit;
	cin >> exit;
}



/*
3. Psychometric Testing
* n = vector size
* q = number of limits
- Progress : O(nq)
*/

vector<int> JobOffers(vector<int> scores, vector<int> lowerLimit, vector<int> upperLimit)
{
	vector<int> offers;
	offers.resize(lowerLimit.size(), 0);

	for (size_t i = 0; i < scores.size(); i++)
	{
		for (size_t j = 0; j < offers.size(); j++)
		{
			if (lowerLimit[j] <= scores[i] && scores[i] <= upperLimit[j])
				offers[j]++;
		}
	}

	return offers;
}

void main()
{
	vector<int> scores = {4,8,7};
	vector<int> lowerLimit = {2,4};
	vector<int> upperLimit = {8,4};

	vector<int> offer = JobOffers(scores, lowerLimit, upperLimit);

	for (int n : offer)
		cout << n << endl;

	int exit;
	cin >> exit;
}


/*
4. Merto Land Festival
* n = number of cities
- Sort : O(nlogn)
- Progress : O(n)
*/

struct CityInfo
{
	CityInfo(int p, int x, int y)
	{
		this->p = p;
		this->x = x;
		this->y = y;
	}

	int p;
	int x;
	int y;
};

int MinimizeCost(vector<int> p, vector<int> x, vector<int> y)
{
	vector<int> prefixSum;
	prefixSum.reserve(p.size());

	vector<CityInfo> cityList;
	cityList.reserve(p.size());

	for (size_t i = 0; i < p.size(); i++)
		cityList.emplace_back(CityInfo(p[i], x[i], y[i]));


	// X
	sort(cityList.begin(), cityList.end(), [](CityInfo a, CityInfo b) -> bool
	{
		return a.x < b.x;
	});

	int sum = 0;
	for (CityInfo& city : cityList)
	{
		sum += city.p;
		prefixSum.emplace_back(sum);
	}

	int minX;
	for (size_t i = 0; i < cityList.size(); i++)
	{
		if (prefixSum[i] < sum - prefixSum[i])
		{
			continue;
		}
		else
		{
			minX = cityList[i].x;
			break;
		}
	}

	int costX = 0;
	for (CityInfo& city : cityList)
		costX += abs(city.x - minX) * city.p;

	// Y
	sort(cityList.begin(), cityList.end(), [](CityInfo a, CityInfo b) -> bool
	{
		return a.y < b.y;
	});

	sum = 0;
	prefixSum.clear();
	prefixSum.reserve(p.size());
	for (CityInfo& city : cityList)
	{
		sum += city.p;
		prefixSum.emplace_back(sum);
	}

	int minY;
	for (size_t i = 0; i < cityList.size(); i++)
	{
		if (prefixSum[i] < sum - prefixSum[i])
		{
			continue;
		}
		else
		{
			minY = cityList[i].y;
			break;
		}
	}

	int costY = 0;
	for (CityInfo& city : cityList)
		costY += abs(city.y - minY) * city.p;


	cout << minX << ", " << minY << endl;
	return costX + costY;
}

void main()
{
	vector<int> p = { 3,1,2 };
	vector<int> x = { 0,3,4 };
	vector<int> y = { 0,3,4 };

	cout << MinimizeCost(p,x,y) << endl;

	int exit;
	cin >> exit;
}



/*
5. The Social NetWork
* n = count size
- Progress : O(nlogn)
*/

void SocialGraphs(vector<int> counts)
{
	unordered_map<int, vector<int>> groupMap;
	for (size_t i=0; i<counts.size(); i++)
		groupMap[counts[i]].emplace_back(i);

	map<int, vector<int>> printMap;
	for (auto& pair : groupMap)
	{
		int size = pair.first;
		for (size_t i = 0; i < pair.second.size(); i += size)
		{
			vector<int> temp;
			for (int j = 0; j < size; j++)
				temp.emplace_back(pair.second[i+j]);
			printMap.emplace(temp[0], temp);
		}
	}

	for (auto& pair : printMap)
	{
		for (int n : pair.second)
			cout << n << " ";
		cout << endl;
	}
	
}

void main()
{
	vector<int> counts = { 2,1,1,2,1 };
	SocialGraphs(counts);

	int exit;
	cin >> exit;
}