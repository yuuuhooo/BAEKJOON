// 백준 14730번. 謎紛芥索紀 (Small). 실버 5. 240925 solved.

#include <iostream>
using namespace std;

int main() {
    int n;
    double coef[101] = {0};
    cin >> n;
    int tmp1, tmp2;
    int C = 0;

    for(int i=0; i<n; i++) {
        cin >> tmp1 >> tmp2;
        coef[i]= tmp1*tmp2;
    }

    long long sum = 0;
    for(int i=0; i<n; i++) {
        sum += coef[i];
    }

    cout << sum;
    
    return 0;
}