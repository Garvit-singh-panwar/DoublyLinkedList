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
    data = val;
    next = NULL;
    prev = NULL; 
}


};

// in single Linked list we studied there are blocks of memory and each block of memory is called a node and each node will point to the next node of Linked list

// [Data | nextNOde pointer]
//  [ ] -> [ ] -> [ ] -> [ ] -> NULL

//  in doubly linked list here we have two two links for every node
// means every node is points to its next node as well as previous node

// [ prevNOde pointer | Data | NextNode pointer]
//     NULL<- [ ] -> <- [ ] -> <- [ ] -> <- [ ] -> NULL

// the last node in our LL is called as tail node


// Advantages of doubly LinkedList over SinglyLinkedList

// 1. traversal is done in both direction
// 2. insertion and deletion becomed more efficient 


// Disadvantage of doubly linked list over single 
// 1. it took more space because of previous pointer



class DoublyLinkedList
{
    public:
    node* head;
    node* tail;

    DoublyLinkedList()
    {
        head = NULL ;
        tail = NULL;
    }

    void traversal();
    void insertionAt_head(int val);
    void insertionAt_tail(int val);
    void insertionAt_arbitary(int val , int k);
    void deletionAt_head();
    void deletionAt_end();
    void deletionAt_indx(int k);
};


// Implementation of a node in Doubly Linked list

//                                      |-----------------------|      |-------------------------
//              |----------      |------|----------------|      |------|-----------------       |      -------------|
//              V         |      V      |                |      V      |                |       V      |            V
//            NULL    [ prev | data | next ]  <---->  [ prev | data | next ]  <---->  [ prev | data | next ]       NULL
//                               ^                                                               ^
//                               |                                                               |
//                             head                                                             tail



// Traversal in doublyLinkedList
// like we said traversal is easy
// we can travel in 2 direction left to right or right to left 

//                  temp  ->       temp    ->   temp     ->    temp   ->     temp (stop)
//                  head             |            |              |            |
//                    |              |            |              |            |
//                    V              V            V              V            V
//       NULL <--->  [   ]  <--->  [   ]  <--->  [   ]  <--->  [   ]  <--->  NULL
//         ^           ^             ^             ^             ^
//         |           |             |             |             |
//         |           |             |             |            tail
// (stop)temp   <-   temp    <-    temp    <-    temp     <-    temp



void DoublyLinkedList :: traversal()
{
    node* temp = head;
    while (temp)
    {
        cout << temp->data << " -> " ;
        temp = temp->next;
    }

    cout << "NULL" << endl;
    

}




// HOw can we insert node in a Doubly LinkedList

// add a node at the start

// 
// 
//         [ ]           NULL <--- [ ] <---> [ ] <---> [ ] ---> NULL
//          ^                       ^
//       newnode                   head
//       newnode->next = head;     head->prev = newnode;
//       head = newnode;

void DoublyLinkedList:: insertionAt_head(int val)
    {

        if(head == NULL)
        {
            head =new node(val);
            tail = head;
            return ;
        }
        node* newnode = new node(val);
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        
    }


//  Add a node at the end    
//                                  newnode->prev          tail->next
//                                       |---------------------|
//                                       V                     V
//   [ ] <---> [ ] <---> [ ] <---> [ ]  --x--> NULL       |-- [ ] ---> NULL
//                                  ^                          ^      
//                                 tail                     newnode
//                                 tail->next = newnode     newnode->prev = tail
//                                                          tail = newnode

void DoublyLinkedList :: insertionAt_tail(int val)
{
    if(head == NULL)
    {
        head = new node(val);
        tail = head;
        return ;
    }

    node* newnode = new node(val);
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;

}


// Add a node in an arbitary position

// 
// 
// 
//                                             q->prev = newnode 
//             head,q      q                   q  (Loopstop)                i=2
//              |          |                   |                  
//              V          V                   V                     
//  indx        0          1                   2         3
//             [ ] <--- > [ ]  <-----x----->  [ ] <---> [ ] - > NULL
//  newindx     0          1        2          3         4  
//              ^          ^ \              / 
//              |          |  \            /
//              p          p   \          /
//                              \        /
//                               --[  ]--
//                      p->next = newnode
//                                newnode->next = q;
//                                newnode->prev = p


void DoublyLinkedList :: insertionAt_arbitary( int val , int k)
{
    node* p = head ;
    node* q = head->next;
    if(k == 0)
    {
        insertionAt_head(val);
        return;
    }

    int i ;
    for( i = 0  ; i < k-1 && q ; i++)
    {
        p = p->next;
        q = q->next;

    }
    if( k > i+1)
    {
        cout << "wrong indx" << endl;
        return ;
    }

    if(q == NULL)
    {
        insertionAt_tail(val);
        return;
    }

    node* newnode = new node(val);
    newnode -> prev = p;
    p->next = newnode;
    newnode-> next =  q;
    q->prev = newnode;
 


}

// Deletion on a Doubly Linked list

//  delete a node at the start
//      head   (head = head->next)
//       |     (head->prev = NULL)
//       V          V
//null<-[ ] <-x- > [  ] <-- > [  ] <- - >null
//       ^           ^
//       |           |
//      temp        head 
//  delete(temp);

