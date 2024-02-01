#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
vector<int> ans;
int op[4] = { 0 }; //연산자 배열 

int N;
void DFS(int index, int total, int opN); //인덱스 번호, 총합, 연산자 번호 

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

  //입력 
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
  //

  //정렬 
	sort(ans.begin(), ans.end());

	cout << ans.back() << "\n";
	cout << ans.front() << "\n";

	return 0;
}

void DFS(int index,int total, int opN) {

  //연산자 번호에 맞게 계산 
	if (opN == 0) total += vec[index];
	else if (opN == 1) total -= vec[index];
	else if (opN == 2) total *= vec[index];
	else {
		if (total < 0) {
			total = ((total * (-1)) / vec[index]) * (-1);
		}
		else total /= vec[index];
	}

  //만약 더 이상 추가할 데이터가 없는 경우 
	if (index == vec.size() - 1) {
		ans.push_back(total);
		return;
	}

  //사용한 연산자 감소 
	op[opN]--;

	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			DFS(index + 1, total, i);
		}
	}
  //백트래킹 
	op[opN]++;

	
}
