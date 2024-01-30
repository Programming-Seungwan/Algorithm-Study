#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[14];
int lotto[6];

void func(int index, int cnt) {
	if (cnt == 6) { // : 6글자를 다 채웠을때 출력 
		for (int i = 0; i < 6; i++) {
			cout << arr[lotto[i]] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = index; i < n; i++) {	
		lotto[cnt] = i;
		func(i+1, cnt + 1);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> n && n) {
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		func(0, 0);
		cout << "\n";
	}
	
    
    return 0;
	
}

