/*
    ��ϰʹ�������������������������ҽڵ㡢��ӽڵ㡢ɾ���ڵ�
*/

#include "stdio.h"
#include "string.h"
#include "assert.h"
#include "stdlib.h"


#define COUNT 3

//����һ���ڵ�ṹ��
struct NODE
{
    unsigned long uID;
    char strName[16];  //��ָ��Ļ�������ʳ�ͻ�쳣
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
	

//����һ������n���ڵ�������Ӽ����������ݽ����ʼ����������������׽ڵ�ָ��
NODE *createNode(int n)
{
    NODE *pHead, //�׽ڵ�ָ��
         *pRear, //β�ڵ�ָ��
         *pNew; //�½ڵ�ָ��
    int i;
    char *strName = new char[16];
    for (i=0; i<n; i++)
    {
        pNew = new NODE;
        do
        {
            printf("������ID�����ƣ� ");
            scanf("%d %s",&pNew->uID, strName);    
            if (strlen(strName) > 16)
            {
                printf("�������Ƴ��ȳ�����Χ�����������룺 \r\n");
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

//��ӡ���������нڵ������
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

//��ѯ�����о���ָ��ID�Ľڵ㣬�����ش˽ڵ�ָ��
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
        printf("����ʧ�ܣ�δ�ҵ��Ҷ�ID�Ľڵ㣡 \r\n");
        return NULL;
    }
}

//ɾ��ָ��ID�Ľڵ�
NODE *deleteNode(NODE *pHead, unsigned long uID)
{
    NODE *pDest, //Ҫɾ���Ľڵ�
         *pBefore; //ǰһ���ڵ�
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
        printf("�ڵ��ѱ�ɾ���� ");
    }
    else
    {
        printf("δ�ҵ�ָ���ڵ㣬�޷�����ɾ���� \r\n");
    }
    return pHead;
}

//��ָ��ID�Ľڵ�����һ���µĽڵ�
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
        printf("�������½ڵ��ID�����ƣ� ");
        scanf("%d %s",&pNew->uID,pNew->strName);
        pNew->next = pDest->next;
        pDest->next = pNew;
        printf("�ڵ������ɣ� \r\n");
    }
    else
    {
        printf("δ�ҵ�ָ���ڵ㣡 \r\n");
    }
    return pHead;
}

int main(int argc, char *argv[])
{
    NODE *pHead, *pDest;
    int nSelect;
    bool isExit = false;
    unsigned long uID;
    printf("�������ʾ�������ݳ�ʼ������ \r\n");
    //pHead = createNode(COUNT);
    //assert(pHead != NULL);
    printf("�������ɹ����洢�������£� \r\n");
    //printNode(pHead);
    NODE_INIT(wuff);
 
    while (!isExit)
    {
        printf("-------------------------- \r\n");
        printf("��ѡ��Ҫ���еĲ����� \r\n");
        printf("1.��ӡ���������нڵ����ݣ� \r\n");
        printf("2.����ID��ѯ���ơ� \r\n");
        printf("3.ɾ��ָ��ID�Ľڵ㡣 \r\n");
        printf("4.��ָ��ID�Ľڵ�����һ���µĽڵ㡣 \r\n");
        printf("5.�˳��� \r\n");
        printf("--------------------------- \r\n");
        scanf("%d",&nSelect);
        switch(nSelect)
        {
        case 1:
            printf("�������нڵ��������£� \r\n");
            printNode(pHead);
            break;
        case 2:
            printf("������Ҫ��ѯ�Ľڵ��ID�� \r\n");
            scanf("%d",&uID);
            pDest = searchNode(pHead, uID);
            if (pDest != NULL)
            {
                printf("���ҵ��ڵ㣬����Ϊ��%s \r\n",pDest->strName);
            }
            break;
        case 3:
            printf("������Ҫɾ���Ľڵ��ID�� \r\n");
            scanf("%d",&uID);
            pHead = deleteNode(pHead, uID);
            break;
        case 4:
            printf("�����뱻����Ľڵ��ID�� \r\n");
            scanf("%d",&uID);
            pHead = insertNode(pHead, uID);
            break;
        case 5:
            isExit = true;
            printf("�������˳��� \r\n");
            break;
        default:
            printf("��������������ѡ�� \r\n");
            break;
        }
    }
}