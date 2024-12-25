#include <stdio.h>
int main()
{
	char str[50];
    FILE*ptr;
    ptr=fopen("demo2.txt","r");
    if(ptr==NULL)
    {
    	printf ("khong phu hop");
    	return 1;
	}
    FILE*ptr1;
    ptr1=fopen("bt06.txt","w");
    if(ptr1==NULL)
    {
    	printf ("khong phu hop");
    	return 1;
	}
    while(fgets(str,sizeof(str),ptr)!=NULL)
    {
    	fputs(str,ptr1);
	}
	printf ("sao chep thanh cong");
	fclose(ptr);
	fclose(ptr1);
	return 0;
}
