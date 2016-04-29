#include "stdio.h"
int main(){
	char b[100];
	while(scanf("%s",b)==1){
		int r=1,i=0;
		for(;b[i]!='\0';++i)if(b[i]=='T'||b[i]=='D'||b[i]=='L'||b[i]=='F')r*=2;
		printf("%d\n",r);
	}
	return 0;
}