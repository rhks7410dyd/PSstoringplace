#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> v;
vector<pair<int,int>> dp;
int N;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	scanf("%d",&N);
	
	int start,end;
	if(N == 1){
		scanf("%d %d",&start,&end);
		printf("%d",(end-start+1));
		return 0;
	}
	
	for(int i = 0 ; i < N ; i++){
		scanf("%d %d",&start,&end);
		v.push_back({start,end});
	}
	
	dp.push_back({end,(end-start+1)});
	for(int i = 1 ; i < N ; i++){
		auto now = v[i];
		if()
	}
	
	return 0;
}