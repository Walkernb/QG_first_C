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

struct LinkList *DeleteList(struct LinkList *L,struct LinkList *e)  //删除e节点
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
        printf("原来的链表：");
        TraverseList(L);
        printf("请入要删除节点的数据（输入数据）：");
        char c[30];
        scanf("%s",c);
        struct LinkList *p=SearchList(L,c);
        if(p==NULL) {printf("输入有误！链表中没有该节点！\n");    return ;   }
        L=DeleteList(L,p);
        printf("删除节点后的链表：");
        TraverseList(L);
}
