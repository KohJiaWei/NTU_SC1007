#include <stdio.h>
#include <stdlib.h>

//structure definition
typedef struct node{
int data;
struct node *next;
}list_nodes;

//list of functions
void clear(list_nodes *head);
int removeNode(list_nodes **ptrHead, int index);
void print_list(list_nodes *head);
list_nodes* find_node(list_nodes* cur, int index);

//start of main
int main(){
list_nodes *temp, *head = NULL;
list_nodes **pointerhead;
int i = 0, index = 0;

printf("Enter a list of numbers, terminated by any non-digit character:\n");
while(scanf("%d",&i)){
if (head == NULL){
    head = (list_nodes *)malloc(sizeof(list_nodes));
    temp = head;
}
else{
    temp->next = (list_nodes *)malloc(sizeof(list_nodes));
    temp = temp->next;
}
temp->data = i;
}
temp->next = NULL;

pointerhead = &head;
printf("Enter the index of the node to be removed:\n");
scanf("%d",&index);

removeNode(pointerhead, index);

print_list(head);
clear(head);
return 0;
}


//////
//
int removeNode(list_nodes **ptrhead, int index){
list_nodes *current, *temp, *head;
current = *ptrhead;
temp = *ptrhead;
head = *ptrhead;
int i = 0;

while(i<index){
    if(i>0){//delays to access the previous node
    temp = temp->next;
    }
    if(i==index){
    current = current->next;
    temp->next = current;
    printf("After the removal operation, Current List:");
    print_list(head);
    return 1;
    }
    else{
    current = current->next;
}
i++;
}
return 0;
}





void clear(list_nodes *head){
list_nodes *temp;
temp = head;
while(temp != NULL){
    free(temp);
    temp = temp->next;
}
}

void print_list(list_nodes *head){
list_nodes *temp;
temp = head;
printf("Current List: ");
while(temp!=NULL){
    printf("%d ",temp->data);
temp = temp->next;

}printf("\n");
}


/*
list_nodes* find_node(list_nodes* cur, int index){
if(cur==NULL || index <0){
    return NULL;
}
while(index>0){
    cur = cur->next;
    if (cur==NULL){
        return NULL;
        index--;
    }
}
}
*/
