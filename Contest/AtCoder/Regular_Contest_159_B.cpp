#include <iostream>

using namespace std;

int gcd(long long a, long long b){
    long long tmp, n;
	
    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
    }
    
    while(b!=0){
        n = a%b;
        a = b;
        b = n;
    }
    return a;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	long long a,b;
	cin >> a >> b;
	
	long long times = 0;
	while(a >= 1 && b >=1){
		times++;
		long long g = gcd(a,b);
		a -= g;
		b -= g;
	}
	
	cout << times << '\n';
	
	return 0;
}