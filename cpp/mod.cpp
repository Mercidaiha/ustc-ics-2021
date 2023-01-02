#include<stdio.h>
short int r0,r1=0,r2=0,r3=0,r4=0,r5=0;
void subroutines(){
	r2=0;
	r3=0;
	r4=0;
	r2=r2+1;
	r3=r3+8;
	while(1){
	   r5=r3&(r1);
	   if(r5) r4=r2+r4;
	   r2=r2+r2;
	   r3=r3+r3;
	   if(r3==0) break;
    }
    return;
}
int main(){
	r1=0x120;
	do{
	subroutines();
	r2=r1%8;
	r1=r2+r4;
	r0=r1-7;
    }
    while(r0>0);
    r0=r1-7;
    if(r0>=0) r1=r1-7;
    printf("r1:%hd",r1);
    return 0;
}

