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
bool compare(string& a,string& b);

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
		
		sort(correct_words.begin(),correct_words.end(),compare);
		
		for(int i = 0 ; i < correct_words.size() ; i++){
			cout << correct_words[i] << '\n';
		}

		correct_words.clear();
		words.clear();
	}
}

bool compare(string& a,string& b){
	int x=0,y=0;
	while(x < a.size() && y < b.size() && a[x] == b[y]){
		x++;	y++;
	}

	if(x == a.size() && y == b.size())	return false;

	if(x == a.size()){
		return true;
	}
	else if(y == b.size()){
		return false;
	}

	return a[x] < b[y];
}

int recursive(int pos,int now_command){
	int& ret = dp[pos][now_command];

	if(ret != -1)	return ret;

	while(pos < word.size() && now_command < wildcard.size() && (wildcard[now_command] == '?' || wildcard[now_command] == word[pos])){
		pos++;	now_command++;
	}

	if(pos == word.size()){
		if(now_command == wildcard.size())	return 1;
		else if(wildcard[now_command] == '*')	return ret = recursive(pos,now_command+1);
		else	return ret = 0;
	}

	if(now_command == wildcard.size())	return ret = 0;

	if(wildcard[now_command] == '*')	return ret = (recursive(pos,now_command+1) || recursive(pos+1,now_command) || recursive(pos+1,now_command+1)) ? 1 : 0;

	return ret = 0;
}

/*
1
a**
1
a
위의 테스트 케이스가 작동을 안함.

6
he?p
3
help
heap
helpp
*p*
3
help
papa
hello
*bb*
1
babbbc
t*l?*o*r?ng*s
3
thelordoftherings
tlorngs
tllorrngs
******a
2
aaaaaaaaaab
abcdea
a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a
2
ahfjsdhfjkdshfkjdshfkdsaojajfjaljaflkajflkdsaljflkaflsaffasfa54656454aafasfsdafsaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb

#1
heap
help
#2
help
papa
#3
babbbc
#4
thelordoftherings
tllorrngs
#5
abcdea
#6
ahfjsdhfjkdshfkjdshfkdsaojajfjaljaflkajflkdsaljflkaflsaffasfa54656454aafasfsdafsaaaaaaaaaaaaaaaaaaaa
*/

