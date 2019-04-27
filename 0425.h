#pragma once
#include <stdio.h>

typedef int SDataType;
//������ڵ��װΪ�ṹ��
typedef struct SListNode
{
	SDataType _data;
	struct SListNode* _next;
}Node,*pNode;

//����Ľṹ����һ��ͷָ�뱣�������һ���ڵ�ĵ�ַ
typedef struct SList
{
	pNode _pHead; //ָ�������еĵ�һ���ڵ�
}SList,*pSList;

//���ȣ�������ʵ��BuyNode����������������������ԭ��ΪListNode* BuyNode(DataType x)��
//����һ��DataType���ͱ���x������һ��ListNode���͵�ָ�룬
//����ֱ����malloc����һ���ռ䣬��x����Data��next��Ϊ�գ��ٷ������ǿ��ٵĿռ��ָ��ͺ��ˡ�
pNode BuyNode(SDataType x);
// ����ĳ�ʼ�� 
void SListInit(SList* s);

//��ӡ����
void SListPrint(SList* s);

// ������s���һ���ڵ�����ֵΪdata�Ľڵ� 
void SListPushBack(SList* s, SDataType data);

// ɾ������s���һ���ڵ� 
void SListPopBack(SList* s);

// ������s��һ���ڵ�ǰ����ֵΪdata�Ľڵ� 
void SListPushFront(SList* s, SDataType data);

// ɾ������s�ĵ�һ���ڵ� 
void SListPopFront(SList* s);

// �������posλ�ú����ֵΪdata�Ľڵ� 
void SListInsert(SList* s,pNode pos, SDataType data);

// ɾ������s��posλ�õĽڵ� 
void SListErase(SList* s, pNode pos);

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻�NULL 
pNode SListFind(SList* s, SDataType data);
	
// ��ȡ��������Ч�ڵ�ĸ��� 
size_t SListSize(SList* s);

// ��������Ƿ�Ϊ�� 
int SListEmpty(SList* s);

// ����������Ч�ڵ���� 
void SListClear(SList* s);

// �������� 
void SListDestroy(SList* s);

