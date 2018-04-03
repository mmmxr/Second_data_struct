#pragma once
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef char DLinkType; 

typedef struct DLinkNode { 
DLinkType data; 
struct DLinkNode* next; 
struct DLinkNode* prev; 
} DLinkNode; 
void DLinkListInit(DLinkNode** phead);//初始化

void DLinkListPushBack(DLinkNode* head, DLinkType value); // 尾插

void DLinListPopBack(DLinkNode* head); //尾删

void DLinkListPushFront(DLinkNode* head, DLinkType value); //头插

void DLinkListPopFront(DLinkNode* head); //头删

DLinkNode* DLinkListFind(DLinkNode* head, DLinkType to_find); //查找指定元素

void DLinkListInsert(DLinkNode* head,DLinkNode* pos, DLinkType value); //在指定位置之前插入一个元素

void DLinkListInsertAfter(DLinkNode* head,DLinkNode* pos, DLinkType value); //在指定元素之后插入一个元素

void DLinkListErase(DLinkNode* head,DLinkNode* pos);//删除指定位置的元素 

void DLinkListRemove(DLinkNode* head,DLinkType value);//删除指定元素 

void DLinkListRemoveAll(DLinkNode* head,DLinkType value); //删除所有的指定元素

size_t DLinkListSize(DLinkNode* head); //双向链表的个数

int DLinkListEmpty(DLinkNode* head); //判断双向链表是否为空

