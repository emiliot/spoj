#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;
const int MAX_N = 101;
const int INF = 0x3f3f3f3f;

struct edge{
    int s, d, cost, fee;
    edge(int _s, int _d, int _cost, int _fee):
        s(_s), d(_d),cost(_cost), fee(_fee){}
};

struct graph{
    vector <edge> v[MAX_N];
    void addEdge(int s, int d, int cost, int fee){
        v[s].push_back(edge(s,d,cost,fee));
    }
};

struct state_t{
    int k, w,cost;
    state_t(int _k, int _w, int _cost):
        k(_k), w(_w),cost(_cost){}
    bool operator <(const state_t &x)const{
        if(x.cost < cost)return true;
        else if(cost < x.cost)return false;
        else if(x.w > w)return true;
        else return false;
    }
};
int mincost[MAX_N][10001];
void addState(priority_queue <state_t> &pq, state_t &st, edge &e){
    if(st.w >= e.fee && mincost[e.d][st.w - e.fee] >= st.cost + e.cost){
        mincost[e.d][st.w - e.fee] = st.cost+e.cost;
        pq.push(state_t(e.d,st.w-e.fee,st.cost+e.cost));
    }
}

int dijkstra(graph &g, int src, int dest, int money){
    memset(mincost,INF, sizeof(mincost));
    priority_queue <state_t> pq;
    pq.push(state_t(0,money,0));
    while(!pq.empty()){
        state_t st = pq.top(); pq.pop();
        if(st.k == dest)return st.cost;
        if(mincost[st.k][st.w] < st.cost)continue;
        for(int i=0, n=g.v[st.k].size(); i<n; ++i){
            addState(pq, st, g.v[st.k][i]);
        }
    }
    return -1;
}

int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int T; scanf("%d", &T);
    for(int t=0; t<T; ++t){
        int w, n, e; scanf("%d\n%d\n%d", &w, &n, &e);
        graph g;
        for(int i=0; i<e; ++i){
            int s, d, cost, fee;
            scanf("%d %d %d %d", &s, &d, &cost, &fee);
            g.addEdge(s-1,d-1,cost, fee);           
        }
        const int res = dijkstra(g,0,n-1,w);
        printf("%d\n",res);
    }
}
