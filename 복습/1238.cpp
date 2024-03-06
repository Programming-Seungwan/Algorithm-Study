#include <bits/stdc++.h>
using namespace std;

int n, m, x;
vector<vector<pair<int, int>>> v; // 정방향 그래프
vector<vector<pair<int, int>>> reverse_v; // 역방향 그래프
int cost[2][1001];

void Dijkstra(int ver, vector<vector<pair<int, int>>> vec) {
    fill(cost[ver], cost[ver] + n+1, 1e9); // 비용 배열 초기화

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //{비용, 도착 노드}
    cost[ver][x] = 0;
    pq.push({ 0,x });

    while (!pq.empty()) {
        int costVal = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (int i = 0; i < vec[node].size(); i++) {
            int nextcost = costVal + vec[node][i].second;
            int nextnode = vec[node][i].first;

            // 다음 노드로 가는 비용이 현재 저장된 비용보다 작으면 업데이트하고 큐에 넣음
            if (cost[ver][nextnode] > nextcost) {
                cost[ver][nextnode] = nextcost;
                pq.push({ nextcost, nextnode });
            }
        }
    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 노드 수, 도로 수, 파티가 열리는 마을 번호
    cin >> n >> m >> x;

    v.resize(n + 1);
    reverse_v.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;

        v[a].push_back({ b,cost });
        reverse_v[b].push_back({ a,cost });
    }

    // 정방향 그래프와 역방향 그래프에서의 다익스트라 알고리즘 실행
    Dijkstra(0, v);
    Dijkstra(1, reverse_v);

    int answer = 0;

    for (int j = 1; j <= n; j++) {
        answer = max(answer, cost[0][j] + cost[1][j]);
     }
    

    cout << answer;
    
   
    return 0;
}

