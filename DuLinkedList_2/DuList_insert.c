#include<stdio.h>
#include<stdlib.h>
struct duLinkedList
{
    char c[30];
    struct duLinkedList *front;
    struct duLinkedList *next;
};


void InsertBeforeList_DuL(struct duLinkedList *p,struct duLinkedList *q,struct duLinkedList *L)     //��pǰ�����q
{
    q->next=p;
    printf("������������");
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

void InsertAfterList_DuL(struct duLinkedList *p,struct duLinkedList *q,struct duLinkedList *L)                 //��p�������q
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
    printf("������������");
    TraverseList_DuL(L);
}

extern  void TraverseList_DuL(struct duLinkedList *L);
extern  struct duLinkedList *Search_list(struct duLinkedList *L, char a[30]);

void  insert_DuList(struct duLinkedList *L)
{
    struct duLinkedList *p=(struct duLinkedList *)malloc(sizeof(struct duLinkedList)),*q;
    int i;
    printf("����һ���½ڵ㣺");
    scanf("%s",&p->c);
    printf("ԭ����");
    TraverseList_DuL(L);
    printf("\nѡ������λ�ã������λ�õ����ݣ���");
    char a[30];
    scanf("%s",a);
    q=Search_list(L,a);
    if(q==NULL)     {printf("��������������û�иýڵ㣡\n");    return ;   }
    for(i=0;i<20;i++)   printf(" ");
    for(i=0;i<25;i++)   printf("*");
    printf("1    �����λ��ǰ     ");
    for(i=0;i<25;i++)   printf("*");    printf("\n");
    for(i=0;i<20;i++)   printf(" ");
    for(i=0;i<25;i++)   printf("*");
    printf("2    �����λ�ú�     ");
    for(i=0;i<25;i++)   printf("*");    printf("\n");
    printf("������ѡ��          ");
    scanf("%d",&i);
    switch(i)
    {
        case 1:InsertBeforeList_DuL(q,p,L);break;
        case 2:InsertAfterList_DuL(q,p,L);break;
        default:printf("��������\n");
    }
}
