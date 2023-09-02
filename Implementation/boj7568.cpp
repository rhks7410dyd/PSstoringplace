#include <iostream>
#include <vector>
#include <random>

using namespace std;

pair<int,int> info[50];
int c[50];
int N;

void Input();
void Rand_input();
void Solve();
void Rand_Solve();

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	Input();
	Solve();
	
	return 0;
}

void Input(){
	cin >> N;
	int a,b;
	for(int i = 0 ; i < N ; i++){
		cin >> a >> b;
		info[i] = {a,b};
	}
}

void Solve(){
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			if(info[i].first < info[j].first && info[i].second < info[j].second){
				c[i]++;
			}
		}
	}
	
	for(int i = 0 ; i < N ; i++){	
		cout << c[i]+1 << ' ';
	}
	cout << '\n';
}

