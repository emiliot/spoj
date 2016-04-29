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

bool mark[30][120];
int memo[30][120];

int f(vector < pair <int, int> > &v, int i, int k){
	if(i >= (int)v.size()){
		if(k == 0)return 1;
		else return 0;
	}
	if(k == 0)return 0;
	int &count = memo[i][k];
	if(mark[i][k])return count;
	mark[i][k] = true;
	count = 0;
	for(int j=v[i].first, n=min(v[i].second, k); j<=n; ++j){
		count += f(v,i+1,k-j);
	}
	return count;
}

int main(){
	//freopen("data.in", "r", stdin);
	int m, n;
	while(scanf("%d %d", &m, &n)==2 && (n || m)){
		vector < pair < int, int> >v(m);
		for(int i=0; i<m; ++i){
			scanf("%d %d", &v[i].first, &v[i].second);
		}
		memset(mark, false, sizeof(mark));
		int res = f(v,0,n);
		printf("%d\n",res);
	}
	return 0;
}
