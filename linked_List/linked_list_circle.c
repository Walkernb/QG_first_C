#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct LinkList
{
    char a[30];
    struct LinkList  *next;
};

extern struct LinkList *SearchList(struct LinkList *L,char c[30]);
extern void TraverseList(struct LinkList *L);

int  IsLoopList(struct LinkList *L)        //�ж������Ƿ�ɻ�
{
    int     jg=0;
    struct LinkList *p=L->next;
    p=p->next;
    while(p!=NULL)
    {
        if(p==L)    {jg=1;  return jg;}
        p=p->next;
        if(p==NULL)     break;
        p=p->next;
        L=L->next;
    }
    return jg;
}

void  circle_List(struct LinkList *L)
{
    struct LinkList *p=L,*q;
    char c;
    char ch[30];
     getchar();
    printf("�Ƿ�ʹ������ɻ�����Y/N����");
    scanf("%c",&c);
    if(c=='Y')
    {
        printf("ԭ���� ");
        TraverseList(L);
        printf("��ѡ�񻷵�ͷ�ڵ㣨�������ݣ���");
        scanf("%s",ch);
        q=SearchList(L,ch);
        if(q==NULL)     {printf("��������������û�иýڵ㣡\n");    return ;   }
        while(p->next!=NULL)        p=p->next;
        p->next=q;
    }
    getchar();
    printf("�Ƿ��жϸ�����ʹ�ɻ��ģ���Y/N����");
    scanf("%c",&c);
    if(c=='Y')
    {
        int jg=IsLoopList(L);
        if(jg==1)   printf("�ɻ���");
        else        printf("���ɻ���");
    }
}
