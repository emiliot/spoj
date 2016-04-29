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

int main(){
#ifndef ONLINE_JUDGE
	freopen("data.in","r",stdin);
#endif
	int n, a, b; scanf("%d %d %d",&n, &a, &b);
	vector <i64> v(n);
	vector <i64> v1, v2; v1.reserve(1 << (n/2)), v2.reserve(1 << ((n+1)/2));
	for(int i=0; i<n; ++i)
		scanf("%lld",&v[i]);
	for(int i=0, m = 1 << (n/2); i<m; ++i){
		i64 sum = 0;
		for(int j=0, w=n/2; j<w; ++j){
			if(i & (1 << j))sum += v[j];
		}
		v1.push_back(sum);
	}
	for(int i=0, m= 1 << ((n+1)/2); i<m; ++i){
		i64 sum = 0;
		for(int j=0, w=(n+1)/2; j<w; ++j){
			if(i & (1 << j)) sum += v[j + (n/2)];
		}
		v2.push_back(sum);
	}
	sort(all(v1),greater<i64>());
	sort(all(v2));
	i64 res = 0;
	//utilizando lower_bound upper_bound nlogn
	/*for(int i=0, m=v2.size(); i<m; ++i){
		vector <i64>::iterator low = lower_bound(all(v1),(i64)(a)-v2[i]);
		vector <i64>::iterator high = upper_bound(all(v1),(i64)(b)-v2[i]);
		res += high - low;
	}*/
	//utilizando ventanas deslizantes
	int p1, p2, p3, m, w;
	for(p1 = p2 = p3 = 0, m = v1.size(), w = v2.size(); p1 < m && p2 < w; ++p1){
		for(;p2 < w && v2[p2] < (i64)(a)-v1[p1]; ++p2);
		if(p2 > p3)p3 = p2;
		for(;p3 < w && v2[p3] <= (i64)(b)-v1[p1];++p3);
		res += p3-p2;
	}
	printf("%lld\n",res);
	return 0;
}
