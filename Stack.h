#include "LinkedList.h"

template <typename T>//템플릿을 선언해준다.
class Stack : public LinkedList<T>{ // Stack 클래스는 LinkedList 클래스의 파생클래스이다.
public:
	bool Delete(T & element); // Delete 함수를 재정의 해준다.
};

template <typename T>//템플릿을 선언해준다.
bool Stack<T>::Delete(T & element){
	
	if(this->first == NULL) return false;//스택이 아무것도 가리키지 않을때 false를 반환한다.	
	Node<T> *now = this->first; //first를 now에 저장한다.
	
	element = this->first->data;//element에 first의 data값을 저장한다.
	this->first=this->first->link; //first에 다음 노드의 링크를 저장한다.
	delete now; // now에 할당된 메모리를 해제한다.
	this->current_size--; //linkedlist의 크기를 나타내는 current_size를 1 감소시킨다.

	return true; //true를 반환한다.

}
