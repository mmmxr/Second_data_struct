#include "dlinklist.h"
#define TEST_HEADER printf("\n====================%s===================\n",__FUNCTION__)
void DLinkListPrint(DLinkNode* head,const char *msg)
{
    printf("%s\n",msg);
    DLinkNode* cur=head->next;
    while(cur!=head)
    {
        printf("[%c] ",cur->data);
        cur=cur->next;
    }
    printf("\n");
    cur=head->prev;
    while(cur!=head)
    {
        printf("[%c] ",cur->data);
        cur=cur->prev;
    }
    printf("\n");
}
DLinkNode* CreatDNode(DLinkType value)
{
    DLinkNode* new_node=(DLinkNode* )malloc(sizeof(DLinkNode));
    new_node->data=value;
    new_node->next=new_node;
    new_node->prev=new_node;

    return new_node;
}
void DestroyDNode(DLinkNode* ptr)
{
    free(ptr);
}
void DLinkListInit(DLinkNode** phead)
{
    if(phead==NULL)
    {
        return;//非法输入
    }
    *phead=CreatDNode(0);
}

void DLinkListPushBack(DLinkNode* head, DLinkType value)
{
    if(head==NULL)
    {
        return;
    }
    DLinkNode* new_node=CreatDNode(value);
    DLinkNode* to_insert_prev=head->prev;
    new_node->next=head;
    head->prev=new_node;
    to_insert_prev->next=new_node;
    new_node->prev=to_insert_prev;
}
void DLinListPopBack(DLinkNode* head)
{
    if(head==NULL)
    {
        return;//非法输入
    }
    if(head->next==head)
    {
        return;//空链表
    }
    DLinkNode* to_delete=head->prev;
    DLinkNode* to_delete_prev=to_delete->prev;
    head->prev=to_delete->prev;
    to_delete_prev->next=head;
    DestroyDNode(to_delete);
}
void DLinkListPushFront(DLinkNode* head, DLinkType value)
{
    if(head==NULL)
    {
        return;
    }
    DLinkNode* to_insert=head->next;
    DLinkNode* new_node=CreatDNode(value);
    new_node->next=to_insert;
    to_insert->prev=new_node;
    head->next=new_node;
    new_node->prev=head;

}
void DLinkListPopFront(DLinkNode* head)
{
    if(head==NULL)
    {
        return;
    }
    if(head->next==head)
    {
        return;
    }
    DLinkNode* to_delete=head->next;
    DLinkNode* to_delete_next=to_delete->next;
    head->next=to_delete_next;
    to_delete_next->prev=head;
    DestroyDNode(to_delete);

}
DLinkNode* DLinkListFind(DLinkNode* head, DLinkType to_find)
{
    if(head==NULL)
    {
        return NULL;
    }
    DLinkNode* cur=head->next;
    for(;cur!=head;cur=cur->next)
    {
        if(cur->data==to_find)
        {
            return cur;
        }
    }
    return NULL;
}
void DLinkListInsert(DLinkNode* head,DLinkNode* pos, DLinkType value)
{
    if(head==NULL||pos==NULL)
    {
        return;
    }
    DLinkNode* cur=pos->prev;
    DLinkNode* new_node=CreatDNode(value);
    new_node->next=pos;
    pos->prev=new_node;
    cur->next=new_node;
    new_node->prev=cur;
}
void DLinkListInsertAfter(DLinkNode* head,DLinkNode* pos, DLinkType value)
{
    if(head==NULL||pos==NULL)
    {
        return;
    }
    DLinkNode* to_insert_next=pos->next;
    DLinkNode* new_node=CreatDNode(value);
    new_node->next=to_insert_next;
    to_insert_next->prev=new_node;
    pos->next=new_node;
    new_node->prev=pos;
}    

void DLinkListErase(DLinkNode* head,DLinkNode* pos)
{
    if(head==NULL||pos==NULL)
    {
        return;
    }
    DLinkNode* to_delete_next=pos->next;
    DLinkNode* to_delete_prev=pos->prev;
    to_delete_prev->next=to_delete_next;
    to_delete_next->prev=to_delete_prev;
    DestroyDNode(pos);
}

void DLinkListRemove(DLinkNode* head,DLinkType value)
{
    if(head==NULL)
    {
        return;
    }
    DLinkNode* cur=head->next;
    for(;cur!=head;cur=cur->next)
    {
        if(cur->data==value)
        {
            DLinkNode* tmp=cur;
            cur->prev->next=cur->next;
            cur->next->prev=cur->prev;
            DestroyDNode(tmp);
            return;
        }
    }
}
void DLinkListRemoveAll(DLinkNode* head,DLinkType value)
{
    if(head==NULL)
    {
        return;
    }
    DLinkNode* cur=head->next;
    for(;cur!=head;cur=cur->next)
    {
        if(cur->data==value)
        {
            DLinkNode* tmp=cur;
            cur->prev->next=cur->next;
            cur->next->prev=cur->prev;
            DestroyDNode(tmp);
        }
    }
}


