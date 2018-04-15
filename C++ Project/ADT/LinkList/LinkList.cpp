// LinkList.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "LinkListHeader.h"
#include <iostream>

using namespace wangkang;
using namespace std;

int main()
{
	LinkListImpl* mList = new LinkListImpl();

	for (int i = 0; i < 20; i++)
	{
		mList->addToHead(i);
	}
	for (int i = 1; i < 20; i++)
	{
		mList->addToTail(i);
	}
	mList->deleteNode(3);
	mList->showList();
    return 0;
}

