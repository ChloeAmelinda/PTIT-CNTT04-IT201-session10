#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation error");
        exit(-1);

    }

    temp->data = data;
    temp->next = NULL;
    return temp;
}
struct Node* createLinkedList() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    printf("Enter the number of nodes in the linked list:\n ");
    for (int i = 1; i <= 5; i++) {
        int data;
        printf("node %d:",i);
        scanf("%d", &data);
        struct Node* node = createNode(data);
        if (head == NULL) {
            head = node;
            temp = node;
        }else {
            temp->next = node;
            temp = node;
        }
    }
    return head;
}
void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    int count = 1;
    printf("\n Linked List:");
    while (temp != NULL) {
        printf("%d ",temp->data);
        if (temp->next != NULL) {
            printf("\t");
        }
        temp = temp->next;
        count++;
    }
}
void deleteNode(struct Node** head) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    temp->next = NULL;
}
int main(void) {
    struct Node* head = createLinkedList();
    printLinkedList(head);
    deleteNode(&head);
    printLinkedList(head);
    return 0;
}