//seg_fault...^^
//dp를 이용하면 훨신 빨라지긴 할 것
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int h,w,r,c,best;
int map[10][10];
vector<vector<pair<int,int>>> rotations;
vector<string> Block;

int blockSize;

vector<string> rotate(const vector<string>& arr);
void generateRotations(vector<string> block);
int Solve();
bool set(int y,int x,const vector<pair<int,int>>& block,int delta);
bool pruning(int placed);
void search(int placed);
void print_map();

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int t;
	string temp;
	cin >> t;
	
	while(t--){
		cin >> h >> w >> r >> c;
		
		for(int i = 0 ; i < h ; i++){
			cin >> temp;
			for(int j = 0 ; j < w ; j++){
				if(temp[j] == '#'){
					map[i][j] = 1;
				}
				else{
					map[i][j] = 0;
				}
			}
		}
		
		Block.clear();
		for(int i = 0 ; i < r ; i++){
			cin >> temp;
			Block.push_back(temp);
		}
		
		generateRotations(Block);
		
		int ans = Solve();
		
		cout << ans << '\n';
	}

	return 0;
}

vector<string> rotate(const vector<string>& arr){
	vector<string> ret(arr[0].size(),string(arr.size(), ' '));
	for(int i = 0 ; i < arr.size() ; i++){
		for(int j = 0 ; j < arr[0].size() ; j++){
			ret[j][arr.size()-i-1] = arr[i][j];
		}
	}
	return ret;
}

void generateRotations(vector<string> block){
	rotations.clear();
	rotations.resize(4);
	for(int rot = 0 ; rot < 4 ; rot++){
		int originY = -1,originX = -1;
		for(int i = 0 ; i < block.size() ; i++){
			for(int j = 0 ; j < block[i].size(); j++){
				if(block[i][j] == '#'){
					if(originY == -1){
						originY = i;
						originX = j;
					}

					rotations[rot].push_back(make_pair(i-originY,j-originX));
				}
			}
		}
		block = rotate(block);
	}
	
	sort(rotations.begin(),rotations.end());
	rotations.erase(unique(rotations.begin(),rotations.end()),rotations.end());
	blockSize = rotations[0].size();
}

void search(int placed){
	if(pruning(placed))	return;

	int y = -1,x = -1;
	for(int i = 0 ; i < h ; i++){
		for(int j = 0 ; j < w ; j++){
			if(!map[i][j]){
				y = i;
				x = j;
				break;
			}
		}
		if(y != -1){
			break;
		}
	}
	
	if(y == -1){
		best = max(best,placed);
		return;
	}
	
	//cout << "y " << y << " x " << x << " placed " << placed << '\n';
	//print_map();
	/*
	여기서 가지치기를 해줘야됨
	내 생각으로는 미리 빈칸 갯수를 확인하고, 그 갯수에서 set으로 놓을 때마다 blockSize만큼 빼주고 다시 안놓았을 때는 더해주고 이런 느낌으로 가야할듯
	*/
	
	for (int i = 0; i < rotations.size(); i++) {
		if (set(y, x, rotations[i], 1))
			search(placed + 1);
		// 게임판 원상복구 
		set(y, x, rotations[i], -1);
	}
	
	map[y][x] = 1;
	search(placed);
	map[y][x] = 0;
}

int Solve(){
	best = 0;
	search(0);
	return best;
}

bool set(int y, int x, const vector<pair<int, int>>& block, int delta) {
	int ret = true;
	for (int i = 0; i < block.size(); i++) {
		int ny = y + block[i].first;
		int nx = x + block[i].second;
		// 게임판을 벗어나면 블럭못놓음
		if (ny < 0 || ny >= h || nx < 0 || nx >= w)
			ret = false;
		// 이미 채워져있으면 +1하고 ret = false한 다음 delta==-1일떄 -1
		else if ((map[ny][nx] += delta) > 1)
			ret = false;
	}
	return ret;
}

void print_map(){
	for(int i = 0 ;  i <h ; i++){
		for(int j = 0 ; j < w ; j++){
			if(map[i][j])	cout << "1 ";
			else	cout << "0 ";
		}
		cout << '\n';
	}
}

bool pruning(int placed){
	int emptys = 0;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 0)
				emptys++;
		}
	return (emptys / blockSize) + placed <= best ? true : false;
}