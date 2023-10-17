/*
아이디어 자체는 좋으나, 검,흰칸을 나눠서 생각하는 것이 핵심
*/
#include <iostream>
#include <algorithm>
#define endl '\n'
#define INF 987654321
#define SIZE 10

using namespace std;

int d[4][2] = {{1,1},{1,-1},{-1,1},{-1,-1}};
int map[SIZE][SIZE];
int n;
int ans;

int recursive(int y,int x,int c);
int huristic(int y,int x);
void Solve();
void Input();
void put_bishop(int y,int x,int put_or_pick);

int main(){
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//continue code. . .
	Solve();

	return 0;
}

void Solve(){
	Input();

	huristic(0,0);
	recursive(0,0,0);

	cout << ans << endl;
	return;
}

void Input(){
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> map[i][j];
		}
	}
}

int recursive(int y,int x,int c){
	int ret = -INF,nx,ny;
	if(y == n)	return 0;

	//여기서 다 ny,nx를 같은 색 칸으로만 되게 하면 문제를 풀기 쉬워?짐
	//남은 1인 칸 갯수 + 현재까지 비숍 갯수 <= 현재의 최댓값
	int one_c = 0;
	for(int i = y*n + x ; i < n*n ; i++){
		if(map[i/n][i%n] == 1)	one_c++;
	}
	if(one_c + c <= ans)	return -INF;

	if(x == n-1){
		nx = 0;	ny = y+1;
	}
	else{
		nx = x + 1; ny = y;
	}

	if(map[y][x] == 1){
		map[y][x] = 0;
		put_bishop(y,x,-1);
		ret = max(ret,recursive(ny,nx,c+1)+1);
		map[y][x] = 1;
		put_bishop(y,x,1);
	}

	ret = max(ret,recursive(ny,nx,c));

	ans = max(ans,ret);

	return ret;
}

void put_bishop(int y,int x,int put_or_pick){
	for(int i = 0 ; i < 4 ; i++){
		int ny = y + d[i][0],nx = x + d[i][1];

		while(ny >= 0 && ny < n && nx >= 0 && nx < n){
			map[ny][nx] += put_or_pick;
			ny += d[i][0];
			nx += d[i][1];
		}
	}
}

int huristic(int y,int x){
	int ret = -INF,nx,ny;
	if(y == n)	return 0;

	if(x == n-1){
		nx = 0;	ny = y+1;
	}
	else{
		nx = x + 1; ny = y;
	}

	if(map[y][x] == 1){
		map[y][x] = 0;
		put_bishop(y,x,-1);
		ret = max(ret,huristic(ny,nx)+1);
		map[y][x] = 1;
		put_bishop(y,x,1);
	}
	else	ret = max(ret,huristic(ny,nx));

	ans = max(ans,ret);	

	return ret;
}

/*
갈아엎고 대각선두개에 대하여 찼는지 안찼는지로 아예 내용을바꿔서 풀어야할듯;//

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

ret : 18
*/