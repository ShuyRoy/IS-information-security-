#include "stdio.h"
#include "malloc.h"
int multipInverse();
int ex_gcd(int a,int n,int *x,int *y,int *gcd);//��չ��ŷ������㷨 
void cal(int a,int n);//����˷���Ԫ 

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
	printf("��������������");
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
	 	printf("%d��%d������,����%d����ģ%d�ĳ˷���Ԫ������,���Լ��Ϊ%d��\n",a,n,a,n,gcd);
	}
 	else {
 		if(ans<=0) 
		 	ans= ans+n;
		(*x)=ans;
 		printf("%d����ģ%d�ĳ˷���ԪΪ%d��\n",a,n,*x);
 		printf("%d����ģ%d�ĳ˷���ԪΪ%d��\n",n,a,*y);
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
