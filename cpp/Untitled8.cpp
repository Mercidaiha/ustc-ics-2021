#include<stdio.h>
int main(){
	short int r;
	r=3;
	for(int i=0;i<18;i++){
		r=r+r;
	}
	printf("%hd",r);
	return 0;
} 
