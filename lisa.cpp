#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
typedef unsigned long long i64;

char buffer[1000];

bool mark[200][200];
i64 memo[200][200];

i64 f(string &s, bool flag, int a, int b){
	//since it is infix it can be reduced to x op y
	i64 x, y;

	//if there are no operators return x
	bool ok = true;
	for(int i=a; i<b && ok; ++i){
		if(s[i] == '+' || s[i] == '*')ok = false;
	}
	if(ok){
		istringstream iss(s.substr(a, b-a));
		iss >> x;
		return x;
	}

	//memoization
	i64 &best = memo[a][b];
	if(mark[a][b])return best;
	mark[a][b] = true;

	best = flag? (1 << 64) - 1 : 0LL;
	//since there are one or more operators split the sentence around them
	for(int i=a; i<b; ++i){
		if(s[i] == '+' || s[i] == '*'){
			x = f(s, flag, a, i), y = f(s, flag, i+1, b);
			if(flag){
				best = min(best, (s[i] == '+'? x+y : x*y));
			}else{
				best = max(best, (s[i] == '+'? x+y : x*y));
			}
		}
	}
	return best;
}

int main(){
	//freopen("data.in", "r", stdin);
	int T; scanf("%d", &T);
	for(int t=1; t<=T; ++t){
		scanf("%s", buffer);
		string s(buffer);
		
		memset(mark, false, sizeof(mark));
		i64 high = f(s, false, 0, (int)s.size());
		
		memset(mark, false, sizeof(mark));
		i64 low = f(s, true, 0, (int)s.size());
		
		printf("%lld %lld\n", high, low);
	}
	return 0;
}
