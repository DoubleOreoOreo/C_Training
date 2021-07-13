#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode ListNode;
struct ListNode{
    int val;
    struct ListNode *next;
};

ListNode* creatNode(int x)
{
    ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
    newnode->val = x;
    newnode->next = NULL;

    return newnode;
}

ListNode* push_back(struct ListNode* head, int x)
{
    ListNode *new_node = creatNode(x);
    
    if (head == NULL){
        head = new_node;
    }else{
        ListNode *current = head;
        
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_node;
    }
    return head;
}

void printList(struct ListNode* head)
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

ListNode* inputData1()
{
    ListNode *l1 = NULL;
    
    //l1 = push_back(l1, 2);
    //l1 = push_back(l1, 4);
    //l1 = push_back(l1, 3);

    l1 = push_back(l1, 9);
    l1 = push_back(l1, 9);
    l1 = push_back(l1, 9);
    l1 = push_back(l1, 9);
    l1 = push_back(l1, 9);
    l1 = push_back(l1, 9);
    l1 = push_back(l1, 9);
    
    return l1;
}

ListNode* inputData2()
{
    ListNode *l2 = NULL;

    //l2 = push_back(l2, 5);
    //l2 = push_back(l2, 6);
    //l2 = push_back(l2, 4);
    
    l2 = push_back(l2, 9);
    l2 = push_back(l2, 9);
    l2 = push_back(l2, 9);
    l2 = push_back(l2, 9);

    return l2;
}

ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head    = NULL;
    struct ListNode *current = NULL;
    struct ListNode *add     = NULL;
    int carry = 0;
    int sum   = 0;

    while(l1 != NULL || l2 != NULL || carry != 0)
    {
        sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);

        carry = (sum >= 10) ? 1 : 0;
        sum = (sum >= 10) ? sum-10 : sum;

        if(head == NULL){
            current = creatNode(sum);
            head = current;
        }else{
            add = creatNode(sum);
            current->next = add;
            current = current->next;
        }
        
        if(l1)
            l1 = l1->next;
        if(l2)
            l2 = l2->next;
    }

    return head;
}

int main()
{
    ListNode *l1 = inputData1();
    ListNode *l2 = inputData2();

    printList(l1);
    printList(l2);
    ListNode *sum = addTwoNumbers(l1, l2);
    printList(sum);
    //printList(l2);

    return 0;
}