#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int map[26][26];
int visited[26][26];

int n;
vector<int> house;

//이동 배열 
int dx[4] = { 0,0,-1,1};
int dy[4] = { -1,1,0,0 };



void DFS(int x, int y){
	visited[x][y] = 1;
	house.push_back(1);
	

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= n) continue;
		if (!visited[next_x][next_y] && map[next_x][next_y]) {
			DFS(next_x, next_y);
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		for (int j = 0; j < n; j++) {
			map[i][j] = x[j] - '0';
		}
	}

	int cnt = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && map[i][j]) {
				DFS(i, j);
				cnt++;
				v.push_back(house.size());
				house.clear();

			}
		}
	}

	sort(v.begin(), v.end());

	cout << cnt << "\n";

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}

	
	return 0;
	
}
