#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int make2(int *p,int i);
char *mul(char *argv1, char *argv2);
void rem0(char *num,int len);


	
	

int main(int argc,char **argv)
{
	
	if(argc != 2){
		printf("fac takes 2 argument only.");
		exit(1);	
	}
	long int x;
	unsigned int len;
	len = strlen(argv[1]);
	
	char num1[len],num2[len];
	char *ans; 
	sprintf(num1,"%d",atoi(argv[1]));
	x = atoi(argv[1]);
	ans = num1;
	while(x > 1){
		sprintf(num2,"%ld", x - 1);
		ans = mul(ans,num2);
		x--;
	}
	printf("%s\nLength = %u\n",ans, strlen(ans));
	free(ans);
	return 0;	
	
	
}


char *mul(char *argv1, char *argv2)
{
		
	int len1 = strlen(argv1);
	int len2 = strlen(argv2);
	int tlen = len1 + len2;
	int i,j,n,x;
	int num1[len1], num2[len2] , ans[tlen]; 
	char arg1[len1], arg2[len2];
	char *ansc;
	int  *a,*b;
	a = malloc(sizeof(int)*2); 
	b = malloc(sizeof(int)*2);
	ansc = malloc(sizeof(char)*tlen);
	sprintf(arg1,"%s",argv1);
	sprintf(arg2,"%s",argv2);
	
	for(i=0;i<len1;i++) {
		num1[i] = (int)(arg1[len1-i-1] - '0');  
	}
	
	for(i=0;i<len2;i++) {
		num2[i] = (int)(arg1[len1-i-1] - '0');
	}
	
	for(i=0;i<tlen;i++){
		ans[i] = (int) 0;		
	}
	for(i=0;i<len2;i++){	
		
		x = 0;
		make2(a,0);
		make2(b,0);
		
		for(j=0;j<len1;j++){
			n = num1[j]*num2[i] + a[1];
			make2(a,n);
			n = a[0] + b[1]  + ans[tlen-x-1-i] ; 
			make2(b,n);
			ans[tlen-x-1-i] = b[0];
			x++;
		}
		
		if(i < (len2-1)){ans[tlen-x-i-1] = a[1] + b[1];}
	}

	ans[0] = b[1] + a[1] + ans[0];
	for(i=0;i<tlen;i++){
		ansc[i] = (char)ans[i] + '0';		
	}
	rem0(ansc,tlen);
	
	free(a);
	free(b);
		
	return ansc;	
}
void rem0(char *num,int tlen)
{
	int i;
	if(num[0] == '0'){
		for(i=0;i<tlen - 1;i++)
		{
			num[i] = num[i+1];	
		}
		num[tlen-1] =  (char) 0;
	}
}
int make2(int *a, int i)
{
	if(i>9){
		a[0] = (int) i%10;
		a[1] = (int) i/10;
		return 1;
		}else{
		a[0] = (int) i;
		a[1] = (int) 0;
		return  0;
		}
	
			
}
