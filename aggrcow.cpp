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

bool ok(vector<int> &v, int c, int gap){
	int last = 0; c--;
	for(int i=1, n=v.size(); i<n; ++i){
		if(v[i] - v[last] > gap){
			c--, last = i;
		}
		if(c <= 0)return true;
	}
	if(c <= 0)return true;
	else return false;
}

int f(vector <int> &v, int c){
	int low = 0, high = 1000000000;
	while(low < high){
		int mid = (low + high)/2;
		if(ok(v,c,mid))low = mid+1;
		else high = mid;
	}
	return low;
}

int main(){
	//freopen("data.in","r",stdin);
	int T; scanf("%d", &T);
	for(int t=0; t<T; ++t){
		int n, c; scanf("%d %d", &n, &c);
		vector <int> v(n);
		for(int i=0; i<n; ++i)
			scanf("%d", &v[i]);
		sort(all(v));
		int res = f(v, c);
		printf("%d\n",res);
	}
	return 0;
}