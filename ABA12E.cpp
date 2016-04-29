#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
typedef long long i64;



//calculate how many sums are below sum
int g(vector <i64> &v, int n, i64 sum){
	int res = 0;
	for(int i=1; i<n; ++i){
		int low = i, high = n, mid;
		while(low < high){
			int mid = (low + high)/2;
			if(v[mid] - v[i-1] <= sum)low = mid+1;
			else high = mid;
		}
		res += low-i;
	}
	return res;
}

//estimate the sum that will be the kth
i64 f(vector <i64> &v, int n, int k){
	i64 low = 1LL, high = v[n-1], mid;
	//printf("DEBUG: %lld\n",high);
	while(low < high){
		mid = (low + high)/2LL;
		//printf("DEBUG: low=%lld mid=%lld high=%lld\n", low,mid,high);
		int w = g(v,n, mid);
		//printf("DEBUG: w=%d\n",w);
		if(w < k)low = mid+1;
		else high = mid;
	}
	return low;
}

int main(){
	//freopen("data_large.in", "r", stdin);
	int n, k; scanf("%d %d", &n, &k);
	vector <i64> v(n+1);
	i64 high = 0LL;
	for(int i=1; i<=n; ++i){
		scanf("%lld", &v[i]);
		v[i] += v[i-1];
	}
	i64 res = f(v, n+1, k);
	printf("%lld\n",res);
	return 0;
}