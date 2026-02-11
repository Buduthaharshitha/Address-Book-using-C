#include "addressbook.h"
#include <stdio_ext.h>
void pull_file_data(struct AddressBook * addressBook,char * file_name)
{
    FILE *fp=fopen(file_name,"r");
    int i=0;
    addressBook->contactCount=0;
    fseek(fp,0,SEEK_END);
    if(ftell(fp) != 0 )
    {
        rewind(fp);
    while(!feof(fp))//till EOF
    {
        fscanf(fp,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].mob_no,
        addressBook->contacts[i].email);
        i++;
    }
    
    }
    addressBook->contactCount=i;
    fclose(fp);
}
void push_data_to_file(struct AddressBook* addressBook,char*file_name)
{
    FILE *fp=fopen(file_name,"w");
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fprintf(fp,"%s,",addressBook->contacts[i].name);
        fprintf(fp,"%s,",addressBook->contacts[i].mob_no);
        fprintf(fp,"%s\n",addressBook->contacts[i].email);  
    }
    //printf("%d\n",addressBook->contactCount);   
    fclose(fp);
}


void add_contact(struct AddressBook * addressBook)
{
char name[50];
char email[50];
char mob_no[15];
printf("Enter the name:");
scanf(" %[^\n]",name);

L1:
printf("Enter the mobile number:");
scanf("%s",mob_no);
if(!(mobile_verf(mob_no)))
{
    printf("Invaild number, please enter the number again!\n");
    goto L1;
}

L2:
printf("Enter the email id:");
scanf("%s",email);
if(!(email_verf(email)))
{
    printf("Invaild email ID,please enter the mail id again!\n");
    goto L2;
}


strcpy(addressBook->contacts[addressBook->contactCount].name,name);
strcpy(addressBook->contacts[addressBook->contactCount].mob_no,mob_no);
strcpy(addressBook->contacts[addressBook->contactCount].email,email);
addressBook->contactCount++;

}
  
  

void search_contact(struct AddressBook *addressBook)
{
     if( addressBook->contactCount == 0 )
	printf("Contact not found\n");

    else
     {  int opt;
	// Print the searched contacts
    printf("select one option");
    printf("\n1.search by name\n2.search by mobile_no\n3.search by email\n");
    scanf("%d",&opt);
    switch(opt)
    {
        case 1:
        {
       char name[50];
       printf("Enter the name:");
       scanf("%s",name);
       search_contact_name( addressBook,name);
         break;
       }
       case 2:
        {
       char mob_no[11];
       l4:
       printf("Enter the mobile number: ");
       scanf(" %s",mob_no);
       if(!(mobile_verf(mob_no))){
        printf("invaild mobile number\n");
        goto l4;
       }

       search_contact_mob_no( addressBook,mob_no);
       break;
       }
       case 3:
        {
       char email[50];
       l5:
       printf("Enter the email: ");
       scanf(" %s",email);
       if(!(email_verf(email)))
       {
        printf("invaild email\n");
        goto l5;
       }
       search_contact_email( addressBook,email);
       break;
       }
      /* case 4:
       {
       return;
       break;
       }*/
    }
}

}
void edit_contact(struct AddressBook *addressBook)
{

 search_contact(addressBook);
 if(addressBook->ir_size==0)
 {
 return;
}
int i=1;
if(addressBook->ir_size>1)
{
printf("Enter the contact you what to edit");
scanf("%d",&i);
}
    l6:
    printf("Name:   %s,",addressBook->contacts[addressBook->index_record[i-1]].name);
    printf("mobile: %s,",addressBook->contacts[addressBook->index_record[i-1]].mob_no);
    printf("email:  %s\n",addressBook->contacts[addressBook->index_record[i-1]].email);

int sno;
printf("1.Edit by name\n2.edit by mobile\n3.Edit by email\n4.exit\n");
scanf("%d",&sno);
switch(sno)
{
case 1:
{
    char new_name[50];
  printf("Enter the new name:"); 
  scanf("%s",new_name);
  strcpy(addressBook->contacts[addressBook->index_record[i-1]].name,new_name);
  goto l6;
break;
}
case 2:
{
    char new_mob_no[11];
    l7:
  printf("Enter the new name:"); 
  scanf("%s",new_mob_no);
 
  if(!(mobile_verf(new_mob_no)))
  {
    printf("Invaild mobile");
    goto l7;
  }
  if(!strcmp(addressBook->contacts[addressBook->index_record[i-1]].mob_no,new_mob_no))
  {
    printf("mobile number is same as previous");
    goto l7;
  }
   strcpy(addressBook->contacts[addressBook->index_record[i-1]].mob_no,new_mob_no);
   goto l6;
 
break;
}
case 3:
{
    char new_email[11];
    l8:
  printf("Enter the new email:"); 
  scanf("%s",new_email);
 
  if(!(email_verf(new_email)))
  {
    printf("Invaild email");
    goto l8;
  }
    if(!strcmp(addressBook->contacts[addressBook->index_record[i-1]].email,new_email))
  {
    printf("new email is same as previous email :");
    goto l7;
  }
   strcpy(addressBook->contacts[addressBook->index_record[i-1]].email,new_email);
   goto l6;
 
break;
}
case 4:
{
    return;
    break;
}

}
}
void delete_contact(struct AddressBook *addressBook)
{
 search_contact(addressBook);
 if(addressBook->ir_size==0)
 {
 return;
}
int i=1;
if(addressBook->ir_size>1)
{
printf("Enter the contact you what to edit");
scanf("%d",&i);
}
    printf("Name:   %s,",addressBook->contacts[addressBook->index_record[i-1]].name);
    printf("mobile: %s,",addressBook->contacts[addressBook->index_record[i-1]].mob_no);
    printf("email:  %s\n",addressBook->contacts[addressBook->index_record[i-1]].email);
    char ch;
    printf("ARE YOU SURE YOU WANT TO DELETE : 'Y' or 'N' =");
    scanf(" %c",&ch);
   if(ch=='Y')
    {
        for(int j=addressBook->index_record[i-1];j<addressBook->contactCount;j++)
        {
            addressBook->contacts[j]=addressBook->contacts[j+1];
        }
        addressBook->contactCount--;
    }
    printf("YOUR CONTACT DELETED!!");
}

