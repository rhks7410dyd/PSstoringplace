/*
갈아엎고 대각선두개에 대하여 찼는지 안찼는지로 아예 내용을바꿔서 풀어야할듯;//
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define INF -987654321

using namespace std;

int n;
int dir[4][2] = {{1,1},{1,-1},{-1,1},{-1,-1}};
int map[10][10];
int pos[10][10];

int get_ans_W(int r,int c,bool put_bishop);
int get_ans_B(int r,int c,bool put_bishop);
bool can_put_bishop(int r,int c);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> map[i][j];
		}
	}
	
	if(n == 1){
		cout << map[0][0] << '\n';
		return 0;
	}
	
	int ans_w = get_ans_W(0,0,false);
	if(map[0][0] == 1){
		pos[0][0] = 1;
		ans_w = max(ans_w,get_ans_W(0,0,true)+1);
		pos[0][0] = 0;
	}
	
	int ans_b=0;
	ans_b = get_ans_B(0,1,false);
	if(map[0][1] == 1){
		pos[0][1] = 1;
		ans_b = max(ans_b,get_ans_B(0,1,true)+1);
		pos[0][1] = 0;
	}

	cout << ans_w << ' ' << ans_b << '\n';
	
	int ans = ans_w + ans_b;
	cout << ans << '\n';
	
	return 0;
}


int get_ans_W(int r,int c,bool put_bishop){
	int ret = INF;
	bool is_possible = can_put_bishop(r,c);
	if(r == n - 1 && (c == n-1 || c == n-2)){
		if(put_bishop && !is_possible){
			return INF;
		}
		return 0;
	}
	
	if(put_bishop && !is_possible){
		return INF;
	}
	
	int nr = r, nc = c + 2;
	if(nc >= n){
		nr = r + 1;
		nc -= n;
	}
	
	if(map[nr][nc] == 1){
		pos[nr][nc] = 1;
		ret = max(ret,get_ans_W(nr,nc,true)+1);
		pos[nr][nc] = 0;
	}
	ret = max(ret,get_ans_W(nr,nc,false));
	
	return ret;
}

int get_ans_B(int r,int c,bool put_bishop){
	int ret = INF;
	bool is_possible = can_put_bishop(r,c);
	if(r == n - 1 && (c == n-1 || c == n-2)){
		if(put_bishop && !is_possible){
			return INF;
		}
		return 0;
	}
	
	if(put_bishop && !is_possible){
		return INF;
	}
	
	int nr = r, nc = c + 2;
	if(nc >= n){
		nr = r + 1;
		nc -= n;
	}
	
	if(map[nr][nc] == 1){
		pos[nr][nc] = 1;
		ret = max(ret,get_ans_B(nr,nc,true)+1);
		pos[nr][nc] = 0;
	}
	ret = max(ret,get_ans_B(nr,nc,false));
	
	return ret;
}

bool can_put_bishop(int r,int c){
	for(int d = 0 ; d < 4 ; d++){
		int nr = r + dir[d][0];
		int nc = c + dir[d][1];
		while(nr >= 0 && nr < n && nc >= 0 && nc < n){
			if(pos[nr][nc])	return false;
			nr += dir[d][0];
			nc += dir[d][1];
		}
	}
	return true;
}

/*
왜 내가 본 테케중에 10일 때인 이것만 안될까?...
10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1

ans : 18
*/