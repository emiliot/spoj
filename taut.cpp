#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;
char buffer[150];

bool getV(vector <int> &vars, int comb, char x){
	int k = x - 'a';
	return comb & (1 << vars[k]);
}

bool g(vector <int> &vars, int comb, string &s){
	stack <bool> v;

	for(int i=(int)s.size()-1; i>=0; --i){
		if(s[i] >= 'a' && s[i] <= 'z'){
			v.push(getV(vars, comb, s[i]));
		}else{
			bool a, b;
			if(s[i] == 'N'){
				a = v.top(); v.pop();
				a = !a;
			}else{
				a = v.top(); v.pop();
				b = v.top(); v.pop();
				
				if(s[i] == 'C')a = a && b;
				else if(s[i] == 'D')a = a || b;
				else if(s[i] == 'I')a = !a?true:b;
				else a = (!a || b) && (a || !b);
			}
			v.push(a);
		}
	}
	
	return v.top();
}

void f(string s){
	int vars = 0;
	vector <int> mark(26, -1);
	for(int i=0, n=(int)s.size(); i<n; ++i){
		if(s[i] >= 'a' && s[i] <= 'z' && mark[s[i]-'a'] == -1){
			mark[s[i] - 'a'] = vars;
			++vars;
		}
	}

	bool ok = true;
	for(int k=0; k < (1 << vars) && ok; ++k){
		ok = ok && g(mark, k, s);
	}

	if(!ok)printf("NO\n");
	else printf("YES\n");
}

int main(){
	int n; scanf("%d", &n);
	for(int i=0; i<n; ++i){
		scanf("%s", buffer);
		f(string(buffer));
	}
	return 0;
}