void list_contacts(struct AddressBook *addressBook)
{

FILE *fp=fopen("database.csv","r");
if(fp==NULL)
{
    printf("Unable to open");
}
else
{

for(int i=1;i<addressBook->contactCount;i++)
{
    printf("\nName:     %s",addressBook->contacts[i].name);
    printf("\nMobileNo: %s",addressBook->contacts[i].mob_no);
    printf("\nEMail:    %s",addressBook->contacts[i].email);
}

}
}

int mobile_verf(char *mob_no)
{
 
    if (strlen(mob_no)==10&&(mob_no[0]>'5'&&mob_no[0]<='9'))
    {
        int i=1;
        while(mob_no[i])
        {
            
            if(mob_no[i]>='0'&&mob_no[i]<='9')
            { 
             return 1;
            }
          i++;  
        }
    }
     else
        return 0;
}

int email_verf(char *email)
{
    if(email[0]=='@'||email[0]==' '||email[0]=='\t')
        return 0;
    int len=strlen(email);
    if(len<11)
        return 0;
    if(strcmp(email+len-10,"@gmail.com")==0)
        return 1;
    else
        return 0;
}
int search_contact_name(struct AddressBook * addressBook,char*name)
{ 
   addressBook->ir_size=0;
     for(int i=0;i<addressBook->contactCount;i++)
    {
      if( strcmp(name,addressBook->contacts[i].name)==0)
      {
        addressBook->index_record[addressBook->ir_size]=i;
         addressBook->ir_size++;
      }
    }
    if (addressBook->ir_size == 0)
    {
        printf("Contact not found\n");
    }
    
    for(int i=0;i<addressBook->ir_size;i++)
    {
    printf("Name:%s,",addressBook->contacts[addressBook->index_record[i]].name);
    printf("mobile:%s,",addressBook->contacts[addressBook->index_record[i]].mob_no);
    printf("email:%s\n",addressBook->contacts[addressBook->index_record[i]].email);
    }
}   
int search_contact_mob_no(struct AddressBook * addressBook,char*mob_no)
{ 

   //addressBook->ir_size=0;
     for(int i=0;i<addressBook->contactCount;i++)
    {
      if( strcmp(mob_no,addressBook->contacts[i].mob_no)==0)
      {
        addressBook->index_record[addressBook->ir_size]=i;
         addressBook->ir_size++;
      }
    }
    if (addressBook->ir_size == 0)
    {
        printf("Contact not found\n");
    }
    
    for(int i=0;i<addressBook->ir_size;i++)
    {
    printf("Name:%s,",addressBook->contacts[addressBook->index_record[i]].name);
    printf("mobile:%s,",addressBook->contacts[addressBook->index_record[i]].mob_no);
    printf("email:%s\n",addressBook->contacts[addressBook->index_record[i]].email);
    }
}   
int search_contact_email(struct AddressBook * addressBook,char*email)
{ 

   //addressBook->ir_size=0;
     for(int i=0;i<addressBook->contactCount;i++)
    {
      if( strcmp(email,addressBook->contacts[i].email)==0)
      {
        addressBook->index_record[addressBook->ir_size]=i;
         addressBook->ir_size++;
      }
    }
    if (addressBook->ir_size == 0)
    {
        printf("Email not found\n");
    }
    
    for(int i=0;i<addressBook->ir_size;i++)
    {
    printf("Name:%s,",addressBook->contacts[addressBook->index_record[i]].name);
    printf("mobile:%s,",addressBook->contacts[addressBook->index_record[i]].mob_no);
    printf("email:%s\n",addressBook->contacts[addressBook->index_record[i]].email);
    }
}   