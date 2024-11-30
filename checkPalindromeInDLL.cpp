// Given the head and tail of a doubly linked list . find if its a palindrome or not 

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* prev ;
    node* next ;

    node(int val)
    {
        data =val;
        next = NULL ;
        prev = NULL ;
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



bool Is_palindrome(node* &head  , node* &tail)
{
    node* T_head = head;
    node* T_tail = tail;

    while(T_head != T_tail && tail != head->prev)
    {
        if(T_head->data != T_tail->data)
        {
                return false;
        }

        T_head = T_head->next;
        T_tail = T_tail->prev;
    }
    return true;

}



int main()
{

DLL f;
f.insertion_E(1);
f.insertion_E(2);
f.insertion_E(4);
f.insertion_E(4);
f.insertion_E(2);
f.insertion_E(1);
f.display();
cout << Is_palindrome(f.head , f.tail);


    return 0;
}
