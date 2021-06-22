#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct TreeNode TreeNode;     //Forward declaration
typedef struct QueueNode QueueNode;
QueueNode *g_queuehead = NULL;
QueueNode *g_queuetail = NULL;
TreeNode *g_treehead = NULL;

struct QueueNode{
    int val;
    struct QueueNode *next;
};

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void printList(struct QueueNode* ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
}

bool IsEmpty()
{
    return (g_queuetail==NULL) ? 1 : 0;
}

void push(int x)
{
    QueueNode *new_node = NULL;
    new_node = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    new_node->val = x;
    new_node->next = NULL;

    if(IsEmpty()){
        g_queuehead = new_node;
        g_queuetail = g_queuehead;
    }else{
        g_queuetail->next = new_node;
        g_queuetail = new_node;
    }
}

void pop()
{
    QueueNode *temp;
    if(IsEmpty()){
        printf("Queue is empty");
    }
    printList(g_queuehead);
    temp = g_queuehead;
    g_queuehead = g_queuehead->next;
    free(temp);
}

TreeNode* creatNode(int x)
{
    TreeNode *new_node = NULL;
    new_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    new_node->val = x;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void creatTree()
{
    TreeNode *node_0, *node_1, *node_2, *node_3, *node_4, *node_5, *node_6;
    node_0 = creatNode(0);
    node_1 = creatNode(1);
    node_2 = creatNode(2);
    node_3 = creatNode(3);
    node_4 = creatNode(4);
    node_5 = creatNode(5);
    node_6 = creatNode(6);
    g_treehead = node_0;

    node_0->left = node_1; node_0->right = node_2;
    node_1->left = node_3; node_1->right = node_4;
    node_2->left = node_5; node_2->right = node_6;
                   
    /*                   
               0                V
            /     \          /     \
           1       2        L       R
          / \     / \
         3   4   5   6
    */
}

void printTree_LO(struct TreeNode* head) //level-oder
{
    TreeNode *current;
    current = head;
    int flag = 0;
    push(current->val);
    
    while (current != NULL)
    {
        if(current->left != NULL){
            push(current->left->val);
            flag = 1;
            printf("%d ", current->left->val);
            //push(current->right->val); //B
            //printf("%d ", current->right->val);
        }
        if(current->right != NULL){
            push(current->right->val);
            printf("%d ", current->right->val);
        }
        current = flag ? current->left : current->right;
    }
}

void printTree_VLR(struct TreeNode* current) //pre-order(VLR)
{
    while (current != NULL)
    {
        /*printf("%d ", current->val);
        if(current->left != NULL){
            current = current->left
            printf("%d ", current->left);
        }
        g_queuehead = g_queuehead->left;*/
    }
}

void insertAfterList(struct TreeNode* ptr, int x)
{
    TreeNode* new_node;
    new_node = creatNode(x);

    //new_node->next = ptr->next;
    //ptr->next = new_node;
}

void insertBeforeheadList(struct TreeNode** head, int x)
{
    TreeNode* new_node;
    new_node = creatNode(x);

    //new_node->next = *head;
    //*head = new_node;

    //概念同Call by address的SWAP
    //如果要Call by value就使用return回傳
}

int main()
{
    creatTree();
    printTree_LO(g_treehead);
    printf("\n");
}