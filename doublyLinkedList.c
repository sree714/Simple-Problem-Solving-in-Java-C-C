#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *previous;
    struct node *next;
};


struct node *head, *tail = NULL;
struct node *current = NULL;
int n = 0;

void remove_data(int data) {
    int pos = 0;
    struct node *pre_node;

    if (head == NULL) {
        printf("Linked List not initialized");
        return;
    }

    if (head->data == data) {
        if (head->next != NULL) {
            head->next->previous = NULL;
            head = head->next;
            return;
        } else {
            head = NULL;
            printf("List is empty now");
            return;
        }
    } else if (head->data != data && head->next == NULL) {
        printf("%d not found in the list\n", data);
        return;
    }

    current = head;

    while (current->next != NULL && current->data != data) {
        pre_node = current;
        current = current->next;
    }

    if (current->data == data) {
        pre_node->next = pre_node->next->next;

        if (pre_node->next != NULL) {          // link back
            pre_node->next->previous = pre_node;
        } else
            tail = pre_node;

        free(current);
    } else
        printf("%d not found in the list.", data);

}

void addNode(int data) {
    //Create a new node
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;

    //If list is empty
    if (head == NULL) {
        //Both head and tail will point to newNode
        head = tail = newNode;
        //head's previous will point to NULL
        head->previous = NULL;
        //tail's next will point to NULL, as it is the last node of the list
        tail->next = NULL;
    } else {
        //newNode will be added after tail such that tail's next will point to newNode
        tail->next = newNode;
        //newNode's previous will point to tail
        newNode->previous = tail;
        //newNode will become new tail
        tail = newNode;
        //As it is last node, tail's next will point to NULL
        tail->next = NULL;
    }
}

//sortList() will sort the given list in ascending order
void sortList() {
    struct node *current = NULL, *index = NULL;
    int temp;
    //Check whether list is empty
    if (head == NULL) {
        return;
    } else {
        //Current will point to head
        for (current = head; current->next != NULL; current = current->next) {
            //Index will point to node next to current
            for (index = current->next; index != NULL; index = index->next) {
                //If current's data is greater than index's data, swap the data of current and index
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
            }
        }
    }
}

void sort(int arr[], int size) {

}

//display() will print out the nodes of the list
void display() {
    int store[100], i = 0;
    //Node current will point to head
    struct node *current = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (current != NULL) {
        //Prints each node by incrementing pointer.
        //printf("%d ", current->data);
        store[i] = current->data;
        i++;
        current = current->next;
    }


    for (int step = 0; step < i; ++step) {
        for (int j = 0; j < i - step; ++j) {

            // To sort in descending order, change">" to "<".
            if (store[j] > store[j + 1]) {

                // swap if greater is at the rear position
                int temp = store[j];
                store[j] = store[j + 1];
                store[j + 1] = temp;
            }
        }
    }

    for (int j = 0; j < i; ++j) {
        printf("%d \t", store[j]);
    }
}

void removeData(int data, int n) {
    //Node current will point to head
    int store[n], i = 0;
    struct node *current = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (current != NULL) {
        store[i] = current->data;
        i++;
        current = current->next;
    }

    for (int i = 0; i < n; i++) {
        if (store[i] == data) {
            remove_data(data);
        }
    }
}

int main() {


    while (1) {
        int choice;
        printf("1. Create List\n");
        printf("2. Delete list\n");
        printf("3. Display list\n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if (choice == 1) {
            int temp;
            printf("Enter the number of elements: ");
            scanf("%d", &temp);
            n = n + temp;
            int arr[n];
            for (int i = 0; i < temp; i++) {
                scanf("%d", &arr[i]);
            }
            for (int i = 0; i < temp; i++) {
                addNode(arr[i]);
            }
            temp = 0;
        } else if (choice == 0)
            exit(0);
        else if (choice == 3) {
            display();
            printf("\n\n");
        } else if (choice == 2) {
            int data;
            printf("Enter the data: ");
            scanf("%d", &data);
            removeData(data, n);
        } else
            printf("Wrong choice");
    }


    return 0;
}
