// Given the head of a doubly linked list , delete the nodes whose neighbour have the same value .
// traverse the list from right to left 

//  1  < - >  2  < - >  1  < - >  1 - >  NULL;

// outpur  1 < - > 1 < - > 1  - > NULL ;

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next ;
    node* prev ;
   
    node(int val)
    {
        data =val;
        next = NULL;
        prev = NULL;
    }

};


class DLL
{

    public: 
    node* head ;
    node* tail ;

    DLL()
    {
        head = NULL;
        tail = NULL;
    }

    void insertion_H(int val)
    {
        if(head == NULL)
        {
            head = new node(val);
            tail = head;
            return;

        }

        head->prev = new node(val);
        head->prev->next = head;
        head = head->prev;

    };


    void insertion_E(int val)
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
        while(temp )
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }


};

void deleteNode_WithSame_Neighbour(node* &head , node* &tail)
{

node* curr = tail->prev;

while( curr != head)
{
    node* prevNode = curr->prev;
    node* nextNode = curr->next;
    if(prevNode->data == nextNode->data)
    {
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        delete(curr);
    }

    curr = curr->prev;


}

}
    

int main()
{
    
DLL f;
f.insertion_E(1);
f.insertion_E(2);
f.insertion_E(3);
f.insertion_E(2);
f.insertion_E(1);
f.insertion_E(3);
f.insertion_E(1);
f.display();
deleteNode_WithSame_Neighbour(f.head,f.tail);
f.display();



    return 0;
}