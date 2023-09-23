#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'

using namespace std;

struct hint_sell_str{
    int r,c,val,set=0;
    bool vertical_hint;
};

bool compare(hint_sell_str& a,hint_sell_str& b){
    if(a.c == b.c)  return a.r < b.r;
    return a.c < b.c;
}

vector<hint_sell_str> info;
int gameboard[21][21];
int n,q;

bool recursive(int y,int x);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int C;
    cin >> C;
    while(C--){
        //continue code. . .
        cin >> n;

        int temp;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                cin >> temp;
                if(temp)    gameboard[i][j] = -1;
                else    gameboard[i][j] = 0;
            }
        }

        cin >> q;
        int x,y,d,s;
        bool ver;
        for(int i = 0 ; i < q ; i++){
            cin >> y >> x >> d >> s;
            if(d == 1)   ver = true;
            else    ver = false;

            hint_sell_str temp = {x,y,s,0,ver};
            info.push_back(temp);
        }

        sort(info.begin(),info.end(),compare);

        /*
        for(int i = 0 ; i < q ; i++){
            cout << info[i].c << ' ' << info[i].r << ' ' << info[i].val << endl;
        }
        cout << endl;
        */
        //

        recursive(1,1);
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                cout << gameboard[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}

/*
1.기본 백트래킹 함수에 필요한 정보 : 좌표
2.현재 위치에 넣을 수 있는 값들만 넣기
3.오류 판단
4.오류시 컨티뉴, 아니면 그 값을 넣고 다음 항으로
5.1~4 재귀로 반복
6.위치가 n+1,1이면 리턴 트루
*/

bool recursive(int y,int x){
    if(x == n+1){
        y++;
        x = 1;
    }

    if(y == n+1){
        for(int i = 0 ; i < q ; i++){
            if(info[i].val) return false;
        }
        return true;
    }
    if(gameboard[y][x] == 0)    return recursive(y,x+1);

    int hori_y=y,hori_x=x,vert_y=y,vert_x=x;

    while(gameboard[hori_y][hori_x] != 0){
        hori_x--;
    }
    while(gameboard[vert_y][vert_x] != 0){
        vert_y--;
    }

    int h_idx,v_idx;
    for(int i = 0 ; i < q ; i++){
        if(info[i].vertical_hint || info[i].c != hori_y || info[i].r != hori_x)   continue;
        h_idx = i;  break;
    }
    for(int i = 0 ; i < q ; i++){
        if(!info[i].vertical_hint || info[i].c != vert_y || info[i].r != vert_x)    continue;
        v_idx = i;  break;
    }

    for(int i = 1 ; i < 10 ; i++){
        if(info[h_idx].set & 1<<i || info[v_idx].set & 1<<i)  continue;

        if(info[h_idx].val <= i || info[v_idx].val <= i)    continue;

        info[h_idx].set += (1<<i);
        info[v_idx].set += (1<<i);
        info[h_idx].val -= i;
        info[v_idx].val -= i;
        gameboard[y][x] = i;
        if(recursive(y,x+1))    return true;
        info[v_idx].val += i;
        info[h_idx].val += i;
        gameboard[y][x] = -1;
        info[h_idx].set -= (1<<i);
        info[v_idx].set -= (1<<i);
    }

    return false;
}