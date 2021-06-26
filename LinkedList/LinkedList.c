#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode ListNode;     //Forward declaration
ListNode* head = NULL;              //Head of Linkedlist (Global)

struct ListNode{
    int val;
    struct ListNode* next;
};

ListNode* creatNode(int x)
{
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->val = x;
    new_node->next = NULL;
    
    return new_node;
}

void printList()
{
    if(head == NULL){
        printf("Linked list is empty\n");
    }else{
        ListNode *current = head;
        printf("Linked list: ");
        while (current != NULL)
        {
            printf("%d -> ", current->val);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void push_back(int x)
{
    ListNode *new_node = creatNode(x);
    
    if (head == NULL){
        head = new_node;
        printf("Success!\n");
    }else{
        ListNode *current = head;
        
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_node;
        printf("Success!\n");
    }
}

void push_front(int x)
{
    ListNode* new_node = creatNode(x);
    if(head == NULL){
        head = new_node;
    }else{
        new_node->next = head;
        head = new_node;
    }
}

void delete(int x)
{
    if(head == NULL){
        printf("Linked list is empty\n");
    }else{
        ListNode* current = head;
        ListNode* previous = NULL;
        
        while(current != NULL && current->val != x){
            previous = current;
            current = current->next;
        }

        if(current == NULL){
            printf("There is no %d in linked list\n", x);
        }else if(current == head){
            head = current->next;
            free(current);
        }else{
            previous->next = current->next;
            free(current);
        }
    }
}

void insertAfterList(struct ListNode* ptr, int x)
{
    ListNode* new_node = creatNode(x);

    new_node->next = ptr->next;
    ptr->next = new_node;
}

void insertBeforeheadList(struct ListNode** head, int x)
{
    ListNode* new_node;
    new_node = creatNode(x);

    new_node->next = *head;
    *head = new_node;

    //概念同Call by address的SWAP
    //如果要Call by value就使用return回傳
}

int main()
{
    int option = 0;
    int val = 0;
    int flag = 1;
    printf("(1) Push back\n");
    printf("(2) Push front\n");
    printf("(3) Insert x (Node: head -> x)\n");
    printf("(4) Delete\n");
    printf("(5) Print this link\n");
    printf("(6) Quit\n");
    while (flag){
        printf("Enter your option: ");
        scanf("%d", &option);
        switch(option)
        {
            case 1: //Push one node at the end of the linked list
                printf("Enter node value: ");
                scanf("%d", &val);
                push_back(val);
                break;
            case 2: //Push one node at the front of the linked list
                printf("Enter node value: ");
                scanf("%d", &val);
                push_front(val);
                break;
            case 3: //Insert

                break;
            case 4: //Delete
                printf("Enter node value: ");
                scanf("%d", &val);
                delete(val);
                break;
            case 5: //Print
                printList();
                break;
            case 6: //Exit
                flag = 0;
                break;
            default:
                break;
        }
    }
    
    free(head);
    return 0;
}