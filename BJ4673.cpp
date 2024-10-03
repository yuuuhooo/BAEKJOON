// 백준 4673번. 셀프 넘버. 실버 5. 241003 solved.
// 브루트포스 알고리즘

#include <iostream>
#include <string>
using namespace std;

int main() {

    int check[10001];
    check[0] = 0;
    string str;
    int res;

    for(int i = 1; i < 10001; i++) {
        res = i;
        str = to_string(i);
        for(int j = 0; j<str.length(); j++) {
            res += (str[j]-'0');
        }
        if(res<=10000) {
            check[res] = -1;
        }
    }

    for(int i = 1; i < 10001; i++) {
        if(check[i]==-1) {
            continue;
        }
        cout << i << endl;
    }

    return 0;
}