#pragma warning(disable:4018)  // signed/unsigned mistatch
#pragma warning(disable:4244)  // w64 to int cast
#pragma warning(disable:4267)  // big to small -- possible loss of data
#pragma warning(disable:4786)  // long identifiers
#pragma warning(disable:4800)  // forcing int to bool
#pragma warning(disable:4996)  // deprecations
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
#define all(v) (v).begin(), (v).end()
typedef long long i64;
template <class T> void make_unique(T& v) {sort(all(v)); v.resize(unique(all(v)) - v.begin());}
using namespace std;
const int MAX_N = 10005;
struct edge{
	int a, b, cost;
	edge(int _a, int _b, int _cost):
	a(_a), b(_b), cost(_cost){}
	bool operator <(const edge &x)const{
		if(x.cost < cost)return true;
		return false;
	}
};

struct graph{
	vector <edge> g[MAX_N];
	void addEdge(int a, int b, int cost){
		g[a].push_back(edge(a,b,cost));
	}
};

int f(const graph &gr, const int n){
	vector <bool> mark(n, false);
	priority_queue<edge> pq;
	for(int i=0; i<n; ++i){
		if(gr.g[i].size()>0){
			for(int k=0, m=gr.g[i].size(); k<m; ++k)
				pq.push(gr.g[i][k]);
			break;
		}
	}
	int res = 0, count = 0;
	while(!pq.empty() && count < n){
		edge next = pq.top(); pq.pop();
		if(!mark[next.a] || !mark[next.b]){
			mark[next.a] = mark[next.b] = true;
			res += next.cost;
			for(int i=0, m=gr.g[next.b].size(); i<m; ++i){
				pq.push(gr.g[next.b][i]);
			}
		}
	}
	return res;

}

int main(){
	int T; scanf("%d", &T);
	char buffer[1000];
	for(int t=0; t<T; ++t){
		int n; scanf("\n%d",&n);
		graph gr;
		for(int i=0; i<n; ++i){
			scanf("%s",buffer);
			int w; scanf("%d", &w);
			for(int j=0; j<w; ++j){
				int b, cost; scanf("%d %d", &b, &cost);
				gr.addEdge(i,b-1,cost);
			}
		}
		const int res = f(gr, n);
		printf("%d\n", res);
	}
	return 0;
}