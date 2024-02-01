#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int arr[10001];
vector<tuple<long long, int, int>> vec; //가중치,정점1,정점2

void Reset(int v) {
	for (int i = 1; i <= v; i++)
		arr[i] = i;
}

int Find(int node) {
	if (arr[node] == node) return node;
	return arr[node] = Find(arr[node]);
}

int Union(int a, int b) {
	int n1 = Find(a);
	int n2 = Find(b);

	//연결하기 전에 사이클 생기는 것을 방지하기 위해 대표 노드가 같은지 검사 
	if (n1 == n2) return -1;

	n1 < n2 ? arr[n2] = n1 : arr[n1] = n2;
	return 0;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e;
	cin >> v >> e;

	Reset(v);

	int a, b;
	long long c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		vec.push_back(make_tuple(c, a, b));
	}

	//가중치 기준 오름차순으로 정렬 
	sort(vec.begin(), vec.end());

	int cnt = 0;
	int answer = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (cnt == v - 1) break; 

		int result = Union(get<1>(vec[i]), get<2>(vec[i]));
		if (result == -1) continue;
		else {
			cnt++;
			answer += get<0>(vec[i]);
		}
	}

	cout << answer;

	return 0;
	
	
}
