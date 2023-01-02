#include<stdio.h>
short int r0,r1=0,r2=0,r7=0,memx3019;
short int mem[10]={0};
void sub(){
	r2=r2-1;
	r7=mem[r2-0x300f];
	if(r7==0x300c){
	    sub();
	    return;
    }
	return;
}
void subroutines(){
	mem[r2-0x300f]=r7;
	r2=r2+1;
	r0=r0+1;
	r1=memx3019;
	r1=r1-1;
	memx3019=r1;
	if(r1==0){
		r2=r2-1;
		r7=mem[r2-0x300f];
		if(r7==0x300c){
			sub();
			return;
		}
		return;
	}
	r7=0x300c;
	subroutines();
	return;
}
int main(){
	memx3019=5;
	r0=0;
	r2=0x300f;
	r7=0x3004;
	subroutines();
	printf("r0:%hx r1:%hx r2:%hx r7:%hx",r0,r1,r2,r7);
	return 0;
}
