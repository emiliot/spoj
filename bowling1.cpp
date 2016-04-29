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

struct frame{
	int n, v1, v2, v3;
	frame(){n = 0, v1 = 0, v2 = 0, v3 = 0;}
};

void readInput(vector <frame> &v){
	for(int i=0; i<9; ++i){
		v[i].n = 1;
		scanf("%d", &v[i].v1);
		if(v[i].v1 < 10){
			v[i].n++;
			scanf("%d", &v[i].v2);
		}
	}
	v[9].n = 2;
	scanf("%d", &v[9].v1);
	scanf("%d", &v[9].v2);
	if(v[9].v1 == 10 || (v[9].v1 + v[9].v2 == 10)){
		v[9].n++;
		scanf("%d", &v[9].v3);
	}
}

int f(vector <frame> &v){
	int res = 0;
	for(int i=0; i<9; ++i){
		res += v[i].v1;
		if(v[i].n == 1){
			res += v[i+1].v1;
			if(v[i+1].n == 1){
				if(i+1 < 9)res+=v[i+2].v1;
				else res += v[i+2].v2;
			}else{
				res += v[i+1].v2;
			}
		}else{
			res += v[i].v2;
			if(v[i].v1 + v[i].v2 == 10){
				res += v[i+1].v1;
			}
		}
	}
	res+=v[9].v1 + v[9].v2;
	if(v[9].n == 3)res += v[9].v3;
	return res;
}

int main(){
	//freopen("data.in","r",stdin);
	int T; scanf("%d", &T);
	for(int t=0; t<T; ++t){
		vector < frame > v(10);
		readInput(v);
		int res = f(v);
		printf("%d\n",res);
	}
	return 0;
}