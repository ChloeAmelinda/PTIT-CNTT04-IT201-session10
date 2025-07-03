#include <stdio.h>

//cau truc
struct Node {
    int data;
    struct Node *next;
};
//ham tao Node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation error");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}
//ham tao lien ket vs nhap ptu
struct Node* createLinkedList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    printf("Enter the number of nodes you want to add: \n");
    for (int i = 0; i < n; i++) {
        int data;
        printf("%d: ",i+1);
        scanf("%d", &data);
        struct Node* node = createNode(data);
        if (head == NULL) {
            head = node;
            temp = node;
        }
        else {
            temp->next = node;
            temp = temp->next;
        }
    }
    return head;

}
void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        if (temp->next != NULL) {
            temp = temp->next;
            printf("\t");
        }
        temp = temp->next;

    }
    printf("\n");
}
void searchNode(struct Node* head,int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    int count = 1;
    struct Node* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (temp->data == position) {
            printf("%d is found at position %d\n",temp->data,count);
            found = 1;

        }
        temp = temp->next;
        count++;
    }
    if (!found) {
        printf("%d is not found at position %d\n",temp->data,position);

    }
}
int main(void) {
    int n=0;
    while(n<=0) {
        printf("Enter the number of nodes you want to add: \n");
        scanf("%d", &n);
        if (n<=0) {
            printf("Nhap lai");
        }
    }
    struct Node* head = createLinkedList(n);
    printLinkedList(head);
    int search ;
    printf("Enter the element you want to search: \n");
    scanf("%d", &search);
    searchNode(head,search);
    return 0;
}