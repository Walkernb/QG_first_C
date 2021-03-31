#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct LinkList
{
    char a[30];
    struct LinkList  *next;
};

 struct LinkList  * InitList(struct LinkList  *L)
{
    struct LinkList *p,*q;
    p=(struct LinkList *)malloc(sizeof(struct LinkList));
    int j=0;
    char c[30];
    while(scanf("%s",c)&&(c[0]!='0'||strlen(c)!=1))
    {
        if(j==0)    L=p;
        else        q->next=p;
        strcpy(p->a,c);
        q=p;
        p=(struct LinkList *)malloc(sizeof(struct LinkList));
        j++;
    }
    q->next=NULL;
    return L;
}

void DestroyList(struct LinkList  *L)           //��������ռ�
{
    struct LinkList *h=L->next,*p;
    p=h,    h=L,    L=p;
    while(L!=NULL)
    {
        free(h);
        h=L;
        L=L->next;
    }
    free(h);
}

void TraverseList(struct LinkList *L)   //��������
{
    printf("%s",L->a);
    L=L->next;
    while(L!=NULL)
    {
        printf("->");
        printf("%s",L->a);
        L=L->next;
    }
    printf("\n");
}

void ReverseList(struct LinkList *L)    //��ת����
{
    struct LinkList *p=L->next,*q;
    int i=0;
    while(p!=NULL)
    {
        q=p->next;
        p->next=L;
        if(i==0)    L->next=NULL;
        i++;
        L=p;
        p=q;
    }
    printf("��ת�������");
    TraverseList(L);
}

void  ReverseEvenList(struct LinkList *L)   //��������ż����
{
    struct LinkList *h,*p;
    int i=0;
    while(L!=NULL)
    {
      p=L->next;
      if(p==NULL)    break;
      L->next=p->next;
      p->next=L;
      if(i==0)  h=p;
      p=L->next;
      if(p==NULL)    break;
      if(p->next!=NULL)  L->next=p->next;
      L=p;
      i++;
    }
    printf("�����������");
    TraverseList(h);
}

struct LinkList *SearchList(struct LinkList *L,char c[30])     //�ҵ�e�ڵ�
{
    while(L!=NULL)
    {
        if(strcmp(L->a,c)==0)    return L;
        else        L=L->next;
    }
    return NULL;
}

void FindMidNode(struct LinkList *L)        //���м�ڵ�
{
    struct LinkList *n=L->next;
    if(n!=NULL)    n=n->next;
    while(n!=NULL)
    {
        L=L->next;
        n=n->next;
        if(n==NULL) break;
        n=n->next;
    }
    printf("�м�ڵ㣺       %s",L->a);
}

void    initaLize()                             //��ʼ����ʾ
{
    for(int i=0;i<20;i++)   printf(" ");
        for(int i=0;i<25;i++)   printf("*");
        printf("   ����   ");
        for(int i=0;i<25;i++)   printf("*");
        printf("\n��������������(��'0'����)��");
}

void   selcet_Fuction()                         //��ʼ����ʾ
{
    for(int i=0;i<20;i++)   printf(" ");
    for(int i=0;i<25;i++)   printf("*");
    printf("1    �������");    for(int i=0;i<9;i++)    printf(" ");
    for(int i=0;i<25;i++)   printf("*");    printf("\n");

    for(int i=0;i<20;i++)   printf(" ");
    for(int i=0;i<25;i++)   printf("*");
    printf("2    ��ת����");     for(int i=0;i<9;i++)    printf(" ");
    for(int i=0;i<25;i++)   printf("*");    printf("\n");

    for(int i=0;i<20;i++)   printf(" ");
    for(int i=0;i<25;i++)   printf("*");
    printf("3    ��������ż����   ");
    for(int i=0;i<25;i++)   printf("*");    printf("\n");

    for(int i=0;i<20;i++)   printf(" ");
    for(int i=0;i<25;i++)   printf("*");
    printf("4    ɾ���ڵ�");    for(int i=0;i<9;i++)    printf(" ");
    for(int i=0;i<25;i++)   printf("*");    printf("\n");

    for(int i=0;i<20;i++)   printf(" ");
    for(int i=0;i<25;i++)   printf("*");
    printf("5    ����ڵ�");    for(int i=0;i<9;i++)    printf(" ");
    for(int i=0;i<25;i++)   printf("*");     printf("\n");

    for(int i=0;i<20;i++)   printf(" ");
    for(int i=0;i<25;i++)   printf("*");
    printf("6    �ɻ�����");    for(int i=0;i<9;i++)    printf(" ");
    for(int i=0;i<25;i++)   printf("*");     printf("\n");

    for(int i=0;i<20;i++)   printf(" ");
    for(int i=0;i<25;i++)   printf("*");
    printf("7    �����м�ڵ�");  for(int i=0;i<5;i++)    printf(" ");
    for(int i=0;i<25;i++)   printf("*");     printf("\n");
    printf("���������ѡ��                    ");
}
extern void delete_list(struct LinkList *l);
extern void insert_List(struct LinkList *L);
void  circle_List(struct LinkList *L);
int main()
{
        struct LinkList *L,*h;
        initaLize();
        L=InitList(L);
        selcet_Fuction();
        int i;
        scanf("%d",&i);
        switch(i)
        {
            case 1:TraverseList(L);break;
            case 2:ReverseList(L);break;
            case 3:ReverseEvenList(L);break;
            case 4:delete_list(L);break;
            case 5:insert_List(L);break;
            case 6:circle_List(L);break;
            case 7:FindMidNode(L);break;
            default:printf("������Ч��\n");
        }
        if(i!=6) DestroyList(L);
        getchar();
        getchar();
        return 0;
}
