#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};


int main() {
    struct node* head = (struct node*)malloc(sizeof(struct node));



    insert_node(&head, 0, 3);
    print_list(head);
    insert_node(&head, 3, 2);
    insert_node(&head, 2, 4);
    insert_node(&head, 1, 4);
    print_list(head);
    delete_node(&head, 1);
    print_list(head);
    delete_node(&head, 2);
    print_list(head);
}


void insert_node(struct node** head, int after, int val) {
    if (*head == NULL || after == 0) {
        (*head)->data = val;
        (*head)->next = NULL;
        return;
    }
    struct node* current = *head;
    struct node* add = (struct node*)malloc(sizeof(struct node));
    add->data = val;

    while (current->data != after) {
        if (current->next == NULL) {
            printf("Do not exist %d value to insert %d\n", after, val);
            return;
        }
        current = current->next;

    }

    add->data = val;
    add->next = current->next;
    current->next = add;
    return;
}


void delete_node(struct node** head, int pos) {
    struct node* current = *head;
    struct node* prev = NULL;
    int p = pos;
    if (pos == 1) {
        *head = current->next;
        printf("Deleted value %d from %d index\n", current->data, p);
        free(current);
        return;
    }

    while (--pos) {
        prev = current;
        current = current->next;
    }

    prev->next = current->next;
    printf("Deleted value %d from %d index\n", current->data, p);
    free(current);
}


void print_list(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
