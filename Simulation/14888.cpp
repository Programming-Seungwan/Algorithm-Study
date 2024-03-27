#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
vector<int> ans;
int op[4] = { 0 };

int N;
void DFS(int index, int total, int opN);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vec.resize(N );

	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}
	
	int a;
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	
	for (int i = 0; i < 4; i++) {
		if(op[i]!=0) DFS(1, vec[0], i);
	}

	sort(ans.begin(), ans.end());

	cout << ans.back() << "\n";
	cout << ans.front() << "\n";

	return 0;
}

void DFS(int index,int total, int opN) {

	if (opN == 0) total += vec[index];
	else if (opN == 1) total -= vec[index];
	else if (opN == 2) total *= vec[index];
	else {
		if (total < 0) {
			total = ((total * (-1)) / vec[index]) * (-1);
		}
		else total /= vec[index];
	}


	if (index == vec.size() - 1) {
		ans.push_back(total);
		return;
	}

	op[opN]--;

	for (int i = 0; i < 4; i++) {
		
		if (op[i] > 0) {
			DFS(index + 1, total, i);
		}
	}
	op[opN]++;

	
}
