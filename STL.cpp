
/*
Project Name : Genaralised Data Structure library: 
Technology used : C++ - Programming
Aurthor Name : Aditya Ashok Ghadge
Date         : 8 Febuary 2023
Data Structures used : LinkedList,Stack,Queue,Binary Tree
*/

#include<iostream>
#include<stdlib.h>
#include<stdbool.h>
using namespace std;

//////////////////////////////////////--------------SINGLY LINEAR LINKED LIST------------------////////////////////////////////////////////////
template<class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

template<class T>
class SinglyLL
{
    public:
        
        struct nodeS<T>*First;
        SinglyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPosition(T no ,int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);
        int Count();
        void Display();

        bool DetectLoop();
};

template<class T>
SinglyLL<T> :: SinglyLL()
{
    First = NULL;
}

template<class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    struct nodeS <T>*newn = new nodeS<T>;

    newn->data = no;
    newn->next =  NULL;

    if(First == NULL) 
    {
        First = newn;
    }
    else  
    {
        newn->next = First;
        First = newn;
    }
}

template<class T>
void SinglyLL<T> :: InsertLast(T no)
{
    struct nodeS <T>*newn = new nodeS<T>;

    newn->data = no;
    newn->next =  NULL;

    if(First == NULL) 
    {
        First = newn;
    }
    else 
    {
        struct nodeS<T>*temp = First;

        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = newn;
    }
}

template<class T>
void SinglyLL<T>:: InsertAtPosition(T no, int ipos)
{
    int iCount = Count();

    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeS <T>*newn = new nodeS<T>;

        newn->data = no;
        newn->next = NULL;

        struct nodeS<T>*temp = First;
        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

template<class T>
void SinglyLL<T>:: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First -> next == NULL) 
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeS<T>*temp = First;
        First = First -> next;
        delete temp;
    }
}

template<class T>
void SinglyLL<T>:: DeleteLast()
{    
    if(First == NULL)   
    {
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeS<T>*temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
}

template<class T>
void SinglyLL<T>:: DeleteAtPosition(int ipos)
{
    int iCount = Count();

    if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }
    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
       struct nodeS<T>*temp1 = First;

        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }

        struct nodeS<T>*temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

    }
}

template<class T>
void SinglyLL<T> :: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    struct nodeS<T>*temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

template<class T>
int SinglyLL<T>:: Count()
{
    struct nodeS<T>*temp = First;
    int icnt  = 0;

    while(temp != NULL)
    {
        icnt++;
        temp = temp->next;
    }
    return icnt;
}

template <class T>
bool SinglyLL<T>:: DetectLoop()
{
    struct nodeS<T>* fast = First;
    struct nodeS<T>* slow = First;
    bool flag = false;

     while((fast != NULL) && (fast->next != NULL))
    {

        fast = fast->next->next;
        slow = slow->next;
        
        if(fast == slow)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

//////////////////////////////////////----------------SINGLY CIRCULAR LINKED LIST------------------////////////////////////////////////////////////

template<class T>
class SinglyCL
{
    public:
        struct nodeS<T>*First;
        struct nodeS<T>*Last;
        SinglyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};

template<class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
}

template<class T>
void SinglyCL<T>::InsertFirst(T no)
{
    struct nodeS <T>*newn = new nodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL)) 
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else 
    {
        newn->next = First;
        First = newn;
        (Last)->next = First;
    }
}

template<class T>
void SinglyCL<T>::InsertLast(T no)
{
    struct nodeS <T>*newn = new nodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL)) 
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else 
    {
        (Last) -> next = newn;
        Last = newn;
        (Last)->next = First;
    }
}

template<class T>
void SinglyCL<T>::DeleteLast()
{
     struct nodeS<T>*temp = First;

    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)   
    { 
        delete First;

        First = NULL;
        Last = NULL;
    }
    else   
    {
        while(temp->next != (Last))
        {
            temp = temp -> next;
        }

        delete temp->next;

        Last = temp; 
        (Last) ->next = First;
    }
}


template<class T>
void SinglyCL<T>::Display()
{
    cout<<"Elements of Linked list are : "<<"\n";
    struct nodeS<T>*temp = First;

    do
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }while(temp != Last->next);

    cout<<"\n";
}

template<class T>
int SinglyCL<T>::Count()
{
    struct nodeS<T>*temp = First;

    int iCnt = 0;
    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);
    return iCnt;
}

template<class T>
void SinglyCL<T>::DeleteFirst()
{
    struct nodeS<T>*temp = First;

    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;

        First = NULL;
        Last = NULL;
    }
    else 
    {
        First = (First)->next;

        delete temp;

        (Last) ->next = First;
    }
}

