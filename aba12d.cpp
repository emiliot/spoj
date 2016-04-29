#include <algorithm>
#include <vector>
#include <string>
#include <queue>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
typedef long long i64;

int v[] = {2, 4, 9, 16, 25, 64, 289, 729, 1681, 2401, 3481, 4096, 5041, 7921, 10201, 15625, 17161, 27889, 28561, 29929, 65536, 83521, 85849, 146689, 262144, 279841, 458329, 491401, 531441, 552049, 579121, 597529, 683929, 703921, 707281, 734449, 829921};

int main(){
	//freopen("data.in", "r", stdin);
	int T; scanf("%d", &T);
	for(int t=0; t<T; ++t){
		int a, b; scanf("%d %d", &a, &b);
		int n = (sizeof(v)/sizeof(int));
		int res = 0;
		for(int i=0; i<n; ++i)
			if(v[i] >= a && v[i] <= b)++res;
		printf("%d\n",res);
	}
	return 0;
}
