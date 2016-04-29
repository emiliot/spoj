#include <algorithm>
#include <vector>
#include <string>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
typedef long long i64;

i64 f(vector <i64> &v, int n, i64 m){
	int low = 1, high = 1;
	i64 best = 0LL;
	while (low < n){
		//open
		for(;high < n && v[high] - v[low-1] <= m; high++);
		
		//check
		i64 next = v[high-1] - v[low-1];
		best = max(best, next);

		//close
		low++;
	}
	return best;
}

int main(){
	//freopen("data.in","r",stdin);
	int n; i64 m;
	scanf("%d %lld", &n, &m);
	vector <i64> v(n+1);
	v[0] = 0LL;
	for(int i=1; i<=n; ++i){
		scanf("%lld", &v[i]);
		v[i] += v[i-1];
	}
	i64 res = f(v,n+1,m);
	printf("%lld\n", res);
	return 0;
}