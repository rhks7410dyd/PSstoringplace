#include <iostream>
#define endl '\n'
#define INF 987654321

using namespace std;

void Solve();

int main(){
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//continue code. . .

	Solve();

	return 0;
}

void Solve(){
	int n,k;
	cin >> n >> k;

	int t=0;	
	for(int j = 0 ; j < 25 ; j++){
		if(n & (1<<j))	t++;
	}
	if(t <= k){
		cout << 0 << endl;
		return;
	}

	int ans = 0;	
	bool can_carry = false;
	for(int i = 0 ; i < 25 ; i++){
		if(n & (1<<i)){
			n += 1<<i;
			t = 0;
			for(int j = 0 ; j < 25 ; j++){
				if(n & (1<<j))	t++;
			}
			ans += 1<<i;

			if(t <= k){
				break;
			}
		}
	}

	cout << ans << endl;
}

/*
15 3
15 = 1111(2)
1 개 사면
16리터로 16 = 10000(2)라서 1개의 물통으로 가능

13 2
13 = 1101(2)

1000000 = 1111 0100 0010 0100 0000(2)
+= 2^6
1111 0100 0010 1000 0000(2)
+= 2^7
1111 0100 0011 0000 0000(2)
+= 2^8
1111 0100 0100 0000 0000(2)
+= 2^10 +2^11 +2^12 +2^13
->
2^6 * (1+2+..+2^7) - 2^9
64*255 - 512

*/