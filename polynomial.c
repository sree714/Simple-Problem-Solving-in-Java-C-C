#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int cof;
    int exp;
    struct node *link;
};

typedef struct link {
    int coeff;
    int pow;
    struct link * next;
} my_poly;

struct node *create(struct node *q);
struct node *insert(struct node *ptr, struct node *p);
void display(char const *tag, struct node *ptr);
void err_exit(char const *tag);
void my_create_poly(my_poly **);
void startAddPoly();
void my_show_poly(my_poly *);
void my_add_poly(my_poly **, my_poly *, my_poly *);


void startAddPoly()
{
    int ch;
    do {
        my_poly * poly1, * poly2, * poly3;

        printf("\nCreate 1st expression\n");
        my_create_poly(&poly1);
        printf("\nStored the 1st expression");
        my_show_poly(poly1);

        printf("\nCreate 2nd expression\n");
        my_create_poly(&poly2);
        printf("\nStored the 2nd expression");
        my_show_poly(poly2);

        my_add_poly(&poly3, poly1, poly2);
        my_show_poly(poly3);

        printf("\nAdd two more expressions? (Y = 1/N = 0): ");
        scanf("%d", &ch);
        scanf("%d", &ch);
    } while (ch);
}

void my_create_poly(my_poly ** node) {
    int flag;
    int coeff, pow;
    my_poly * tmp_node;
    tmp_node = (my_poly *) malloc(sizeof(my_poly));
    *node = tmp_node;
    do {
        printf("\nEnter Coeff:");
        scanf("%d", &coeff);
        tmp_node->coeff = coeff;
        printf("\nEnter Pow:");
        scanf("%d", &pow);
        tmp_node->pow = pow;



        tmp_node->next = NULL;

        //Ask user for continuation
        printf("\nContinue adding more terms to the polynomial list?(Y = 1/N = 0): ");
        scanf("%d", &flag);
        //printf("\nFLAG: %c\n", flag);
        //Grow the linked list on condition
        if(flag) {
            tmp_node->next = (my_poly *) malloc(sizeof(my_poly)); //Grow the list
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    } while (flag);
}

void my_show_poly(my_poly * node) {
    printf("\nThe polynomial expression is:\n");
    while(node != NULL) {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if(node != NULL)
            printf(" + ");
    }
}


void my_add_poly(my_poly ** result, my_poly * poly1, my_poly * poly2) {
    my_poly * tmp_node; //Temporary storage for the linked list
    tmp_node = (my_poly *) malloc(sizeof(my_poly));
    tmp_node->next = NULL;
    *result = tmp_node; //Copy the head address to the result linked list

    //Loop while both of the linked lists have value
    while(poly1 && poly2) {
        if (poly1->pow > poly2->pow) {
            tmp_node->pow = poly1->pow;
            tmp_node->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow) {
            tmp_node->pow = poly2->pow;
            tmp_node->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else {
            tmp_node->pow = poly1->pow;
            tmp_node->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        //Grow the linked list on condition
        if(poly1 && poly2) {
            tmp_node->next = (my_poly *) malloc(sizeof(my_poly));
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    }

    //Loop while either of the linked lists has value
    while(poly1 || poly2) {
        //We have to create the list at beginning
        //As the last while loop will not create any unnecessary node
        tmp_node->next = (my_poly *) malloc(sizeof(my_poly));
        tmp_node = tmp_node->next;
        tmp_node->next = NULL;

        if(poly1) {
            tmp_node->pow = poly1->pow;
            tmp_node->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if(poly2) {
            tmp_node->pow = poly2->pow;
            tmp_node->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
    }

    printf("\nAddition Complete");
}



struct node *create(struct node *q) {
    int i, n;
    printf("enter the number of nodes: ");
    if (scanf("%d", &n) != 1)
        err_exit("Read error (number of nodes)");
    for (i = 0; i < n; i++) {
        struct node *ptr = (struct node *) malloc(sizeof(struct node));
        if (ptr == 0)
            err_exit("Out of memory (1)");
        printf("enter the coefficient and exponent respectively: ");
        if (scanf("%d%d", &ptr->cof, &ptr->exp) != 2)
            err_exit("Read error (coefficient and exponent)");
        ptr->link = NULL;
        q = insert(ptr, q);
        display("after input", q);
    }
    return q;
}

struct node *insert(struct node *ptr, struct node *p) {
    struct node *temp, *b;
    if (p == NULL)
        p = ptr;
    else {
        display("insert: p   = ", p);
        display("insert: ptr = ", ptr);
        if (p->exp < ptr->exp) {
            ptr->link = p;
            p = ptr;
        } else {
            temp = p;
            while ((temp->link != NULL) && (temp->link->exp < ptr->exp))
                display("insert: tmp = ", temp),
                        temp = temp->link;
            display("insert: post loop", temp);
            b = temp->link;
            temp->link = ptr;
            ptr->link = b;
        }
    }
    return p;
}

void display(char const *tag, struct node *ptr) {
    struct node *temp;
    const char *pad = "";
    temp = ptr;
    printf("%s: ", tag);
    while (temp != NULL) {
        printf("%s%d x ^ %d", pad, temp->cof, temp->exp);
        temp = temp->link;
        pad = " + ";
    }
    putchar('\n');
}
struct node *p1 = NULL;
void creatPolynomial() {
    printf("enter the first polynomial:\n");;
    p1 = create(p1);
}

int main() {
    while (1) {
        int choice;
        printf("\nEnter your choice: ");
        printf("\n1.create a polynomial\n2.display a polynomial\n3.add two polynomials\n4.Exit\n");
        scanf("%d", &choice);
        if (choice == 4)
            exit(0);
        else if(choice == 1)
            creatPolynomial();
        else if(choice == 2)
            display("p1",p1);
        else if(choice == 3)
            startAddPoly();
        else
            printf("Wrong choice");
    }
    return 0;
}

void err_exit(char const *tag) {
    fprintf(stderr, "%s\n", tag);
    exit(1);
}











