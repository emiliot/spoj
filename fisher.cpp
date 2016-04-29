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
const int INF = 0x3f3f3f3f;
using namespace std;

struct state_t{
	int i, cost, time;
	
	state_t(int _i, int _cost, int _time):
	i(_i), cost(_cost), time(_time){}

	bool operator <(const state_t &x)const{
		if(x.cost < cost)return true;
		else if(cost < x.cost)return false;
		else return x.time < time;
	}
};

int times[100][100];
int tolls[100][100];
int mincost[100][1002];

void addState(priority_queue <state_t> &pq, int i, int nextCost, int nextTime){
	if(nextCost < mincost[i][nextTime]){
		mincost[i][nextTime] = nextCost;
		pq.push(state_t(i,nextCost, nextTime));
	}
}

pair <int, int> f(int n, int t){
	memset(mincost, INF, sizeof(mincost));
	priority_queue <state_t> pq;
	pq.push(state_t(0,0,0));
	mincost[0][0] = 0;
	while(!pq.empty()){
		state_t st = pq.top(); pq.pop();
		if(st.i == n-1 && st.time <= t)return make_pair(st.cost, st.time);
		if(st.time > t)continue;
		for(int k=0; k<n; ++k){
			if(k != st.i)
				addState(pq, k, st.cost + tolls[st.i][k], st.time + times[st.i][k]);
		}
	}
	return make_pair(0,0);
}

int main(){
	//freopen("data.in","r",stdin);
	int n, t;
	while(scanf("%d %d", &n, &t) == 2 && (n || t)){
		memset(times, 0, sizeof(times));
		memset(tolls, 0, sizeof(tolls));
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j)
				scanf("%d", &times[i][j]);
		}
		scanf("\n");
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j)
				scanf("%d", &tolls[i][j]);
		}
		pair <int, int> res = f(n,t);
		printf("%d %d\n", res.first, res.second);
	}
	return 0;
}