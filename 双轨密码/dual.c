#include "stdio.h"
# include "string.h" 
#define N 10000

void encryption(); //加密函数 
void deciphering();//解密函数 

void main()
{
	while(1)
	{
		encryption();
		deciphering();
	}
 } 
 
 void encryption()
 {
 	char  clear_text[N]="0",cipher_text_odd[N]="0",cipher_text_even[N]="0";
 	char *p;
 	int num,i,n;
 	printf(" 请输入明文内容：\n");
 	gets(clear_text);
 	p = clear_text;
 	num = strlen(p);//所输入明文内容的字符串长度 
 	
 	
 	if(num%2==0)
 	{
 		n=num/2;
 		for(i=0;i<n;i++)
 		{
 			cipher_text_odd[i]=clear_text[2*i];//将奇数个的字符放入cipher_text_odd数组中 
 			cipher_text_even[i]=clear_text[2*i+1];//将偶数个的字符放入cipher_text_even数组中
		 }
	 }
	 else
	 {
	 	n=num/2+1;
	 	for(i=0;i<n;i++)
	 	{
	 		cipher_text_odd[i]=clear_text[2*i];//将奇数个的字符放入cipher_text_odd数组中
 			cipher_text_even[i]=clear_text[2*i+1];//将偶数个的字符放入cipher_text_even数组中
		 }
	 }
	 
	 printf("%s %s\n",cipher_text_odd,cipher_text_even);
	 getchar();
 }
 
 void deciphering()
 {
 	char cipher_text[N]="0",clear_text[N]="0";
 	int num,i,n;
 	char *p;
 	printf("请输入密文：\n");
 	gets(cipher_text);
 	p = cipher_text;
 	num = strlen(p);//所输入密文内容的字符串长度 
 	
 	if(num%2==0)
 		n = num/2;
 	else
 		n = num/2+1;
 	
 	for(i=0;i<num;i++)
 	{
 		if(i<n)
 		{
 			clear_text[2*i] = cipher_text[i];//将密文的前一半的内容分别按顺序放在奇数个的位置 
		 }	
 		else
 		{
 			clear_text[(i-n)*2+1] = cipher_text[i];//将密文的后一半的内容分别按顺序放在偶数个的位置 
		 }
 			
	 }
	 
	 printf("%s\n",clear_text);
	 getchar();
 }
