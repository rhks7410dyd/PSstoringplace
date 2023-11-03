/*
1. LIS의 길이를 구한다.
2. 최대 가지수가 long long의 범위를 넘어가더라도, 어차피 K의 값이 32비트 부호형 정수 범위 안이기 때문에, 저장하는데 문제는 없을 것이다.
3. dp[idx][l] == idx번째 인덱스부터 l의 길이를 갖는 부분증가수열의 갯수
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

const int SIZE = 501;
const long long Cut = 2*10e9;
int N,K;
vector<int> v;
long long dp[SIZE][SIZE];

void Solve();
void Input();

int main(){
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int C;
	cin >> C;
	while(C--){
		//continue code. . .
	}
	return 0;
}

void Solve(){
	Input();
}

void Input(){
	v.clear();
	memset(&dp[0][0],-1,sizeof(dp));

	cin >> N >> K;
	v.resize(N,0);
	for(int i = 0 ; i < N ; i++){
		cin >> v[i];
	}
}

