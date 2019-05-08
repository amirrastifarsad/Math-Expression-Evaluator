/*
* StringLink.h
*
* Created: 3/3/2019 9:38:21 PM
*  Author: amir
*/


#ifndef STRINGLINK_H_
#define STRINGLINK_H_

struct CharNode{
	CharNode* Next=nullptr;
	char value;
};

class StringLink
{
	public:
	CharNode* first;
	CharNode* Last;
	CharNode* iterator;
	StringLink(){
		first = nullptr;
		Last = nullptr;
		iterator = nullptr;
	}
	void PushFront(char value){
		if (first==nullptr)
		{
			first=new CharNode;
			first->value=value;
			Last=first;
		}
		else{
			CharNode* temp=new CharNode;
			temp->Next=first;
			first=temp;
			first->value=value;
		}
	}
	void PushBack(char value){
		if (first==nullptr)
		{
			first=new CharNode;
			first->value=value;
			Last=first;
		}
		else{
			
			Last->Next=new CharNode;
			Last=Last->Next;
			Last->value=value;
		}
	}
	void ResetIterator(){
		iterator=nullptr;
	}
	char next(){
		if (iterator==nullptr)
		{
			iterator=first;
			return iterator->value;
		}
		if (iterator->Next!=nullptr)
		{
			iterator=iterator->Next;
			return iterator->value;
		}
		else{
			return 'E';
		}
	}
	~StringLink() {
		iterator = first;
		CharNode* temp;
		while (iterator!=nullptr)
		{
			temp = iterator;
			iterator = iterator->Next;
			delete temp;
		}
	}
};

#endif /* STRINGLINK_H_ */