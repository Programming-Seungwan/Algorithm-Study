#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000 // 시작 노드에서 해당 노드까지의 경로가 없는 경우의 비용
#define MAX_VERTEX 20001 // 최대 vertex 개수
#define MAX_EDGE 300001 // 최대 edge 개수

using namespace std;

// 최소 비용 배열
int d[MAX_VERTEX];

// 간선 정보를 담은 Vector 생성
// index : 시작 노드
// value : pair<비용, 도착 노드> 목록
vector<pair<int, int> > edge[MAX_EDGE];



void dijkstra(int start_node) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //{비용, 도착 노드}
    d[start_node] = 0;

    // 시작 노드에서 시작 노드로 가는 경로와 비용을 pq 에 삽입
    pq.push({ 0,start_node });

    while (!pq.empty()) {
        //도착 노드를 현재 노드로 설정
        int current = pq.top().second;
        int start_to_current = pq.top().first;
        pq.pop();


        for (int i = 0; i < edge[current].size(); i++) {
            int next = edge[current][i].second;
            int start_to_next = start_to_current + edge[current][i].first;

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

    int V, E; //정점, 간선 
    cin >> V >> E;
    edge->resize(V + 1);

    int K; //시작 정점 
    cin >> K;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({ w,v });
    }

    for (int i = 1; i < V + 1; i++) {
        d[i] = INF;
    }

    dijkstra(K);

    for (int i = 1; i < V + 1; i++) {
        if (d[i] == INF) cout << "INF" << "\n";
        else cout << d[i] << "\n";
    }

    return 0;

}
