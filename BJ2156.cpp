//백준 2156번. 포도주 시식. 실버 1. 240926 solved.
//2579번과 상당히 유사하다...

#include <iostream>
#include <vector>
using namespace std;

int comp(int n1, int n2) {
	if (n1 > n2) {
		return n1;
	}
	else {
		return n2;
	}
}

int comp3(int n1, int n2, int n3) {
    if(n1>=n2 && n1>=n3) {
        return n1;
    } else if(n2>=n1&&n2>=n3) {
        return n2;
    } else {
        return n3;
    }
}

int maxarr[10001] = { 0 };
int pn[10001] = { 0 };

void user_scan(int N) { // 입력 받는 부분
	pn[0] = 0;

	for (int i = 1; i < N + 1; i++) {
		cin >> pn[i];
	}
}

void wine(int *pn, int num) { // 최댓값 배열 만드는 부분
	maxarr[1] = pn[1];
	maxarr[2] = pn[1] + pn[2];
	maxarr[3] = comp3(pn[1] + pn[2], pn[2] + pn[3], pn[1] + pn[3]);

	for (int i = 4; i < num + 1; i++) {
		maxarr[i] = comp3(maxarr[i - 2] + pn[i], maxarr[i - 3] + pn[i - 1] + pn[i], maxarr[i-1]);
	}

	cout << maxarr[num];
}

int main() {
	int N;
	cin >> N;
	
	user_scan(N);
	wine(pn, N);

	return 0;
}