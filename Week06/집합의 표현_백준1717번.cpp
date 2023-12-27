#include <iostream>
using namespace std;

int arr[1000001];

// 각 노드가 모두 대표 노드이므로 배열은 자신의 인덱스값으로 초기화
void Reset(int node) {
	for (int i = 1; i <= node; i++)
		arr[i] = i;
}

//자신이 속한 집합의 대표 노드를 찾는 연산 
int Find(int node) {
	if (arr[node] == node) return node;
	return arr[node] = Find(arr[node]);
}

// A U B 
void Union(int a, int b) {
	int node1 = Find(a);
	int node2 = Find(b);

	(node1 < node2) ? arr[node2] = node1 : arr[node1] = node2;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	Reset(n);

	int x, a, b;
	for (int i = 0; i < m; i++) {
		cin >> x >> a >> b;
		if (x == 0) Union(a, b);
		else {
			if (Find(a) == Find(b)) cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
	}

	return 0;
}

