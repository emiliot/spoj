#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#include <algorithm>
#include <vector>
#include <string>
 
using namespace std;
 
typedef long long i64;
 
int main(){
        int T; scanf("%d\n\n", &T);
        for(int t=1; t<=T; ++t){
                int n, m; scanf("%d %d", &m, &n);
                vector <int> vy(n), vx(m);
                vy[0] = 0, vx[0] = 0;
                
                int sx, sy, res;
                sx = sy = res = 0;
                
                //printf("DEBUG: %d %d\n", m, n);
                
                for(int i=1; i<m; ++i){
                        scanf("%d", &vx[i]);
                        sx += vx[i];
                }
                //printf("\n");
                
                for(int i=1; i<n; ++i){
                        scanf("%d", &vy[i]);
                        sy += vy[i];
                }
                
                /*for(int i=0; i<m; ++i)printf("%d ", vx[i]);
                printf("\n");*/
                
                sort(vx.begin()+1, vx.end());
                sort(vy.begin()+1, vy.end());
                
                for(int i=n-1, j=m-1; i || j;){
                        if(vx[j] > vy[i]){
                                res += vx[j] + sy;
                                sx-=vx[j];
                                --j;
                        }else{
                                res += vy[i] + sx;
                                sy -= vy[i];
                                --i;
                        }
                }
                
                printf("%d\n", res);
 
        }
        return 0;
}

