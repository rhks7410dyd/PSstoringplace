#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string wildcard;
string word;
vector<string> words;
vector<string> correct_words;

int recursive(int pos,int now_command);
int dp[101][101];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int C;
	cin >> C;
	for(int c = 0 ; c < C ; c++){
		int word_c;
		string temp;
		
		cin >> wildcard;
		cin >> word_c;
		
		for(int i = 0 ; i < word_c ; i++){
			cin >> temp;
			words.push_back(temp);
		}
		
		for(int i = 0 ; i < word_c ; i++){
			fill(&dp[0][0],&dp[100][101],-1);
			word = words[i];
			if(recursive(0,0)){
				correct_words.push_back(word);
			}
		}
		
		sort(correct_words.begin(),correct_words.end());
		
		for(int i = 0 ; i < correct_words.size() ; i++){
			cout << correct_words[i] << '\n';
		}

		correct_words.clear();
		words.clear();
	}
}

int recursive(int pos,int now_command){
	int& ret = dp[pos][now_command];

	if(ret != -1)	return ret;

	if(word[pos] == wildcard[now_command])	return ret = recursive(pos+1,now_command+1);

	//

	return ret;
}

/*
1
a**
1
a
위의 테스트 케이스가 작동을 안함.
*/