#include "ArrayList.h"

template<typename T>
ArrayList<T>::ArrayList()
{
	this->arr =(T*)malloc(sizeof(T)*def);
	this->cacp = def;
	this->used = 0;
}
template<typename T>
ArrayList<T>::ArrayList(ArrayList<T>& list)
{
	this->cacp = list.cacp;
	this->used = list.used;
	this->arr = (T*)malloc(sizeof(T)*list.cacp);
	for (int i = 0; i < list.cacp; i++)
		this->arr[i] = list.arr[i];
}

template<typename T>
ArrayList<T>::ArrayList(int cacp)
{
	this->arr = (T*)malloc(sizeof(T) * cacp);
	this->cacp = cacp;
	this->used = 0;
}

template<typename T>
ArrayList<T>::~ArrayList()
{
	unsigned char* mem = (unsigned char*)this->arr;
	for (int i = 0; i < sizeof(T) * sizeof(char); i++)
		mem[i] = 0xcc;
	
	if (this->arr)
		free(this->arr);
	this->arr = NULL;
	this->cacp = 0;
	this->used = 0;
}

template<typename T>
Set<T>& ArrayList<T>::add(T value)
{
	if (!this->isFull())
	{
		this->arr[used++] = value;
	}	
	else 
	{
		this->thisAlloc();
		this->arr[used++] = value;
	}

	return *this;
}
template<typename T>
bool ArrayList<T>::isFull()
{
	return this->used == this->cacp;
}
template<typename T>
T* ArrayList<T>::thisAlloc()
{
	T* t = (T*)malloc(sizeof(T)*(int)(cacp*1.5));
	for (size_t i = 0; i < cacp * 1.5; i++)
		t[i] = this->arr[i];
	if(arr)
		free(arr);
	arr = t;
	cacp = (int)(cacp * 1.5);
	t = NULL;
}

template<typename T>
void ArrayList<T>::clear()
{
	this->used = 0;
}
template<typename T>
T ArrayList<T>::get(int index)
{
	if (index >= used || index < 0) 
		return *(T*)NULL;
	return this->arr[index];
}
/**
 * @brief
 * @return
*/
template<typename T>
T* ArrayList<T>::toArray()
{
	return this->arr;
}
/**
 * @brief
 * @return
*/
template<typename T>
 bool ArrayList<T>::isEmpty()
 {
	 return this->used == 0;
 }
/**
 * @brief
 * @return
*/
 template<typename T>
 int ArrayList<T>::size()
 {
	 return this->used;
 }
/**
 * @brief
 * @return
*/
 template<typename T>
 bool ArrayList<T>::contains(T value)
 {
	 for (int i = 0; i < used; i++) 
	 {
		 if (value == this->arr[i])
			 return true;
	 }
	 return false;
 }
/**
 * @brief
 * @param set
*/
 template<typename T>
 void ArrayList<T>::removeAll(Set<T> set)
 {
	 for (int i = 0; i < set->size(); i++) 
		 if (contains(set->get(i)))
			 remove(i);
	 
 }
/**
 * @brief
 * @param index
*/
 template<typename T>
 void ArrayList<T>::remove(int index)
{
	 if (index < 0 || index >= used)
	 {
		 *(T*)NULL;
	 }
	 if (index == used-1)
	 {
		 used--;
		 return;
	 }
	 this->memcpy(this->arr+index,this->arr+(index-1));
	 this->used--;
}
/* template<typename T>
void ArrayList<T>::remove(T value)
{
	for (int i = 0; i < used; i++)
	{
		if (this->arr[i] == value)
			remove(i);
	}
}*/
template<typename T>
void ArrayList<T>::memcpy(void* desc, void* from, size_t t)
{
	unsigned char* A = (unsigned char*)desc;
	unsigned char* B = (unsigned char*)from;
	for (size_t i = 0; i < t; i++)
		A[i] = B[i];
}