/*1931 회의실 배정
2029.11.30(목)

각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int,int> v1, pair<int,int> v2){
    if(v1.second == v2.second){
        return v1.first<v2.first;
    }
    else{
        return v1.second < v2.second;
    }
}

int main(){
    /*입력*/
    int n; //(1 ≤ N ≤ 100,000)
    cin>>n;

    vector<pair<int,int>> time; //0<= t <=2^31-1

    int start,end;
    for(int i=0;i<n;i++){
        cin>>start>>end;
        time.push_back(make_pair(start,end));
    } 

    //time 출력
    // for(int i=0;i<n;i++){
    //     cout<<time[i].first<<" "<<time[i].second<<endl;
    // } 

    //sorting
    sort(time.begin(),time.end(),cmp);

    //사용할 수 있는 회의의 최대 개수 계산
    start = time[0].first; // 첫번째는 무조건 선택
    end = time[0].second;
    int cnt=1;

    for(int i=1;i<n;i++){
        if(time[i].first>=end){
            start=time[i].first;
            end=time[i].second;
            cnt++;
        }
    }
    cout<<cnt<<endl;


}