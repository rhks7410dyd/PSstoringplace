//문제에서 두번째 상황까지 끝나고 값을 원하는건지 어떤건지 모르겠음
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct fireball{
	int r,c,m,d,s;
	fireball(int R,int C,int M,int D,int S) : r(R),c(C),m(M),d(D),s(S) {};
	fireball(){
		r = 0;
		c = 0;
		m = 0;
		d = 0;
		s = 0;
	};
};

int dir[8][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
int temp[51][51][4];
int N,M,K;
queue<fireball> q;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M >> K;
	
	int r,c,m,d,s,even;
	for(int i = 0 ; i < M ; i++){
		cin >> r >> c >> m >> d >> s;
		q.push({r,c,m,d,s});
	}
	// K-1 번만 하는게 나을듯
	K--;
	while(K--){
		int qsize = q.size();
		
		memset(temp,0,sizeof(temp));
		
		for(int i = 0 ; i < qsize ; i++){
			auto now = q.front();
			q.pop();
			int next_r,next_c;
			//음수와 0 은 N을 더해줘야 되고 양수는 그대로 쓰면 됨
			next_r = (now.r + now.s*dir[now.d][0])%N;
			next_c = (now.c + now.s*dir[now.d][1])%N;
			if(next_r <= 0){
				next_r += N;
			}
			if(next_c <= 0){
				next_c += N;
			}
			
			temp[next_r][next_c][0] += now.m;
			temp[next_r][next_c][1] += now.s;
			temp[next_r][next_c][3] ++;
			
			if(temp[next_r][next_c][2] == -1)	continue;
			
			if(temp[next_r][next_c][2] == 0){
				temp[next_r][next_c][2] = now.d%2;
			}
			else if(now.d == 1){
				if(temp[next_r][next_c][2] == 2){
					temp[next_r][next_c][2] = -1;
				}
			}
			else{
				if(temp[next_r][next_c][2] == 1){
					temp[next_r][next_c][2] = -1;
				}
			}
		}
		
		for(int next_r = 1 ; next_r <= N ; next_r++){
			for(int next_c = 1 ; next_c <= N ; next_c++){
				if(!temp[next_r][next_c][3])	continue;
				
				temp[next_r][next_c][0] /= 5;
				temp[next_r][next_c][1] /= temp[next_r][next_c][3];
				
				if(temp[next_r][next_c][0]){
					if(temp[next_r][next_c][2] == -1){
						//1,3,5,7
						for(int k = 0 ; k < 4 ; k++){
							q.push({next_r,next_c,temp[next_r][next_c][0],2*k+1,temp[next_r][next_c][1]});
						}
					}
					else{
						//0,2,4,6
						for(int k = 0 ; k < 4 ; k++){
							q.push({next_r,next_c,temp[next_r][next_c][0],2*k,temp[next_r][next_c][1]});
						}
					}
				}
			}
		}
	}
	
	int ans = 0;
	for(int i = 0 ;  i < q.size() ; i++){
		ans += q.front().m;
	}
	
	cout << ans << '\n';
	
	return 0;
}

/*
4 2 2
1 1 5 2 2
1 4 7 1 6

8


7 5 3
1 3 5 2 4
2 3 5 2 6
5 2 9 1 7
6 2 1 3 5
4 4 2 4 2

9
*/