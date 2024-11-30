// A critical point in a linked list is defined as either a local maxima or a local minima .
// Given a linkedlist tail , return an array of length 2 containing [min distance , max distance]
// where mindistance is the minimum distance between any two distinct critical point and maxdistance is the maximum distance between any two distinct critical point 
// if there re fewer than two critical points , return[-1,-1].

// note that a node can only be a local maxima/minima if there exist both a previous node and a next node

//  NULL <- 1 <-> 5 <-> 2 <-> 6 <-> 3 -> NULL
//              LMax  Lmin  Lmax


#include<iostream>
#include<limits.h>
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

bool is_CriticalPoint(node* &currNode)
{
    if(currNode->prev->data < currNode->data && currNode->next->data < currNode->data)
    {
        return true;
    }
    if(currNode->prev->data > currNode->data && currNode->next->data > currNode->data)
    {
        return true;
    }
    return false;
}


vector <int> MinAndMax_DistanceBetween_TwoCriticalPoint(node* &head , node* &tail)
{
    vector <int> ans(2,INT_MAX);  // inatilizing all value of ans as INT_MAX
    int firstCp = -1 ; //initially pos of 1st cp is -1 
    int lastCp = -1; // initially pos of last cp is = -1 ;

    node* currNode = tail->prev;

    // curr node = tail prev // because tail has only 1 neighbour

    if(currNode == NULL) // if currNode = NUll means there is only one node present 
    {
        ans[0] = ans[1] = -1;
        return ans;
    } 

// counting the pos of every node on which curr pointer is pointing
    int currpos = 0;
    while(currNode->prev)  // means when curr prev == NULL loop break
    {
        if(is_CriticalPoint(currNode)) // fun which check curr node is critical point or not
        {
            if(firstCp == -1)    // if firstcp is -1 means initially there is no critical point before it
            {
                firstCp = lastCp = currpos;    // we are updating our first and last critical point as curr pos 
            }
            else  // if first critical point is already arrived then this is our 2nd critical point so we are updating our min and max position
            {
                ans[0]= min(ans[0] ,currpos-lastCp );  // min distance
                ans[1] = currpos - firstCp; // max distance
                lastCp = currpos;   // now our last cp is our current cp
            }
        }

        currpos++;
        currNode = currNode->prev;
    }

    if(ans[0] == INT_MAX)
    {
        ans[0] = ans[1] = -1;
    }

return ans;
}

int main()
{

DLL f;
f.insertionAt_tail(1);
f.insertionAt_tail(2);
f.insertionAt_tail(3);
f.insertionAt_tail(5);
f.insertionAt_tail(4);
f.insertionAt_tail(6);
f.insertionAt_tail(7);
f.display();
vector <int> ans = MinAndMax_DistanceBetween_TwoCriticalPoint(f.head , f.tail);
cout << "[" << ans[0] << "|" << ans[1] << "]" << endl;
    return 0;
}