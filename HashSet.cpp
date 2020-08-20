#include "HashSet.h"
template<typename K>
HashSet<K>::HashSet(int cacp)
{
	HashSet<K> mythis = *this;
	mythis.valueSize = 0;
	mythis.cacp = cacp;
	mythis.head = new Node;
	mythis.tail = mythis.head;
	for (int i = 0; i < cacp - 1; i++)
	{
		Node* pNew = new Node;
		mythis.tail->next = pNew;
		mythis.tail = pNew;
	}
}

template<typename K>
HashSet<K>::HashSet()
{
	HashSet<K> mythis = *this;
	mythis.valueSize = 0;
	mythis.cacp = cacp;
	mythis.head = NULL;
	mythis.tail = mythis.head;
}

template<typename K>
HashSet<K>& HashSet<K>::mythis()
{
	return *this;
}
template<typename K>
Set<K>& HashSet<K>::add(K vale)
{
	HashSet<K> mythis = *this;
	Node* p = mythis.head;
	if (mythis.valueSize < mythis.cacp)
	{
		for (int i = 0; i < mythis.valueSize + 1; i++)
		{
			if (p->value == vale)
			{
				p->value = vale;
				mythis.valueSize++;
				return *this;
			}
			p = p->next;
		}
		p->value = vale;
		mythis.valueSize++;
	}
	else
	{
		p = new Node;
		p->value = vale;
		p->next = NULL;
		mythis.tail->next = p;
		mythis.tail = p;
		if (mythis.head == NULL)
			mythis.head = mythis.tail;
		mythis.valueSize++;
		mythis.cacp++;
	}
	return *this;
}
template<typename K>
bool HashSet<K>::isEmpty()
{
	return mythis().size() == 0;
}


template<typename K>
K HashSet<K>::get(int index)
{
	K* ptr = NULL;
	if (index > this->size() || index < 0)
	{
		return *ptr;
	}
	Node* P = this->head;
	for (int i = 0; i < index; i++)
	{
		P = P->next;
	}
	return P->value;
}

template<typename K>
int HashSet<K>::size()
{
	return this->valueSize;
}

template<typename K>
bool HashSet<K>::contains(K value)
{
	Node* p = this->head;
	for (int i = 0; i < this->valueSize; i++)
	{
		if (p->value == value)
		{
			return true;
		}
	}
	return false;
}

template<typename K>
void  HashSet<K>::remove(K value)
{
	Node* p = this->head;
	if (head != NULL && head->vale == value)
	{
		delete head;
		this->valueSize--;
		this->cacp--;
		head = NULL;
		tail = NULL;
		return;
	}
	for (int i = 0; i < this->valueSize - 1; i++)
	{
		if (p->next->value == value)
		{
			Node* del = p->next;
			p->next = del->next;
			del->next = NULL;
			delete del;
			this->valueSize--;
			this->cacp--;
			return;
		}
		p = p->next;
	}
	while (NULL != (this->tail = this->head))
	{
		this->tail = this->tail->next;
	}
}