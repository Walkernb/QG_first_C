#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct duLinkedList
{
    char c[30];
    struct duLinkedList *front;
    struct duLinkedList *next;
};

void TraverseList_DuL(struct duLinkedList *L)       //遍历链表
{
    printf("%s",L->c);
    L=L->next;
    while(L!=NULL)
    {
        printf("->%s",L->c);
        L=L->next;
    }
}

struct duLinkedList *InitList_DuL(struct duLinkedList *L)
{
    struct duLinkedList *p,*h,*q;
    int i=0;
    char a[30];
    while(scanf("%s",a)&&(a[0]!='0'||strlen(a)!=1))
    {
        p=(struct duLinkedList *)malloc(sizeof(struct duLinkedList));
        strcpy(p->c,a);
        if(i==0)     h=p;
        else    L->next=p,L->front=q;
        if(i==0)    q=p;
        else        q=L;
        L=p;
        i++;
    }
    h->front=NULL;
    L->front=q;
    L->next=NULL;
    return h;
}

void DestroyList_DuL(struct duLinkedList *L)
{
    struct duLinkedList *p=L->next;
    while(L->next!=NULL)
    {
        free(L);
        L=p;
        p=L->next;
    }
    free(L);
}


struct duLinkedList *Search_list(struct duLinkedList *L, char a[30])
{
    while(L!=NULL)
    {
        if(strcmp(a,L->c)==0)     return L;
        L=L->next;
    }
    return NULL;
}


void Initialize()
{
    int i;
    for(i=0;i<20;i++)   printf(" ");
    for(i=0;i<25;i++)   printf("*");
    printf("     双向链表     ");
    for(i=0;i<25;i++)   printf("*");    printf("\n");
    printf("创建链表（以'0'结束）：    ");
}

void    Interface()
{
    int i;
    for(i=0;i<20;i++)   printf(" ");
    for(i=0;i<25;i++)   printf("*");
    printf("1    遍历链表     ");
    for(i=0;i<25;i++)   printf("*");    printf("\n");

    for(i=0;i<20;i++)   printf(" ");
    for(i=0;i<25;i++)   printf("*");
    printf("2    插入节点     ");
    for(i=0;i<25;i++)   printf("*");    printf("\n");

    for(i=0;i<20;i++)   printf(" ");
    for(i=0;i<25;i++)   printf("*");
    printf("3    删除节点     ");
    for(i=0;i<25;i++)   printf("*");    printf("\n");
    printf("请输入选择:                        ");
}

extern void  insert_DuList(struct duLinkedList *L);
extern void  delete_Dulist(struct duLinkedList *L);

int main()
{
    struct duLinkedList *L;
    Initialize();
    L=InitList_DuL(L);
    Interface();
    int i;
    scanf("%d",&i);
    switch(i)
    {
        case 1:TraverseList_DuL(L);break;
        case 2:insert_DuList(L);break;
        case 3:delete_Dulist(L);break;
        default:printf("输入有误！");
    }
    getchar();
    getchar();
    return 0;
}
