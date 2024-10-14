#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;                                  //declaring pointer of Node data type
}Node;

int main(){
    printf("Enter the number of Nodes you want: ");
    int n;
    scanf("%d",&n);

    Node *head = NULL;
    Node *temp = NULL;                                 //Temp is needed for linking address to the previous carriage
    Node *newNode = NULL;

    for (int i = 0;i< n; i++){
        newNode = (Node*)malloc(sizeof(Node));
        printf("Enter the data: ");
        int data;
        scanf("%d",&newNode->data);
        newNode->next = NULL;                         //The newNode points to nothing as it the last element
        
        if (head == NULL){
            head = newNode;                           //Head always points to the First Node
        }
        else{
            temp->next = newNode;                     //temp makes the previous node to point the newly created node (Old newNode -> New newNode)
        }
        temp = newNode;                               // After pointing it jumps on to the New newNode
    }

    printf("The linked list is: \n");
    temp = head;                                      //temp is initialised to head ( which is pointing to the firstNode)
    while (temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\0");
}
