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

int memo[2001][2001];
bool mark[2001][2001];

int f(const vector <int> &ag, const vector <int> &tom, int i, int j){
	const int n = ag.size(), m = tom.size();
	if(i >= n || j >= m)return 0;
	int &best = memo[i][j];
	if(mark[i][j])return best;
	mark[i][j] = true;
	if(ag[i] == tom[j])best = 1 + f(ag,tom,i+1,j+1);
	else best = max(f(ag,tom,i+1,j),f(ag, tom, i, j+1));
	return best;
}

int main(){
	int T; scanf("%d", &T);
	for(int t=0; t<T; ++t){
		vector <int> ag;
		for(int next;scanf("%d", &next) == 1 && next != 0;)ag.push_back(next);
		int best = 0;
		for(int next; scanf("%d", &next) == 1 && next !=0;){
			memset(mark, false, sizeof(mark));
			vector <int> tom; tom.push_back(next);
			for(;scanf("%d", &next)==1 && next !=0;)tom.push_back(next);
			const int res = f(ag,tom,0,0);
			best = max(best, res);
		}
		printf("%d\n", best);
	}
	return 0;
}