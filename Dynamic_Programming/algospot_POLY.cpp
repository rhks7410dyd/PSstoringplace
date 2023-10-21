//메모해서 정리해보기
#include <iostream>
#include <cstring>
#include <cstdlib>
#define ll long long
#define endl '\n'
#define mod 10000000
#define SIZE 100 + 1

using namespace std;

ll dp[SIZE][SIZE];

void Solve();
ll poly(int num,int b_b);

int main(){
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int c;
	cin >> c;
	for(int i = 0 ; i < c ; i++){
		Solve();
	}

	return 0;
}

void Solve(){
	int n;
	cin >> n;
	
	memset(dp,-1,sizeof(dp));

	ll ans = poly(n,0);

	cout << ans << endl;

	return ;
}

ll poly(int num,int b_b){
	ll& ret = dp[num][b_b];

	if(ret != -1)	return ret;

	if(num == 0)	return ret = 1;
	
	if(num == 1)	return ret = b_b;

	ret = 0;
	for(int i = 1 ; i <= num ; i++){
		int time_num = b_b + i - 1;
		if(b_b == 0)	time_num = 1;
		ret += time_num * poly(num-i,i);
		ret %= mod;
	}


	return ret;
}