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

bool f(const vector<int> &v){
	stack <int> side;
	int k = 1;
	for(int i=0, n=v.size(); i<n;){
		if(v[i] != k){
			if(!side.empty() && side.top() == k)
				side.pop(), k++;
			else side.push(v[i]), ++i;
		}else
			k++, i++;
	}
	while(!side.empty()){
		if(side.top() != k)return false;
		side.pop();
		k++;
	}
	return true;
}

int main(){
	int n; 
	while(scanf("%d", &n)==1 && n != 0){
		vector <int> v(n);
		for(int i=0; i<n; ++i){
			scanf("%d", &v[i]);
		}
		if(f(v))printf("yes\n");
		else printf("no\n");
	}
	return 0;
}