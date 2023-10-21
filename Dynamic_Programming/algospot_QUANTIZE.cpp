//범위 같은데서 졸려서 그런지 좀 잔실수가 많이 나왔음. 다시 읽어보면서 이런것만 좀 고치면 맞을듯
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define SIZE 100
#define INF 987654321

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

	int ans = rec(n,0);

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

int rec(int S,int index){
	int& ret = big_dp[S][index],temp;

	if(S == 1){
		int& t_min = dp[index][i];
		
		if(t_min == -1){
			for(int q = arr[index] ; q <= arr[n-1] ; q++){
				t_min = min(t_min,get_val(index,n-1,q));
			}
		}
		return ret = t_min;
	}

	if(ret != INF)	return ret;

	for(int i = index + 1 ; i < n ; i++){
		int& t_min = dp[index][i];
		
		if(t_min == -1){
			for(int q = arr[index] ; q <= arr[i] ; q++){
				t_min = min(t_min,get_val(index,i,q));
			}
		}

		ret = min(ret,rec(n-1,i+1)+t_min);
	}

	return ret;
}

int get_val(int s,int e,int q_num){
	int ret = 0,t;
	for(int i = s ; i <= e ; i++){
		t = arr[s] - q_num;
		ret += t*t;
	}

	return ret;
}