// NTU LINKED LIST TUTORIAL Q1

/*
Implement the removeNode() function for a linked list, using the lecture
diagrams and pseudo-code as a reference. The prototype of the removeNode()
function is given below:
int removeNode(ListNode **ptrHead, int index);
The function should return 1 if the delete operation is successful and 0 otherwise.
Recall that the function requires a pointer to the head pointer in order to
correctly delete the first node.
Write a program to test the removeNode() function. It should first allow the
user to create a linked list of integers by appending values to the end of the list.
Next, it should allow the user to delete nodes one by one based on their indices.
The program can be terminated by providing an out-of-range index to delete the
node.
Sample inputs and outputs:
Enter a list of numbers, terminated by any non-digit character:
1
2
3
4
5
a
Current List: 1 2 3 4 5
Enter the index of the node to be removed: 0
After the removal operation,
Current List: 2 3 4 5
Enter the index of the node to be removed: 3
After the removal operation,
Current List: 2 3 4
Enter the index of the node to be removed: 1
After the removal operation,
Current List: 2 4
Enter the index of the node to be removed: 3
The node cannot be removed.
Current List: 2 4

*/

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
removeNode(pointerhead, index);
print_list(head);
}

clear(head);
return 0;
}


//////
//
int removeNode(list_nodes **ptrhead, int index){
list_nodes *current, *pre, *head;
current = *ptrhead;
head = *ptrhead;

current = find_node(head, index);
if(current != NULL){
    if (index == 0){
        *ptrhead = current->next;
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


