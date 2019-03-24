#include "stdio.h"
#include "malloc.h"
int multipInverse();
int ex_gcd(int a,int n,int *x,int *y,int *gcd);//扩展的欧几里得算法 
void cal(int a,int n);//计算乘法逆元 

void main()
{
	while (1)
	{
		multipInverse();
	}
}

int multipInverse()
{
	int a,n;
	printf("请输入两个数：");
	scanf("%d %d",&a,&n);
	
	cal(a,n);
	return 0;
}
 
 void cal(int a,int n)
 {
 	int *x,*y,gcd,ans;
 	x=(int*)malloc(sizeof(int));
 	y=(int*)malloc(sizeof(int));
 	ans=ex_gcd(a,n,x,y,&gcd);
 	if(gcd!=1)  
	{
	 	printf("%d和%d不互素,所以%d关于模%d的乘法逆元不存在,最大公约数为%d。\n",a,n,a,n,gcd);
	}
 	else {
 		if(ans<=0) 
		 	ans= ans+n;
		(*x)=ans;
 		printf("%d关于模%d的乘法逆元为%d。\n",a,n,*x);
 		printf("%d关于模%d的乘法逆元为%d。\n",n,a,*y);
	 }	
 }

 int ex_gcd(int a,int n,int *x,int *y,int *gcd)
{
	int ans,temp;
	if(n==0)
	{
		(*x)=1; 
		(*y)=0;
		(*gcd)=a;
		return *x;
	}
	ans=ex_gcd(n,a%n,x,y,gcd);
	temp = (*x);
	(*x)=(*y);
	(*y)=temp-a/n*(*y);
	return *x;
 } 
