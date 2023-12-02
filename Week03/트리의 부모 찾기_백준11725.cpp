#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> v; //연결리스트 
bool visited[100001]; //방문 배열 
int parentArr[100001]; //부모 노드 배열 

void bfs(int start) {
	visited[start] = 1;

	queue<int> q;
	q.push(start);

	while (!q.empty()) { //큐에 값이 없을 때까지 
		int top = q.front(); //부모 노드 
		q.pop(); 

		for (int i = 0; i < v[top].size(); i++) { //top의 자식 노드 순회 
			int nextNode = v[top][i];

			if (!visited[nextNode]) {
				visited[nextNode] = true;
				q.push(nextNode);
				parentArr[nextNode] = top;
			}
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	v.resize(N + 1);

	int n1, n2;
	for (int i = 0; i < N-1; i++) {
		cin >> n1 >> n2;

		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}

	bfs(1);

	for (int i = 2; i < N+1; i++) {
		cout << parentArr[i] << "\n";
	}


	return 0;

}
