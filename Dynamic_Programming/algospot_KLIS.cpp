/*
1. LIS의 길이를 구한다.
2. 최대 가지수가 long long의 범위를 넘어가더라도, 어차피 K의 값이 32비트 부호형 정수 범위 안이기 때문에, 저장하는데 문제는 없을 것이다.
3. dp[idx] == idx번째 인덱스로 시작되는 LIS 길이
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl '\n'

using namespace std;

const int SIZE = 501;
const long long Cut = 2*10e9 + 1;
int N,K;
vector<int> v;
long long dp[SIZE];

void Solve();
void Input();
long long rec(int idx);

int main(){
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int C;
	cin >> C;
	while(C--){
		Solve();
	}
	return 0;
}

void Solve(){
	Input();

	int ans = rec(-1);

	cout << ans << endl;
}

void Input(){
	v.clear();
	memset(&dp[0],-1,sizeof(dp));

	cin >> N >> K;
	v.resize(N,0);
	for(int i = 0 ; i < N ; i++){
		cin >> v[i];
	}
}

long long rec(int idx){
	long long& ret = dp[idx];

	if(ret != -1)	return ret;
	
	ret = 1;
	for(int i = idx+1 ; i < N ; i++){
		if(idx == -1 || v[i] > v[idx])	ret = max(ret,rec(i)+1);
	}

	return ret;
}