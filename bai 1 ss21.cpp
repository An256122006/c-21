#include <stdio.h>
#include <string.h>
int main()
{
	char str[50];
	printf ("moi ban nhap chuoi:");
	fgets(str,50,stdin);
	FILE*ptr;
	ptr=fopen("demo2.txt","w");
	if (ptr==NULL)
	{
		printf ("file khong ton tai\n");
		return 1;
	}
	fputs(str,ptr);
	printf ("ghi file thanhf coong\n");
	fclose(ptr);
	char read[100];
	ptr=fopen("demo2.txt","r");
	if (ptr==NULL)
	{
		printf ("file khong ton tai\n");
		return 1;
	}
	fgets(read,sizeof(read),ptr);
	printf("%s\n",read);
	fclose(ptr);
	return 0;
}
