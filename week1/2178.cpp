#include <iostream>
#include <queue>
using namespace std;

int cnt[100][100];
int direction[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

void findWay(char list[][100],int n,int m, int x, int y){//n,m : 끝지점 x,y : 시작지점
    // k번째부터 찍어나감
    cnt[x][y]=1;

    queue<pair<int, int> > q; // 큐 생성
	q.push(make_pair(x, y)); // 시작점 넣기

    while(!q.empty()){
        int x = q.front().first;
		int y = q.front().second;

		q.pop(); // 큐 맨 앞 데이터 제거

        for (int i = 0; i < 4; i++){
            int next_x = x + direction[i][0];
			int next_y = y + direction[i][1];

			if(next_x<0 || n<next_x || next_y<0 || m<next_y || cnt[next_x][next_y]!=0 || list[next_x][next_y]=='0'){
                continue;
            }else{
                cnt[next_x][next_y]=cnt[x][y]+1;
                q.push(make_pair(next_x, next_y)); // 큐에 데이터 밀어넣기
            }

        }
    }
}

int main(){
    char list[100][100];
    int n,m; //2 ≤ N, M ≤ 100
    cin>>n>>m;

    //cnt 초기화
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                cnt[i][j]=0;
        }
    }

    for(int i=0;i<n;i++){ 
            cin>>list[i];
    }

    cnt[0][0]=1; //시작
    findWay(list,n-1,m-1,0,0);
    cout<<cnt[n-1][m-1]<<endl;


    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //             cout<< cnt[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

}


    