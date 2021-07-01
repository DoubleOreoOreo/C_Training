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

void clear()
{
    while(head != NULL){
        ListNode *current = head;
        head = current->next;
        free(current);
    }
    printf("All nodes are removed!\n");
}

void insert(int x, int y)
{
    /*ListNode *new_node = creatNode(x);
    
    if (head == NULL){
        printf("Insertion fail, Linked list is empty!\n");
    }else{
        ListNode *current = head;
        
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_node;
        printf("Success!\n");
    }*/
}

void reverse()
{
    if(head == NULL || head->next == NULL)
        printf("Linked list is empty or Linked list only has one node!");
    else{
        ListNode* previous = NULL;
        ListNode* current = head;
        ListNode* following = head->next;

        while(following != NULL)
        {
            current->next = previous;
            previous = current;
            current = following;
            following = following->next;
        }
        current->next = previous;
        head = current;
    }
}

int main()
{
    int option = 0;
    int val = 0;
    int flag = 1;
    printf("(1) Push back\n");
    printf("(2) Push front\n");
    printf("(3) Insert x (Node: head -> x)\n");
    printf("(4) Reverse\n");
    printf("(5) Delete\n");
    printf("(6) Clear\n");
    printf("(7) Print this link\n");
    printf("(8) Quit\n");

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
            case 4: //Reverse
                reverse();
                break;
            case 5: //Delete
                printf("Enter node value: ");
                scanf("%d", &val);
                delete(val);
                break;
            case 6: //Clear
                clear();
                break;
            case 7: //Print
                printList();
                break;
            case 8: //Exit
                flag = 0;
                break;
            default:
                break;
        }
    }
    
    free(head);
    return 0;
}