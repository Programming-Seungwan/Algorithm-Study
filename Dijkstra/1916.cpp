#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<pair<int,int> >> vec; //비용, 도착 노드 
vector<int> arr;

void func(int start,int end) {
	arr[start] = 0;
	queue<pair<int,int>> q;
	q.push({0,start});

	while (!q.empty()) {
		int x = q.front().second;
		int c = q.front().first;
		q.pop();

		if (c > arr[x]) continue;

		for (int i = 0; i < vec[x].size(); i++) {
			int next = vec[x][i].first;
			int cost = vec[x][i].second;

			if (arr[next] > arr[x] + cost) {
				arr[next] = arr[x] + cost;
				q.push({ arr[x] + cost, next });
			}
		}

	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	vec.resize(n + 1);
	arr.resize(n + 1, 1e9);

	for (int i = 0; i < m; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		vec[x].push_back({ y,cost });
	}

	int start, end;
	cin >> start >> end;

	func(start,end);

	cout << arr[end];

	return 0;

}

