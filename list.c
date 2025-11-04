#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* next;
};

void addNode(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void sortList(struct Node* head) {
    if (head == NULL || head->next == NULL) return;
    int swapped;
    struct Node* ptr;
    do {
        swapped = 0;
        ptr = head;
        while (ptr->next != NULL) {
            if (ptr->data > ptr->next->data) {
                int tmp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = tmp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
    } while (swapped);
}

void clearList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head->next;
        free(head);
        head = temp;
    }
}

int main() {
    srand((unsigned)time(NULL));
    int n;
    printf("Введите размер списка: ");
    scanf("%d", &n);
    struct Node* head = NULL;
    for (int i = 0; i < n; i++)
        addNode(&head, rand() % 100);
    printf("\nИсходный список: ");
    printList(head);
    sortList(head);
    printf("\nСписок после сортировки: ");
    printList(head);
    clearList(head);
    return 0;
}
