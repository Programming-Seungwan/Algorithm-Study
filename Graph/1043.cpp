#include <iostream>
using namespace std;
// 자신의 그룹이 어디에 속해있는지 리턴
int find_p(int parent[], int x){
    if(x != parent[x])
        return parent[x] = find_p(parent, parent[x]);
    else
        return parent[x];
}
// x와 y를 같은 그룹으로 만들어줌
void mer(int parent[], int x, int y){
    int px = find_p(parent, parent[x]);
    int py = find_p(parent, parent[y]);
    if(px != py){
        if(px < py)
            parent[py] = parent[px];
        else
            parent[px] = parent[py];
    }
}
int main(){
    int n,m; // 사람 수, 파티 수
    cin >> n >> m;
 
    int know_tru; // 진실을 아는 사람 수
    cin >> know_tru; 
    
    int parent[53]; // 어느 그룹에 속해 있는지 
    
    for(int i =0;i<=n; i++)
        parent[i] = i; // 각자 자신의 그룹으로 먼저 분류
    
    int temp; // 진실을 아는 사람
    for(int i =0 ;i<know_tru;i++){
        cin >> temp;
        parent[temp] = 0; // 진실을 아는 사람은 0 집합으로 분류
    }
 
    int Pnum;
    int temp2;
 
    int arr[53][53]; // 파티번호, 파티 사람 번호
    int arrsiz[53]; // 각 파티의 인원수 저장
    for(int i =0;i<m;i++){
        cin >> Pnum; // 파티에 오는 사람 수 
        cin >> temp; // 파티에 오는 첫번째 사람
        arrsiz[i] = Pnum; // 각 파티의 인원 수 저장
        arr[i][0] =temp; 
        // 첫번째 사람만 올 경우 혼자 오는 것이기 때문에
        // 다른 사람과 그룹을 합치지 않아도 돼서 분류
        for(int j = 1; j < Pnum; j++){
            cin >> temp2; // 파티에 오는 사람 번호
            arr[i][j] = temp2; // 파티에 오는 사람 번호 저장
            mer(parent, temp ,temp2); // 파티에 오는 사람 그룹 합침
        }
    }
    int answer = m; // 전부 거짓말을 할 경우 수 부터 시작
    
    // 각 파티마다 진실을 아는 사람이 한명이라도 있으면 거짓말을 할 수 없음
    // -> 하나 빼줌
    for(int i =0; i<m;i++){
        for(int j=0;j<arrsiz[i]; j++){
            if(find_p(parent, parent[arr[i][j]]) == 0){
                answer--;
                break;
            }
        }
    }
    cout << answer;
    return 0;
}
