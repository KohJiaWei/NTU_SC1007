#include <stdio.h>
#include <stdlib.h>

//structure definition
typedef struct node{
int data;
struct node *next;
}list_nodes;


//list of functions
void clear(list_nodes *head);
int removeNode2(list_nodes *ll, int index);
void print_list(list_nodes *head);
list_nodes* find_node(list_nodes* cur, int index);



//start of main
int main(){
list_nodes *temp, *head = NULL;
list_nodes **pointerhead;
int i = 0, index = 0;

printf("Enter a list of numbers, terminated by any non-digit character:\n");
while(scanf("%d",&i)){
if(i==-1){
    break;
}
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


while(1){
printf("Enter the index of the node to be removed:\n");
scanf("%d",&index);
removeNode2(*pointerhead, index);
print_list(head);
}




clear(head);
return 0;
}


//////
//

int removeNode2(list_nodes *ll, int index){

list_nodes *current, *pre, *head;
current = ll;
head = ll;

current = find_node(head, index);
if(current != NULL){
    if (index == 0){
        current = current->next;
        free(current);
        return 1;
    }
    else{
        pre = find_node(head,index-1);
        pre->next = current->next;
        free(current);
        return 1;
    }
}else{
    return 0;
}

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



list_nodes* find_node(list_nodes* cur, int index){
if(cur==NULL || index <0){
    return NULL;
}
while(index>0){
    cur = cur->next;
    if(cur==NULL){
        return NULL;
    }
        index--;
}
return cur;
}
