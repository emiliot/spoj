#include <algorithm>
#include <vector>
#include <string>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
typedef long long i64;
const int INF=0x3f3f3f3f;

int memo[105][105][105];
bool mark[105][105][105];

int f(vector <int> &v, int n, int i, int j, int w){
	if(i >= (int)v.size()){
		if(j <= n && w == 0)return 0;
		else return INF;
	}

	int &best = memo[i][j][w];
	if(mark[i][j][w])return best;
	mark[i][j][w] = true;

	best = f(v,n,i+1,j,w);
	if(v[i] != -1){
		for(int next=1; next + j <= n; ++next){
			int nextW = w - (next * (i+1));
			if(nextW >= 0)
				best = min(best, f(v,n,i+1,next+j,nextW) + (next*v[i]));
		}
	}

	return best;
}

int main(){
	//freopen("data.in", "r", stdin);
	int T; scanf("%d", &T);	
	for(int t=0; t < T; ++t){
		int n, k; scanf("%d %d", &n, &k);
		vector <int> v(k);
		for(int i=0; i<k; ++i)
			scanf("%d", &v[i]);
		memset(mark, false, sizeof(mark));
		
		int res = f(v, n, 0, 0, k);
		if(res >= INF)res = -1;
		printf("%d\n",res);
	}
	return 0;	
}
