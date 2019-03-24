#include "stdio.h"
#include "string.h"
#define N 1000

void select();
void lie(char *c);
void zhouqi(char *c);
void Qsort(char *ch, int low, int high);

void main()
{
	select();
	getch(); 
}

void select()
{
	char a[N]="0",a2[N]="0";
	int i=0,j=0;
	printf("请输入明文：\n");
	gets(a);
	
	while(a[i]!='\0')
	{
		if(a[i]==' ');
		else
			{
				a2[j]=a[i];
				j++;
			}
			i++;
	}
	
	printf("\t\t加密方法列表\n");
	printf("\t\t1、列换位密码\n");
	printf("\t\t2、周期换位密码\n");
	
	int x;
	printf("请输入你想用的加密方法所对应的序号：");
	scanf("%d",&x);
	
	switch(x)
	{
		case 1: lie(a2);    break;
		case 2: zhouqi(a2); break;
		default :           break;
	}
}

void lie(char *c)
{
	int r,m,n,co;
	printf("你希望将明文放在几×几矩阵中，请输入：");
	scanf("%d %d",&r,&co);
	 
	char text[N][N]={0,0},t[N]="0";
	char t2[N]="0";
	int i=0,j=0;
		
	for(i=0;i<r;i++)
		for(j=0;j<co;j++)
		{
			text[i][j] = c[j+co*i];
		}
	for(j=0;j<co;j++)
	{
		t[j] = text[0][j];
	}
	
	for(j=0;j<co;j++)
	{
		t2[j]=t[j];
	}
	
	Qsort(t2,0,co-1); //对二维数组的第一行进行排序
	
	for(m=0;m<co;m++)
		for(n=0;n<co;n++)
		{
			if(t[n]==t2[m])
			{
				if(t2[m]!=t2[m+1])
				{
					for(i=0;i<r;i++)
					{
						if((text[i][n]>='a'&&text[i][n]<='z')||(text[i][n]>='A'&&text[i][n]<='Z'))
							printf("%c",text[i][n]);
					}
				}
			
			}
		 }  
	printf("\n\n\n");
	getchar(); 
}

void zhouqi(char *c)
{
	int t=4,r,co,i,j,len;
	char text[N][N] = {0,0},text2[N][N]={0,0};
	
	len = strlen(c);
	
	if(len%t==0)
		r = len/t;
	else
		r = len/t+1;
	co = t;
	
	for(i=0;i<r;i++)
		for(j=0;j<co;j++)
		{
			text[i][j] = c[j+co*i];
		}
	
	for(i=0;i<r;i++)
	{	
		for(j=0;j<co;j++)
		{
			if(j==0) text2[i][j+2]=text[i][j];
			if(j==1) text2[i][j-1]=text[i][j];
			if(j==2) text2[i][j+1]=text[i][j];
			if(j==3) text2[i][j-2]=text[i][j];
		}
		for(j=0;j<co;j++)
		{
			if((text2[i][j]>='a'&&text2[i][j]<='z')||(text2[i][j]>='A'&&text2[i][j]<='Z'))
				printf("%c",text2[i][j]);
		 } 
		
		printf(" ");
	}
	getchar();
}

void Qsort(char *ch, int low, int high)     
{     
    if(low >= high)  
    {         
	 	return;  
    }     
	int first = low;    
    int last = high;      
	char key = ch[first];     //用字表的第一个记录作为枢轴    
	
	while(first < last)     
	{         
	    while(first < last && ch[last] >= key)        
		{           
		     --last;      
	    }         
		ch[first] = ch[last];          //将比第一个小的移到低端      
		   
		while(first < last && ch[first] <= key)        
		{       
		    ++first;    
	    }                  
		ch[last] = ch[first];       //将比第一个大的移到高端 
	}
	ch[first] = key;  //枢轴记录到位   
	
	Qsort(ch, low, first-1);    
	Qsort(ch, first+1, high); 
}
