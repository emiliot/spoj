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

int getPos(string &key){
	int k = 0;
	for(int i=0, n = key.size(); i<n; ++i)
		k += (i+1)*((int)(key[i]));
	k *= 19;
	return k % 101;
}

void add(set<string> &inside,vector <bool> &mark, vector <string> &v, int &counter, string &key){
	if(inside.find(key)==inside.end()){
		int k = getPos(key);
		for(int i=0; i<20; ++i){
			if(!mark[((i*i)+(23*i)+k)%101]){
				inside.insert(key);
				v[((i*i)+(23*i)+k)%101] = key;
				mark[((i*i)+(23*i)+k)%101] = true;
				counter++;
				break;
			}
		}
	}
}
void del(set<string> &inside,vector <bool> &mark, vector <string> &v, int &counter, string &key){
	set <string>::iterator it = inside.find(key);
	if(it != inside.end()){
		inside.erase(it);
		int k = getPos(key);
		for(int i=0; i<20; ++i){
			if(mark[((i*i)+(23*i)+k)%101] && v[((i*i)+(23*i)+k)%101] == key){
				mark[((i*i)+(23*i)+k)%101]= false;
				counter--;
				break;
			}
		}
	}
}
int main(){
	int T; scanf("%d", &T);
	char buffer[1000];
	for(int t=0; t<T; ++t){
		vector <bool> mark(101, false);
		vector <string> v(101, "");
		set <string> inside;
		int counter = 0;
		int n; scanf("%d", &n);
		for(int k=0; k<n; ++k){
			scanf("%s", buffer);
			string next(buffer);
			next[3]=' '; istringstream iss(next);
			string ins, key; iss >> ins >> key;
			//printf("%s %s\n",ins.c_str(), key.c_str());
			if(ins == "ADD")add(inside,mark,v,counter,key);
			else del(inside,mark,v,counter,key);
		}
		printf("%d\n",counter);
		for(int i=0; i<101; ++i){
			if(mark[i]){
				printf("%d:%s\n",i,v[i].c_str());
			}
		}
	}
	return 0;
}