// 백준 14912번. 숫자 빈도수. 실버 5. 241004 solved.
// 매우 이-지 하네요

#include <iostream>
using namespace std;

int d_res[10];

void check(int n) {
    int tmp;
    if(n==0) {
        return;
    }
    tmp = n%10;
    d_res[tmp] += 1;
    check(n/10);
}

int main() {
    int n, d;
    cin >> n >> d;

    for(int i = 0; i <10; i++) {
        d_res[i] = 0;
    }

    for(int j=1; j<n+1; j++) {
        check(j);
    }

    cout << d_res[d];

    return 0;
}