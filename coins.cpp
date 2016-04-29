#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
typedef long long i64;
map <i64, i64> memo;

i64 f(i64 n){
	if(n <= 2LL)return n;

	pair < map <i64, i64>::iterator , bool > best = memo.insert(make_pair(n,n));
	if(!best.second)return best.first->second;
	
	i64 next = f(n/2) + f(n/3) + f(n/4);
	if(next > best.first->second)best.first->second = next;

	return best.first->second;
}

int main(){
	i64 n;
	while(scanf("%lld", &n) == 1){
		memo.clear();
		i64 res = f(n);
		printf("%lld\n", res);
	}
}
