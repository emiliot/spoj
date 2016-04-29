#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long i64;
char buffer[100];

int gcd(int a, int b){
	if(b == 0)return a;
	else return gcd(b, a % b);
}

int main(){
	//freopen("data.in", "r", stdin);
	while(scanf("%s", buffer) == 1 && buffer[0] != '*'){
		string s(buffer);
		i64 n = 1LL;
		for(int i=0, k=1, m=s.size(); i<m; ++i,++k){
			if(s[i] == 'Y')n = (n * k)/gcd(n,k);
		}

		bool flag = true;
		for(int i=0, k=1, m=s.size(); i<m; ++i, ++k){
			if(s[i] == 'Y')flag = flag && (n % k == 0);
			else flag = flag && (n % k > 0);
		}
		if(flag)printf("%d\n",n);
		else printf("%d\n",-1);
	}
	return 0;
}
