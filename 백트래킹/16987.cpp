#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v; //내구도, 무게 
int n;
int ans = 0;

void Func(int grab) {
	
	if (grab == n) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (v[i].first <= 0) cnt++;
		}
		ans = max(cnt, ans);
		return;
	}

	if (v[grab].first <= 0) {
		Func(grab + 1);
		return;
	}

	bool act = false;
	for (int i = 0; i < n; i++) {
		if (v[i].first <= 0 || grab == i) continue;
		act = true;

		v[grab].first -= v[i].second;
		v[i].first -= v[grab].second;

		Func(grab+1);

		v[grab].first += v[i].second;
		v[i].first += v[grab].second;
	}

	if (!act) { //집을 수 있는 달걀이 하나도 없을 때 
		Func(grab + 1);
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	int d, w;
	for (int i = 0; i < n; i++) {
		cin >> d >> w;
		v.push_back({ d,w });
	}

	Func(0);

	cout << ans << endl;
    
    return 0;
	
}

