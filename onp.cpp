#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

string f(string &s, int &i){
	if(i >= (int)(s.size()))return "";
	string res = "";
	stack <char> op;
	for(int n = s.size(); i<n && s[i]!=')'; ++i){
		if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')op.push(s[i]);
		else{
			if(res.size() > 0){
				if(s[i] =='('){
					i++;
					(res += f(s,i)) += op.top(), op.pop();
				}else
					(res += s[i]) += op.top(), op.pop();
			}else{
				if(s[i] == '('){
					i++;
					res += f(s,i);
				}else
					res += s[i];
			}
		}
	}
	return res;
}

int main(){
	int T; scanf("%d", &T);
	char buffer[1000];
	for(int t=0; t<T; ++t){
		scanf("%s", buffer);
		string s(buffer);
		int i = 0;
		string res = f(s, i);
		printf("%s\n", res.c_str());
	}
	return 0;
}