#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int node;
int x, y;
vector<vector<int>> v;
int visited[51];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			if (!visited[v[x][i]] || visited[v[x][i]] > visited[x] + 1) {
				q.push(v[x][i]);
				visited[v[x][i]] = visited[x] + 1;
			}
		}
	}

}

void reset() {
	for (int i = 0; i <= node; i++) visited[i] = 0;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> node;
	v.resize(node + 1);

	while (cin >> x >> y && ((x != -1) && (y != -1))) {
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	vector<pair<int,int>> v1; //점수, 후보 번호 
	for (int i = 1; i <= node; i++) {
		bfs(i);
		//i를 기준으로 각 회원과의 점수 중 최대 점수를 저장 
		v1.push_back({ *max_element(visited, visited + (node + 1)),i }); 
		reset();
	}

	//오름차순으로 정렬 
	sort(v1.begin(), v1.end());
    
	int num = v1[0].first;
	vector<int> index; // 회장 후보 
	index.push_back(v1[0].second);

	for (int i = 1; i < node; i++) {
		if (num == v1[i].first) { 
			index.push_back(v1[i].second); //회장 후보 저장 
		}
		else break;
	}

	cout << num-1 << " " << index.size() << "\n";

	for (auto i : index) {
		cout << i << " ";
	}

    return 0;
	
}

