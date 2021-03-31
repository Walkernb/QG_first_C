#include<stdio.h>
#include<stdlib.h>
struct duLinkedList
{
    char c[30];
    struct duLinkedList *front;
    struct duLinkedList *next;
};


void InsertBeforeList_DuL(struct duLinkedList *p,struct duLinkedList *q,struct duLinkedList *L)     //在p前面插入q
{
    q->next=p;
    printf("插入后的新链表：");
    if(p->front==NULL)
    {
        p->front=q;
        q->front=NULL;
        TraverseList_DuL(q);
    }
    else
    {
        struct duLinkedList *h=p->front;
        h->next=q;
        q->front=h;
        p->front=q;
        TraverseList_DuL(L);
    }
}

void InsertAfterList_DuL(struct duLinkedList *p,struct duLinkedList *q,struct duLinkedList *L)                 //在p后面插入q
{
    q->front=p;
    if(p->next==NULL)
    {
        p->next=q;
        q->next=NULL;
    }
    else
    {
        struct duLinkedList *h=p->next;
        q->next=h;
        h->front=q;
        p->next=q;
    }
    printf("插入后的新链表：");
    TraverseList_DuL(L);
}

extern  void TraverseList_DuL(struct duLinkedList *L);
extern  struct duLinkedList *Search_list(struct duLinkedList *L, char a[30]);

void  insert_DuList(struct duLinkedList *L)
{
    struct duLinkedList *p=(struct duLinkedList *)malloc(sizeof(struct duLinkedList)),*q;
    int i;
    printf("创建一个新节点：");
    scanf("%s",&p->c);
    printf("原链表：");
    TraverseList_DuL(L);
    printf("\n选择插入的位置（输入该位置的数据）：");
    char a[30];
    scanf("%s",a);
    q=Search_list(L,a);
    if(q==NULL)     {printf("输入有误！链表中没有该节点！\n");    return ;   }
    for(i=0;i<20;i++)   printf(" ");
    for(i=0;i<25;i++)   printf("*");
    printf("1    插入该位置前     ");
    for(i=0;i<25;i++)   printf("*");    printf("\n");
    for(i=0;i<20;i++)   printf(" ");
    for(i=0;i<25;i++)   printf("*");
    printf("2    插入该位置后     ");
    for(i=0;i<25;i++)   printf("*");    printf("\n");
    printf("请输入选择：          ");
    scanf("%d",&i);
    switch(i)
    {
        case 1:InsertBeforeList_DuL(q,p,L);break;
        case 2:InsertAfterList_DuL(q,p,L);break;
        default:printf("输入有误！\n");
    }
}
