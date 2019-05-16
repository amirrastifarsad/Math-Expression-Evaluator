/*
 * CppExtensions.h
 *
 * Created: 5/4/2019 8:29:56 PM
 *  Author: amir
 */ 


#ifndef CPPEXTENSIONS_H_
#define CPPEXTENSIONS_H_

#include <stdlib.h>
void* operator new (size_t obj){
	return malloc(obj);
}
void* operator new[] (size_t obj){
	return malloc(obj);
}
void operator delete (void* obj){
	free(obj);
}
void operator delete[] (void* obj){
	free(obj);
}




#endif /* CPPEXTENSIONS_H_ */
