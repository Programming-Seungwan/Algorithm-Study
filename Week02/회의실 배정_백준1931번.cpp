#include <iostream>
#include <queue>
using namespace std;

//오름차순으로 정렬 
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;

		//끝나는 시간 기준으로 오름차순 정렬
		pq.push({ end,start }); 
	}

	int answer = 1;
	//현재 회의 끝나는 시간 
	int now_end = pq.top().first;
	while (!pq.empty()) {
		pq.pop();

		if (pq.empty()) break;
		int next_start = pq.top().second;
		
		//현재 회의 끝나는 시간 <= 다음 회의 시작 시간
		if (now_end <= next_start) {
			//현재 회의 끝나는 시간을 다음 회의 끝나는 시간으로 설정
			now_end = pq.top().first;
			answer++;
		}

	}
	cout << answer << "\n";
	
	return 0;
	
}
