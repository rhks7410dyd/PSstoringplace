#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF 987654321
#define MOD 1000000007

using namespace std;

int n;
vector<int> v;

long long DP[300000];
long long rec(long long val,int times);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .

    cin >> n;

    int t;
    for(int i = 0 ; i < n ; i++){
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(),v.end());

    long long ans = 0;

    //여기 좀만 더 생각해보기
    for(int i = 0 ; i < n ; i++){
        rec(0,i);
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(v[i] == v[j])    continue;

            ans += (DP[j-i] * (v[j] - v[i])) % MOD;
            ans %= MOD;
        }
    }

    return 0;
}

/*
모든 조합을 고려해야한느 문제 같지만, 그것이 아니라 조합 + 분할 정복을 이용한 거듭제곱 문제임
동적 프로그래밍으로 시간을 올려할 것 같음
*/