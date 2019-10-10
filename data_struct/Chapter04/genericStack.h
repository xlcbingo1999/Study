
#ifndef genericStack_H
#define genericStack_H
#include <cstdlib>
template <typename ElementType>
class Stack
{
private:
    struct Node
    {
        ElementType element;
        Node *next;
    };
    Node *top;
public:
    Stack(){
    	top=NULL;
	}
    ~Stack(){
    	Node* p;
    	while(top!=NULL){
    		p=top;
    		top=top->next;
    		delete p;
		}
	}
    void push(ElementType obj){
    	Node* q;
    	q=new Node;
    	if(q!=NULL){
    		q->next=top;
    		q->element=obj;
    		top=q;
		}
	}
    void pop(){
    	Node* q;
    	if(top!=NULL){
    		q=top;
    		top=top->next;
    		delete q;
      }
	}
    ElementType getTop ()const{
		return top->element;
	} 
    bool isEmpty ()const{
    	if(top==NULL)
	     	return 1;
      else
		 		return 0;
    }
}; 
#endif