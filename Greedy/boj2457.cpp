#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

struct flower{
	int blossom, wither;
};

int N;
vector <flower> v;

/*
정렬 기준
1. 꽃이 빠르게 피는 순으로 정렬 
2. 피는 날짜가 같다면 빠르게 지는 순으로 정렬
*/

bool compare(flower& a, flower& b){
	if(a.blossom != b.blossom){//꽃이 다른 날에 피는 경우
		return a.blossom < b.blossom;
	}
	else{//꽃이 같은 날에 피는 경우
		return a.wither < b.wither;
	}
}

/*
어렵게 생각하지 말고, 그리디에 맞게 다시 생각해보자.
1. 피는 날짜가 빠른 순으로, 만약 꽃이 피는 날짜가 같다면 먼저 지는 것이 앞으로 오게 정렬한다.
2. 앞에서부터 현재 다음 꽃이 펴야 되는 시점까지 피는 꽃들을 앞부터 탐색한다. 그 중에서 가장 늦게 지는 날짜를
다음 번 다음 꽃이 펴야되는 시점으로 한다. 그리고 카운트를 1 올려준다.
중간에 이어질 수 없게 된다면(하나도 다음 순번이 될 수 있는 꽃이 없을 때) 0을 출력하고
main 함수를 종료한다.
이런 식으로 이어갔을 때, 지는 날짜가 11월 30일을 넘어간다면 루프를 멈추고 그 때의 카운트 값을 출력한다.

비교 함수 같은 경우에는 먼저 몇월, 몇일을 따로 나누지 않고
101~1231까지 천의 자리와 백의 자리를 달, 십의 자리와 일의 자리를 날짜로 생각하고 비교한다면 정수 비교를 통해 정렬할 수 있으므로 간단해 진다.
이를 이용해 꽃의 정보를 간단하게 정리할 수 있다.
*/

void printvector(){
	for(int i = 0 ; i < N ; i++){
		cout << v[i].blossom/100 << ' ' << v[i].blossom%100 << ' ' << v[i].wither/100 << ' ' << v[i].wither%100 << '\n';
	}
}

int nowpos = 0;
int next_pos; 

int greedy(){
	int now_flower_wither = 301; //언제 피는 지는 관심사가 아님\
	
	int count = 0;
	int latest_wither_day = 301;
	flower best_flower;
	vector<int> can_use_flower;
	while(true){
		for(int i = 0 ; i < N ; i++){
			if(v[i].blossom <= now_flower_wither && v[i].wither >= latest_wither_day){
				//현재 꽃이 지기 전에 피고, 현재 최적의 꽃보다 늦게 지는 경우를 찾는다.
				latest_wither_day = v[i].wither;
				next_pos = i;
			}
			else if(v[i].blossom > now_flower_wither){
				//어차피 일찍 피는 순으로 정렬했기 때문에, 여기서부터는 이후로 쭉 다 이전에 안핀다.
				nowpos = i;
				break;
			}
		}
		if(now_flower_wither >= 1201)	return count;
		
		//검색이 안된 경우를 어떻게 걸러낼 것인지 여기에 입력
		if(now_flower_wither == latest_wither_day){
			return 0;
		}
		
		now_flower_wither = latest_wither_day;
		count++;
	}
	return count;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);
	
	cin >> N;
	
	int first_month, first_day, second_month, second_day,i;
	for(i = 0 ; i < N ; i++){
		cin >> first_month >> first_day >> second_month >> second_day;
		v.push_back({first_month * 100 + first_day , second_month * 100 + second_day});
	}
	
	sort(v.begin(),v.end(),compare);
	
	//printvector();
	
	cout << greedy() << endl;
	
	return 0;
}