#include <stdio.h>
#include <string.h>
typedef struct sinhvien{
	int id;
	char name[50];
	int age;
}student;

void nhap(student *user,int *index)
{
	for (int i=0; i<*index; i++)
	{
		printf ("sinh vien thu %d:\n",i+1);
		printf ("moi ban nhap id:");
		scanf ("%d",&user[i].id);
		fflush(stdin);
		printf ("moi ban nhap ten sinh vien:");
		fgets(user[i].name,50,stdin);
		user[i].name[strcspn(user[i].name,"\n")]='\0';
		printf ("moi ban nhap tuoi :");
		scanf ("%d",&user[i].age);
	}
}
void find(student *user, int *index)
{
	FILE*ptr;
	ptr=fopen("student.txt","w");
    if (ptr==NULL)
    {
    	printf ("file khong ton tai\n");
    	return ;
	}
	for (int i=0; i<*index;i++)
	{
		fprintf(ptr,"id:%d,name:%s,tuoi:%d\n",user[i].id,user[i].name,user[i].age);
	}
	fclose(ptr);
}
int main()
{
	int index;
	printf ("moi abn nhap so luong sinh vien:");
	scanf ("%d",&index);
	getchar();
	student user[100];
	nhap (user,&index);
	find(user,&index);
	return 0;
}