void DoublyLinkedList :: deletionAt_head()
{

    if(head == NULL)
    {
        return;
    }
    node* temp = head;
    head = head->next;
    if(head->next == NULL)
    {
        tail = NULL;
    }
    else{
        head->prev = NULL;
    }
    
    delete(temp);


}


//   delete a node from the end
//                            temp
//                tail  <-    tail
//                 |           |
//                 V           V
//      [ ] <---> [  ] <--x-> [ ]->null
//                       |-----------|
// 
//                tail = tail->prev;
//                tail->next = NULL;
//                      delete(temp);

void DoublyLinkedList :: deletionAt_end()
{
  if(head == NULL)
  {
    return;
  }  

    node* temp = tail;
    tail = tail->prev;
    if(tail == NULL)
    {
        head = NULL;
    }else{
        tail->next = NULL;
    }
    delete(temp);

}



//  delete a node at an arbitary position
//             head       q         q                                       i=2
//              |         |         |                  (q = p->next) (stop when i = indx-1)
//              V         V         V     q->next->prev = q->prev;            
//  indx        0         1         2       3
//             [ ] <---> [  ]  <x> [ ] <x> [  ] - > NULL
//  newindx     0          1        X        2  
//              ^          ^ \             / 
//              |          |  \           /
//              p          p   \         /
//                              \       /
//                               p->next = q->next;                            
//                               delete(q);



void DoublyLinkedList :: deletionAt_indx(int k)
{

if(head == NULL ) return ;

node* p = head;
node* q = head->next;
int i = 0;
while(i<k-1 && q)
{
 q = q->next ;
 p = p->next ;
 i++;
}

if( k > i+1 )
{
    cout << "wrong indx" << endl;
    return ;
}

if(q == NULL)
{
    return ;
}

if(q->next == NULL )
{
    p->next = q->next;
}
else{
    p->next = q->next;
    q->next->prev = p;
}

delete(q);

}



int main()
{


    // This will show insertion at head function and traversal in Doubly LinkedList
    // uncomment and check don't forget to comment back

    // DoublyLinkedList Dll;
    // Dll.insertionAt_head(4);
    // Dll.traversal();    
    // Dll.insertionAt_head(3);
    // Dll.traversal();
    // Dll.insertionAt_head(2);
    // Dll.traversal();
    // Dll.insertionAt_head(1);
    // Dll.traversal();

    // This Will show insertion at tail and traversal in Doubly LinkedList
    // uncomment and check don't forget to comment back

    // DoublyLinkedList Dll;
    // Dll.insertionAt_tail(1);
    // Dll.traversal();
    // Dll.insertionAt_tail(2);
    // Dll.traversal();
    // Dll.insertionAt_tail(3);
    // Dll.traversal();
    // Dll.insertionAt_tail(4);
    // Dll.traversal();
    // Dll.insertionAt_tail(5);
    // Dll.traversal();


    // This will show insertion at an arbitary position
    // uncomment and check don't forget to comment back

    // DoublyLinkedList Dll;
    // Dll.insertionAt_head(1);
    // Dll.insertionAt_tail(2); 
    // Dll.insertionAt_tail(4);
    // Dll.insertionAt_tail(5);
    // Dll.insertionAt_tail(6);
    // Dll.insertionAt_tail(7);
    // Dll.traversal();
    // Dll.insertionAt_arbitary(3,2);
    // Dll.traversal();



    // This Will show deleteion at head and insertion function and traversal function 
    // uncomment and check don't forget to comment back

    // DoublyLinkedList Dll;
    // Dll.insertionAt_tail(1);
    // Dll.insertionAt_tail(2);
    // Dll.insertionAt_tail(3);
    // Dll.insertionAt_tail(4);
    // Dll.insertionAt_tail(5);
    // Dll.insertionAt_tail(6);
    // Dll.insertionAt_tail(7);
    // Dll.traversal();
    // Dll.deletionAt_head();
    // Dll.traversal();


    // this will show deletion at end position and insertion and traversal function
    // uncomment and check and don't forget to comment back

    // DoublyLinkedList Dll;
    // Dll.insertionAt_tail(1);
    // Dll.insertionAt_tail(2);
    // Dll.insertionAt_tail(3);
    // Dll.insertionAt_tail(4);
    // Dll.insertionAt_tail(5);
    // Dll.insertionAt_tail(6);
    // Dll.insertionAt_tail(7);
    // Dll.traversal();
    // Dll.deletionAt_end();
    // Dll.traversal();

    // This will show you deletion at an arbitary position and insertiuon function 
    // uncomment and check and don't forget to comment back

    // DoublyLinkedList Dll;
    // Dll.insertionAt_tail(1);
    // Dll.insertionAt_tail(2);
    // Dll.insertionAt_tail(3);
    // Dll.insertionAt_tail(4);
    // Dll.insertionAt_tail(5);
    // Dll.insertionAt_tail(6);
    // Dll.insertionAt_tail(7);
    // Dll.traversal();
    // Dll.deletionAt_indx(6);
    // Dll.traversal();



    return 0;
}