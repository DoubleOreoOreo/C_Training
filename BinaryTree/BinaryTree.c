#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode ListNode;     //Forward declaration
//ListNode* head = NULL;              //Head of Linkedlist (Global)

struct ListNode{
    int val;
    struct ListNode* next;
};

ListNode* creatNode(int x)
{
    ListNode *new_node = NULL;
    new_node = (struct ListNode*)malloc(sizeof(struct ListNode));

    new_node->val = x;
    new_node->next = NULL;

    return new_node;
}

void printList(struct ListNode* head)
{
    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
}

void insertAfterList(struct ListNode* ptr, int x)
{
    ListNode* new_node;
    new_node = creatNode(x);

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

void deleteList(struct ListNode* n, int x)
{
    //待補
}

int main()
{
    ListNode* head = NULL;
    ListNode* second = NULL;
    ListNode* third = NULL;

    head = creatNode(0);
    second = creatNode(1);
    third = creatNode(2);

    head->next = second;
    second->next = third;

    insertAfterList(third, 10);
    insertBeforeheadList(&head, 11);
    
    printList(head);
    free(head);
    return 0;
}