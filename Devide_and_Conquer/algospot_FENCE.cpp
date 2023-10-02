//스위핑 알고리즘을 사용하지 않은 방식을 만들기 위해서 작성
//백준 6549 문제와 동일한 문제임.
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int Solve();
int Recursive(int left,int right,vector<int>& h);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int C;
	
	scanf("%d",&C);
	
	for(int i = 0 ; i < C ; i++){
		int ans = Solve();
		printf("%d\n",ans);
	}
	
	return 0;
}


int Solve(){
	int N,t;
	scanf("%d",&N);
	vector<int> v;
	for(int i = 0 ; i < N ; i++){
		scanf("%d",&t);
		v.push_back(t);
	}
	
	int ret = Recursive(0,N-1,v);
	return ret;
}

int Recursive(int left,int right,vector<int>& h){
	int mid = (left + right)/2;
	int ret = 0;
	//cout << "ln47 " << "left " << left << " right " << right << " mid " << mid << endl;
	if(left == right){
		//cout << "ln49 " << "l " << left << " r " << right << " return value " << h[left] << endl;
		return h[left];
	}
	
	ret = max(ret,Recursive(left,mid,h));
	ret = max(ret,Recursive(mid+1,right,h));
	
	int l=mid,r=mid+1;
	int height = INF;
	while(l >= left && r <= right){
		height = min(height,h[l]);
		height = min(height,h[r]);
		int tmp = height*(r-l+1);
		ret = max(ret,tmp);
		
		if(r == right)	l--;
		else if(l == left)	r++;
		else{
			if(h[l-1] > h[r+1])	l--;
			else	r++;	
		}
	}
	
	return ret;
}

/*
1
7
7 1 5 9 6 7 3

ln47 left 0 right 6 mid 3
	ln47 left 0 right 3 mid 1
		ln47 left 0 right 1 mid 0
			ln47 left 0 right 0 mid 0
			ln49 l 0 r 0 return value 7
			ln47 left 1 right 1 mid 1
			ln49 l 1 r 1 return value 1
			ln74 l 0 r 1 return value 7
		
		ln47 left 2 right 3 mid 2
			ln47 left 2 right 2 mid 2
			ln49 l 2 r 2 return value 5
			ln47 left 3 right 3 mid 3
			ln49 l 3 r 3 return value 9
			ln74 l 2 r 3 return value 9
		
		ln74 l 1 r 2 return value 9
		ln74 l 0 r 2 return value 9
		ln74 l 0 r 3 return value 9
	ln47 left 4 right 6 mid 5
	ln47 left 4 right 5 mid 4
	ln47 left 4 right 4 mid 4
	ln49 l 4 r 4 return value 6
	ln47 left 5 right 5 mid 5
	ln49 l 5 r 5 return value 7
	ln74 l 4 r 5 return value 7
	ln47 left 6 right 6 mid 6
	ln49 l 6 r 6 return value 3
	ln74 l 5 r 6 return value 7
	ln74 l 4 r 6 return value 7
	ln74 l 3 r 4 return value 12
	ln74 l 2 r 4 return value 12
	ln74 l 1 r 4 return value 12
	ln74 l 0 r 4 return value 12
	ln74 l 0 r 5 return value 12
	ln74 l 0 r 6 return value 12
12
*/