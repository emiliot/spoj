#include <algorithm>
#include <vector>
#include <string>
#include <queue>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
typedef long long i64;

char grid[60][60];
bool mark[60][60];

struct state_t{
	int i, j, k;
	char x;
	state_t(int _i, int _j, int _k, char _x):
	i(_i), j(_j),k(_k), x(_x){}
};

int movi[8] = {-1,-1,-1,0,0,1,1,1};
int movj[8] = {-1,0,1,-1,1,-1,0,1};

int f(int i, int j, int w, int h){
	memset(mark, false, sizeof(mark));
	queue <state_t> q;
	q.push(state_t(i,j,1,'A'));
	mark[i][j] = true;
	int best = 1;
	while(!q.empty()){
		state_t st = q.front(); q.pop();
		best = max(best, st.k);
		if(st.x < 'Z'){
			for(int s=0; s<8; ++s){
				int ni = st.i + movi[s], nj = st.j+movj[s];
				if(ni >= 0 && ni < h && nj >= 0 && nj < w && !mark[ni][nj] && grid[ni][nj] == st.x + 1){
					q.push(state_t(ni,nj,st.k+1,st.x+1));
					mark[ni][nj] = true;
				}
			}
		}
	}
	return best;
}

int main(){
	//freopen("data.in", "r", stdin);
	int w, h, t=1; 
	while(scanf("%d %d", &h, &w)==2 && (w || h)){
		//printf("%d %d\n",h,w);
		for(int i=0; i<h; ++i)
			scanf("%s", &grid[i]);
		int best = 0;
		for(int i=0; i<h; ++i){
			for(int j=0; j<w; ++j){
				if(grid[i][j] == 'A'){
					best = max(best, f(i,j, w, h));
				}
			}
		}
		printf("Case %d: %d\n",t++, best);
	}
	return 0;	
}