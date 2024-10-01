// 백준 30802번. 웰컴 키트. 브론즈 3. 240930 Solved.
// 넘 피곤해쏘요...

#include <iostream>
using namespace std;

int main() {
    long long N, S, M, L, XL, XXL, XXXL, T, P;
    cin >> N;
    cin >> S >> M >> L >> XL >> XXL >> XXXL;
    cin >> T >> P;


    long long count = 0;
    if(S%T==0) {
        count += S/T;
    } else {
        count +=  S/T + 1;
    }
    if(M%T==0) {
        count += M/T;
    } else {
        count += M/T + 1;
    }
    if(L%T==0) {
        count += L/T;
    } else {
        count += L/T + 1;
    }
    if(XL%T==0) {
        count += XL/T;
    } else {
        count += XL/T + 1;
    }

    if(XXL%T==0) {
        count += XXL/T;
    } else {
        count += XXL/T + 1;
    }
    if(XXXL%T==0) {
        count += XXXL/T;
    } else {
        count += XXXL/T + 1;
    }
    cout << count << endl;
    cout << N/P << " " << N%P;

    return 0;
}