size_t DLinkListSize(DLinkNode* head)
{
    if(head==NULL)
    {
        return (size_t)-1;
    }
    if(head->next==head)
    {
        return 0;
    }
    DLinkNode* cur=head->next;
    size_t count=0;
    while(cur!=head)
    {
        count++;
        cur=cur->next;
    }
    return count;
}
int DLinkListEmpty(DLinkNode* head)
{
    if(head==NULL)
    {
        return -1;
    }
    if(head->next==head)
    {
        return 0;
    }
    return 1;
}
/////////////////////////////////////////////
//以下是测试函数·
/////////////////////////////////////////////
void TestEmpty()
{ 
    TEST_HEADER;
    DLinkNode* head;
    DLinkListInit(&head);
    int count=DLinkListEmpty(head);
    printf("空链表  expect 0,actual %d\n",count);
    DLinkListPushFront(head,'a');
    DLinkListPushFront(head,'b');
    DLinkListPushFront(head,'c');
    DLinkListPushFront(head,'d');
    DLinkListPrint(head,"头插4个元素");
    count=DLinkListEmpty(head);
    printf("非空链表 expect 1,actual %d\n",count);

}
void TestSize()
{
    TEST_HEADER;
    DLinkNode* head;
    DLinkListInit(&head);
    size_t count=DLinkListSize(head);
    printf("空链表 size expect 0,actual %lu\n",count);
    DLinkListPushFront(head,'a');
    DLinkListPushFront(head,'b');
    DLinkListPushFront(head,'c');
    DLinkListPushFront(head,'d');
    DLinkListPrint(head,"头插4个元素");
    count=DLinkListSize(head);
    printf("size expect 4,actual %lu\n",count);
}
void TestRomoveALL()
{
    TEST_HEADER;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushFront(head,'a');
    DLinkListPushFront(head,'b');
    DLinkListPushFront(head,'c');
    DLinkListPushFront(head,'d');
    DLinkListPushFront(head,'a');
    DLinkListPushFront(head,'b');
    DLinkListPushFront(head,'c');
    DLinkListPushFront(head,'d');
    DLinkListPrint(head,"头插8个元素");
    DLinkListRemoveAll(head,'a');
    DLinkListPrint(head,"删除a");
}
void TestRomove()
{
    TEST_HEADER;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushFront(head,'a');
    DLinkListPushFront(head,'b');
    DLinkListPushFront(head,'c');
    DLinkListPushFront(head,'d');
    DLinkListPrint(head,"头插四个元素");
    DLinkListRemove(head,'a');
    DLinkListPrint(head,"删除a");
}
void TestErase()
{
    TEST_HEADER;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushFront(head,'a');
    DLinkListPushFront(head,'b');
    DLinkListPushFront(head,'c');
    DLinkListPushFront(head,'d');
    DLinkListPrint(head,"头插四个元素");
    DLinkNode* pos_b=DLinkListFind(head,'b');
    DLinkListErase(head,pos_b);
    DLinkListPrint(head,"删除b");
}
void TestInsertAfter()
{
    TEST_HEADER;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushFront(head,'a');
    DLinkListPushFront(head,'b');
    DLinkListPushFront(head,'c');
    DLinkListPushFront(head,'d');
    DLinkListPrint(head,"头插四个元素");
    DLinkNode* pos_b=DLinkListFind(head,'b');
    DLinkListInsertAfter(head,pos_b,'x');
    DLinkListPrint(head,"b后面插入x");
}
void TestInsert()
{
    TEST_HEADER;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushFront(head,'a');
    DLinkListPushFront(head,'b');
    DLinkListPushFront(head,'c');
    DLinkListPushFront(head,'d');
    DLinkListPrint(head,"头插四个元素");
    DLinkNode* pos_b=DLinkListFind(head,'b');
    DLinkListInsert(head,pos_b,'x');
    DLinkListPrint(head,"b前面插入x");
  
}
void TestFind()
{
    TEST_HEADER;
    DLinkNode* head;
     DLinkListInit(&head);
    DLinkListPushFront(head,'a');
    DLinkListPushFront(head,'b');
    DLinkListPushFront(head,'c');
    DLinkListPushFront(head,'d');
    DLinkListPrint(head,"头插四个元素");
    DLinkNode* pos_a=DLinkListFind(head,'a');
    printf("a expect %p,actual %p\n",head->prev,pos_a);
    DLinkNode* pos_x=DLinkListFind(head,'x');
    printf("a expect NULL,actual %p\n",pos_x);
}
void TestPopFront()
{
    TEST_HEADER;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushFront(head,'a');
    DLinkListPushFront(head,'b');
    DLinkListPushFront(head,'c');
    DLinkListPushFront(head,'d');
    DLinkListPrint(head,"头插四个元素");
    DLinkListPopFront(head);
    DLinkListPopFront(head);
    DLinkListPrint(head,"头删2个元素");
    DLinkListPopFront(head);
    DLinkListPopFront(head);
    DLinkListPrint(head,"头删2个元素");
    DLinkListPopFront(head);
    DLinkListPrint(head,"对空链表头删");
}
void TestPushFront()
{
    TEST_HEADER;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushFront(head,'a');
    DLinkListPushFront(head,'b');
    DLinkListPushFront(head,'c');
    DLinkListPushFront(head,'d');
    DLinkListPrint(head,"头插四个元素");
}
void TestPopBack()
{
    TEST_HEADER;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPrint(head,"尾插四个元素");
    DLinListPopBack(head);
    DLinListPopBack(head);
    DLinkListPrint(head,"尾删2个元素");
    DLinListPopBack(head);
    DLinListPopBack(head);
    DLinkListPrint(head,"尾删2个元素");
    DLinListPopBack(head);
    DLinkListPrint(head,"对空链表尾删");
}

void TestPushBack()
{
    TEST_HEADER;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPrint(head,"尾插四个元素");

}
void TestInit()
{
    TEST_HEADER;
    DLinkNode* head;
    DLinkListInit(&head);
    printf("head expect %p , actual %p\n",head,head->next);
}

int main()
{
    TestInit();
    TestPushBack();
    TestPopBack();
    TestPushFront();
    TestPopFront();
    TestFind();
    TestInsert();
    TestInsertAfter();
    TestErase();
    TestRomove();
    TestRomoveALL();
    TestSize();
    TestEmpty();
    return 0;
}

