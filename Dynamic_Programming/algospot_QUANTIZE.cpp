//틀렸음. 사실 틀린 것도 중요하지만 코드를 확인해보니 수식을 전개해서 문제를 단순화함
//2차방정식의 최솟값을 응용해서 오차가 최소가 되게 하는 값을 계산을 통해 구할 수 있음
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define endl '\n'
#define SIZE 101
#define INF 987654321

using namespace std;

int N,S;
int dp[SIZE][SIZE];
int DP[11][SIZE];
int subsum[SIZE];
vector<int> v;

void Solve();
void Input();
int get_quant_num(int s,int e);
int rec(int s,int idx);

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
	memset(&dp[0][0],-1,sizeof(dp));
	memset(&DP[0][0],-1,sizeof(DP));

	Input();

	int ans;
	if(S >= N)	ans = 0;
	else	ans = rec(S,0);

	cout << ans << endl;
}

void Input(){
	cin >> N >> S;

	v.resize(N,0);

	for(int i = 0 ; i < N ; i++){
		cin >> v[i];
	}

	sort(v.begin(),v.begin()+N);

	subsum[0] = 0;
	for(int i = 1 ; i <= N ; i++){
		subsum[i] = subsum[i-1] + v[i-1];
	}
}

int rec(int s,int idx){
	int& ret = DP[s][idx];
	if(ret != -1)	return ret;

	if(N - idx <= s)	return ret = 0;

	if(s == 0){
		if(idx != N)	return INF;
		else	return 0;
	}

	if(idx == N){
		return 0;
	}

	ret = INF;
	for(int i = idx+1 ; i <= N ; i++){
		int q_num = get_quant_num(idx,i);
		ret = min(ret,q_num + rec(s-1,i));
	}

	return ret;
}

int get_quant_num(int s,int e){
	int& ret = dp[s][e];
	if(ret != -1)	return ret;
	if(e-s == 1)	return ret = 0;

	int best_quantize_num = round((subsum[e]-subsum[s])/(double)(e-s));

	int t;
	ret = 0;
	for(int i = s ; i < e ; i++){
		t = (double)v[i] - best_quantize_num;
		ret += t*t;
	}

	return ret;
}

