#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
typedef long long i64;
const int INF = 0x3f3f3f3f;

int costs[100002][3];
int memo[100002][3];
bool mark[100002][3];

int f(int n, int i, int j){
	if(i == n-1 && j == 1)return costs[i][j];
	int &best = memo[i][j];
	if(mark[i][j])return best;
	mark[i][j] = true;
	best = INF;

	//trans
	if(j == 0){
		best = min (best, f(n,i,j+1) + costs[i][j]);
		if(i+1 < n){
			best = min(best, f(n, i+1, j) + costs[i][j]);
			best = min(best, f(n, i+1, j+1) + costs[i][j]);
		}
	}else if(j == 1){
		best = min(best, f(n,i,j+1) + costs[i][j]);
		if(i+1 < n){
			best = min(best, f(n, i+1, j-1) + costs[i][j]);
			best = min(best, f(n, i+1, j) + costs[i][j]);
			best = min(best, f(n, i+1, j+1) + costs[i][j]);
		}
	}else{
		if(i+1 < n){
			best = min(best, f(n, i+1, j-1)+ costs[i][j]);
			best = min(best, f(n, i+1, j) + costs[i][j]);
		}
	}
	return best;
}

int main(){
	//freopen("data.in", "r", stdin);
	int n;
	for(int k=1; scanf("%d", &n)==1 && n; ++k){
		for(int i=0; i<n; ++i){
			scanf("%d %d %d", &costs[i][0], &costs[i][1], &costs[i][2]);
		}
		memset(mark, false, sizeof(mark));
		int res = f(n, 0, 1);
		printf("%d. %d\n",k,res);
	}
	return 0;
}
