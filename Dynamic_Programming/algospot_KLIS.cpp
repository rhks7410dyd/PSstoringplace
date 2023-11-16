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
const long long Cut = 3*10e9;
int N,K;
vector<int> v;
vector<int> ans_list;
long long dp[SIZE];
long long countdp[SIZE];

void Solve();
void Input();
long long rec(int idx);
void reconstruct(int now,int skip,vector<int>& list);
long long count(int start);

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

	cout << ans-1 << endl;

	reconstruct(-1,K,ans_list);

	for (int i=0; i< ans_list.size(); i++)
	{
	  cout << v[ans_list[i]] << ' ';
	}
	cout << endl;
}

void Input(){
	v.clear();
	ans_list.clear();
	memset(&dp[0],-1,sizeof(dp));
	memset(&countdp[0],-1,sizeof(countdp));

	cin >> N >> K;
	v.resize(N,0);
	for(int i = 0 ; i < N ; i++){
		cin >> v[i];
	}
}

long long rec(int idx){
	long long& ret = dp[idx+1];

	if(ret != -1)	return ret;
	 
	ret = 1;
	for(int i = idx+1 ; i < N ; i++){
		if(idx == -1 || v[i] > v[idx])	ret = max(ret,rec(i)+1);
	}

	return ret;
}

void reconstruct(int now,int skip,vector<int>& list){
	if(now != -1)	list.push_back(now);
	
	vector<pair<int,int>> next_list;
	for(int i = now + 1 ; i < N ; i++){
		if((now == -1 || v[i] > v[now]) && rec(i) + 1 == rec(now))	next_list.push_back(make_pair(v[i],i));
	}

	sort(next_list.begin(),next_list.end());

	for(int i=0; i< next_list.size(); i++){
		auto& now = next_list[i];
		long long c = count(now.second);
		if(c < skip){
			skip -= c;
		}
		else{
			reconstruct(now.second,skip,list);
			break;
		}
	}
}

long long count(int start){
	if(rec(start) == 1)	return 1;

	long long& ret = countdp[start+1];
	if(ret!= -1)	return ret;
	ret = 0;
	for(int i = start + 1 ; i < N ; i++){
		if((start == -1 || v[i] > v[start]) && rec(i) + 1 == rec(start))	ret = min<long long>(Cut,ret + count(i)); 
	}

	return ret;
}