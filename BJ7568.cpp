// 백준 7568번. 덩치. 실버 5. 241003 solved;
// 쉬운 문제이긴 한데 문제의 기준이 상식적이진 않다 ㅋㅋ

#include <iostream>
using namespace std;

int main() {
    int N;

    cin >> N;

    int height[N];
    int weight[N];
    int res[N];
    int cnt;

    for(int i=0; i<N; i++) {
        cin >> weight[i] >> height[i];
    }

    for(int j = 0; j < N; j++){
        res[j] = 0;
        for(int l = 0; l < N; l++) {
            cnt = 0;
            if(j==l) continue;

            if(height[j]<height[l]&&weight[j]<weight[l]) {
                res[j] += 1;
            }
        }
    }

    for(int i=0; i<N; i++) {
        cout << res[i]+1 << " ";
    }
    return 0;
}
