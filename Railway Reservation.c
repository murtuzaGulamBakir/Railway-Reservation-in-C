#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include<string.h>
int k=20101,f,r,choice=1;
char st[100];
struct node
{          //RAILWAY RESERVATION
int age,fare,pnr,route;
char name[100];


struct node *next;
};
struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_beg(struct node *);



int main() {
int option;
clrscr();
do
{
printf("\n\n ****Welcome to Western railway***");
printf("\n 1: Create reservation list");
printf("\n 2: Display the Reservation list");
printf("\n 3: Add to Reservation List");
printf("\n 4: Cancel Reservation");
printf("\n 5: EXIT");
printf("\n\n Enter your option : ");
scanf("%d",&option);
switch(option)
{
case 1: start = create_ll(start);
printf("\n RAILWAY RESERVATION LIST CREATED");
break;
case 2: start = display(start);
break;
case 3: start = insert_end(start);
break;
case 4: start = delete_node(start);
break;
}
}while(option !=5);
getch();
return 0;
}
struct node *create_ll(struct node *start)
{

struct node *new_node, *ptr;
int num;
printf("Enter your route\n1.Mumbai-Delhi\n2.Mumbai-Chennai\n3.Mumbai-Kolkata:");
scanf("%d",&r);

while(choice==1)
{printf("\nEnter the name of the person:");
scanf("%s",&st);
 printf("\nEnter the age of person: ");
scanf("%d", &num);
 if(r==1)
 { if(num>=60)
     f=460;
      else
     f=650;
 }
 else
 if(r==2)
 { if(num>=60)
     f=375;
      else
     f=500;
 }
 else
 { if(num>=60)
     f=690;
      else
     f=750;
 }

new_node = (struct node*)malloc(sizeof(struct node));
new_node->route=r;
new_node -> age=num;
new_node -> pnr=k;
strcpy(new_node->name,st);
new_node ->fare=f;
k++;
if(start==NULL)
{
new_node -> next = NULL;
start = new_node;
}
else
{
ptr=start;
while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next = new_node;
new_node->next=NULL;
}
printf("\nPress 1 to Continue..... : ");
scanf("%d", &choice);
}
return start;
}
struct node *display(struct node *start)
{ struct node *ptr;
ptr = start;
printf("\nPNR\tSOURCE\tDESTINATION\tAGE\tNAME\t\tFARE\n");
while(ptr != NULL)
{
printf("%d\t", ptr -> pnr);
printf("Mumbai\t");
if(ptr->route==1)
printf("Delhi\t\t");
else if(ptr->route==2)
printf("Chennai\t\t");
else if(ptr->route==3)
printf("Kolkata\t\t");
printf("%d\t", ptr -> age);
printf("%s\t\t", ptr -> name);
printf("%d\n", ptr -> fare);
ptr = ptr -> next;
}
return start;
}

struct node *insert_end(struct node *start)
{
struct node *ptr, *new_node;
int num,j=1;
while(j==1)
{printf("Enter your route\n1. Mumbai-Delhi\n2. Mumbai-Chennai\n3. Mumbai-Kolkata:");
 scanf("%d",&r);
 printf("\nEnter the name:");
 scanf("%s",&st);
 printf("\nEnter the age : ");
 scanf("%d", &num);
if(r==1)
 { if(num>=60)
     f=460;
      else
     f=650;
 }
 else
 if(r==2)
 { if(num>=60)
     f=375;
      else
     f=500;
 }
 else
 { if(num>=60)
     f=690;
      else
     f=750;
 }
new_node = (struct node *)malloc(sizeof(struct node));
new_node->route=r;
new_node -> age=num;
new_node -> pnr=k;
strcpy(new_node->name,st);
new_node ->fare=f;
k++;
new_node -> next = NULL;
ptr = start;
while(ptr -> next != NULL)
ptr = ptr -> next;
ptr -> next = new_node;
printf("Press 1 to continue Reservation.....:");
scanf("%d",&j);
}
return start;
}





struct node *delete_node(struct node *start)
{
struct node *ptr, *preptr;
int val;
printf("\nEnter the PNR number of the ticket to be cancelled : ");
scanf("%d", &val);
ptr = start;
if(ptr ->pnr  == val)
{
start = delete_beg(start);
printf("The ticket with PNR %d has been cancelled\n",val);
return start;
}
else
{ while(ptr -> pnr != val)
  {
     preptr = ptr;
     ptr = ptr -> next;
  }

  printf("The ticket with PNR %d has been cancelled\n",val);
  preptr -> next = ptr -> next;
  free(ptr);

return start;
}
}
struct node *delete_beg(struct node *start)
{
struct node *ptr;
ptr = start;
start = start -> next;
free(ptr);
return start;
}