template<class T>
void SinglyCL<T>:: InsertAtPos(T no, int ipos)
{
    int iCount = Count();

    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeS <T>*newn = new nodeS<T>;

        newn->data = no;
        newn->next = NULL;

        struct nodeS<T>*temp = First;
        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

template<class T>
void SinglyCL<T>::DeleteAtPos(int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        struct nodeS<T>*temp1 = First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }   

        struct nodeS<T>*temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;
    }
}

////////////////////////////////////------------------DOUBLY LINEAR LINKED LIST------------------////////////////////////////////////////////////
template <class T>
struct nodeD
{
    T data;
    struct nodeD *next;
    struct nodeD *prev;
};


template<class T>
class DoublyLL
{
public:
    struct nodeD<T>*First;

    DoublyLL();

    void InsertFirst(T no);
    void InsertLast(T no);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(T no,int iPos);
    void DelAtPos(int iPos);

    void Display();
    int count();

};

template<class T>
DoublyLL<T> ::DoublyLL()
{
    First = NULL;
}

template<class T>
void DoublyLL<T> ::InsertFirst(T no)
{
     struct nodeD <T>*newn = new nodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((First) == NULL) 
    {
        First = newn;
    }
    else                   
    {
        (First)->prev = newn;
        newn->next = First;
        First = newn;
    }
}

template<class T>
void DoublyLL<T>::InsertLast(T no)
{
    struct nodeD<T>* temp = First;
    struct nodeD <T>*newn = new nodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    
    if((First) == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
}

template<class T>
void DoublyLL<T>::DeleteFirst()
{
    struct nodeD<T>* temp = First;
    if(First == NULL)
    {
        return;
    }
    else if((First)->next == NULL)
    {
        free(First);
        First = NULL;
    }
    else
    {
        First = (First)->next;
        free((First)->prev);
        (First)->prev = NULL;  
    }
}

template<class T>
void DoublyLL<T>::DeleteLast()
{
    struct nodeD<T>* temp = First;

    if(First == NULL)
    {
        return;
    }
    else if((First)->next == NULL)
    {
        free(First);
        First = NULL;
    }
    else
    {
        while(temp->next->next!= NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

template<class T>
void DoublyLL<T>::Display()
{
    printf("Elements of Linked list are\n");
    printf("NULL<=> ");

    while (First != NULL)
    {
        printf("| %d |<=> ",First->data);
        First = First->next;
    }
    printf("NULL\n");
}

template<class T>
int DoublyLL<T>::count()
{
    int iCnt = 0;
    while (First != NULL)
    {
        iCnt++;
        First = First->next;
    }
    
   return iCnt;
}

template<class T>
void DoublyLL<T> :: InsertAtPos( T  no, int ipos) //ERROR
{
    int NodeCnt = 0, iCnt = 0;
    struct nodeD<T> * newn = NULL;
    struct nodeD<T> * temp = NULL;

    NodeCnt = count();
    printf("Node count: %d\n",NodeCnt);

    if((ipos < 1) || (ipos > (NodeCnt + 1)))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == NodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeD<T> * newn = new nodeD<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;      // X

        temp =First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next->prev = newn;    // X
        temp->next = newn;
        newn->prev = temp;      // X
    }
}

//-


template<class T>
void DoublyLL<T>::DelAtPos(int iPos)
{
    int iCnt = 0;
    int NodeCnt = count();
    struct nodeD <T>* temp1 = First;
    struct nodeD <T>* temp2 = NULL;

    if((iPos < 1) ||  (iPos > NodeCnt))
    { 
        printf("Invalid position\n");
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == (NodeCnt))
    {
        DeleteLast();   
    }
    else
    {
        for(iCnt = 1;iCnt < (iPos-1);iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        free(temp2);
    }
}


////////////////////////////////////----------------DOUBLY CIRCULAR LINKED LIST------------------////////////////////////////////////////////////

template <class T>
class DoublyCL
{
    public:
        struct nodeD<T> * First;
        struct nodeD<T> * Last;
        DoublyCL();

        void InsertFirst(T   no);
        void InsertLast(T   no);
        void InsertAtPos(T   no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};

template<class T>
DoublyCL<T>::DoublyCL()
{
    First = NULL;
    Last = NULL;
}

template <class T>
void DoublyCL<T> :: InsertFirst(T   no)
{
    struct nodeD<T> * newn = new nodeD<T>; 

    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) 
    {
        First = newn;
        Last = newn;
    }
    else 
    {
        newn->next = First;
        (First)->prev = newn;
        First = newn; 
    }

    (First)->prev = Last;
    (Last)->next = First;
}

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
    struct nodeD<T> * newn = new nodeD<T>; 

    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) 
    {
        First = newn;
        Last = newn;
    }
    else 
    {
        (Last) -> next = newn;
        newn->prev = Last;
        Last = newn;
    }

    (First)->prev = Last;
    (Last)->next = First;
}

template <class T>
void DoublyCL<T> :: Display()
{
    struct nodeD<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }

    cout<<"Elements of Linked list are : "<<"\n";
    do
    {
        cout<<"| " <<temp->data<<"|<=> ";
        temp = temp -> next;
    }while(temp != Last->next);

    cout<<"\n";
}

template <class T>
int DoublyCL<T> :: Count()
{
    int iCnt = 0;
    struct nodeD<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        return iCnt;
    }

    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);

    return iCnt;
}

