#pragma once

namespace wangkang
{
	class LinkListImpl{
	private:
		class LinkList {
		public:
			LinkList(int info, LinkList* ptrList = nullptr)
				: next{ptrList}
				, mInfo{info}
			{}
			~LinkList()
			{
				mInfo = 0;
				next = nullptr;
			}
			LinkList* next;
			int mInfo;
		};

	public:
		LinkListImpl()
			: header{nullptr}
			, tailer{nullptr}
		{}
		~LinkListImpl();

	private:
		LinkList * header, *tailer;

	public:
		bool isEmpty()
		{
			return header == nullptr;
		}

		void addToHead(int info);
		void addToTail(int info);
		int deleteFromHead();//delete the head and return its info
		int deleteFromTail();//delete the tail and return its info
		void deleteNode(int info);
		bool isInList(int info);
		void showList()const;
	};
}