/*
비트연산에 뭔가 문제가 있는듯?...
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#define endl '\n'

using namespace std;

const int INF = 987654321;

void Solve();
void Input();
int get_ans(int set,int idx);
int get_minus_length(int a,int b);
bool is_included(string& a,string& b);

int N,s_size;
int dp[1<<15][15];
int best_select[1<<15][15];
int overlap_length[15][15];

vector<string> input_list;
vector<string> sub_string;

int main(){
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int C;
	cin >> C;
	while(C--){
		Solve();
	}
	return 0;
}

void Solve(){
	memset(&dp[0][0],-1,sizeof(dp));
	memset(&best_select[0][0],-1,sizeof(best_select));
	sub_string.clear();
	input_list.clear();

	Input();

	//input_list에서 완전히 포함되는 부분배열들을 삭제하는 과정이 필요함.
	sort(input_list.begin(), input_list.end(),[](string a,string b) { return a.size() < b.size(); });

	bool is_overlapped[15];
	for(int i = 0 ; i < N ; i++){
		is_overlapped[i]=false;
		for(int j = i+1 ; j < N ; j++){
			if(input_list[j].find(input_list[i]) != string::npos){
				is_overlapped[i] = true;
				break;
			}
		}
	}

	for(int i = 0 ; i < N ; i++){
		if(!is_overlapped[i])	sub_string.push_back(input_list[i]);
	}

	s_size = sub_string.size();

	get_ans(0,0);

	int now = 0;
	int now_set = 0;
	for(int i = 0 ; i < s_size ; i++){
		int next = best_select[now_set][now];
		cout << sub_string[next] << ' ';
		now = next;
		now_set = now_set | next;
	}
	cout << endl;
	
}

void Input(){
	cin >> N;

	string temp;
	for(int i = 0 ; i < N ; i++){
		cin >> temp;
		input_list.push_back(temp);
	}
}

//이번 인덱스 값 + get_ans - 다음 예정 인덱스와 겹치는 값
int get_ans(int set,int idx){
	int& ret = dp[set][idx];
	if(ret != -1)	return ret;

	if(set == (1<<s_size)-1)	return sub_string[idx].size();

	ret = INF;
	if(set == 0){//가장 처음인 경우
		for(int i = 0 ; i < s_size ; i++){
			if(set & 1<<i)	continue;
			int temp = get_ans((set | (1<<i)),i);
			if (temp < ret){
				ret = temp;
				best_select[set][idx] = i;
			}
		}
		return ret;
	}

	for(int i = 0 ; i < s_size ; i++){
		if(idx == i)	continue;
		if(set & (1<<i))	continue;
		int next_set = set | (1<<i);
		int temp = sub_string[idx].size() + get_ans(next_set,i) - get_minus_length(idx,i);
		if(temp < ret){
			ret = temp;
			best_select[set][idx] = i;
		}
	}

	return ret;
}

int get_minus_length(int a,int b){
	int& ret = overlap_length[a][b];
	if(ret != -1)	return ret;
	
	string& f = sub_string[a];
	string& e = sub_string[b];
	int fsize = f.size();
	int Size = f.size() < e.size() ? f.size() : e.size();
	
	ret = 0;
	for(int l = 1 ; l < Size; l++){
		bool can_overlap = true;
		for(int i = 0 ; i < l ; i++){
			if(f[fsize-l+i] != e[i]){
				can_overlap = false;
				break;
			}
		}
		if(can_overlap)	ret = l;
	}
	//cout << f << ' ' << e << ' ' << ret << '\n';
	return ret;
}

//최솟값을 찾는 과정을 생각해봐야됨.
//하나의 집합에서 16가지 경우의 수 중에서 최적화 된 선택한 인덱스를 택할 것


/*
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#define INF 987654321

using namespace std;

int k;
int dp[1<<15];
int overlap_length[15][15];
vector<string> input;
string reconstruct(int last,int Set);
int Solve(int Set,int str);
int get_minus_length(int a,int b);
bool compare(string& a,string& b);
bool is_included(string& a,string& b);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int C;
	cin >> C;
	while(C--){
		memset(&dp[0],-1,sizeof(dp));
		memset(&overlap_length[0][0],-1,sizeof(overlap_length));
		input.clear();
		cin >> k;
		for(int i = 0 ; i < k ; i++){
			string temp;
			cin >> temp;
			input.push_back(temp);
		}
		
		sort(input.begin(),input.end(),compare);
		
		bool is_overlapped[15];
		for(int i = 0 ; i < k ; i++){
			is_overlapped[i]=false;
			for(int j = i+1 ; j < k ; j++){
				if(input[j].find(input[i]) != string::npos){
					is_overlapped[i] = true;
					break;
				}
			}
		}
		
		int erase_cnt = 0;
		for(int i = 0 ; i < k ; i++){
			if(is_overlapped[i]){
				input.erase(input.begin()+i-erase_cnt);
				erase_cnt++;
			}
		}
		
		
		int ans = INF;
		
		for(int i = 0 ; i < input.size() ; i++){
			int temp = Solve(1<<i,i);
			//cout << "temp_i(" << i <<") " << temp << '\n';
			if(temp < ans)	ans = temp;
		}
		
		string s_ans;
		for(int i = 0 ; i < input.size() ; i++){
			string temp = input[i];
			temp += reconstruct(i,1<<i);
			//cout << "i " << i << " temp " << temp << " ans " << ans << '\n';
			if(temp.size() == ans){
				s_ans = temp;
				break;
			}
		}
		
		cout << s_ans << '\n';
	}
	
	return 0;
}

int Solve(int Set,int str){
	if(Set == (1<<input.size())-1){
		return input[str].size();
	}
	
	int& ret = dp[Set];
	if(ret != -1)	return ret;
	
	ret = INF;
	for(int next = 0 ; next < input.size() ; next++){
		if(!(Set & (1 << next))){
			int temp = Solve(Set + (1 << next),next) - get_minus_length(str,next);
			if(temp + input[str].size() < ret){
				ret = temp + input[str].size();
			}
		}
	}
	
	//cout << "Set " << Set << " str " << str << " : " << input[str] << " ret " << ret << '\n';
	return ret;
}

int get_minus_length(int a,int b){
	int& ret = overlap_length[a][b];
	if(ret != -1)	return ret;
	
	string& f = input[a];
	string& e = input[b];
	int fsize = f.size();
	int Size = f.size() < e.size() ? f.size() : e.size();
	
	ret = 0;
	for(int l = 1 ; l < Size; l++){
		bool can_overlap = true;
		for(int i = 0 ; i < l ; i++){
			if(f[fsize-l+i] != e[i]){
				can_overlap = false;
				break;
			}
		}
		if(can_overlap)	ret = l;
	}
	
	
	//cout << f << ' ' << e << ' ' << ret << '\n';
	return ret;
}

bool compare(string& a,string& b){
	return a.size() < b.size();
}

//아직도 맨 아래 워닝이 나옴
string reconstruct(int last,int Set){
	if(Set == (1<<input.size())-1)	return "";
	
	for(int next = 0 ; next < input.size() ; next++){
		if(Set & (1<<next))	continue;
		int ifUsed = Solve(Set+(1<<next),next) + input[last].size() - get_minus_length(last,next);

		if(Solve(Set,last) == ifUsed){
			return (input[next].substr(overlap_length[last][next]) + reconstruct(next, Set + (1<<next)));
		}
	}
	return "***** WARNING! *****";
}
*/
