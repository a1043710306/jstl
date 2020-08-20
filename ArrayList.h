#ifndef _ARRYLIST__
#define _ARRYLIST__

#include<stdio.h>
#include<stdlib.h>
#include "jstl.h"
template<typename T>
class ArrayList :public Set<T>
{
public:
	ArrayList();
	ArrayList(int);
	~ArrayList();
	void clear(); 
	virtual Set<T>& add(T vale);
	/**
	 * @brief
	 * @param index
	 * @return
	*/
	virtual T get(int index);
	/**
	 * @brief
	 * @return
	*/
	virtual T* toArray();
	/**
	 * @brief
	 * @return
	*/
	virtual bool isEmpty();
	/**
	 * @brief
	 * @return
	*/
	virtual int size();
	/**
	 * @brief
	 * @return
	*/
	virtual bool contains(T value) ;
	/**
	 * @brief
	 * @param set
	*/
	virtual void removeAll(Set<T> set);
	/**
	 * @brief
	 * @param index
	*/
	virtual void remove(int index) ;

	//virtual void remove(T value) ;
private:
	ArrayList(ArrayList<T>&);
	bool isFull();
	T* thisAlloc();
	void memcpy(void*,void*,size_t t);
	T* arr;
	int cacp;
	int used;
	const int def = 10;
};
#endif // _ARRYLIST

