#include<stdio.h>
#include<stdlib.h>
struct duLinkedList
{
    char c[30];
    struct duLinkedList *front;
    struct duLinkedList *next;
};


extern  void TraverseList_DuL(struct duLinkedList *L);
extern  struct duLinkedList *Search_list(struct duLinkedList *L, char a[30]);

void DeleteList_DuL(struct duLinkedList *p,struct duLinkedList *L)  //ɾ��p����Ľڵ�
{
    struct duLinkedList *h=p->next;
    if(p->next==NULL)   {printf("�ýڵ���β�ڵ㣬�����޽ڵ㣡\n");    return ;}
    p->next=h->next;
    free(h);
    printf("ɾ�����������");
    TraverseList_DuL(L);
}

void  delete_Dulist(struct duLinkedList *L)
{
    struct duLinkedList *p;
    printf("ԭ����");
    TraverseList_DuL(L);
    printf("\n��ѡ��Ҫɾ����ǰһ���ڵ㣨����ڵ�����ݣ���     ");
    char a[30];
    scanf("%s",a);
    p=Search_list(L,a);
    if(p==NULL)     {printf("��������������û�иýڵ㣡\n");    return ;   }
    DeleteList_DuL(p,L);
}
