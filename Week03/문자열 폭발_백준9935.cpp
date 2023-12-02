#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string x, bomb;
    cin >> x >> bomb;

    vector<char> answer;
    int bombLength = bomb.length();

    for (char c : x) {
        answer.push_back(c);

        //answer의 길이가 bomb 단어 길이 이상 && answer의 뒷글자가 bomb의 뒷글자와 동일한 경우 
        if (answer.size() >= bombLength && answer.back() == bomb.back()) {
            bool isBomb = true;
            //answer와 bomb이 다른 경우 
            //answer의 끝에서부터 bomb이랑 다른지 확인 
            for (int i = 1; i < bombLength; ++i) {
                if (answer[answer.size() - 1 - i] != bomb[bombLength - 1 - i]) {
                    isBomb = false;
                    break;
                }
            }
            //bomb이 있는 경우 
            if (isBomb) {
                answer.resize(answer.size() - bombLength);
            }
        }
    }

    if (answer.empty()) cout << "FRULA" << "\n";
    else cout << string(answer.begin(), answer.end()) << "\n";

    return 0;
}
