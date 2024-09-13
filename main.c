#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct {
    struct Node *head;
    struct Node *tail;
    int length;
} SinglyLinkedList;

void push(SinglyLinkedList *list, const int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list->length == 0) {
        list->head = newNode;
        list->tail = list->head;
    } else {
        struct Node *temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        list->tail = newNode;
    }
    list->length++;
}

void pop(SinglyLinkedList *list) {
    if (list->length == 0) {
        return;
    }
    struct Node *temp = list->head;
    if (list->length == 1) {
        list->head = NULL;
        list->tail = NULL;
        free(temp);
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    struct Node *del = temp->next;
    temp->next = NULL;
    list->tail = NULL;
    list->length--;
    free(del);
}

void unshift(SinglyLinkedList *list, const int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (list->length == 0) {
        newNode->next = NULL;
        list->head = newNode;
        list->tail = list->head;
    } else {
        struct Node *temp = list->head;
        newNode->next = temp;
        list->head = newNode;
    }
    list->length++;
}

void shift(SinglyLinkedList *list) {
    if (list->length == 0) {
        return;
    }
    struct Node *temp = list->head;
    list->head = temp->next;
    list->length--;
    free(temp);
}

void get(const SinglyLinkedList *list, int index) {
    if (index < 0 || index >= list->length) {
        return;
    }
    const struct Node *temp = list->head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    printf("founded: [%d]\n", temp->data);
}

void set(const SinglyLinkedList *list, const int index, const int data) {
    if (index < 0 || index >= list->length) {
        return;
    }
    struct Node *temp = list->head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    temp->data = data;
}

void insert(SinglyLinkedList *list, const int index, const int data) {
    if (index < 0 || index >= list->length) {
        return;
    }
    if (index == 0) {
        unshift(list, data);
        return;
    }
    if (index == list->length - 1) {
        push(list, data);
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node *temp = list->head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    list->length++;
}

void removeNode(SinglyLinkedList *list, const int index) {
    if (index < 0 || index >= list->length) {
        return;
    }
    if (index == 0) {
        shift(list);
        return;
    }
    if (index == list->length - 1) {
        pop(list);
        return;
    }
    struct Node *temp = list->head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    struct Node *del = temp->next;
    temp->next = del->next;
    list->length--;
    free(del);
}

void reverseToArray(const SinglyLinkedList *list) {
    if (list->length == 0) {
        return;
    }
    int reverseArray[list->length];
    const struct Node *temp = list->head;
    for (int i = list->length - 1; i >= 0; i--) {
        reverseArray[i] = temp->data;
        temp = temp->next;
    }
    for (int i = 0; i < list->length; i++) {
        printf("[%d] -> ", reverseArray[i]);
    }
    printf("\n");
}

void traverse(const SinglyLinkedList *list) {
    struct Node *temp = list->head;
    while (temp != NULL) {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(void)
{
    SinglyLinkedList list;
    list.length = 0;
    push(&list, 1);
    push(&list, 2);
    push(&list, 3);
    push(&list, 4);
    traverse(&list);
    pop(&list);
    pop(&list);
    pop(&list);
    traverse(&list);
    unshift(&list, 10);
    unshift(&list, 20);
    unshift(&list, 30);
    unshift(&list, 40);
    traverse(&list);
    shift(&list);
    shift(&list);
    traverse(&list);
    get(&list, 1);
    set(&list, 2, 30);
    traverse(&list);
    insert(&list, 1, 15);
    traverse(&list);
    insert(&list, 0, 25);
    traverse(&list);
    insert(&list, 4, 45);
    traverse(&list);
    removeNode(&list, 5);
    traverse(&list);
    removeNode(&list, 0);
    traverse(&list);
    removeNode(&list, 1);
    traverse(&list);
    reverseToArray(&list);
    return 0;
}
