#include <iostream>
#define MAX 1000000

using namespace std;

int main(){
	int n = 37;
	bool have_num[n][n+1];
	for(int i = 2 ; i < n ; i++){
		int tmp = 1;
		have_num[i][n] = true;
		for(int j = 1 ; j < n ; j++){
			//continue code...
			tmp *= i;
			tmp %= n;
			if(have_num[i][tmp]==true){
				have_num[i][n]= false;
				break;
			}
			have_num[i][tmp] = true;
		}
	}
	cout << "============================Result============================\n";
	for(int i = 2 ; i < n ; i++){
		//continue code...
		if(have_num[i][n]==true){
			cout << i << '\t';
		}
	}

	return 0;
}
