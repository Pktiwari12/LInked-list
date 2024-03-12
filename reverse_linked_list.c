#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
};
void reverse_linked_list(struct node**);
int main()
{
    struct node*head;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;
    struct node*current;
    current = (struct node*)malloc(sizeof(struct node));
    current->data = 46;
    current->link = NULL;
    head->link = current;
    /*current = (struct node*)malloc(sizeof(struct node));
    current->data = 47;
    current->link = NULL;
    head->link->link = current;
    current = (struct node*)malloc(sizeof(struct node));
    current->data = 48;
    current->link = NULL;
    head->link->link->link = current;
    current = (struct node*)malloc(sizeof(struct node));
    current->data = 49;
    current->link = NULL;
    head->link->link->link->link = current;*/
    // For printing
    current = head;
    while(current != NULL)
    {
        printf("%d\t",current->data);
        current = current->link;
    }
    printf("\n");
    reverse_linked_list(&head);
    // For printing
    current = head;
    while(current != NULL)
    {
        printf("%d\t",current->data);
        current = current->link;
    }


}
void reverse_linked_list(struct node**head1)
{
    if(*head1 == NULL)
    {
        printf("linked list is empty . ");
        exit(0);
    }
	
    struct node*temp;
    struct node*pre=NULL;
    struct node*front;
    temp = *head1;
    front = *head1;
    while(temp != NULL)
    {
        front = temp->link;
        temp->link = pre;
        pre = temp;
        temp = front;
    }
    if(temp == NULL)
    {
        *head1 = pre;
    }
}