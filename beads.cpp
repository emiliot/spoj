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

char buffer[10005];

int main(){
	//freopen("data.in","r",stdin);
	int T; scanf("%d", &T);
	for(int t=0; t<T; ++t){
		scanf("%s\n",buffer);
		string s(buffer), choice(buffer);
		int best = 0;
		for(int i=0, n=s.size(); i<n; ++i){
			string next = s.substr(i, n-i) + s.substr(0,i);
			if(next < choice){
				best = i;
				choice = next;
			}
		}
		printf("%d\n",best+1);
	}
	return 0;
}