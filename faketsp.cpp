#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char buffer[5000];
char buffer1[5000];
double x,y,sx, sy;

void f(){
	int n = strlen(buffer), i=0, j;
	for(;i<n && buffer[i]!='(';++i);
	i++;
	for(j=0;i<n && buffer[i]!=')';++i,++j){
		buffer1[j] = buffer[i];
	}
	buffer1[j] = '\0';
	sscanf(buffer1,"%lf, %lf", &x, &y);
}

int main(){
	//freopen("data.in","r",stdin);
	gets(buffer);
	f();
	sx = x, sy = y;
	double trip = 0.0;
	gets(buffer);
	while(strlen(buffer)>0){
		f();
		trip += sqrt(((x-sx)*(x-sx))+((y-sy)*(y-sy)));
		sx = x;
		sy = y;
		printf("The salesman has traveled a total of %.3lf kilometers.\n",trip);
		memset(buffer,'\0',sizeof(buffer));
		gets(buffer);
	}
	return 0;
}