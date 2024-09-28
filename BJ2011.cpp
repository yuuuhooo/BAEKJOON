//백준 2011번. 암호코드. 골드5. unsolved.

#include <iostream>
#include <string>
using namespace std;

int ok(string str) {
    if(stoi(str)<27) {
        return 1;
    } else {
        return 0;
    }
}

int zero_end(string str) {
    switch(stoi(str)) {
        case 10:
            return 1;
            break;
        case 20:
            return 1;
            break;
        case 30:
            return 0;
            break;
        case 40:
            return 0;
            break;
        case 50:
            return 0;
            break;
        case 60:
            return 0;
            break;
        case 70:
            return 0;
            break;
        case 80:
            return 0;
            break;
        case 90:
            return 0;
            break;
        default:
            return 2; // 0으로 끝나지 않는 수
            break;

    }
}

int main() {
    int n; 
    string str;
    cin >> str;
    n = str.length();



    if(stoi(str.substr(0,1))==0) {
        cout << 0;
        return 0;
    }

    long long dp[n+1];
    dp[0] = 1;
    dp[1] = 1; // 글자 한 개 있을 때

    int check[n+1]; //두 자리 수 가능한 개수
    check[0] = 0;
    check[1] = 0;


    if(n==1) {
        cout << 1;
        return 0;
    }

    if(n>=2) {
        if(zero_end(str.substr(0,2))==1) { // 맨 앞 두 자리가 10이나 20이라면
            dp[2] = 1;
            check[2] = 0;
        } else if(ok(str.substr(0,2))) { // 두 자리 수가 된다면
            dp[2] = 2;
            check[2] = 1;
        } else { // 두 자리 수가 안 된다면
            dp[2] = 1;
            check[2] = 0;
        }
    }

    if(stoi(str.substr(0,1))==0) { // 0이 입력으로 들어올 때
        cout << 0;
        return 0;
    }

    if(zero_end(str.substr(0,2))==0) { // 30, 40, ... , 90 이 들어온다면 0 출력 하고 프로그램 종료.
        cout << 0;
        return 0;
    }
    

    for(int i=3; i<=n; i++) { // 글자 3개 있을 때부터 반복문 돌리기.
        if(zero_end(str.substr(i-2,2))==0) { // 30~90 그 숫자가 등장한다면 프로그램 종료
            cout << 0;
            return 0;
        }

        if(ok(str.substr(i-2,2))) { // 27 이내의 숫자
            if(stoi(str.substr(i-2,2))<10) {
                check[i] = 0;
            } else {
                check[i] = check[i-1] + 1;
            }

            if(zero_end(str.substr(i-2,2))==1){ // 10이나 20일 때
                // if(check[i-1] - check[i-2] == 1){
                //  check[i] = -1;
                // } else { 
                //     check[i] = check[i-1];
                // }
                //cout << "큰일남 20 or 10 등장함!!" << endl;
                dp[i] = dp[i-2];
                check[i] = 0;
                //cout << "10 or 20 등장함..." << "\t";
                //cout << "dp[" << i << "] = " << dp[i] << endl;
                continue;
            }

            if(check[i]-check[i-2]==2) {
                dp[i] = (dp[i-2]+dp[i-1])%1000000;
                //cout << "2연속 두자리수 만들기 가능함!" << "\t";
                //cout << "dp[" << i << "] = " << dp[i] << endl;
            } else if(check[i]-check[i-2]==1) {
                dp[i] = (dp[i-2]*2)%1000000;
                //cout << "직전엔 안 됐지만 이번엔 두자리수 만들기 가능함!" << "\t";
                //cout << "dp[" << i << "] = " << dp[i] << endl;
            } else {
                check[i] = check[i-1];
                dp[i] = (dp[i-1])%1000000;
                //cout << "두자리수 만들기가 계속 안 되네요..." << "\t";
                //cout << "dp[" << i << "] = " << dp[i] << endl;
        }

        } else { // 27 이상의 숫자일 때
            check[i] = check[i-1];
            dp[i] = (dp[i-1])%1000000;
            //cout << "dp[" << i << "] = " << dp[i] << endl;
        }

        // if(check[i] == -1){
        //     dp[i] = dp[i-2];
        //     check[i] = 0;
        //     cout << "10 or 20 등장함..." << "\t";
        //     cout << "dp[" << i << "] = " << dp[i] << endl;
        // }
    }

    cout << dp[n];

    return 0;
}

