#ifndef CONTACT_H
#define CONTACT_H
#include<stdio.h>
#include<string.h>

struct Contact{
    char name[50];
    char mob_no[15];
    char email[50];
};



struct AddressBook {
    struct Contact contacts[100];
    int contactCount;
    int index_record[100];
    int ir_size;
};
void pull_file_data(struct AddressBook * ,char *);
void push_data_to_file(struct AddressBook *,char *);
void add_contact(struct AddressBook *addressBook);
void search_contact(struct AddressBook *addressBook);
void edit_contact(struct AddressBook *addressBook);
void delete_contact(struct AddressBook *addressBook);
void list_contacts(struct AddressBook *addressBook);
int email_verf(char *);
int mobile_verf(char *);
int search_contact_name(struct AddressBook *addressBook,char*name);
int search_contact_mob_no(struct AddressBook * addressBook,char*mob_no);
int search_contact_email(struct AddressBook * addressBook,char*email);
#endif
