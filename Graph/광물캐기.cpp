#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> pick_v;
vector<string> minerals_v;
int stress = 999999;

int picks_Arr[15];
int total = 0;

int Stress(int p, int m){ //곡괭이와 광석에 따라 피로도 수치 계산 
    int s = 0;
    switch(p){
        case 0:
            s+=1;
            break;
        case 1:
            if(minerals_v[m] == "diamond") s+=5;
            else s+=1;
            break;
        case 2:
            if(minerals_v[m] == "diamond") s+=25;
            else if(minerals_v[m] == "iron") s+=5;
            else s += 1;
            break;
    }
    
    return s;
}

void Break(){
    int index = 0;
    int s = 0;
    for(int i=0; i<minerals_v.size(); i++){
        if(index == total) break;
        s += Stress(picks_Arr[index],i);
        if(i%5 == 4) index++;
    }
    
    stress = min(s,stress);
}

void Pick(int cnt){ //곡괭이 선택 
    if(cnt == total){
        Break();
        return;
    }
    
    
    for(int i=0; i<3; i++){
        if(pick_v[i] <= 0) continue;
        
        pick_v[i] -= 1;
        picks_Arr[cnt] = i;
        Pick(cnt+1);
        pick_v[i] += 1;
    }
    
}


int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    total = minerals.size() / 5;
    if(minerals.size() % 5  != 0) total += 1;
    
    int cnt = 0;
    for(int i=0; i<picks.size(); i++) cnt += picks[i];
    
    if(total > cnt) total = cnt;
    
    pick_v = picks;
    minerals_v = minerals;
    Pick(0);
    
    answer = stress;
    
    return answer;
}
