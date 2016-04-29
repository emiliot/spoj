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

const double eps = 1e-9;
const double ratio = 1000.0/37.0;
int main(){
	//freopen("data.in","r",stdin);
	int ni, nw;
	while(scanf("%d %d",&ni, &nw)==2 && ni!=-1 && nw!=-1){
		double sc2 = (double)ni / (double)nw;

		if((fabs(ratio - sc2)*2.0)/(ratio + sc2) <= eps)
			printf("Y\n");
		else printf("N\n");
	}
	return 0;
}