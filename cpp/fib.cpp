#include<stdio.h>
int main(){
	short int r0,r2=0,r3=0,r4=0,r7=0;
	printf("please enter the r0(n)\n");
	scanf("%hd",&r0);
	r2=1;
	r3=1;
	r4=2;
	
	r0=r0-2;
	if(r0<0){
		r7=1;
		printf("r7(fn):%hd",r7);
	    return 0;
	}
	else if(r0==0){
		r7=2;
		printf("r7(fn):%hd",r7);
	    return 0;
	}
	else{
		while(r0>0){
			r2=r2+r2;
			r7=r2+r4;
			r7=r7%1024;
			r2=r3;
			r3=r4;
			r4=r7;
			r0=r0-1; 
		}
		printf("r7(fn):%hd",r7);
	    return 0;
	}
}

