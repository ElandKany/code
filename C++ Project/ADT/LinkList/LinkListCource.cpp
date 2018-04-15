#include "stdafx.h"
#include "LinkListHeader.h"
#include <iostream>

namespace wangkang {

using namespace std;

LinkListImpl::~LinkListImpl()
{
	for (LinkList*p; !isEmpty();)
	{
		p = header->next;
		delete header;
		header = p;
	}
}

// add info to header
void LinkListImpl::addToHead(int info)
{
	/*
	header = new LinkList(info);
	if (tailer == nullptr)
		tailer = header;
	*/
	if (header != nullptr)
	{
		LinkList* tmp = new LinkList(info, header);
		header = tmp;
		if (tailer == nullptr)
		{
			tailer = header->next;
		}
	}
	else
	{
		header = new LinkList(info);
		if (tailer == nullptr)
		{
			tailer = header;
		}
	}
}

//����β�ڵ�ʱ����Ҫ���ǵ�ǰ�����Ƿ�Ϊ����������ǣ���header��tailerͬʱָ���´����Ľڵ㣬
//������ǿ��������½��ڵ�����������Ҫ��tailer�ڵ�ָ���¼���Ľڵ㣬��֤�������ȷִ�С�
void LinkListImpl::addToTail(int info)
{
	if (tailer != nullptr)
	{
		tailer->next = new LinkList(info);
		tailer = tailer->next;
	}
	else
	{
		header = tailer = new LinkList(info);
	}
}

//delete the head and return its info
int LinkListImpl::deleteFromHead()
{
	if (isEmpty())
	{
		//-1 means that the list is null.
		return -1;
	}
	int info = header->mInfo;
	LinkList* tmpList = header;
	if (header == tailer)
	{
		header = tailer = nullptr;
	}
	else
	{
		header = header->next;
	}
	delete tmpList;
	tmpList = nullptr;
	return info;
}

int LinkListImpl::deleteFromTail()
{
	if (isEmpty())
	{
		//-1 means that the List is null
		return -1;
	}
	int info = tailer->mInfo;
	if (header == tailer)
	{
		delete tailer;
		tailer = header = nullptr;
	}
	else
	{
		LinkList* tmpList; //find the precious node of tailer
		for (tmpList = header; tmpList != tailer; tmpList = tmpList->next);
		delete tailer;
		tailer = tmpList;
		tailer->next = nullptr;
	}
	return info;
}

void LinkListImpl::deleteNode(int info)
{
	//case for the list is null
	if (header == nullptr)
	{
		return;
	}

	//case for the only node in the list
	if (header == tailer && header->mInfo == info)
	{
		delete header;
		header = tailer = nullptr;
	}
	else if (header->mInfo == info)
	{
		//for the header case
		LinkList* tmpList = header;
		header = tmpList->next;
		delete tmpList;
	}
	else
	{
		//for other case
		LinkList* tmpList, *ptrList;
		//then find the position of node
		//there is a bug, when there are some the same elements in the list, it only can delete first of them.
		for (ptrList = header, tmpList = header->next; tmpList != nullptr, tmpList->mInfo != info; ptrList = ptrList->next, tmpList = tmpList->next);
		if(tmpList != nullptr)
		{
			ptrList->next = tmpList->next;
			if (tmpList == tailer)
			{
				tailer = ptrList;
			}
			delete tmpList;
			tmpList = nullptr;
		}
	}
}

bool LinkListImpl::isInList(int info)
{
	LinkList* tmpList;
	for (tmpList = header; tmpList != nullptr; tmpList = tmpList->next)
	{
		if (info == tmpList->mInfo)
		{
			return true;
		}
	}
	return false;
}

void LinkListImpl::showList()const
{
	cout << "Show List: ";
	LinkList* tmpList;
	for (tmpList = header; tmpList != tailer; tmpList = tmpList->next)
	{
		cout << tmpList->mInfo << "->";
	}
	cout << tmpList->mInfo << endl;
}

}