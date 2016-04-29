#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long i64;

struct item{
	int cost, value, u;
	item(){}
	item(int _cost, int _value, int _u):
	cost(_cost), value(_value), u(_u){}
};

vector <item> v[100];
int memo[100][5][33000];
bool mark[100][5][33000];

int f(const int n, int i, int j, int w){
	if(i >= n || w <= 0)return 0;
	int &best = memo[i][j][w];
	if(mark[i][j][w])return best;
	mark[i][j][w] = true;

	best = f(n, i+1, 0, w);

	if(v[i].size() > 0){
		if(j == 0){
			if(v[i][j].cost <= w)
				best = max(best, f(n,i,j+1,w-v[i][j].cost) + v[i][j].value);
		}else{
			if(j < (int)v[i].size() && v[i][j].cost <= w)
				best = max(best, f(n,i,j+1,w-v[i][j].cost) + v[i][j].value);
			best = max(best, f(n, i+1, 0, w));
		}
	}
	return best;
}

int main(){
	//freopen("data.in","r", stdin);
	int T; scanf("%d", &T);
	for(int t=1; t<=T; ++t){
		int w, n; scanf("%d %d", &w, &n);
		for(int i=0; i<100; ++i)v[i].clear();

		for(int i=0; i<n; ++i){
			int cost, value, u;
			scanf("%d %d %d", &cost, &value, &u);
			if(u != 0)v[u-1].push_back(item(cost, cost*value, u));
			else v[i].push_back(item(cost, cost*value, u));
		}

		memset(mark, false, sizeof(mark));
		int res = f(n,0,0,w);
		printf("%d\n",res);
	}
}