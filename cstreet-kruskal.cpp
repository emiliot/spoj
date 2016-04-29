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
	road(){}
	road(int _a, int _b, int _cost):
	a(_a), b(_b), cost(_cost){}

	bool operator <(const road &other)const{
		return cost < other.cost;
	}
};

i64 f(int n, int m, i64 p, vector <road> &v){
	vector <int> mark(n);
	for(int i=0; i<n; ++i)mark[i] = i;

	i64 res = 0LL;
	bool spanned = false;
	sort(v.begin(), v.end());
	
	for(int k=0; k<m && !spanned; ++k){
		road &next = v[k];

		//check if the next road belong to the same tree
		if(mark[next.a] == mark[next.b])continue;

		//add the cost
		res += next.cost;

		//merge trees
		int treeMark = min(mark[next.a], mark[next.b]), old1 = mark[next.a], old2 = mark[next.b];
		int aux = 0;
		for(int i=0; i<n; ++i){
			if(mark[i] == old1|| mark[i] == old2)
				mark[i] = treeMark;
			if(mark[i] == 0)++aux;
		}

		//check if its done
		spanned = (aux == n);
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

		vector < road > v(m);
		
		for(int i=0; i<m; ++i){
			int a, b, c; scanf("%d %d %d", &a, &b, &c);
			v[i].a = a-1, v[i].b = b-1, v[i].cost = c;
		}
		
		i64 res = f(n, m, (i64)p, v);
		printf("%lld\n", res);
	}

	return 0;
}

