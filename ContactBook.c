#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct contact{
    char phone[200];
	char name[400];
	char gmail[500];
	char address[900];
}con;
 void add();
 void view();
 void edit();
 void search();
 void delete_contact();
 void delete_all_contacts();
 int main(){
	int n;
	do{
	printf("\n---------Contact Book---------\n");
	printf("1.Add New Contact\n2.View all Contacts\n3.Edit Contact\n4.Search Contact\n5.Delete all Contact\n6.Exit\nSelect The Option: ");
	 scanf("%d",&n);
	 switch(n)
	 {
	 	case 1:
	 		add();
	 		break;
	 	case 2:
	 		view();
	 		break;
	 	case 3:
	 		edit();
	 		break;
	 	case 4:
	 		search();
	 		break;
	 	case 5:
	 		delete_all_contacts();
	 		break;
	 }
	}while(n!=7);	
	}
void add(){
	FILE *fp;
	fp=fopen("contact.txt","a");
	printf("Enter the Name:");
	fflush(stdin);
	gets(con.name);
	printf("Enter The Phone Number:");
	scanf("%s",con.phone);
	printf("Enter the Gmail:");
	fflush(stdin);
	gets(con.gmail);
	printf("Enter the Address: ");
	gets(con.address);
	fwrite(&con,sizeof(con),1,fp);
	fclose(fp);
    printf("Contact Added successfully......\n");
fclose(fp);
}
void view(){
	FILE *fp;
	fp=fopen("contact.txt","r");
	while(fread(&con,sizeof(con),1,fp)){
        printf("-------------------------\n");
		printf("Name: %s\n",con.name);
		printf("Phone Number: %s\n",con.phone);
		printf("Gmail: %s\n",con.gmail);
		printf("Address: %s\n",con.address);
	}
fclose(fp);
}
void edit(){
	int found=0;
	FILE*fp;
	FILE *f;
	fp =fopen("contact.txt","r");
	f = fopen("tempcontacts.txt","w");
	char name1[50];
	printf("Enter the Name to Edit:");
	fflush(stdin);
	gets(name1);	
	while(fread(&con,sizeof(con),1,fp))
	{
		if(strcmp(con.name,name1)==0)
		{
			printf("-----Person Found-----\n");
			printf("Person Details:\n");
			printf("Name: %s\n",con.name);
			printf("Phone Number: %s\n",con.phone);
			printf("Gmail: %s\n",con.gmail);
			printf("Address: %s\n",con.address);
			printf("------------------------\n");
			printf("What Details You want to edit:\n");
			int m;
			printf("1.Edit Name\n2.Edit Phone Number\n3.Edit Gmail\n4.Edit Address\n5.Edit all the Details\n");
			printf("select the Following Choice:");
			scanf("%d",&m);
		    switch(m)
			{
			case 1:
				printf("Enter the New Name:");
				fflush(stdin);
				gets(con.name);
				break;
			case 2:
				printf("Enter The  New Phone Number:");
				fflush(stdin);
				scanf("%s",con.phone);
				break;
			case 3:
				printf("Enter the New Gmail:");
				fflush(stdin);
				gets(con.gmail);
				break;
			case 4:
				printf("Enter the New Address: ");
                fflush(stdin);
				gets(con.address);
				break;
			case 5:
				printf("Enter the New Name:");
				fflush(stdin);
				gets(con.name);
				printf("Enter The New Phone Number:");
				fflush(stdin);
				scanf("%s",con.phone);
				printf("Enter the New Gmail:");
				fflush(stdin);
				gets(con.gmail);
				printf("Enter the New Address: ");
				gets(con.address);
				break;
		    }
		   fwrite(&con,sizeof(con),1,f);
		   found=1;
		}
        else
        {
        	fwrite(&con,sizeof(con),1,f);
		}
    }		
	if(!found)
	{
		printf("Contact Not found......");
	}

fclose(fp);
fclose(f);
remove("contact.txt");
rename("tempcontacts.txt","contact.txt");

}
void search(){
	char name[30];
	int found =0;
    FILE *fp;
    fp =fopen("contact.txt","r");
    printf("Enter the name to search:");
    fflush(stdin);
    gets(name);
    while(fread(&con,sizeof(con),1,fp)){
    	if(strcmp(con.name,name)==0)
		{
    	printf("\n---------------------\n");
		printf("Contact Found:\n");	
   	    printf("Name: %s\n",con.name);
		printf("Phone Number: %s\n",con.phone);
		printf("Gmail: %s\n",con.gmail);
		printf("Address: %s\n",con.address);
		found =1;
		break;
		}
    }
    if(!found)
	{
		printf("Contact Not found......");
	}
    fclose(fp);
}
void delete_all_contacts(){
    FILE *fp;
    fp =fopen("contact.txt","w");
    fclose(fp);
    printf("Contacts Deleted Successfully...");
}
