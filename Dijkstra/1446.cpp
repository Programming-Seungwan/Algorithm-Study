#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, d;
int arr[10001];
vector<pair<int, int>> v[10001];

//다익스트라 + dp 문제 

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> d;

	for (int i = 0; i < n; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		v[end].push_back({ cost, start });
	}

	//초기화 
	for (int i = 0; i < 10001; i++) {
		arr[i] = 1e9;
	}
	arr[0] = 0;
	

	for (int i = 1; i < 10001; i++) {
		if (v[i].empty()) {
			arr[i] = arr[i-1] + 1;
			continue;
		}
		
		//같은 도착 노드에 도착하는 경우 
		for (auto a : v[i]) {
			int tmp = arr[a.second] + a.first;
			arr[i] = min(arr[i], min(arr[i - 1] + 1, tmp));
		}
	}

	cout << arr[d] << endl;


	return 0;

}

