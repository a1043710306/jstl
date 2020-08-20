
#ifndef _HashSet__

#define _HashSet__

#include<stdio.h>
#include "jstl.h"
template<typename K>
class HashSet : public Set<K> {
	int valueSize;
	int cacp;
	struct Node
	{
		K value;
		Node* next;
	};
	Node* tail;
	Node* head;
	HashSet<K>& mythis();
public:
	HashSet(int cacp);
	HashSet();
	HashSet<K> operator=(HashSet<K>);

	virtual Set<K>& add(K vale);

	virtual K get(int index);

	virtual K* toArray();

	virtual bool isEmpty();

	virtual int size();

	virtual bool contains(K value);

	virtual void removeAll(Set<K> set);

	virtual void remove(int index);

	virtual void remove(K value);
};
#endif // !_HashSet__