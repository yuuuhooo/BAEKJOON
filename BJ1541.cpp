// 백준 1541번. 잃어버린 괄호. 실버 2. 241001 solved.
// 한번에 맞추긴 했는데 뭔가 너무 돌아간 느낌이 들기도 한다... 비효율적인 코드 같음.

#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

// 숫자인지 연산자인지 체크하는 함수 필요.
// 숫자면 카운트 늘려가면서 substr 함수 두 번째 인자 값 키워가기.

bool check(char c) {
    if('0'<=c&&c<='9') {
        return true;
    } else {
        return false;
    }
}

int oper_order(char c) {
    if(c=='+') {
        return 2;
    } else {
        return 1;
    }
}

int main() {
    string main;
    cin >> main;
    int len = main.length();

    int num_len = 0;
    int start_point;

    vector<pair<char, int>> oper_v;
    vector<int> num_v;

    for(int i = 0; i<len; i++) {
        start_point = i;
        while(check(main[i])) { // 숫자면 쭉 감
            num_len++;
            i++;
        }
        num_v.push_back(stoi(main.substr(start_point, num_len))); // 숫자 부분 숫자로 변환해서 push
        oper_v.push_back(make_pair(main[i], oper_order(main[i]))); // 연산자 + 라면 우선순위 2, - 라면 우선순위 1
    }

    // for(int j = 0; j<num_v.size(); j++) {
    //     cout << num_v[j] << " ";
    // }
    // cout << endl;

    int state = 1;
    long long result = num_v[0];

    for(int k=0; k<oper_v.size()-1; k++) {
        if(state == 1) {
            if(oper_v[k].second==2) { // 더하기 등장
                state = 1;
                // cout << result << " " << oper_v[k].first << " " << num_v[k+1];
                result += num_v[k+1];
                // cout << " = " << result << endl;
            } else {
                state = 2;
                // cout << result << " " << oper_v[k].first << " " << num_v[k+1];
                result -= num_v[k+1];
                // cout << " = " << result << endl;
            }
        } else { // 앞에 거가 빼기였을 때
            if(oper_v[k].second==2) { // 더하기 등장
                // state = 1;
                // cout << result << " " << oper_v[k].first << " " << num_v[k+1];
                result -= num_v[k+1];
                // cout << " = " << result << endl;
            } else {
                state = 2;
                // cout << result << " " << oper_v[k].first << " " << num_v[k+1];
                result -= num_v[k+1];
                // cout << " = " << result << endl;
            }
        }
    }

    cout << result;

    return 0;
}