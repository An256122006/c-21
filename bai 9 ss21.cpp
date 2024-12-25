#include <stdio.h>
#include <string.h>
typedef struct Book{
	int id;
	char bookname[50];
	char author[50];
	int price;
}book;
void scan(book *user,int *index)
{
	for (int i=0; i<*index; i++)
	{
		printf ("sach thu %d:\n",i+1);
	    printf ("moi ban nhap ma sach:");
	    scanf ("%d",&user[i].id);
	    getchar();
	    printf ("moi ban nhap ten sach:");
	    fgets(user[i].bookname,50,stdin);
	    user[i].bookname[strcspn(user[i].bookname,"\n")]='\0';
	    printf ("moi ban nhap ten tac gia:");
	    fgets(user[i].author,50,stdin);
	    user[i].author[strcspn(user[i].author,"\n")]='\0';
	    printf ("moi ban nhap gia tien :");
	    scanf("%d",&user[i].price);
	}
}
void save(book*user,int *index)
{
	FILE*ptr;
	ptr=fopen("book.dat","wb");
	if(ptr==NULL)
	{
		printf ("file khong ton tai");
	}
	fwrite(user,sizeof(book),*index,ptr);
	printf ("luu sach thanh cong\n");
	fclose(ptr);
}
void find(book *user, int *index)
{
	FILE*ptr;
	ptr=fopen("book.dat","rb");
	if(ptr==NULL)
	{
		printf ("file khong ton tai");
	}
	book read[50];
	fread(read,sizeof(book),*index,ptr);
	printf ("lay thong tin thanh cong\n");
	fclose(ptr);
}
void print(book *user, int *index)
{
	FILE*ptr;
	ptr=fopen("book.dat","rb");
	if(ptr==NULL)
	{
		printf ("file khong ton tai");
	}
	book read[50];
	*index=fread(read,sizeof(book),*index,ptr);
	for (int i=0; i<*index; i++)
	{
		printf ("id:%d\n",read[i].id);
		printf ("bookname:%s\n",read[i].bookname);
		printf ("author:%s\n",read[i].author);
		printf ("gia tien :%d\n",read[i].price);
	}
	fclose(ptr);
}
int main()
{
	book user[100];
	int index,value;
	do
	{
		printf ("=================menu====================\n");
		printf ("   1.Nh?p s? lu?ng và thông tin sách\n");
		printf ("   2.Luu thông tin sách vào file\n");
		printf ("   3.L?y thông tin sách t? file\n");
		printf ("   4.Hi?n th? thông tin sách\n");
		printf ("   5.thoat\n");
		printf ("=========================================\n");
		printf("moi ban nhap lua chon:");
	    scanf ("%d", &value);
	    getchar();
	    switch(value)
	    {
	    	case 1:
	    		printf ("moi nhap so luong sach:");
	            scanf ("%d",&index);
	            scan(user,&index);
	            break;
	        case 2:
			    save(user,&index);
			    break;
			case 3:
			    find(user,&index);
			    break;
			case 4:
			    print(user,&index);
			    break; 
			case 5:
				printf ("thoat");
				return 1;
			default:
				printf ("khong hop le \n");
				break;   
		}
	}while (1);
	return 0;
}
