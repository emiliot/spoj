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

vector <int> build_failure(char *needle, int m){
	vector <int> v(m+1, 0);
	for(int i=2; i<=m; ++i){
		int j = v[i-1];
		for(;;){
			if(needle[i-1] == needle[j]){
				v[i] = j+1;
				break;
			}
			if(j == 0){
				v[i] = 0;
				break;
			}
			j = v[j];
		}
	}
	return v;
}

void kmp(char *ptr, vector <int> &v, int m){
	int i = 0, j = 0;
	char x; scanf("%c", &x);
	for(;x != '\n';){
		if(ptr[i] == x){
			i++;
			scanf("%c", &x); ++j;
			if(i == m)printf("%d\n",j-m);
		}else if(i > 0){
			i = v[i];
		}else{
			scanf("%c",&x); ++j;
		}
	}
}

int main(){
	//freopen("data.in","r",stdin);
	int m; char x;
	char *needle;
	while(scanf("%d\n",&m) == 1 && m){
		needle = new char[m+1];
		scanf("%s\n",needle); needle[m] = '\0';
		//printf("%s\n",needle);

		vector <int> v = build_failure(needle, m);
		kmp(needle, v, m);
		printf("\n");
		delete(needle);
	}
	return 0;
}