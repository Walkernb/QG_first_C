#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct LinkList
{
    char a[30];
    struct LinkList  *next;
};


void InsertList(struct LinkList *q,struct LinkList *p)   //��q�������p
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
    printf("��Ϊ��Ҫ���������ֵ:");
    scanf("%s",p->a);
    TraverseList(L);
    printf("��ѡ��Ҫ����Ľڵ㣨�������ݣ���");
    char c[30];
    scanf("%s",c);
    q=SearchList(L,c);
    if(q==NULL)     {printf("��������������û�иýڵ㣡\n");    return ;   }
    InsertList(q,p);
    printf("�����½ڵ�������");
    TraverseList(L);
}
