#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

// 定义双链表节点
typedef struct DuLnode
{
    ElemType data;
    struct DuLnode *prev, *next;
} DuLnode, *DuLinkList;

// 打印节点信息
void printList(DuLinkList list)
{
    if (list != NULL)
    {
        DuLnode *node = list->next;
        while (node)
        {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

// 初始化双链表头节点
bool InitDuLinkList(DuLinkList *list)
{
    *list = (DuLnode *)malloc(sizeof(DuLnode));
    if (*list == NULL)
        return false;

    (*list)->prev = NULL;
    (*list)->next = NULL;

    return true;
}

// 头插法创建双向链表
void CreateDuLinkList_H(DuLinkList *list)
{
    if (*list == NULL)
        InitDuLinkList(list);

    ElemType input;
    DuLnode *current = (DuLnode *)*list;

    do
    {
        printf("请输入元素节点的值，以-1结束\n");
        scanf("%d", &input);

        if (input == -1)
            return;

        DuLnode *node = (DuLnode *)malloc(sizeof(DuLnode));

        node->data = input;
        node->prev = current;
        node->next = current->next;

        current->next = node;

        if (current->next != NULL)
            current->next->prev = node;

    } while (1);
}

// 尾插法创建双向链表
void CreateDuLinkList_T(DuLinkList *list)
{
    if (*list == NULL)
        InitDuLinkList(list);

    ElemType input;
    DuLnode *currNode, *endNode;

    endNode = (DuLnode *)*list; // 将最后的节点设置为第一个节点

    // 将节点移动至最后一个节点
    while (endNode->next != NULL)
    {
        endNode = endNode->next;
    }

    do
    {
        printf("请输入插入的值，-1结束\n");
        scanf("%d", &input);

        if (input == -1)
            return;
        currNode = (DuLnode *)malloc(sizeof(DuLnode));
        currNode->data = input;   // 设置节点的值
        currNode->next = NULL;    // 将当前节点的下一个节点设置为NULL
        currNode->prev = endNode; // 将当前节点的上一个点设置这最后一个节点

        endNode->next = currNode; // 将最后一个节点的下一节点设置为当前节点
        endNode = currNode;       // 最后节点往后移
    } while (1);
}

/*
 * 双向链表按指定位置插入元素，位置起始序号从1开始
 * index插入的位置
 */
bool ListInsert(DuLinkList *list, int index, ElemType e)
{
    if (*list == NULL || index < 1)
    {
        printf("非法的插入位置：%d\n", index);
        return false;
    }

    DuLnode *currNode = *list; // 插入点的节点,默认为头节点
    int j = 0;
    while (currNode != NULL && j < index - 1)
    {
        currNode = currNode->next;
        j++;
    }

    if (currNode == NULL)
    {
        printf("非法的插入位置：%d\n", index);
        return false;
    }

    DuLnode *node = (DuLnode *)malloc(sizeof(DuLnode));
    if (node == NULL)
    {
        printf("内存分配失败\n");
        return false;
    }

    node->data = e;
    node->prev = currNode;       // 设置新节点的上一个节点
    node->next = currNode->next; // 设置新节点的下一个节点

    // 如果不是末尾节点，调整后一个节点的上一节点位置
    if (currNode->next != NULL)
        currNode->next->prev = node;

    currNode->next = node; // 调整前一节点的下一节点为当前节点

    return true;
}

int main(void)
{
    printf("Hello world!\n");
    DuLinkList list = NULL;
    // CreateDuLinkList_H(&list);'
    CreateDuLinkList_T(&list);

    ElemType e = 555;
    ListInsert(&list, 4, e);

    printList(list);
    return 0;
}
