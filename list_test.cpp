/*
    练习使用链表：创建链表、遍历链表、查找节点、添加节点、删除节点
*/

#include "stdio.h"
#include "string.h"
#include "assert.h"
#include "stdlib.h"


#define COUNT 3

//定义一个节点结构体
struct NODE
{
    unsigned long uID;
    char strName[16];  //用指针的话会出访问冲突异常
    NODE *next;
};


struct NODE_LIST
{
	struct NODE_LIST *pre;
	struct NODE_LIST *next;
	unsigned int nodeId;
	char nodeInfo[16];
};

#define NODE_INIT(nodeName) do{struct NODE_LIST nodeName;\
	nodeName.pre=NULL;\
	nodeName.next=NULL;\
	nodeName.nodeId=0;\
	memset(nodeName.nodeInfo,0,16);}while(0)
	

//创建一个具有n个节点的链表，从键盘输入数据将其初始化，并返回链表的首节点指针
NODE *createNode(int n)
{
    NODE *pHead, //首节点指针
         *pRear, //尾节点指针
         *pNew; //新节点指针
    int i;
    char *strName = new char[16];
    for (i=0; i<n; i++)
    {
        pNew = new NODE;
        do
        {
            printf("请输入ID和名称： ");
            scanf("%d %s",&pNew->uID, strName);    
            if (strlen(strName) > 16)
            {
                printf("输入名称长度超出范围，请重新输入： \r\n");
                //Sleep(1000);
            }
        } while(strlen(strName) > 16);
        strcpy(pNew->strName, strName);

        if (0==i)
        {
            pRear = pHead = pNew;
        }
        else
        {
            pRear->next = pNew;
        }
        pNew->next = NULL;
        pRear = pNew;
    }
    delete []strName;
    return pHead;
}

//打印链表中所有节点的数据
void printNode(NODE *pHead)
{
    NODE *pTemp = pHead;
    assert(pTemp != NULL);
    while (pTemp != NULL)
    {
        printf("%d %s \r\n",pTemp->uID, pTemp->strName);
        pTemp = pTemp->next;
    }
}

//查询链表中具有指定ID的节点，并返回此节点指针
NODE *searchNode(NODE *pHead, unsigned long uID)
{
    NODE *pDest = pHead;
    assert(pDest != NULL);
    while (pDest->next!=NULL && pDest->uID!=uID)
    {
        pDest = pDest->next;
    }
    if (pDest->uID == uID)
    {
        return pDest;
    }
    else
    {
        printf("搜索失败，未找到找定ID的节点！ \r\n");
        return NULL;
    }
}

//删除指定ID的节点
NODE *deleteNode(NODE *pHead, unsigned long uID)
{
    NODE *pDest, //要删除的节点
         *pBefore; //前一个节点
    pDest = pHead;
    assert(pDest != NULL);
    while (pDest->next!=NULL && pDest->uID!=uID)
    {
        pBefore = pDest;
        pDest = pDest->next;
    }
    if (pDest->uID == uID)
    {
        if (pDest == pHead)
        {
            pHead = pDest->next;
        }
        else
        {
            pBefore->next = pDest->next;
        }
        free(pDest);
        printf("节点已被删除！ ");
    }
    else
    {
        printf("未找到指定节点，无法将其删除！ \r\n");
    }
    return pHead;
}

//在指定ID的节点后插入一个新的节点
NODE *insertNode(NODE *pHead, unsigned long uID)
{
    NODE *pDest, *pNew;
    pDest = pHead;
    assert(pDest != NULL);
    while(pDest->next!=NULL && pDest->uID!=uID)
    {
        pDest = pDest->next;
    }
    if(pDest->uID == uID)
    {
        pNew = new NODE;
        printf("请输入新节点的ID和名称： ");
        scanf("%d %s",&pNew->uID,pNew->strName);
        pNew->next = pDest->next;
        pDest->next = pNew;
        printf("节点插入完成！ \r\n");
    }
    else
    {
        printf("未找到指定节点！ \r\n");
    }
    return pHead;
}

int main(int argc, char *argv[])
{
    NODE *pHead, *pDest;
    int nSelect;
    bool isExit = false;
    unsigned long uID;
    printf("请根据提示输入数据初始化链表： \r\n");
    //pHead = createNode(COUNT);
    //assert(pHead != NULL);
    printf("链表创建成功！存储数据如下： \r\n");
    //printNode(pHead);
    NODE_INIT(wuff);
 
    while (!isExit)
    {
        printf("-------------------------- \r\n");
        printf("请选择要进行的操作： \r\n");
        printf("1.打印出链表所有节点数据： \r\n");
        printf("2.输入ID查询名称。 \r\n");
        printf("3.删除指定ID的节点。 \r\n");
        printf("4.在指定ID的节点后插入一个新的节点。 \r\n");
        printf("5.退出。 \r\n");
        printf("--------------------------- \r\n");
        scanf("%d",&nSelect);
        switch(nSelect)
        {
        case 1:
            printf("链表所有节点数据如下： \r\n");
            printNode(pHead);
            break;
        case 2:
            printf("请输入要查询的节点的ID： \r\n");
            scanf("%d",&uID);
            pDest = searchNode(pHead, uID);
            if (pDest != NULL)
            {
                printf("已找到节点，名字为：%s \r\n",pDest->strName);
            }
            break;
        case 3:
            printf("请输入要删除的节点的ID： \r\n");
            scanf("%d",&uID);
            pHead = deleteNode(pHead, uID);
            break;
        case 4:
            printf("请输入被插入的节点的ID： \r\n");
            scanf("%d",&uID);
            pHead = insertNode(pHead, uID);
            break;
        case 5:
            isExit = true;
            printf("程序已退出！ \r\n");
            break;
        default:
            printf("按键错误，请重新选择！ \r\n");
            break;
        }
    }
}