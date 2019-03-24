#include "stdio.h"
#include "string.h"
#define N 100

void keyControl();
void Qsort(char *ch, int low, int high);

void main()
{
	while(1)
	{
		keyControl();
	}
 } 
 
void keyControl()
{
	char clear_text[N]="0",keyt[N]="0",t[N]="0",text[N][N]={0,0};//clear_text为明文，keyt为密钥，text为名为的二维数组 
	char keyt2[N]="0"; //排序后的密钥 
	int num_c,num_k,row,column,i=0,j=0;//num_c为明文长度，num_k为密钥长度，row为明文行数，column为密钥列数 
	char *p,*q;
	
	//密钥的处理 
	printf("请输入密钥：\n");
	gets(keyt);
	p = keyt;
	num_k = strlen(p); // 密钥的长度；
	column = num_k - 1; //列数，从0开始记的 

	for(i=0;i<num_k;i++)
	{
		keyt2[i] = keyt[i];
	}
	
	
	Qsort(keyt2,0,column);//对密钥进行排序 
	
	//明文的处理 
	printf("请输入明文\n");
	gets(clear_text);
	
	i=0;j=0;
	//去掉明文中的空格 
	while(clear_text[i]!='\0')
	{
		if(clear_text[i]==' ');
		else
			{
				t[j]=clear_text[i];
				j++;
			}
			i++;
	}
	
	t[j+1]='\0';
	 
	q = t;
	num_c = strlen(q);//明文的长度；
	if(num_c%num_k==0)
		row = num_c/num_k; //明文的行数，从1开始记的 ，因为第0行为密钥 
	else
		row = num_c/num_k+1;//明文的行数，从1开始记的 
	j=0;
	i=0;
	//将明文放在同二维数组中	
	for(i=0;i<=row;i++)
		for(j=0;j<=column;j++)
		{
			text[i][j] = t[j+(column+1)*i];
		}


	printf("密文为：\n");
	int m,n;
	for(m=0;m<=num_k;m++)
	{
		for(n=0;n<=num_k;n++)
		{
			if(keyt[n]==keyt2[m])
			{
				if(num_c%num_k==0) 
					for(i=0;i<=num_c/num_k;i++)
					{
						printf("%c",text[i][n]);
					}
				else
				for(i=0;i<=num_c/num_k+1;i++)
				{
					if((text[i][n]>='a'&&text[i][n]<='z')||(text[i][n]>='A'&&text[i][n]<='Z'))
						printf("%c",text[i][n]);
				}		
			}
			
		}
		printf("\n");
	}

	
	getchar();
}

//快速排序 
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