template <class T>
void DoublyCL<T> :: DeleteFirst()
{
    if(First == NULL && Last == NULL) 
    {
        return;
    }
    else if(First == Last) 
    {
        delete First;
        First = NULL;
        Last= NULL;
    }
    else 
    {
        (First) = (First) ->next;
        delete (Last)->next; 

        (First)->prev = Last;
        (Last)->next = First;
    }
}

template <class T>
void DoublyCL<T> :: DeleteLast()
{
    if(First == NULL && Last == NULL)
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last= NULL;
    }
    else  
    {
        Last = (Last) -> prev;
        delete (First)->prev; 

        (First)->prev = Last;
        (Last)->next = First;
    }
}

template <class T>
void DoublyCL<T> :: InsertAtPos(T   no, int ipos)
{
    int iNodeCnt = Count();
    struct nodeD<T> * newn = NULL;
    struct nodeD<T> * temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos ==1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new nodeD<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
}

template <class T>
void DoublyCL<T> :: DeleteAtPos(int ipos)
{
    int iNodeCnt = Count();
    struct nodeD<T> * temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}
////////////////////////////////////////////---------------STACK-------------//////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeST
{
    T data;
    struct nodeST *next;
};

template <class T>
class Stack
{
    public:
        struct nodeST<T> *First;
        
        Stack();
        bool IsStackEmpty();
        void Push(T no);      // Insert
        T Pop();              // Delete
        void Display();
        int Count();
        int getTop();
};

template <class T>
Stack<T> :: Stack()
{
    First = NULL;
}

template <class T>
bool Stack<T> :: IsStackEmpty()
{
   int iCount = Count();
    if(iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
int Stack<T> :: getTop()
{
    int TOPE = 0;
    if(First == NULL)
    {
        cout<<"Stack is empty."<<"\n";
    }
    else 
    {
        struct nodeST<T> *temp = First;
        TOPE = temp->data;
    }

    return TOPE;
}

template <class T>
void Stack<T> :: Push(T no)  // InsertFirst
{
    struct nodeST<T> *newn = new nodeST<T>;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }

    cout<<no<<" gets pushed in the stack succesfully"<<"\n";
}

template <class T>
T Stack<T> :: Pop()          // DeleteFirst
{
    if(First == NULL)
    {
        cout<<"Unable to pop the element as Stack is empty."<<"\n";
        return -1;
    }
    else 
    {
        T value = First -> data;
        struct nodeST<T> *temp = First;

        First = First ->next;
        delete temp;

        return value;
    }
}

template <class T>
void Stack<T> :: Display()
{
    if(First == NULL)
    {
        cout<<"Stack is empty."<<"\n";
    }
    else 
    {
        cout<<"Elements of stack are : "<<"\n";

        struct nodeST<T> *temp = First;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |-> ";
            temp = temp -> next;
        }
        cout<<" NULL"<<"\n";
    }
}

template <class T>
int Stack<T> :: Count()
{
    
        int iCnt = 0;
        struct nodeST<T> *temp = First;
        while(temp != NULL)
        {
            iCnt++;
            temp = temp -> next;
        }
   
   return iCnt;
}
////////////////////////////////////////////--------------QUEUE-------------///////////////////////////////////////////////////////////

template <class T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* front;
    Node* rear;

public:
    Queue();
    bool IsEmpty();
    void Enqueue(T value);
    void Dequeue();
    T Front();
    void Display();
};

template <class T>
Queue<T>::Queue() {
    front = NULL;
    rear = NULL;
}

template <class T>
bool Queue<T>::IsEmpty() {
    return front == NULL;
}

template <class T>
void Queue<T>::Enqueue(T value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

template <class T>
void Queue<T>::Dequeue() {
    if (IsEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }

    Node* temp = front;
    front = front->next;
    delete temp;
}

template <class T>
T Queue<T>::Front() {
    if (IsEmpty()) {
        cout << "Queue is empty. No front element." << endl;
        return T();
    }
    return front->data;
}

template <class T>
void Queue<T>::Display() {
    if (IsEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue elements: ";
    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    //doubly circular checked 
    //stack checked
    //queue checked

    Stack<int>obj;

    obj.Push(11);
    obj.Push(21);
    obj.Push(51);
    obj.Push(101);
    obj.Push(111);
    
    obj.Display();

    obj.Pop();
    obj.Display();

    
    return 0;
}