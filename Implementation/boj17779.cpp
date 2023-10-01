//그림으로 그리든 해서 좀 정리하고 구현하는게 좋아보임
#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define INF 987654321
#define SIZE 20

using namespace std;

int n;
int map[SIZE][SIZE];
int section[SIZE][SIZE];

void Solve();
void Input();
void set_section_5(int x,int y,int d1,int d2);
void set_other_sectors(int x,int y,int d1,int d2);
int get_diff();

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    Solve();

    return 0;
}

void printvector(){
    cout << endl;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << section[i][j] << ' ';
        }
    cout << '\n';
    }
    cout << endl;
}

void Solve(){
    Input();

    int ans = INF,t=0;
    for(int d1 = 1 ; d1 < n; d1++){
        for(int d2 = 1 ; d2 < n ; d2++){
            for(int x = 0 ; x < n ; x++){
                for(int y = 0 ; y < n ; y++){
                    if(y - d1 < 0 || x + d1 + d2 >= n || y + d2 >= n)     continue;
                    t++;
                    fill(&section[0][0],&section[SIZE-1][SIZE],-1);
                    set_section_5(x,y,d1,d2);
                    set_other_sectors(x,y,d1,d2);
                    
                    printvector();
                    
                    ans = min(ans,get_diff());
                }
            }
        }
    }

    cout << ans << endl << t << endl;
    return;
}

void set_section_5(int x,int y,int d1,int d2){
    //여기서 문제가 나서 중간에 빈공간 뚫림(해결)
    int s_x=x,s_y=y,t=0;
    while(s_x <= x+d1){
        for(int i = 0 ; i <= d2 - t ; i++){
            section[s_x+i][s_y+i] = 5;
        }
        //x 값을 먼저 움직이고, 이후에 y 값을 움직이는 식으로해서 중간에 엇갈리는 부분도 채울 수 있게 해줌
        //동시에 채워지는 칸의 갯수가 -1개가 되어야하므로 이를 위한 판단 조건으로 변수 t를 이용함
        if(!t){
            s_x++;
            t = 1;
        }
        else{
            s_y--;
            t = 0;
        }
    }
}

void set_other_sectors(int x,int y,int d1,int d2){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            //continue code...
            if(section[i][j] != -1) continue;
            if(i <= x+ d1 && j < y) section[i][j] = 1;
            else if(i >= x + d2 && j > y - d1 + d2) section[i][j] = 4;
            else if(i < x + d2 && j >= y)   section[i][j] = 3;
            else    section[i][j] = 2;
        }
    }
}

void Input(){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> map[i][j];
        }
    }
}

int get_diff(){
    int ret = INF;
    vector<int> v(5,0);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            //continue code...
            v[section[i][j]-1] += map[i][j];
        }
    }

    sort(v.begin(),v.end());
    ret = v[4] - v[0];

    return ret;
}