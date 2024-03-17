#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> cntVec; //횟수, 처음 등장한 인덱스 번호, 값 
vector<int> v;
unordered_map<int, pair<int,int>> um; //값, (횟수, 처음 등장한 인덱스 번호)

bool cmp(tuple<int,int,int> a, tuple<int,int,int> b) {
    if (get<0>(a) == get<0>(b)) {
        return get<1>(a) < get<1>(b);
    }
    else return get<0>(a) > get<0>(b);
}

bool cmp2(int a, int b) {
    if (um[a].first == um[b].first) {
        return um[a].second < um[b].second;
    }
    return um[a].first > um[b].first;
}



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,c;
    cin >> n >> c;

    cntVec.resize(n + 1);

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        auto it = find(v.begin(), v.end(), num);
        if (it != v.end()) {
            cntVec[it - v.begin()] = make_tuple(get<0>(cntVec[it - v.begin()]) + 1,it-v.begin(), num);
        }
        else   cntVec[i] = make_tuple(get<0>(cntVec[i]) + 1, i, num);


        v.push_back(num);
    }

    sort(cntVec.begin(), cntVec.end(), cmp);
    
    for (int i = 0; i < n; i++) {
        if (get<0>(cntVec[i]) == 0) break;
        um[get<2>(cntVec[i])] = { get<0>(cntVec[i]),get<1>(cntVec[i])};
    }

    sort(v.begin(), v.end(), cmp2);
    
    for (auto i : v) {
        cout << i << " ";
    }
   
    
   
    return 0;
}

