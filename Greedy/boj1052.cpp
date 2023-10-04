//시간 재다가 막혀서 못품
//중간에 k-n이 더 좋게 먹히는 경우가 생기는 게 아니라면 애매한듯
//이거 처리 못하겠으면 비트 연산자로 재구현해보기
//그냥 2진수니까 물병 13개를 8 + 4 + 1로 보면 3개로 생각 가능
#include <iostream>

using namespace std;

int exponent[25];

void Solve();
int get_ans(int n,int k);

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	Solve();
	
	return 0;
}

void Solve()
{
	int n,k;
	cin >> n >> k;
	
	int temp = 1;
	for(int i = 0 ; i < 25 ; i++){
		exponent[i] = temp;
		temp *= 2;
	}
	int ans = k-n;
	if(n>k)	ans = get_ans(n,k);
	
	cout << ans << '\n';
}

int get_ans(int n,int k)
{
	//cout << "----------------\n";
	//cout << n << ' ' << k << '\n';
	if(n==k)	return 0;
	
	int merge_val;
	for(int i = 0 ; i < 25 ; i++){
		if(exponent[i] < n && exponent[i+1] > n)	merge_val = exponent[i];
	}
	//cout << merge_val << '\n';
	if(k == 1){
		return	merge_val*2 - n;
	}
	
	if(n-merge_val < k-1)
	{
		while(n-merge_val < k-1){
			merge_val /= 2;
		}
		//cout << "case 1 : changed merge_val is " << merge_val << '\n';
		n -= merge_val;
		k--;
		return get_ans(n,k);
	}
	else
	{
		n -= merge_val;
		k--;

		return get_ans(n,k);
	}
}