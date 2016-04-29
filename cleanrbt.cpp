#include "assert.h"
#include "ctype.h"
#include "float.h"
#include "math.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdarg.h"
#include "time.h"
#include "algorithm"
#include "numeric"
#include "functional"
#include "utility"
#include "bitset"
#include "vector"
#include "list"
#include "set"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "sstream"
#include "iostream"

using namespace std;

char table[30][30];
int mincost[30][30][1 << 11];
const int INF = 0x3f3f3f3f;

int movi[4] = {-1, 0, 0, 1};
int movj[4] = {0, -1, 1, 0};

struct state_t{
	int i, j, cost, mask;
	state_t(int _i, int _j, int _cost, int _mask):
	i(_i), j(_j), cost(_cost), mask(_mask){}
};

void addState(queue < state_t > &q, vector < pair <int, int> >&v, int ncost, int mask, int ni, int nj){
	int nmask;
	if(table[ni][nj] == '.' || table[ni][nj] == 'o'){
		nmask = mask;
	}else{
		int k = 0;
		for(int n=(int)v.size(); k<n; ++k){
			if(v[k].first == ni && v[k].second == nj)break;
		}
		nmask = mask | (1 << k);
	}
	
	if(ncost < mincost[ni][nj][nmask]){
		mincost[ni][nj][nmask] = ncost;
		q.push(state_t(ni, nj, ncost, nmask));
	}
}

int f(vector < pair <int, int> >&v, pair <int, int> &robot, int w, int h){
	memset(mincost, INF, sizeof(mincost));
	queue < state_t > q;
	q.push(state_t(robot.first, robot.second, 0, 0));
	mincost[robot.first][robot.second][0] = 0;
	int res = INF;
	
	while(!q.empty()){
		state_t st = q.front(); q.pop();
		if(st.cost > mincost[st.i][st.j][st.mask])continue;
		if(st.mask == (1 << (int)(v.size()))-1)res = min(res, st.cost);
		
		for(int k=0; k<4; ++k){
			int ni = movi[k] + st.i;
			int nj = movj[k] + st.j;
			if(ni >= 0 && ni < h && nj >= 0 && nj < w && table[ni][nj] != 'x'){
				addState(q, v, st.cost + 1, st.mask, ni, nj);
			}
		}
	}
	
	return res;
}

int main(){
	int w, h;
	while(scanf("%d %d", &w, &h) == 2 && (w || h)){
		vector < pair <int, int> > v;
		pair <int, int> robot;
		
		for(int i=0; i<h; ++i){
			scanf("%s", &table[i]);
			for(int j=0; j<w; ++j){
				if(table[i][j] == 'o')robot = make_pair(i, j);
				if(table[i][j] == '*')v.push_back(make_pair(i, j));
			}
		}
		
		int res = f(v, robot, w, h);
		if(res >= INF){
			printf("-1\n");
		}else{
			printf("%d\n", res);
		}
	}
	return 0;
}

