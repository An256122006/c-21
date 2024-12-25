#include <stdio.h>
int main()
{
	FILE*ptr;
	ptr=fopen("demo2.txt","r");
	if(ptr==NULL)
	{
		printf ("file khong ton tai");
	}
	int c=fgetc(ptr);
	printf("%c",c);
	fclose(ptr);
	return 0;
}
