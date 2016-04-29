#include <algorithm>
#include <vector>
#include <string>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
typedef long long i64;

int main(){
	int T; scanf("%d", &T);	
	for(int t=0; t < T; ++t){
		i64 a, b; scanf("%lld %lld", &a, &b);
		printf("%lld\n",b);
	}
	return 0;	
}
