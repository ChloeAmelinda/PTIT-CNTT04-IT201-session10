#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *createNode(int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation error");
        exit(1);
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}
struct Node* createLinkedList(int size) {
    struct Node *head = NULL;
    struct Node *temp = NULL;
    for (int i = 0; i < size; i++) {
        int data;
        printf("node %d:",i+1);
        scanf("%d", &data);
        struct Node *node = createNode(data);
        if (head == NULL) {
            head = node;
            temp = node;
        }else {
            temp->next = node;
            temp = temp->next;
        }
    }
    return head;
}
void printLinkedList(struct Node *head) {
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        if (temp->next != NULL) {
            printf("\t");
        }
        temp = temp->next;
    }
    printf("\n");
}
void deleteNode(struct Node** head, int position) {

   if (*head == NULL) {
       return;
   }
    struct Node *temp = *head;
    struct Node *prev = NULL;

    while (temp != NULL ) {
        if (temp->data == position) {
            if (temp == *head) {
                *head = temp->next;
                free(temp);
                temp= *head;
            }else {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        }else {
            prev = temp;
            temp = temp->next;
        }
    }

}

    int main(void) {
        int n=0;
        while (n<=0) {
            printf("Please enter a number: ");
            scanf("%d", &n);
            if (n<=0) {
                printf("Nhap lai");
            }
        }
        struct Node *head = createLinkedList(n);
        printLinkedList(head);
        int positionDelete ;
        printf("Nhap positionDelete : ");
        scanf("%d", &positionDelete);
        deleteNode(&head, positionDelete);
        printLinkedList(head);

        return 0;
    }
