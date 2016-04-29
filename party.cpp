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
const int INF = 0x3f3f3f3f;

int memo[110][550];
bool mark[110][550];

int f(const vector < pair <int, int> > &v, int i, int k){
	if(i >= v.size() || k <= 0)return 0;
	int &best = memo[i][k];
	if(mark[i][k])return best;
	mark[i][k] = true;
	best = f(v, i + 1, k);
	if(v[i].first <= k){
		int next = f(v, i+1, k-v[i].first)+v[i].second;
		best = max(best, next);
	}
	return best;
}

int g(const vector < pair <int, int> > &v, int i, int fun){
	if(fun == 0)return 0;
	if(i >= v.size())return INF;
	int &best = memo[i][fun];
	if(mark[i][fun])return best;
	mark[i][fun] = true;
	best = g(v, i+1, fun);
	best = min(best, g(v, i+1, fun-v[i].second)+v[i].first);
	return best;
}
int main(){
	int n, p;
	while(scanf("%d %d", &p, &n)==2 && (p || n)){
		vector < pair <int, int> > v(n);
		memset(mark, false,sizeof(mark));
		for(int i=0; i<n; ++i){
			scanf("%d %d", &v[i].first, &v[i].second);
		}
		const int res = f(v, 0, p);
		memset(mark, false, sizeof(mark));
		const int spent = g(v, 0, res);
		printf("%d %d\n", spent, res);
	}
	return 0;
}