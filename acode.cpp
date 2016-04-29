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

i64 memo[5001];
bool mark[5001];
char buffer[5001];
int n;

i64 f(int k){
	if(k >= n)return 1;
	if(buffer[k] == '0')return 0;
	i64 &count = memo[k];
	if(mark[k])return count;
	mark[k] = true;
	count = f(k+1);
	if((buffer[k] == '1' || buffer[k] == '2') && k+2 <= n)
		count += f(k+2);
	return count;
}

int main(){
	freopen("data.in","r",stdin);
	while(scanf("%s", buffer) == 1 && buffer[0] != '0'){
		n = strlen(buffer);
		memset(mark,false,sizeof(mark));
		i64 res = f(0);
		printf("%lld\n",res);
	}
	return 0;
}