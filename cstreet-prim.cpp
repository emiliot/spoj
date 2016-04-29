#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long i64;

struct road{
	int a, b, cost;
	road(int _a, int _b, int _cost):
	a(_a), b(_b), cost(_cost){}

	bool operator <(const road &other)const{
		return other.cost < cost;
	}
};

i64 f(int n, int m, i64 p, vector < vector < road > > &v){
	vector <bool> mark(n, false);
	priority_queue <road> pq;

	for(int i=0, w=(int)v[0].size(); i<w; ++i){
		pq.push(v[0][i]);
	}
	
	i64 res = 0LL;

	while(!pq.empty()){
		road next = pq.top(); pq.pop();

		if(!mark[next.a] || !mark[next.b]){
			res += next.cost;
			mark[next.a] = mark[next.b] = true;

			for(int i=0, w=(int)v[next.b].size(); i<w; ++i){
				pq.push(v[next.b][i]);
			}
		}
	}

	return res * p;
}

int main(){
	//freopen("data.in", "r", stdin);

	int T; scanf("%d", &T);
	for(int t=0; t<T; ++t){
		int p; scanf("%d", &p);
		int n; scanf("%d", &n);
		int m; scanf("%d", &m);

		vector < vector < road > > v(n);
		
		for(int i=0; i<m; ++i){
			int a, b, c; scanf("%d %d %d", &a, &b, &c);
			v[a-1].push_back(road(a-1, b-1, c));
			v[b-1].push_back(road(b-1, a-1, c));
		}
		
		i64 res = f(n, m, (i64)p, v);
		printf("%lld\n", res);
	}

	return 0;
}

