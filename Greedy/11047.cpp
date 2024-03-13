#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int N,K,cnt;


void CoinFunc(int x);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K;

	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}

	for (int i = v.size()-1; i >= 0; i--) {
		if (K == 0) {
			
			break;
		}
		CoinFunc(v[i]);
	}

	cout << cnt;
	return 0;
}

void CoinFunc(int x) {
	if (x > K) return;

	cnt += K / x;
	K = K % x;
}
