#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include<iostream>
using namespace std;

template<typename T>//템플릿을 선언해준다.
class Node{ 
public:
    T data; //데이터 값을 저장하는 변수이다.
    Node *link; // 노드를 연결해주는 포인터 변수이다.
    
    Node(T element){ //data에 element를 저장하고 link에 NULL을 저장해준다.
    	data = element;
	link = NULL;
    }
};

template<typename T> //템플릿을 선언해준다.
class LinkedList{
protected:
	Node<T> *first; //linkedlist의 첫번째 노드를 가리키는 변수이다.
	int current_size;// linkedlist의 크기를 저장할 변수이다.
public:
	LinkedList(){ // first값과 current_size를 각각 NULL과 0으로 초기화하는 생성자이다.
	    first = NULL;
	    current_size = 0;
	};
	int GetSize(){return current_size;};// linkedlist의 크기를 반환하는 멤버 함수이다.
	void Insert(T element);//linkedlist 앞부분에 element를 저장한다.
	virtual bool Delete(T & element);//linkedlist의 원소를 element에 저장한 뒤에 원소를 삭제한다.
	void Print();//형식에 맞게 linkedlist를 출력한다.
};

template<typename T>
void LinkedList<T>::Insert(T element){
    Node<T> *newnode = new Node<T>(element);//newnode에 메모리를 할당해준다.
    newnode->link = first;//newnode의 link에 first를 저장한다.
    first = newnode; //first에 newnode를 저장한다.
    current_size++; // current_size를 1만큼 증가시킨다.
}

template<typename T>
bool LinkedList<T>::Delete(T & element){
    if(first==NULL) return false;//first가 아무것도 가리키지 않으면 false를 리턴한다.
    Node<T> *current = first; //current에 first를 저장한다.
    Node<T> *previous = NULL; //previous에 NULL을 저장한다.
    while(1){
		if(current->link==NULL) //link가 NULL을 가리킬때 까지, 즉 노드의 끝까지 루프를 돌린다.
		{
		    if(previous)previous->link=current->link; //만약 previous가 존재하면 previous의 link에 NULL을 저장한다.
		    else first=first->link;//previous가 없다면 first에 NULL을 저장하고 루프를 종료한다.
		    break;
		}
		previous = current;//previous에 current를 저장한다.
		current = current->link;//current에 current의 link를 저장한다.
    }
    element = current->data;//element에 current의 data를 저장한다.
    delete current;//current에 할당된 메모리를 해제한다.
    current_size--;//current_size를 1만큼 감소시킨다.
    return true;//true를 반환한다.
}

template <typename T>
void LinkedList<T>::Print(){
	Node<T> *current = first;//current에 first를 저장한다.
	for(int i=0; i<current_size; i++){ // current_size 만큼 for루프를 통해 data를 형식에 맞게 출력한다.
		cout << "[" << i+1 << "|" << current->data << "]";
		if(i != current_size-1) cout << "->";
		current = current->link;
	}
	cout << endl;
}

#endif
