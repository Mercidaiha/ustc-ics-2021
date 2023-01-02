#include<stdio.h>
int main(){
	short int r0,r1,r7=0,r2=0,r3=0,r4=0;
	printf("please enter the r0 and r1\n");
	scanf("%hd%hd",&r0,&r1);
	r3=15;
	if(r1<0){
		r1=-r1;
		r0=-r0;
	}
	r3=r3-1;
	while(r3>0){
		r1=r1+r1;
		if(r1<0){
			r2=r0;
			r4=r3;
			while(r4){
			r2=r2+r2;
			r4=r4-1;
		    }
		    r7=r7+r2;
		}
		r3=r3-1;
	}
	r1=r1+r1;
	if(r1>=0){
		printf("r7:%hd",r7);
	    return 0;
	}
	else{
		r7=r7+r0;
		printf("r7:%hd",r7);
	    return 0;
	}
}

