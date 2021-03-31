#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct LinkList
{
    char a[30];
    struct LinkList  *next;
};


void InsertList(struct LinkList *q,struct LinkList *p)   //在q后面插入p
{
    p->next=q->next;
    q->next=p;
}


extern void TraverseList(struct LinkList *L);
extern struct LinkList *SearchList(struct LinkList *L,char c[30]);

void insert_List(struct LinkList *L)
{
    struct LinkList *p,*q;
    p=(struct LinkList *)malloc(sizeof(struct LinkList));
    printf("请为将要插入的链表赋值:");
    scanf("%s",p->a);
    TraverseList(L);
    printf("请选择要插入的节点（输入数据）：");
    char c[30];
    scanf("%s",c);
    q=SearchList(L,c);
    if(q==NULL)     {printf("输入有误！链表中没有该节点！\n");    return ;   }
    InsertList(q,p);
    printf("插入新节点后的链表：");
    TraverseList(L);
}
