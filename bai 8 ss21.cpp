#include <stdio.h>
#include <string.h>
typedef struct sinhvien{
	int id;
	char name[50];
	int age;
}student;
void read(student *user,int *index)
{
	FILE*ptr;
	ptr=fopen("student.txt","r");
    if (ptr==NULL)
    {
    	printf ("file khong ton tai\n");
    	return ;
	}
	(*index)=0;
	while(fscanf(ptr,"id:%d, name:%s ,tuoi:%d\n",&user[*index].id,user[*index].name,&user[*index].age)!=NULL)
	{
	     printf("ID: %d, Tên: %s, Tu?i: %d\n",user[*index].id,user[*index].name,user[*index].age);
		 (*index)++;	
	}
	fclose (ptr);
}
int main()
{
	int index;
	student user[100];
	read(user,&index);
	return 0;
}
