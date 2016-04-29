#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

char buffer[100];
bool mark[90][90][2];
int memo[90][90][2];

int f(vector <string> &v, vector < vector <int> > &table, string &s, int i, int start, bool ok){
	if(i >= (int)s.size())return 0;

	int &best = memo[i][start][ok?1:0];
	if(mark[i][start][ok?1:0])return best;
	mark[i][start][ok?1:0] = true;

	//check if at position i an emoticon begins
	bool begins = false;
	for(int k=0, m=(int)table.size(); k<m && !begins; ++k){
		if(binary_search(table[k].begin(), table[k].end(), i))begins = true;
	}
	
	if(!ok){ //start is not at a position where a emoticon begins
		if(!begins)best = f(v, table, s, i+1, start, ok);
		else {
			best = f(v, table, s, i+1, i, true);
			best = min(best, f(v, table, s, i+1, i+1, false) + 1);
		}
	}else{
		best = f(v, table, s, i+1, i+1, false) + 1; //erase the character i
		
		//try to leave the same character i
		bool flag = true;
		for(int k=0, m=(int)v.size(); k<m && flag; ++k){
			if(v[k] == s.substr(start, i - start + 1))flag = false;
			//if(s[i] == v[k][i - start] && i - start == (int)v[k].size()-1)flag = false;
		}

		if(flag){
			best = min(best, f(v, table, s, i+1, start, ok));
		}

	}

	return best;
}

vector <int> getInfo(string &pat, string &s){
	vector <int> res;
	int last = 0, x;
	while((x = s.substr(last, s.size() - last).find(pat)) != -1){
		res.push_back(x+last);
		last = x+1+last;
	}
	return res;
}

int processLine(vector <string> &v, string s){
	vector < vector <int> > table(v.size());
	bool ok = false;
	for(int i=0, n=(int)v.size(); i<n; ++i){
		table[i] = getInfo(v[i], s);
		for(int j=0, m=(int)table[i].size(); j<m; ++j){
			//printf("DEBUG Match %s in %d\n", v[i].c_str(), table[i][j]);
			if(table[i][j] == 0)ok = true;
		}
	}

	memset(mark, false, sizeof(mark));
	int res = f(v, table, s, 0, 0, ok);
	return res;
}

int main(){
	freopen("data.in", "r", stdin);
	freopen("emoticons.out", "w", stdout);
	int n, m;
	while(scanf("%d %d\n", &n, &m) == 2 && (n || m)){
		vector <string> v(n, "");
		for(int i=0; i<n; ++i){
			gets(buffer);
			v[i] = buffer;
		}
		
		int res = 0;
		for(int i=0; i<m; ++i){
			gets(buffer);
			res += processLine(v, string(buffer));
		}
		
		printf("%d\n", res);
	}
}
