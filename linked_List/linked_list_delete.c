#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct LinkList
{
    char a[30];
    struct LinkList  *next;
};

extern void TraverseList(struct LinkList *L);
extern struct LinkList *SearchList(struct LinkList *L,char c[30]);

struct LinkList *DeleteList(struct LinkList *L,struct LinkList *e)  //ɾ��e�ڵ�
{
    struct LinkList *p,*h=L;
    if(L==e)    {p=L->next;   free(L);   return p;}
    else        p=L->next;
    while(L!=NULL)
    {
        if(p==e)    {L->next=p->next;  free(p); break; }
        L=p;
        p=L->next;
    }
    return h;
}

void delete_list(struct LinkList *L)
{
        printf("ԭ��������");
        TraverseList(L);
        printf("����Ҫɾ���ڵ�����ݣ��������ݣ���");
        char c[30];
        scanf("%s",c);
        struct LinkList *p=SearchList(L,c);
        if(p==NULL) {printf("��������������û�иýڵ㣡\n");    return ;   }
        L=DeleteList(L,p);
        printf("ɾ���ڵ�������");
        TraverseList(L);
}
