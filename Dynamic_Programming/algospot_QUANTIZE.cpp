//범위 같은데서 졸려서 그런지 좀 잔실수가 많이 나왔음. 다시 읽어보면서 이런것만 좀 고치면 맞을듯
//틀렸음. 사실 틀린 것도 중요하지만 코드를 확인해보니 수식을 전개해서 문제를 단순화함
//2차방정식의 최솟값을 응용해서 오차가 최소가 되게 하는 값을 계산을 통해 구할 수 있음
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define SIZE 100 + 1
#define INF 1000001000

using namespace std;

int n,s;
int dp[SIZE][SIZE];
int big_dp[10][SIZE];
vector<int> arr;

void Solve();
void Input();
int rec(int S,int index);	//bqn == before quntsize number
int get_val(int s,int e,int q_num);

int main(){
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int C;
	cin >> C;
	for(int i = 0 ; i < C ; i++){
		Solve();
	}

	return 0;
}

void Solve(){
	arr.clear(); 
	fill(&dp[0][0],&dp[SIZE-1][SIZE],INF);
	fill(&big_dp[0][0],&big_dp[9][SIZE],INF);
	
	Input();

	sort(arr.begin(),arr.end());

	int ans;
	if(s >= n) ans = 0;
	else	ans = rec(s,0);

	cout << ans << endl;

}

void Input(){
	cin >> n >> s;
	
	int t;
	for(int i = 0 ; i < n ; i++){
		cin >> t;
		arr.push_back(t);
	}
}

int rec(int S,int index){//남은 양자수 S개,index부터
	int& ret = big_dp[S][index];

	if(index == n)	return 0;
	if(ret != INF)	return ret;

	if(S == 1){
		int& t_min = dp[index][n];//[index,n)
		
		if(t_min == INF){
			for(int q = arr[index] ; q <= arr[n-1] ; q++){
				t_min = min(t_min,get_val(index,n,q));
			}
		}
		return ret = t_min;
	}

	for(int i = index + 1 ; i <= n ; i++){
		int& t_min = dp[index][i];
		
		if(t_min == INF){
			for(int q = arr[index] ; q <= arr[i-1] ; q++){
				t_min = min(t_min,get_val(index,i,q));
			}
		}

		ret = min(ret,rec(S-1,i)+t_min);
	}

	return ret;
}

int get_val(int s,int e,int q_num){
	int ret = 0,t;
	for(int i = s ; i < e ; i++){
		t = arr[i] - q_num;
		ret += t*t;
	}

	return ret;
}

