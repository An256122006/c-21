#include <stdio.h>
int main()
{
	FILE*ptr;
	ptr=fopen("demo2.txt","r");
	if(ptr==NULL)
	{
		printf ("file khong ton tai");
	}
	char read[50];
	fgets(read,sizeof(read),ptr);
	printf("%s\n",read);
	fclose(ptr);
	return 0;
}
