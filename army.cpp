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

int main(){
	//freopen("data.in","r",stdin);
	int T; scanf("%d", &T);
	for(int t=0; t<T; ++t){
		int ng, nm;
		scanf("\n\n%d %d", &ng, &nm);
		int a = 0, b = 0;
		for(int i=0; i<ng; ++i){
			int x;
			scanf("%d", &x);
			a = max(a,x);
		}
		for(int i=0; i<nm; ++i){
			int x;
			scanf("%d", &x);
			b = max(b,x);
		}
		if(b > a){
			printf("MechaGodzilla\n");
		}else{
			printf("Godzilla\n");
		}
	}
	return 0;
}