#include <iostream>
#include <string>
#include <vector>
#define endl '\n'
#define SIZE 2501

using namespace std;

int dp[SIZE];
string input;
vector<int> palindrom[2501];

void get_palindrom();

void printvector(){
    auto v = palindrom;
    for(int i = 1 ; i < input.length() ; i++){
        cout << input[i] << " : ";
        for(int j = 0 ; j < v[i].size() ; j++){
            cout << v[i][j] << ' ';
        }
    cout << '\n';
    }
}

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    cin >> input;
    input = " " + input;
    get_palindrom();

    //printvector();

    dp[1] = 1;

    for(int i = 2 ; i < input.length() ; i++){
        auto now_vec = palindrom[i];
        dp[i] = dp[i-1] + 1;
        for(int j = 0 ; j < now_vec.size() ; j++){
            //continue code...
            dp[i] = min(dp[i], dp[now_vec[j]-1]+1);
        }
    }

    cout << dp[input.length()-1] << endl;

    return 0;
}

void get_palindrom(){
    //홀수개 팰린드롬
    for(int i = 1 ; i <= input.length() ; i++){
        //continue code...
        int le = i-1,ri=i+1;
        while(le > 0 && ri <= input.length()){
            if(input[le] == input[ri]){
                palindrom[ri].push_back(le);
                le--;   ri++;
            }
            else{
                break;
            }
        }
    }

    //짝수개 팰린드롬
    for(int i = 1 ; i < input.length() ; i++){
        //continue code...
        int le = i,ri=i+1;
        while(le > 0 && ri <= input.length()){
            if(input[le] == input[ri]){
                palindrom[ri].push_back(le);
                le--;   ri++;
            }
            else{
                break;
            }
        }
    }
}

/*
21072	56	C++17 / 수정	1796

https://www.acmicpc.net/source/87695676
20300	1068	C++17	1147
이 사람은 맨 앞에 dp 결과가 적용되도록 뒤에서부터 연산함. 근데 substring으로 문자열을 다 넣어버려서 좀 오래걸린듯


https://www.acmicpc.net/source/87589677
26532	28	C++17	745
이중 반복문을 통해 팰린드롬 문자열을 구했는데, 그 구현 과정이 꽤 신박함. 중심이 되는 [i][i]로부터 계속 value가 1인 경우 그 1을 확장해나가는 형태로 dp를 적용시키고
이후 이 dp를 이용해 dp2에서 내가 한 구현과 동일한 구현 과정을 통해 결과를 구해냄. 나보다 시간 짧게 걸린 사람들은 다 이 형태로 했을 것 같음. => 약간의 최적화 차이일 뿐 동일함.

*/