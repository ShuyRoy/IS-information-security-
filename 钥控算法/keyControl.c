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
	char clear_text[N]="0",keyt[N]="0",t[N]="0",text[N][N]={0,0};//clear_textΪ���ģ�keytΪ��Կ��textΪ��Ϊ�Ķ�ά���� 
	char keyt2[N]="0"; //��������Կ 
	int num_c,num_k,row,column,i=0,j=0;//num_cΪ���ĳ��ȣ�num_kΪ��Կ���ȣ�rowΪ����������columnΪ��Կ���� 
	char *p,*q;
	
	//��Կ�Ĵ��� 
	printf("��������Կ��\n");
	gets(keyt);
	p = keyt;
	num_k = strlen(p); // ��Կ�ĳ��ȣ�
	column = num_k - 1; //��������0��ʼ�ǵ� 

	for(i=0;i<num_k;i++)
	{
		keyt2[i] = keyt[i];
	}
	
	
	Qsort(keyt2,0,column);//����Կ�������� 
	
	//���ĵĴ��� 
	printf("����������\n");
	gets(clear_text);
	
	i=0;j=0;
	//ȥ�������еĿո� 
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
	num_c = strlen(q);//���ĵĳ��ȣ�
	if(num_c%num_k==0)
		row = num_c/num_k; //���ĵ���������1��ʼ�ǵ� ����Ϊ��0��Ϊ��Կ 
	else
		row = num_c/num_k+1;//���ĵ���������1��ʼ�ǵ� 
	j=0;
	i=0;
	//�����ķ���ͬ��ά������	
	for(i=0;i<=row;i++)
		for(j=0;j<=column;j++)
		{
			text[i][j] = t[j+(column+1)*i];
		}


	printf("����Ϊ��\n");
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

//�������� 
 void Qsort(char *ch, int low, int high)     
{     
    if(low >= high)  
    {         
	 	return;  
    }     
	int first = low;    
    int last = high;      
	char key = ch[first];     //���ֱ�ĵ�һ����¼��Ϊ����    
	
	while(first < last)     
	{         
	    while(first < last && ch[last] >= key)        
		{           
		     --last;      
	    }         
		ch[first] = ch[last];          //���ȵ�һ��С���Ƶ��Ͷ�      
		   
		while(first < last && ch[first] <= key)        
		{       
		    ++first;    
	    }                  
		ch[last] = ch[first];       //���ȵ�һ������Ƶ��߶� 
	}
	ch[first] = key;  //�����¼��λ   
	
	Qsort(ch, low, first-1);    
	Qsort(ch, first+1, high); 
}
