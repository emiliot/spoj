#pragma warning(disable:4018)  // signed/unsigned mistatch
#pragma warning(disable:4244)  // w64 to int cast
#pragma warning(disable:4267)  // big to small -- possible loss of data
#pragma warning(disable:4786)  // long identifiers
#pragma warning(disable:4800)  // forcing int to bool
#pragma warning(disable:4996)  // deprecations
#include "assert.h"
#include "ctype.h"
#include "float.h"
#include "math.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdarg.h"
#include "time.h"
#include "algorithm"
#include "numeric"
#include "functional"
#include "utility"
#include "bitset"
#include "vector"
#include "list"
#include "set"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "sstream"
#include "iostream"
#define all(v) (v).begin(), (v).end()
typedef long long i64;
template <class T> void make_unique(T& v) {sort(all(v)); v.resize(unique(all(v)) - v.begin());}
using namespace std;

void f(int res, int n){
	for(int i=n; i>1; --i){
		while(res % i == 0 && n % i == 0){
			res /= i, n/= i;
		}
	}
	printf("%d / %d\n",res,n);
}

int main(){
	freopen("data.in","r", stdin);
	char buffer[150];
	int res = 0, n=0;
	set <string> mark;

	while(gets(buffer) != NULL){
		string s = buffer;
		for(int i=0, m=s.size(); i<m; ++i){
			if(((s[i] >= 'A' && s[i] <='Z') || (s[i] >='a' && s[i] <= 'z'))){
				s[i] = toupper(s[i]);
			}else s[i] = ' ';
		}
		istringstream iss(s);
		
		while(iss >> s){
			if(s == "BULLSHIT"){
				//printf("count %d\n",count);
				res += mark.size();
				n++;
				mark.clear();
			}else mark.insert(s);
		}
	}
	f(res,n);
	return 0;
}