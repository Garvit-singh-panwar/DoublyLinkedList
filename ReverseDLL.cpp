// Given a head of a Doubly LinkedList , reverse it


#include<iostream>
using namespace std;

class node
{

    public:
    int data;
    node* next;
    node* prev;

    node(int val)
    {
        data= val;
        next= NULL ;
        prev =NULL;

    }

};

class DLL
{

public:
node* head ;
node* tail;

DLL()
{
    head = NULL;
    tail = NULL;
}


void insertionAt_head(int val)
{
    if(head == NULL)
    {
        head = new node(val);
        tail = head;
        return ;
    }
    head ->prev = new node(val) ;
    head->prev->next = head;
    head = head->prev;

}

void insertionAt_tail(int val)
{
    if(head == NULL)
    {
        head = new node(val);
        tail = head;
        return ;
    }

    tail->next = new node(val);
    tail->next->prev = tail;
    tail = tail->next;

}

void display()
{
    node* temp = head;
    while(temp)
    {
        cout << temp->data << "  - >  ";
        temp = temp->next;
    }
    cout << "null" << endl;
}

};


void reverseA_DoublyLinkedList(node* &head , node* &tail)
{
    if(head == NULL) return ; 
    node* temp = head;

    while(temp)
    {
        swap(temp->next , temp->prev);
        temp = temp->prev;
    }

    swap(head,tail);

}


int main()
{

DLL f;
f.insertionAt_head(6);
f.insertionAt_head(5);
f.insertionAt_head(4);
f.insertionAt_head(3);
f.insertionAt_head(2);
f.insertionAt_head(1);
f.display();
reverseA_DoublyLinkedList(f.head ,f.tail);
f.display();



    return 0;

}