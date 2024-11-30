// Given the head of a doubly Linked List. The values of the linked list are sorted in non - decreasing order .
// find if there exist a pair of distinct nodes such that the sum of there values is x .
// return the pair in the form of vector [l,r] , where l and r are the value stored in the 2 nodes pointed by the pointers.
// if there are multiple such pairs, return any of them . if there is no such pair return [-1,-1] 

#include<iostream>
#include<vector>

using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DLL
{   public:
    node* head ;
    node* tail;

    DLL()
    {
        head = NULL ;
        tail = NULL ;

    }


    void insertionH(int val)
    {
        if(head == NULL)
        {
            head = new node(val);
            tail = head ;
            return ;
        }

        head->prev = new node(val);
        head->prev->next = head;
        head = head->prev;
    }

    void insertionE(int val)
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
        node* temp = head ;
        while(temp)
        {
            cout << temp->data << " - > ";
            temp = temp->next;
        }

        cout << " NULL " << endl;
    }



};


// this is because our array is sorted in increasing order
vector <int> SumOfDistinctNode_isX(node* &head ,node* &tail, int &x)
{

vector <int> ans(2,-1);
if(head == tail) return ans;
 node* p = head;
 node* q = tail;
 while(p!=q && q->next != p)
 {
    if(p->data + q->data == x)
    {
        ans[0]=p->data;
        ans[1]=q->data;
        return ans;
    }
    if(p->data + q->data > x)
    {
        q = q->prev;
    }
    if(p->data + q->data < x)
    {
        p = p->next;
    }
    

 }

return ans;

} 


int main()
{
DLL f;
f.insertionH(2);
f.insertionH(1);
f.insertionE(3);
f.insertionE(4);
f.insertionE(5);
f.insertionE(6);
f.display();
int x = 3;
vector <int> ans = SumOfDistinctNode_isX(f.head,f.tail , x);

cout << "[" << ans[0] << "|" << ans[1] << "]" << endl;

    return 0;
}


