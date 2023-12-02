#include <iostream>
#define MAX 1000000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	bool dp[MAX+1];
	for(int i = 2 ; i*i <= MAX ; i++){
		if(dp[i])	continue;
		for(int j = i*i ; j <= MAX ; j+=i){
			dp[j]=true;
		}
	}

	int n,a;
	bool ch;
	while(true){
		cin >> n;
		if(!n)	break;
		a=2;
		ch=false;
		while(a<=n/2){
			if(!dp[a] && !dp[n-a]){
				ch=true;
				break;
			}
			a++;
		}
		if(ch){
			cout << n << " = " << a << " + " << n-a << '\n';
		}
		else{
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}

	return 0;
}
