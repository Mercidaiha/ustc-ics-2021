#include<stdio.h>
int main(){
	short int r0,r1,r7=0,r2=0;
	printf("please enter the r0 and r1\n");
	scanf("%hd%hd",&r0,&r1);
	r2=r0;
	if(r2<0){
		while(r2<0){
		r7=r7+r1;
		r2=r2+1;
	    }
	    r7=-r7;
	    printf("r7:%hd",r7);
	    return 0;
	}
	else if(r2==0){
		printf("r7:%hd",r7);
	    return 0;
	}
	else{
		while(r2>0){
		r7=r7+r1;
		r2=r2-1;	
		}
		printf("r7:%hd",r7);
		return 0;
	}
}  


