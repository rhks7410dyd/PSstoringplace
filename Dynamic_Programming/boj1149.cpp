#include <iostream>
#include <algorithm>
#define endl '\n'
#define INF 987654321

using namespace std;

enum RGB{
	Red,
	Green,
	Blue
};

int info[1001][3];
int DP[1001][3];

int main(){
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//continue code. . .
	int n;
	cin >> n;

	for(int i = 0 ; i < n ; i++){
		//continue code...
		cin >> info[i][Red] >> info[i][Green] >> info[i][Blue];
	}

	//첫 번째 집만 고려했을 때는 info와 값이 동일
	DP[0][Red] = info[0][Red];
	DP[0][Green] = info[0][Green];
	DP[0][Blue] = info[0][Blue];

	for(int i = 1 ; i < n ; i++){
		//continue code...
		//DP[i][Red]는 i+1번째 집의 색을 Red로 했을 때 최솟값을 의미함.
		DP[i][Red] = min(DP[i-1][Green],DP[i-1][Blue]) + info[i][Red];
		DP[i][Green] = min(DP[i-1][Red],DP[i-1][Blue]) + info[i][Green];
		DP[i][Blue] = min(DP[i-1][Green],DP[i-1][Red]) + info[i][Blue];
	}
	
	//n번째 집의 각 색에 따라 min인 최솟값을 출력
	cout << min({DP[n-1][Red],DP[n-1][Green],DP[n-1][Blue]}) << endl;
	
	return 0;
}