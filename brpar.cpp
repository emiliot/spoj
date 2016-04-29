#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <vector>
#include <algorithm>

using namespace std;
typedef long long i64;
const i64 mod = 1000000007;

i64 c[1005];
i64 f[1005];

void catalan(){
	c[0] = 1;
	for(int n=1; n<=1002; ++n){
		for(int k=0; k<n; ++k){
			i64 ck = ((c[k] % mod) * (c[n-1-k] % mod) % mod);
			c[n] = ((c[n] % mod) + ck) % mod;
		}
		//if(c[n] < 0)printf("DEBUG: error overflow c[%d]\n", n);
	}
}

void factorial(){
	f[0] = 1;
	for(i64 i=1; i<=1002; ++i){
		f[i] = ((f[i-1] % mod) * (i % mod)) % mod;
	}
}

i64 fastP(i64 a, i64 b){
	if(b <= 0LL)return 1LL;
	if(b % 2 == 1){
		return ((a % mod) * (fastP(a, b-1) % mod)) % mod;
	}else{
		i64 next = fastP(a, b/2);
		return ((next % mod) * (next % mod))%mod;
	}
}

i64 getInverse(i64 x){
	return fastP(x, mod - 2) % mod;
}

i64 getPermutations(int m, vector <int> &v){
	i64 num = f[m] % mod;
	i64 den = 1;
	for(int i=0, n=(int)v.size(); i<n; ++i){
		i64 next = f[v[i]] % mod;
		den = ((den % mod) * next) % mod;
	}
	//falta hacer esta division con aritmetica modular y listo :)
	//return num / den;
	return (num % mod) * (getInverse(den) % mod) % mod;
}

int main(){
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	catalan();
	factorial();
	int T; scanf("%d", &T);
	for(int t=1; t<=T; ++t){
		int n, m = 0; scanf("%d", &n);
		vector <int> v(n);
		
		for(int i=0; i<n; ++i){
			scanf("%d", &v[i]);
			m+=v[i];
		}
		
		i64 perm = (getPermutations(m, v) % mod);
		
		i64 res = ((c[m] % mod) * (perm % mod) )%mod;
		printf("%lld\n", res);
	}
	return 0;
}

