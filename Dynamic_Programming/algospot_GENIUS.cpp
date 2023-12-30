#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

const int SIZE = 50;

int n,k,m;
int dp[5][SIZE];
int Like_song[10];
int song_len[SIZE];
double table[SIZE][SIZE];

void Solve();
void Input();
void print_info();
void recur(int t);

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

	//print_info();

	//
}

void Input(){
	cin >> n >> k >> m;
	for(int i = 0 ; i < n ; i++){
		cin >> song_len[i];
	}
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> table[i][j];
		}
	}

	for(int i = 0 ; i < m ; i++){
		cin >> Like_song[i];
	}
}

void print_info(){
	cout << "\n\n====================\n\n";
	cout << n << ' ' << k << ' ' << m << endl;
	for(int i = 0 ; i < n ; i++){
		cout << song_len[i] << ' ';
	}
	cout << endl;

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cout << table[i][j] << ' ';
		}
		cout << endl;
	}

	for(int i = 0 ; i < n ; i++){
		cout << Like_song[i] << ' ';
	}
	cout << endl;
}

