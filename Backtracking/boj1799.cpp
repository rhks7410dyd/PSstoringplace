/*
아이디어 자체는 좋으나, 검,흰칸을 나눠서 생각하는 것이 핵심
*/
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#define endl '\n'
#define INF 987654321
#define SIZE 10

using namespace std;

bool map[SIZE][SIZE];
int n;
int ans;
vector<pair<int,int>> v;

int first_recursive(int y,int x);
int second_recursive(int y,int x);
bool can_put_bishop(int y,int x);
void Solve();
void Input();

int main(){
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//continue code. . .
	Solve();

	return 0;
}

void Solve(){
	Input();

	ans = first_recursive(0,0);
	if(n != 1)	ans += second_recursive(0,1);

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

int first_recursive(int y,int x){
	if(y == n-1 && (x==n-1 || x==n-2)){
		if(map[y][x] && can_put_bishop(y,x))	return 1;
		else	return 0;
	}

	int ny,nx;
	if(x == n-1 || x == n-2){
		ny = y+1;
		if(ny%2){
			nx = 1;
		}
		else	nx = 0;
	}
	else{
		ny = y;	nx = x+2;
	}

	int ret = -INF;

	if(map[y][x] && can_put_bishop(y,x)){
		v.push_back({y,x});
		int pos = v.size()-1;
		ret = max(ret,first_recursive(ny,nx)+1);
		v.erase(v.begin() + pos);
	}

	ret = max(ret,first_recursive(ny,nx));

	return ret;
}

int second_recursive(int y,int x){
	if(y == n-1 && (x==n-1 || x==n-2)){
		if(map[y][x] && can_put_bishop(y,x))	return 1;
		else	return 0;
	}

	int ny,nx;
	if(x == n-1 || x == n-2){
		ny = y+1;
		if(ny%2){
			nx = 0;
		}
		else	nx = 1;
	}
	else{
		ny = y;	nx = x+2;
	}


	int ret = -INF;

	if(map[y][x] && can_put_bishop(y,x)){
		v.push_back({y,x});
		int pos = v.size()-1;
		ret = max(ret,second_recursive(ny,nx)+1);
		v.erase(v.begin() + pos);
	}

	ret = max(ret,second_recursive(ny,nx));

	return ret;
}

bool can_put_bishop(int y,int x){
	for(int i = 0 ; i < v.size() ; i++){
		if(abs(v[i].first-y) == abs(v[i].second - x))	return false;
	}
	return true;
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