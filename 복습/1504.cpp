#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, E;

#define MAX_EDGE 805
#define MAXNUM 99999876

vector<pair<long long, int>> v[MAX_EDGE]; //{비용, 도착지점}
int d[MAX_EDGE];

void findDist(int s) {
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; //{비용, 도착 노드}

	for (int i = 1; i < N + 1; i++) {
		d[i] = MAXNUM;
	}

	d[s] = 0;
	pq.push({ 0,s });


	while (!pq.empty()) {
		int current = pq.top().second;
		long long start_to_current = pq.top().first;
		pq.pop();

		for (int i = 0; i < v[current].size(); i++) {
			int next = v[current][i].second;
			long long start_to_next = start_to_current + v[current][i].first;


			if (d[next] > start_to_next) {
				d[next] = start_to_next;
				pq.push({ start_to_next,next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		v[start].push_back({ cost,end });
		v[end].push_back({ cost,start });
	}

	int startNode, endNode;
	cin >> startNode >> endNode;

	findDist(startNode);
	long long v1_1 = d[1]; //1 --> startNode
	long long v1_v2 = d[endNode]; // startNode --> endNode
	long long v1_n = d[N];

	findDist(endNode);
	long long v2_1 = d[1];
	long long v2_n = d[N];

	long long ans1 = v1_1 + v1_v2 + v2_n;
	long long ans2 = v2_1 + v1_v2 + v1_n;
	long long ans = (ans1 > ans2) ? ans2 : ans1;

	if (ans >= MAXNUM) ans = -1;
	cout << ans << "\n";

}
