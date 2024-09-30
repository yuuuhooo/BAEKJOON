// 백준 1931번. 회의실 배정. 실버 1. 240930 solved.

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool compare2(pair<double, double>& a, pair<double, double>& b) { // 이 정렬 파트가 중요한 문제
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int N;
    cin >> N;
    vector <pair<double, double>> v;

    double tmp1, tmp2;

    for(int i=0; i<N; i++) {
        cin >> tmp1 >> tmp2;
        v.push_back(make_pair(tmp1, tmp2));
    }

    sort(v.begin(), v.end(), compare2);

    double cnt = 0;
    double time = v[0].second;
    cnt++;

    for(int k=1; k<N; k++) {
        if(time<=v[k].first) {
            time = v[k].second;
            cnt++;
            //cout << "[" << v[k].first << ", " << v[k].second << "]" << endl;
        }
    }
    cout << cnt;

    return 0;
}