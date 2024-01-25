#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
bool visited[9] = { false };
int N, M,cnt;

void func(int x, int cnt);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	v.resize(M+1, 0);
	
	for (int i = 1; i < N+1; i++) {
		func(i, 1);
		visited[i] = false;
	}

	

	return 0;
}


void func(int x,int cnt) {
	v[cnt] = x;
	visited[x] = true;

	if (cnt == M) {
		for (int i = 1; i < M+1; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i < N+1; i++) {
		if (!visited[i]) {
			func(i, cnt + 1);
			visited[i] = false;
		}
	}
}
