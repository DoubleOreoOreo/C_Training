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

void printMiddle()
{
    ListNode *slow_ptr = head;
    ListNode *fast_ptr = head;

    if(head == NULL){
        printf("Linked list is empty\n");
    }else{
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is %d\n", slow_ptr->val);
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

void Sort()
{
    if(head == NULL)
        printf("Empty!\n");
    else{
        ListNode *node=NULL, *temp = NULL;
        int tempvar;//temp variable to store node data
        node = head;
        //temp = node;//temp node to hold node data and next link
        while(node != NULL)
        {
            temp=node; 
            while (temp->next !=NULL)//travel till the second last element 
            {
            if(temp->val > temp->next->val)// compare the data of the nodes 
                {
                tempvar = temp->val;
                temp->val = temp->next->val;// swap the data
                temp->next->val = tempvar;
                }
            temp = temp->next;    // move to the next element 
            }
            node = node->next;    // move to the next node
        }
    }
}

void pop()
{
    if(head==NULL)
        printf("Empty");
    else{
        ListNode *current = head;

        head = head->next;
        free(current);
    }
}

void pop_back()
{
    if(head==NULL)
        printf("Empty");
    else{
        ListNode *current = head;
        ListNode *pervious = NULL;

        while(current->next != NULL){
            pervious = current;
            current = current->next;
        }
        pervious->next = NULL;
        free(current);
    }
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

void sorting_BubbleSort()
{
    if(head == NULL)
        printf("Empty");
    else{
        ListNode *current = head;
        ListNode *previous = head;
        ListNode *temp = head;
        int size = 0;
        while (current != NULL){
            size++;
            current = current->next;
        }
        
        for (int i = size; i>0; i--)
        {
            current = head;
            previous = head;
            for (int j = 0; j<i-1 && current->next; j++){
                if(current->val > current->next->val){
                    temp = current->next;
                    current->next = temp->next;
                    temp->next = current;

                    if(current == head){
                        head = temp;
                        previous = temp;
                    }else{
                        previous->next = temp;
                        previous = previous->next;
                    }
                }else{
                    current = current->next;
                    if(j!=0)
                        previous = previous->next;
                }
            }
        }
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
    printf("(5) Sorting\n");
    printf("(6) Delete\n");
    printf("(7) Clear\n");
    printf("(8) Print this link\n");
    printf("(9) Print middle node\n");
    printf("(10) Quit\n");
    printf("(11) Pop\n");
    printf("(12) Pop_back\n");

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
            case 5: //sorting
                sorting_BubbleSort();
                break;
            case 6: //Delete
                printf("Enter node value: ");
                scanf("%d", &val);
                delete(val);
                break;
            case 7: //Clear
                clear();
                break;
            case 8: //Print
                printList();
                break;
            case 9: //Print middle node
                printMiddle();
                break;
            case 10: //Exit
                flag = 0;
                break;
            case 11: //queue
                pop();
                break;
            case 12: //stack
                pop_back();
                break;
            default:
                break;
        }
    }
    
    free(head);
    return 0;
}