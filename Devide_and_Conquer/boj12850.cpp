#include <iostream>
#define mod 1000000007LL

using namespace std;

/*
0 : 정보과학관		1,2
1 : 전산관			0,2,3
2 : 미래관			0,1,3,4
3 : 신양관			1,2,4,5
4 : 한경직기념관	2,3,5,7
5 : 진리관			3,4,6
6 : 학생회관	 	5,7
7 : 형남공학관	 	4,6
*/

long long map[8][8] = {
	{0,1,1,0,0,0,0,0},
	{1,0,1,1,0,0,0,0},
	{1,1,0,1,1,0,0,0},
	{0,1,1,0,1,1,0,0},
	{0,0,1,1,0,1,0,1},
	{0,0,0,1,1,0,1,0},
	{0,0,0,0,0,1,0,1},
	{0,0,0,0,1,0,1,0}
};

long long ans[8][8];

void multiple_ans();
void multiple_map();

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int D;
	cin >> D;

	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			if(i == j) ans[i][j] = 1;
			else ans[i][j] = 0;
		}
	}

	for(int i = 0 ; i < 32 ; i++){
		if((1 << i) & D){
			multiple_ans();
		}
		multiple_map();
	}

	cout << ans[0][0] << endl;
}

void multiple_map(){
	long long temp[8][8];
	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			temp[i][j] = 0;
			for(int k = 0 ; k < 8 ; k++){
				temp[i][j] += map[i][k]*map[k][j]%mod;
				temp[i][j] %= mod;
			}
		}
	}

	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			map[i][j] = temp[i][j];
		}
	}
}

void multiple_ans(){
	long long temp[8][8];
	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			temp[i][j] = 0;
			for(int k = 0 ; k < 8 ; k++){
				temp[i][j] += ans[i][k]*map[k][j];
				temp[i][j] %= mod;
			}
		}
	}

	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			ans[i][j] = temp[i][j];
		}
	}
}