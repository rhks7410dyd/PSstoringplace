/*
디테일한 부분에서 조금 더 신경 써줘서 마무리하면 쉽게 풀듯
*/

#include <iostream>
#define endl '\n'
#define INF 987654321

using namespace std;

int n;
long long backtracking(int times,int x,int y);
int percent[4];
bool visit[40][40];

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .

    cin >> n;
    for(int i = 0 ; i < 4 ; i++){
        cin >> percent[i];
    }
    long long ret = backtracking(n,20,20);

    double ans = ret;
    for(int i = 0 ; i < n ; i++){
        ans /= 100;
    }
    return 0;
}

long long backtracking(int times,int x,int y){
    long long ret = 1;

    d
    return ret;
}