#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> q; //우선순위 큐 선언
int arr[100001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];

		if (arr[i] != 0) { //입력값이 0이 아니라면 -> 우선순위 큐에 push 
			q.push(arr[i]);
		}
		else { //입력값이 0인 경우 
			if (q.empty())cout << "0" << "\n"; //만약 우선순위 큐가 비워있으면 
			else {
				cout << q.top() << "\n"; //우선순위 큐 첫번째 값 출력 
				q.pop();
			}
		}
	}

	return 0;
}
