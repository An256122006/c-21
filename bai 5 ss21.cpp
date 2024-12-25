#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	char str[100];
	printf ("moi ban nhap so dong:");
	scanf("%d",&n);
	getchar();
	FILE*ptr;
	ptr=fopen("bt05.txt","w");
	if(ptr==NULL)
	{
		printf("file khong ton tai\n");
	}
	for (int i=0; i<n;i++)
	{
		printf ("moi ban nhap chuoi thu %d:",i+1);
	    fgets(str,sizeof(str),stdin);
	    str[strcspn(str,"\n")]='\0';
	    fputs(str,ptr);
	    fputs("\n",ptr);
	}
	fclose(ptr);
	char read[50];
	ptr=fopen("bt05.txt","r");
	if(ptr==NULL)
	{
		printf("file khong ton tai\n");
	}
	for (int i=0; i<n;i++)
	{	
	    fgets(read,sizeof(read),ptr);
	    printf("%s",read);
	}
	fclose(ptr);
	return 0;
}
