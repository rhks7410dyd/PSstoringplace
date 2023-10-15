//생각을 잘못해서 무조건 1부터 둘다 시작을 해야되는 상황임. 이거 어케 고치지 망해따//풀었는데?
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a_subtotal;
vector<int> b_subtotal;
int T,t;

bool can_be_T(int start,int end);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n,m;
	
	scanf("%d",&T);
	int temp;
	a_subtotal.push_back(0);
	b_subtotal.push_back(0);

	scanf("%d",&n);
	for(int i = 1 ; i <= n ;i++){
		scanf("%d",&temp);
		if(i == 1){
			a_subtotal.push_back(temp);
			continue;
		}
		a_subtotal.push_back(a_subtotal[i-1]+temp);
	}

	scanf("%d",&m);
	for(int i = 1 ; i <= m ;i++){
		scanf("%d",&temp);
		if(i == 1){
			b_subtotal.push_back(temp);
			continue;
		}
		b_subtotal.push_back(b_subtotal[i-1]+temp);
	}

	sort(a_subtotal.begin(),a_subtotal.end());
	sort(b_subtotal.begin(),b_subtotal.end());

	if((a_subtotal[0]+b_subtotal[0] > T) || (a_subtotal[n-1]+b_subtotal[m-1] < T)){
		printf("0\n");
		return 0;
	}

	int count = 0;
	int sum;
	bool possible;
	for(int i = 0 ; i < n ; i++){
		t = a_subtotal[i];
		possible = can_be_T(0,m);
		if(possible)	count++;
	}
	
	printf("%d\n",count);

	return 0;
}

bool can_be_T(int start,int end){
	if(start > end)	return false;
	
	int mid = (start+end)/2;
	int now_val = b_subtotal[mid]+t;
	if(now_val == T){
		return true;
	}
	
	if(now_val > T){
		return can_be_T(start,mid-1);
	}
	else{
		return can_be_T(mid+1,end);
	}
}