#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define SIZE 100001

using namespace std;

vector<pair<int,int>> input;
vector<vector<pair<int,int>>> dp; // first : value & second : pos

void put_num(int val, int pos);
int check_min_val(vector<pair<int,int>>& v);

void print_dp();

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int a,b;
    for(int i = 0 ; i < n ; i++){
        cin >> a >> b;
        input.push_back({a,b});
    }

    //input을 A를 기준으로 오름차순으로 정렬
    sort(input.begin(),input.end());

    //dp의 초기 0번 인덱스 입력
    dp.push_back(vector<pair<int,int>>());
    dp[0].push_back(input[0]);

    for(int i = 1 ; i < n ; i++){
        put_num(input[i].second,input[i].first);
        //print_dp();
    }
    
    //print_dp();

    //dp의 size는 가장 긴 증가하는 부분수열의 값이므로 없애야될 전깃줄 개수는 n- dpsize
    cout << n - dp.size() << endl;

    vector<pair<int,int>> ans;  //ans벡터는 실제 가장 긴 증가하는 부분 수열
    int dpSize = dp.size();
    ans.push_back(dp[dpSize-1][dp[dpSize-1].size()-1]); //ans의 초기 값으로 dp에서 부분 수열의 제일 마지막 값을 넣어줌
    pair<int,int> mark_info = ans[0]; //mark_info는 ans의 이전 인덱스의 정보 편의성을 위해 변수 선언
    for(int i = dp.size()-2 ; i >= 0 ; i--){
        for(int j = dp[i].size()-1 ; j >= 0 ; j--){     //mark_info보다 A에서 앞 쪽 인덱스인 것중 가장 높은 것을 찾기 위해서
            if(dp[i][j].first < mark_info.first){       //뒤에서부터 탐색
                ans.push_back(dp[i][j]);
                mark_info = dp[i][j];
                break;
            }
        }
    }
    //제대로 된 순서로 바꾸기 위해 벡터 뒤집기
    reverse(ans.begin(),ans.end());

    int next_linked_idx = 0;
    for(int i = 0 ; i < n ; i++){
        if(input[i].first == ans[next_linked_idx].first){//ans에 있는 것은 패스하고 그 다음 인덱스가 나오도록 +1
            next_linked_idx++;
        }
        else{
            //ans에 없는 건 출력
            cout << input[i].first << endl;
        }
    }

    return 0;
}

void put_num(int val, int pos){
    // 이분탐색으로 경계에 있는 위치를 탐색
    int le = 0, ri = dp.size();
    while(le < ri){
        if(ri - le == 1){//경계에 도착했을 때
            if(check_min_val(dp[le]) < val){ //dp[le]에서 가장 작은 값보다 val가 클 경우, ri 인덱스에 추가해야됨
                if(ri == dp.size()) dp.push_back(vector<pair<int,int>>());  //새로운 최장거리 생성
                dp[ri].push_back({pos,val});
                return;
            }
            else{
                dp[le].push_back({pos,val});
                return;
            }
        }
        
        int mid = (le + ri)/2;

        int quest_val = check_min_val(dp[mid]);
        if(quest_val > val){
            ri = mid;
        }
        else{
            le = mid;
        }
    }
    //에러 핸들링
    cout << "==============error==============\n";
    cout << "le : " << le << "\tri : " << ri << endl << "val : " << val << "\tpos : " << pos << endl;
    print_dp();
    exit(1);
}

int check_min_val(vector<pair<int,int>>& v){
    return v[v.size()-1].second;
}

void print_dp(){//로그 출력용 함수
    for(int i = 0 ; i < dp.size() ; i++){
        cout << i << " : ";
        for(int j = 0 ; j < dp[i].size() ; j++){
            cout << '{' << dp[i][j].first << " , " << dp[i][j].second << "}, ";
        }
        cout << endl;
    }
}