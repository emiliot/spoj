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

struct problem{
	char id;
	int ac, time, sub;
	problem():
	ac(0), time(0), sub(0){}
};

int submissions[62][10];
bool mark[62][10];
char buffer[100];

int main(){
	int T; scanf("%d", &T);
	for(int t = 0; t<T; ++t){
		int n; scanf("%d", &n);
		vector <problem> v(9); for(int i=0; i<9; ++i)v[i].id = 'A'+i;
		memset(submissions, 0 ,sizeof(submissions));
		memset(mark, false, sizeof(mark));
		map <string, int> teams;
		for(int i=0; i<n; ++i){
			int time; char id, ans; string name;
			scanf("%d %s %c %c", &time, buffer, &id, &ans);
			name = buffer;
			int k = id - 'A', team;
			map<string, int>::iterator it = teams.find(name);
			if(it!=teams.end())team = it->second;
			else team = teams.size(), teams[name] = team;
			submissions[team][k]++;
			if(ans == 'A' && !mark[team][k]){
				mark[team][k] = true;
				v[k].ac++;
				v[k].time += time;
				v[k].sub += submissions[team][k];
			}
		}
		for(int i=0; i<9; ++i){
			printf("%c %d",v[i].id, v[i].ac);
			if(v[i].ac > 0){
				double avgSub = v[i].sub / (double)v[i].ac;
				double avgTime = v[i].time / (double)v[i].ac;
				printf(" %.2lf %.2lf\n",avgSub, avgTime);
			}
			else printf("\n");
		}
	}
	return 0;
}
