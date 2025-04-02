#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321

using namespace std;

int n = 3,empty_num = 45;
int mv[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string input_str = "";
    int tmp;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> tmp;
            empty_num -= tmp;
            input_str += tmp+'0';
        }
    }

    string ans = "";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            ans += i*n+j+1 + '0';
            if(i*n+j+1 == empty_num)    ans[i*n+j] = '0';
        }
    }

    //cout << "input : " << input_str << "\t ans : " << ans << endl;

    map<string,int> map;
    map[input_str] = 0;
    
    if(map.find(ans) != map.end()){
        cout << 0 << endl;
        return 0;
    }
    map[ans] = INF;
    
    queue<string> q;
    q.push(input_str);
    while(!q.empty()){
        auto now_str = q.front();
        int now_val = map[now_str];
        q.pop();

        int now_arr[n][n];

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                //continue code...
                now_arr[i][j] = now_str[i*3+j] - '0';
            }
        }

        int zero_row_pos,zero_col_pos;
        for(int i = 0 ; i < n*n ; i++){
            if(now_arr[i/n][i%n] == 0){
                zero_col_pos = i/n; zero_row_pos = i%n;
            }
        }

        for(int i = 0 ; i < 4 ; i++){
            //continue code...
            int next_row = zero_row_pos + mv[i][0];
            int next_col = zero_col_pos + mv[i][1];
            
            if(next_row < 0 || next_row >= n || next_col < 0 || next_col >= n){
                continue;
            }

            auto temp_arr = now_arr;
            swap(temp_arr[zero_col_pos][zero_row_pos],temp_arr[next_col][next_row]);
            
            string temp_str = "";
            for(int i = 0 ; i < n*n ; i++){
                temp_str += temp_arr[i/3][i%3] + '0';
            }
            
            if(map.find(temp_str) != map.end()){
                if(map[temp_str] == INF){
                    cout << now_val + 1 << endl;
                    return 0;
                }
            }
            else{
                map[temp_str] = now_val+1;
                //cout << "push temp_str : " << temp_str << endl;
                q.push(temp_str);
            }
            swap(temp_arr[zero_col_pos][zero_row_pos],temp_arr[next_col][next_row]);
        }
    }

    cout << -1 << endl;
    return 0;
}

/*
string도 굳이 다시 이차원 배열로 안만들어줘도 생각보다 쉬었다.
그리고 map이 아니라 set을 이용해서 이미 탐색했는지만 확인해보는 게 더 싸게 먹히긴했다.
어차피 map을 사용해도 값을 저장하는데, 이 값을 저장하는건 그냥 탐색했었다의 의미만 되기 때문에
set을 쓰는 건 좋은 발상으로 보임.
*/