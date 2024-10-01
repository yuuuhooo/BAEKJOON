// 백준 5430번. AC. 골드 5. 241001 solved.
// split 같은 거 쓰면 벡터 만드는 부분 쉽게 됐을 텐데...

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int state = 0; // 0은 원래 상태, 1은 뒤집어진 상태

bool check(char c) {
    if('0'<=c&&c<='9') {
        return true;
    } else {
        return false;
    }
}

void make_v(int n, string str) {
    int start_point = 0;
    int num_len = 0;
    state = 0; // 여기가 핵심이었음. 새로운 벡터를 만들면 상태도 리셋해줬어야 했는데 이걸 안 해줌...

    for(int i=1; i<str.length(); i++) {
        if(str[i]==']'){
            return;
        }
        start_point = i;
        num_len = 1;
        i++;

        while(check(str[i])) { // 숫자면 쭉 감
            // cout << str[i] << " ";
            num_len++;
            i++;
        }
        // cout << stoi(str.substr(start_point, num_len)) << " 추가" << endl;
        v.push_back(stoi(str.substr(start_point, num_len)));
        
    }
    return;
}

void oper(string func) { // R이 들어왔다고 절대로 진짜 뒤집으면 안 됨. 시간복잡도 초과됨.
    int n = func.length();
    for(int i=0; i<n; i++) {
        if(func[i]=='R') {
            if(state == 0) {
                state = 1;
            } else if (state == 1) {
                state = 0;
            }
            // reverse(v.begin(), v.end());
        } else if (func[i]=='D') {
            if(v.empty()) {
                cout << "error" << endl;
                return;
            } else {
                if(state == 1) {
                    v.pop_back();
                } else if(state == 0) {
                    v.erase(v.begin());
                }
                
            }
        }
    }

    if(state==0) {
        if(v.size()==0) {
            cout << "[]" << endl;
            return;
        }
        cout << "[" << v[0];
        for(int j = 1; j<v.size(); j++) {
            cout << "," << v[j];
        }
        cout << "]" << endl;
    } else {
        if(v.size()==0) {
            cout << "[]" << endl;
            return;
        }

        cout << "[" << v.back();
        for(int j = v.size()-2; j>=0; j--) {
            cout << "," << v[j];
        }
        cout << "]" << endl;
    }
    return ;
}


void go(string func, int count, string arrstr) {
    make_v(count, arrstr);
    oper(func);
    v.clear();
    return ;
}

int main() {
    int T;
    string p;
    int n;
    string arr;

    cin >> T;

    for(int i=0; i<T; i++) {
        cin >> p;
        cin >> n;
        cin >> arr;
        go(p, n, arr);
    }


    // int n;
    // string arr;
    // cin >> n;
    // cin >> arr;

    // make_v(n, arr);

    return 0;
}