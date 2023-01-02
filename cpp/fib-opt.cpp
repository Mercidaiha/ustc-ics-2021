#include<stdio.h>
int main(){
	short int r0,r1=0,r2=0,r3=0,r6=0,r7=0;
	printf("please enter the r0(n)\n");
	scanf("%hd",&r0);
	
	r1=1;
	r2=1;
	r3=2;
	r6=r0-20;
	if(r6>=0){
		r0=r0-20;
		r0=r0%128;
		r0=r0+20;
	}
	r7=r7+r0;
	r0=r0-2;
    while(r0>0){
		r7=r3+r1;
		r7=r7+r1;
		r1=r2;
		r2=r3;
		r3=r7;
		r0=r0-1; 
	}
	r7=r7%1024;
	if(r7<0) r7=r7+1024;
	printf("r7(fn):%hd",r7);

	return 0;
}


