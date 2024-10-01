// 백준 11047번. 동전 0. 실버 4. 241001 solved.
// 매우 쉬운 그리디 알고리즘 문제

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> coin;
    int tmp1;
    for(int i=0; i<N; i++) {
        cin >> tmp1;
        coin.push_back(tmp1);
    }

    long long count = 0;

    for(int j=N-1; j>=0; j--) {
        //cout << "현재 잔액" << K << "원" << endl;
        //cout << coin[j] << " 동전 " << K/coin[j] << "개 사용 후 잔액 ";
        count += K/coin[j];
        K -= K/coin[j]*coin[j];
        //cout << K << "원" << endl;
        if(K==0) {
            break;
        }
    }
    
    cout << count;

    return 0;
}