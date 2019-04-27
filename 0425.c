#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "0425.h"

pNode BuyNode(SDataType x)
{
	pNode p = (pNode)malloc(sizeof(Node));
    assert(p);
	p->_data = x;
	p->_next = NULL;
	return p;
}
//链表初始化
void SListInit(SList* s)
{
	assert(s);
	s->_pHead = NULL;
}
//打印整个链表
void SListPrint(SList* s)
{
	assert(s);
	if (!s->_pHead)
	{
		printf("链表为NULL\n");
	}
	else
	{
		int count = 0;
		while (s->_pHead)
		{
			printf(" 第%d个数%d-->", count, s->_pHead->_data);
			s->_pHead = s->_pHead->_next;
			count++;
		}
		printf("NULL\n");
	}
} 
//链表尾插
void SListPushBack(SList* s, SDataType data)
{
	assert(s);
	if (!s->_pHead)
	{
		s->_pHead = BuyNode(data);
	}
	else
	{ 
		pNode p1 = s->_pHead;
		while (p1->_next)
		{
			p1 = p1->_next;
		}
		p1->_next = BuyNode(data);
		p1->_next->_next = NULL;
	}
}
//链表尾删
void SListPopBack(SList* s)
{
	assert(s);
	if(!s->_pHead)
	{
		return ;
	}
	else if(!s->_pHead->_next)
	{
		 free(s->_pHead);
		 s->_pHead = NULL;
	}
	else
	{
		pNode pre = NULL;
		pNode p1 = s->_pHead;
		while (p1->_next)
		{
			pre = p1;
			p1 = p1->_next;
		}
		pre->_next = NULL;
		free(p1);
		p1 = NULL;
	}
}
// 在链表s第一个节点前插入值为data的节点 
void SListPushFront(SList* s, SDataType data)
{
	assert(s);
	if (!s->_pHead)
	{
		s->_pHead = BuyNode(data);
		s->_pHead->_next = NULL;
	}
	else
	{ 
		pNode NewHead = BuyNode(data);
		pNode p1 = s->_pHead;
		s->_pHead = NewHead;
		NewHead->_next = p1;
	}
	
}

// 删除链表s的第一个节点 
void SListPopFront(SList* s)
{
	assert(s);
	if(!s->_pHead)
	{
		return ;
	}
	else
	{
		pNode p1 = s->_pHead;
		s->_pHead = s->_pHead->_next;
		free(p1);
		p1 = NULL;
	}
}
// 在链表的pos位置后插入值为data的节点 
void SListInsert(SList* s, pNode pos, SDataType data)
{
	if (pos == NULL || s == NULL)
	{
		return ;
	}
	if (s->_pHead == NULL)
	{
		return ; 
	}
	else
	{
		if(pos == s->_pHead)
		{
			pos = BuyNode(data);
			pNode p1 = s->_pHead;
			s->_pHead = pos;
			pos->_next = p1;
		}
		else
		{
			pNode p1 = NULL;
			p1 = s->_pHead;
			while (p1->_next)
			{
				pNode pre_pos = p1;
				p1 = p1->_next;
				if (p1 == pos)
				{
					pos = BuyNode(data);
					pos->_next = p1;
					pre_pos->_next = pos;
				}
			}
		}
	}
}

// 删除链表s中pos位置的节点 
void SListErase(SList* s, pNode pos)
{
	assert(s);
	assert(pos);
	if (!s->_pHead)
	{
		return ;
	}
	if (s->_pHead == pos)
	{
		free(s->_pHead);
		s->_pHead = NULL;
	}
	else
	{
		pNode pre_pos = NULL;
		pNode p1 = NULL;
	    p1 = s->_pHead;
		while (p1!= pos)
		{
			pre_pos = p1;
			p1 = p1->_next;
		}
		if (!p1->_next)
		{
			SListPopBack(s);
		}
		else
		{
			pre_pos->_next = pos->_next;
			free(pos);
			pos = NULL;
		}
	}
}

// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回NULL 
pNode SListFind(SList* s, SDataType data)
{
	assert(s);
	pNode p1 = s->_pHead;
	while (p1)
	{
		if (p1->_data == data)
		{
			return p1;
		}
		p1 = p1->_next;
	}
	return NULL;
}

// 获取链表中有效节点的个数 
size_t SListSize(SList* s)
{
	assert(s);
	size_t count = 0;
	if (!s->_pHead)
	{
		return count;
	}
	else
	{
		while (s->_pHead->_next)
		{
			count++;
			s->_pHead = s->_pHead->_next;
		}
		count++;
		return count;
	}
}
// 检测链表是否为空 
int SListEmpty(SList* s)
{
	assert(s);
	if (s->_pHead == NULL)
	{
		return  1;
	}
	return 0;
}

// 将链表中有效节点清空 
void SListClear(SList* s)
{
	assert(s);
	if (!s->_pHead)
	{
		return;
	}
	while (s->_pHead)
	{
		pNode del_pos = s->_pHead;
		s->_pHead = s->_pHead->_next;
		free(del_pos);
		del_pos = NULL;
	}
}

void SListDestroy(SList* s)
{
	assert(s);
	if (!s->_pHead)
	{
		return ;
	}
	while(s->_pHead->_next)
	{ 
		pNode p = s->_pHead;
		s->_pHead = s->_pHead->_next;
		free(p);
		p = NULL;
	}
	free(s->_pHead);
	s->_pHead = NULL;
}

int main()
{
	SList s;
	SListInit(&s);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(&s, 5);
	SListPopBack(&s);
	SListPushFront(&s, 0);
	SListPopFront(&s);
	SListPopFront(&s);
	pNode p = SListFind(&s,5);
	SListInsert(&s, p , 8);
	SListErase(&s, p);
	size_t a = SListSize(&s);
	printf("%d\n",a);
	SListClear(&s);
	a = SListSize(&s);
	printf("%d\n", a);
	SListPrint(&s);
	SListDestroy(&s);
	system("pause");
	return 0;
}