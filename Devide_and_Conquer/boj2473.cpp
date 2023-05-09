//아니, 이분탐색을 하면 안되는듯?
/*
<케이스>

6
-104336608 239510944 997686289 627058077 722156401 -942278495

=>-942278495 -104336608 239510944 627058077 722156401 997686289

<답>

-942278495 239510944 722156401

<케이스>

7
912022275 -968846127 195376182 -212509759 589371385 817446019 -59843192

<답>

-968846127 195376182 817446019
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int N;
vector<long> v;
int get_best_val(int s,int e);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	scanf("%d",&N);
	
	int t;
	for(int i = 0 ; i < N ; i++){
		scanf("%d",&t);
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	
	int start=0,end=N-1;
	int best[3];//오름차순으로 3개
	long best_val=98765432123456789;
	
	while(end-start > 1){
		int mid = get_best_val(start,end);
		long long temp = v[start]+v[end]+v[mid];
		if(abs(temp) < best_val){
			best[0] = start;
			best[1] = mid;
			best[2] = end;
			best_val = abs(temp);
			if(temp == 0){
				break;
			}
		}
		
		if(temp < 0){
			start++;
		}
		else{
			end--;
		}
	}
	
	printf("%ld %ld %ld\n",v[best[0]],v[best[1]],v[best[2]]);
	
	return 0;
}

int get_best_val(int s,int e){
	int b_mid = (s+e)/2;
	long long best_val = abs(v[s]+v[b_mid]+v[e]);
	int start = s,end = e;
	while(start + 1 < end){
		int mid = (start+end)/2;
		long long temp = v[s]+v[mid]+v[e];
		if(temp == 0){
			return mid;
		}
		if(abs(temp) < best_val){
			b_mid = mid;
			best_val = abs(temp);
		}
		if(temp < 0){
			start = mid;
		}
		else{
			end = mid;
		}
	}
	
	return b_mid;
}