#include <stdio.h>
int main()
{
	char str[50];
	printf("moi nhap vao chuoi:");
	fgets(str,50,stdin);
	FILE*ptr;
	ptr=fopen("demo2.txt","a");
	if(ptr==NULL)
	{
		printf ("file khongton tai\n");
		return 1;
	}
	fputs(str,ptr);
	printf ("ghi file thanh cong");
	fclose (ptr);
	return 0;
}
