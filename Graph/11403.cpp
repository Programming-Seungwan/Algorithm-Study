#include <iostream>
#include <queue>

using namespace std;

int n;
int arr[100][100]; // 입력으로 받은 그래프의 인접 행렬
int ans[100][100]; // 결과를 저장할 그래프의 인접 행렬


// 시작 노드부터 도달 가능한 모든 노드를 탐색하고 결과를 ans 행렬에 표시
void Func(int start) {
	queue<int> q;

	// 시작 노드에서 인접한 노드들을 큐에 추가하고 ans 행렬에 1로 표시
	for (int i = 0; i < n; i++) {
		if (arr[start][i]) {
			q.push(i);
			ans[start][i] = 1;
		}
	}

	// BFS를 통해 시작 노드부터 도달 가능한 모든 노드를 탐색
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		// 현재 노드에서 인접한 노드들을 큐에 추가하고 ans 행렬에 1로 표시
		for (int i = 0; i < n; i++) {
			if (arr[x][i] && !ans[start][i]) {
				q.push(i);
				ans[start][i] = 1;
			}
		}
	}
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}


	for (int i = 0; i < n; i++) {
		Func(i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
    
    return 0;
	
}

