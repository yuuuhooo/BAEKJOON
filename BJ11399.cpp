// 백준 11399번. ATM. 실버 4. 241005 solved.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, tmp;
    vector<int> v;

    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());


    int res = 0;

    for(int j=0; j<N; j++) {
        res += v[j] * (N - j);
    }

    cout << res;

    return 0;
}