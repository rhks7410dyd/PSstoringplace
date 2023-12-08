#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

const int SIZE = 300001;

int n,s;

vector<pair<int,int>> info;
int dp[SIZE];


void Solve();
void Input();

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    Solve();

    return 0;
}

void Solve(){
    Input();
}

void Input(){
    cin >> n >> s;
    info.clear();
    int h,c;
    for(int i = 0 ; i < n ; i++){
        cin >> h >> c;
        info.push_back({h,c});
    }
    sort(info.begin(),info.end());
}

/*
문제에서 중요한 것은 얼마나 많은 그림이 세로가 s 이상이 되게 배치되는가? 즉, 완전 탐색으로 모든 경우를 찾아야한다. 그리고 휴리스틱을 사용해서 시간 절약

값들 정렬하기(높이순)


*/