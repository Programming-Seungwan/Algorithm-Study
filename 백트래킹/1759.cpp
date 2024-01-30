#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[16];
bool visited[16];
char depth[16];
int l, c;

//인덱스 번호, 깊이, 모음 개수 
void func(int index, int cnt, int vow) {

	if (vow > l-2) { //"최소 두 개의 자음" 규칙을 지키지 못한 경우 
		return;
	}

	if (cnt == l) {
		if (vow == 0) return; //"최소 한개의 모음" 규칙을 지키지 못한 경우 
		for (int i = 0; i < l; i++) {
			cout << depth[i];
		}
		cout << "\n";
		return;
	}

	for (int i = index; i < c; i++) {
		if (visited[i]) continue;

		visited[i] = 1;
		char x = arr[i];
		depth[cnt] = x;

		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
			func(i + 1, cnt + 1, vow + 1);
		}
		else func(i + 1, cnt + 1, vow);

		visited[i] = 0;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> l >> c;

	char x;
	for (int i = 0; i < c; i++) {
		cin >> x;
		arr[i] = x;
	}

	sort(arr, arr + c);

	func(0, 0, 0);
    
    return 0;
	
}

