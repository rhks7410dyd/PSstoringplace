#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define endl '\n'

using namespace std;

const int SIZE = 100;

int h,w,ans = 0;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
char map[SIZE][SIZE];
bool get_key[26];
bool visit[SIZE][SIZE];
vector<pair<int,int>> block_pos;

void Solve();
void Input();
bool can_open(int y,int x);
void BFS();

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
	/*
	* = 42
	. = 42
	A = 65
	a = 97정도
	*/
	Input();

	if(h == 1 && w == 1){
		if(map[0][0] == '$')	ans = 1;
	}	
	else	BFS();

	/*
	for(int i = 0 ; i < h ; i++){
		for(int j = 0 ; j < w ; j++){
			if(visit[i][j])	cout << 1;
			else	cout << 0;
		}
		cout << endl;
	}*/

	cout << ans << endl;
}

void Input(){
	memset(&get_key[0],0,sizeof(get_key));
	memset(&visit[0][0],0,sizeof(visit));
	ans = 0;
	block_pos.clear();
	
	cin >> h >> w;

	int n = h,m = w;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> map[i][j];
		}
	}

	string key;
	cin >> key;
	if(key[0] != '0'){
		for(int i = 0 ; i < key.size() ; i++){
			get_key[key[i]-'a'] = true;
		}
	}
}

bool can_open(int y,int x){
	char Key = map[y][x] - 'A';
	return get_key[Key];
}


void BFS(){
	//최근에 푼 BFS 처럼 와일 문 마지막에 다 비어있으면 못 연 문 중에 열 수 있는 곳을 추가하는 방식으로 구현하기
	queue<pair<int,int>> q;

	//테두리 선입력 전처리
	for(int i = 0 ; i < h ; i++){
		if(map[i][0] == '.'){
			q.push({i,0});
			visit[i][0] =true;
		}
		else if(map[i][0] >= 'a'){//소문자 경우
			q.push({i,0});
			visit[i][0] =true;
			get_key[map[i][0]-'a'] = true;
		}
		else if(map[i][0] >= 'A'){//대문자의 경우
			if(!can_open(i,0)){
				block_pos.push_back({i,0});
			}
			else{
				q.push({i,0});
				visit[i][0] =true;
			}
		}
		else if(map[i][0]== '$'){
			ans++;
			visit[i][0] = true;
			q.push({i,0});
		}

		if(!visit[i][w-1]){
			if(map[i][w-1] == '.'){
				q.push({i,w-1});
				visit[i][w-1] =true;
			}
			else if(map[i][w-1] >= 'a'){//소문자 경우
				q.push({i,w-1});
				visit[i][w-1] =true;
				get_key[map[i][w-1]-'a'] = true;
			}
			else if(map[i][w-1] >= 'A'){//대문자의 경우
				if(!can_open(i,w-1)){
					block_pos.push_back({i,w-1});
				}			
				else{
					q.push({i,w-1});
					visit[i][w-1] =true;
				}
			}
			else if(map[i][w-1]== '$'){
				ans++;
				visit[i][w-1] = true;
				q.push({0,i});
			}
		}

	}

	for(int i = 1 ; i < w - 1 ; i++){
		if(!visit[0][i]){
			if(map[0][i] == '.'){
				q.push({0,i});
				visit[0][i] =true;
			}
			else if(map[0][i] >= 'a'){//소문자 경우
				q.push({0,i});
				visit[0][i] =true;
				get_key[map[0][i]-'a'] = true;
			}
			else if(map[0][i] >= 'A'){//대문자의 경우
				if(!can_open(0,i)){
					block_pos.push_back({0,i});
				}
				else{
					q.push({0,i});
					visit[0][i] =true;
				}
			}
			else if(map[0][i]== '$'){
				ans++;
				visit[0][i] = true;
				q.push({0,i});
			}
		}


		if(!visit[h-1][i]){
			if(map[h-1][i] == '.'){
				q.push({h-1,i});
				visit[h-1][i] =true;
			}
			else if(map[h-1][i] >= 'a'){//소문자 경우
				q.push({h-1,i});
				visit[h-1][i] =true;
				get_key[map[h-1][i]-'a'] = true;
			}
			else if(map[h-1][i] >= 'A'){//대문자의 경우
				if(!can_open(h-1,i)){
					block_pos.push_back({h-1,i});
				}
				else{
					q.push({h-1,i});
					visit[h-1][i] =true;
				}
			}
			else if(map[h-1][i]== '$'){
				ans++;
				visit[h-1][i] = true;
				q.push({h-1,i});
			}
		}
	}


	while(!q.empty()){
		auto Now = q.front();
		q.pop();

		for(int i = 0 ; i < 4 ; i++){
			int ny = Now.first + dy[i];
			int nx = Now.second + dx[i];

			if(ny < 0 || ny >= h || nx < 0 || nx >= w || visit[ny][nx])	continue;

			if(map[ny][nx] == '.'){
				q.push({ny,nx});
				visit[ny][nx] =true;
			}
			else if(map[ny][nx] >= 'a'){//소문자 경우
				q.push({ny,nx});
				visit[ny][nx] =true;
				get_key[map[ny][nx]-'a'] = true;
			}
			else if(map[ny][nx] >= 'A'){//대문자의 경우
				if(!can_open(ny,nx)){
					block_pos.push_back({ny,nx});
				}
				else{
					q.push({ny,nx});
					visit[ny][nx] = true;
				}
			}
			else if(map[ny][nx]== '$'){
				ans++;
				visit[ny][nx] = true;
				q.push({ny,nx});
			}
		}

		if(q.empty()){
			for(int i = 0 ; i < block_pos.size() ; i++){
				auto now = block_pos[i];
				if(get_key[map[now.first][now.second]-'A'] && !visit[now.first][now.second]){
					q.push({now.first,now.second});
					visit[now.first][now.second] = true;
				}
			}
		}
	}	
}
/*반례
2
15 15
**$*.**********
****.*******$**
****B.$****b.**
$*****c*****.**
*C$.*****fD..**
*$*xd******.**$
$.C********A.**
**h********.AA.
***************
***.i**********
***.***.K$*****
*k.$$I.$*******
******.$..j***$
*******D*******
****$**F*******
zai
15 15
**$*.**********
****.*******$**
****B.$****b.**
$*****c*****.**
*C$.*****fD..**
*$*xd******.**$
$.C********A.**
**h********.AA.
***************
***.i**********
***.***.K$*****
*k.$$I.$*******
******.$..j***$
*******D*******
****$**F*******
za
ans : 
15
12
출력 : 10
아래 두 개가 카운팅이 안됨

4
1 2
$$
asv
2 1
$
$
asdd
2 2
$.
.$
0
2 5
$.$$A$
$$$$$B
ab
*/
