#include <stdio.h>

// Write a function to reverse pairs of elements in a linked list. For example,
//     A --> B --> C --> D --> E
// shoud become
//     B --> A --> D --> C --> E

struct node {
    char val;
    struct node* next;
};

void print(struct node* head) {
    while (head) {
        printf("%c --> ", head->val);
        head = head->next;
    }
    printf("\n");
}

struct node* swap(struct node* a, struct node* b) { 
    if (b) {
        b->next = a;
        a->next = 0;
        return b;
    }
    a->next = 0;
    return a;
}

struct node* reverse(struct node* head) {
    struct node* p = head;
    struct node* q = 0;
    head = 0;
    
    while(1) {
        struct node* a = p ? p : 0;
        if (a) p = p->next;
        struct node* b = p ? p : 0;
        if (b) p = p->next;

        if (!a && !b) {
            break;
        }

        struct node* c = swap(a, b);
        if (!head) {
            q = c;
            head = c;
        } else {
            q->next = c;
        }
        q = q->next;
        if (q->next)
            q = q->next;           
    }

    return head;
}

int main() {
    struct node e = {.val='E', .next=0};
    struct node d = {.val='D', .next=&e};
    struct node c = {.val='C', .next=&d};
    struct node b = {.val='B', .next=&c};
    struct node a = {.val='A', .next=&b};
    struct node* r = &a;
    print(r);
    r = reverse(r);
    print(r);
    return 0;
}