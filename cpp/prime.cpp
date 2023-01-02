#include<stdio.h>
void subroutines(short int &r0,short int &r1,short int &r2,short int &r3,short int &r4,short int &r5,short int &r6){
	while(1){
		r4=r2-1;
		r5=r2;
		while(r4>0){
		    r5=r5+r2;
		    r4=r4-1;
	    }
	    r5=-r5;
	    r5=r0+r5;
	    if(r5<0) return;
	    r3=r0;
	    r6=r2;
	    r6=-r6;
	    while(r3>0){
	    	r3=r3+r6;
	    	if(r3==0){
	    		r1=0;
	    		return;
			} 
		}
		r2=r2+1;
	}
	return;
}

int main(){
	short int r0,r1=0,r2=0,r3=0,r4=0,r5=0,r6=0,r7=0;
	printf("please enter the r0\n");
	scanf("%hd",&r0);
	
	r1=1;
	r2=2;
	subroutines(r0,r1,r2,r3,r4,r5,r6);
	printf("r1:%hd\n",r1);
	return 0;
} 
