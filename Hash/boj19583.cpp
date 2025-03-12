#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321

using namespace std;

int time_refactoring(int h,int m){
    return h*60+m;
}
int time_refactoring(string time){
    assert(time.size() == 5);
    int h = 10*(time[0]-'0') + time[1]-'0';
    int m = 10*(time[3]-'0') + time[4]-'0';
    return h*60+m;
}


int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    int info[3][2];
    int start_val,end_val,stream_end_val;
    char buf;

    string stream_info;
    getline(cin,stream_info);
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 2 ; j++){
            //continue code...
            info[i][j] = 10*(stream_info[6*i+3*j]-'0') + (stream_info[6*i+3*j+1]-'0');
        }
    }
    start_val = time_refactoring(info[0][0],info[0][1]);    end_val = time_refactoring(info[1][0],info[1][1]);
    stream_end_val = time_refactoring(info[2][0],info[2][1]);
    
    map<string,int> check_map;
    string viewing_info;
    int cnt = 0;
    while(getline(cin,viewing_info)){
        istringstream iss(viewing_info);
        string time,name;
        getline(iss,time,' ');
        getline(iss, name, ' ');
    
        int time_val = time_refactoring(time);
        if(time_val <= start_val){
            check_map[name] = 1;
        }
        else if(time_val >= end_val && time_val <= stream_end_val){
            if(check_map[name] == 1){
                check_map[name] = 2;
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}