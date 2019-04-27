#pragma once
#include <stdio.h>

typedef int SDataType;
//将链表节点封装为结构体
typedef struct SListNode
{
	SDataType _data;
	struct SListNode* _next;
}Node,*pNode;

//链表的结构，给一个头指针保存链表第一个节点的地址
typedef struct SList
{
	pNode _pHead; //指向链表中的第一个节点
}SList,*pSList;

//首先，我们来实现BuyNode函数（创建单链表），函数原型为ListNode* BuyNode(DataType x)，
//传入一个DataType类型变量x，返回一个ListNode类型的指针，
//我们直接用malloc开辟一个空间，将x赋给Data，next置为空，再返回我们开辟的空间的指针就好了。
pNode BuyNode(SDataType x);
// 链表的初始化 
void SListInit(SList* s);

//打印链表
void SListPrint(SList* s);

// 在链表s最后一个节点后插入值为data的节点 
void SListPushBack(SList* s, SDataType data);

// 删除链表s最后一个节点 
void SListPopBack(SList* s);

// 在链表s第一个节点前插入值为data的节点 
void SListPushFront(SList* s, SDataType data);

// 删除链表s的第一个节点 
void SListPopFront(SList* s);

// 在链表的pos位置后插入值为data的节点 
void SListInsert(SList* s,pNode pos, SDataType data);

// 删除链表s中pos位置的节点 
void SListErase(SList* s, pNode pos);

// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回NULL 
pNode SListFind(SList* s, SDataType data);
	
// 获取链表中有效节点的个数 
size_t SListSize(SList* s);

// 检测链表是否为空 
int SListEmpty(SList* s);

// 将链表中有效节点清空 
void SListClear(SList* s);

// 销毁链表 
void SListDestroy(SList* s);

