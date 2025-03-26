#include <iostream>
#include <stdexcept>

template <class T>
class LinkedList
{
	struct Node
	{
		T value;
		Node* next;
		Node* prev;
	};
public:
	class Iterator
	{
	public:
		Iterator() {}
		Iterator(Node* node) : current(node) {}
		inline Iterator& operator=(const Iterator& obj) { current = obj.current; return *this; }
		inline T& operator*() { return current->value; }
		inline Iterator& operator++(int) { current = current->next; return *this; }
		inline bool operator!=(const Iterator& obj) const { return current != obj.current; }
		friend void LinkedList<T>::insert(const Iterator& iterator, const T& value);
		friend void LinkedList<T>::erase(Iterator& iterator);
	private:
		Node* current;
	};

	Iterator getBeginList() const;
	Iterator getEndList() const;
	void insert(const Iterator& iterator, const T& value);
	void erase(Iterator& iterator);
public:
	explicit LinkedList() : size(0), begin(nullptr), end(nullptr) {}
	explicit LinkedList(const LinkedList& obj);
	explicit LinkedList(LinkedList&& obj);
	LinkedList& operator=(const LinkedList& obj);

	void pushBack(const T& value);
	void pushFront(const T& value);
	void popBack();
	void popFront();

	void clear();

	T back() const;
	T front() const;
	bool empty() const;

   ~LinkedList();
private:
	void copyLinkedList(const LinkedList& other);
	void pushFirstElement(const T& value);

	Node* begin;
	Node* end;
	size_t size;
};

template<class T>
auto LinkedList<T>::getBeginList() const -> Iterator
{
	if (empty())
		throw std::runtime_error("List is empty.");

	return Iterator(begin);
}

template<class T>
auto LinkedList<T>::getEndList() const -> Iterator
{
	return Iterator(end->next);
}

template<class T>
void LinkedList<T>::insert(const Iterator& iterator, const T& value)
{
	Node* tmpPrev = iterator.current;
	Node* tmpNext = iterator.current->next;
	Node* newNode = new Node;

	newNode->value = value;
	newNode->prev = tmpPrev;
	newNode->next = tmpNext;

	if (tmpNext == nullptr)
	{
		end->next = newNode;
		end = end->next;
	}
	else
	{
		tmpNext->prev = newNode;
		tmpPrev->next = newNode;
	}
	++size;
}

template<class T>
void LinkedList<T>::erase(Iterator& iterator)
{
	Node* tmpNext = iterator.current->next;
	Node* tmpPrev = iterator.current->prev;
	Node* tmpCurr = iterator.current;

	if (tmpPrev == nullptr && tmpNext == nullptr)
	{
		clear();
	}
	else if (tmpPrev == nullptr)
	{
		iterator.current = iterator.current->next;
		popFront();
	}
	else if (tmpNext == nullptr)
	{
		iterator.current = iterator.current->prev;
		popBack();
	}
	else
	{
		tmpPrev->next = tmpNext;
		tmpNext->prev = tmpPrev;
		iterator.current = iterator.current->next;
		delete tmpCurr;
		--size;
	}
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList& obj)
{
	copyLinkedList(obj);
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& obj)
{
	if (empty())
		clear();

	copyLinkedList(obj);
	return *this;
}

template<class T>
void LinkedList<T>::copyLinkedList(const LinkedList& obj)
{
	Node* tmpOther = obj.begin;
	begin = new Node;
	begin->value = tmpOther->value;
	begin->prev = nullptr;
	begin->next = nullptr;
	end = begin;
	tmpOther = tmpOther->next;

	while (tmpOther != nullptr)
	{
		Node* tmpPtr = end;
		end->next = new Node;
		end = end->next;
		end->prev = tmpPtr;
		end->next = nullptr;
		end->value = tmpOther->value;
		tmpOther = tmpOther->next;
	}
}

template<class T>
LinkedList<T>::LinkedList(LinkedList&& obj)
{
	begin = obj.begin;
	end = obj.end;
	size = obj.size;
	obj.begin = nullptr;
	obj.end = nullptr;
	obj.size = 0;
}

template<class T>
void LinkedList<T>::pushBack(const T& value)
{
	if (empty())
	{
		pushFirstElement(value);
	}
	else
	{
		Node* tmpPtr = end;
		end->next = new Node;
		end = end->next;
		end->prev = tmpPtr;
		end->next = nullptr;
		end->value = value;
	}
	++size;
}

template<class T>
void LinkedList<T>::pushFront(const T& value)
{
	if (empty())
	{
		pushFirstElement(value);
	}
	else
	{
		Node* tmpPtr = begin;
		begin->prev = new Node;
		begin = begin->prev;
		begin->next = tmpPtr;
		begin->prev = nullptr;
		begin->value = value;
	}
	++size;
}

template<class T>
void LinkedList<T>::pushFirstElement(const T& value)
{
	Node* head = new Node;
	head->value = value;
	head->prev = nullptr;
	head->next = nullptr;
	begin = head;
	end = head;
}

template<class T>
void LinkedList<T>::popBack()
{
	if (empty())
		throw std::runtime_error("List is empty.");

	Node* tmpPtr = end;
	end = end->prev;
	delete tmpPtr;
	--size;
}

template<class T>
void LinkedList<T>::popFront()
{
	if (empty())
		throw std::runtime_error("List is empty.");

	Node* tmpPtr = begin;
	begin = begin->next;
	delete tmpPtr;
	--size;
}

template<class T>
void LinkedList<T>::clear()
{
	if (empty())
		return;

	while (begin != end)
	{
		begin = begin->next;
		delete begin->prev;
	}

	delete end;
	size = 0;
}

template<class T>
T LinkedList<T>::back() const
{
	return end->value;
}

template<class T>
T LinkedList<T>::front() const
{
	return begin->value;
}

template<class T>
bool LinkedList<T>::empty() const
{
	return size == 0;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	clear();
}

int main()
{
	LinkedList<int> list;
	list.pushBack(10);
	list.pushFront(5);
	list.pushBack(20);

	for (LinkedList<int>::Iterator it = list.getBeginList(); it != list.getEndList(); it++)
	{
		if (*it == 5)
			list.erase(it);
		if (*it == 10)
			list.insert(it, 15);
	}

	while (!list.empty())
	{
		std::cout << list.front() << "\n";
		list.popFront();
	}
	
	return 0;
}