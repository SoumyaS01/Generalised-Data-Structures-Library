//////////////////////////////////////
/*
Author :               Soumya A Sheelavant
Project Description :  Generalised Data Structures Library
*/
//////////////////////////////////////////////////////
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////
// Singly Linear Linked List

template <class T>
struct SLLnode
{
    T Data;
    struct SLLnode *Next;
};

template <class T>
class Singly_Linkedlist
{
private:
    struct SLLnode<T> *Head;

public:
    Singly_Linkedlist();
    ~Singly_Linkedlist();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    void Display();
    inline int Count();
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
Singly_Linkedlist<T>::Singly_Linkedlist()
{
    Head = NULL;
}

template <class T>
Singly_Linkedlist<T>::~Singly_Linkedlist()
{
    struct SLLnode<T> *Temp = NULL;
    struct SLLnode<T> *Navigate = NULL;

    if (Head != NULL)
    {
        Navigate = Head;
        while (Navigate != NULL)
        {
            Temp = Navigate->Next;
            delete Navigate;
            Navigate = Temp;
        }
    }
}

template <class T>
void Singly_Linkedlist<T>::InsertFirst(T iNo)
{
    struct SLLnode<T> *newn = NULL;

    newn = new SLLnode<T>;

    newn->Next = NULL;
    newn->Data = iNo;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->Next = Head;
        Head = newn;
    }
}

template <class T>
void Singly_Linkedlist<T>::InsertLast(T iNo)
{
    struct SLLnode<T> *newn = NULL, *temp = Head;
    newn = new SLLnode<T>;

    newn->Next = NULL;
    newn->Data = iNo;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        while (temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = newn;
    }
}

template <class T>
void Singly_Linkedlist<T>::InsertAtPos(T iNo, int iPos)
{
    if ((Head == NULL) || (iPos > Count() + 1) || (iPos <= 0))
    {
        cout << "...You have entered wrong position...\n";
        return;
    }
    if (iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == (Count()) + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        struct SLLnode<T> *newn = NULL, *temp = Head;

        newn = new SLLnode<T>;
        if (newn == NULL)
        {
            cout << "Failed to allocate memory\n";
            return;
        }

        newn->Next = NULL;
        newn->Data = iNo;

        for (int i = 1; i <= (iPos - 2); i++)
        {
            temp = temp->Next;
        }

        newn->Next = temp->Next;
        temp->Next = newn;
    }
}

template <class T>
void Singly_Linkedlist<T>::Display()
{
    struct SLLnode<T> *Temp = Head;

    while (Temp != NULL)
    {
        cout << "[ " << Temp->Data << " ]->";
        Temp = Temp->Next;
    }
    cout << "NULL\n";
}

template <class T>
inline int Singly_Linkedlist<T>::Count()
{
    struct SLLnode<T> *Temp = Head;
    int iCnt = 0;

    while (Temp != NULL)
    {
        iCnt++;
        Temp = Temp->Next;
    }
    return iCnt;
}

template <class T>
void Singly_Linkedlist<T>::DeleteFirst()
{
    struct SLLnode<T> *temp = Head;

    if (Head == NULL)
    {
        cout << "Linked list is empty...\n";
        return;
    }
    else
    {
        Head = Head->Next;
        delete temp;
    }
}

template <class T>
void Singly_Linkedlist<T>::DeleteLast()
{
    if (Head == NULL)
    {
        cout << "Linked list is empty...\n";
        return;
    }
    else if (Head->Next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct SLLnode<T> *temp1 = Head, *temp2 = NULL;

        while (temp1->Next->Next != NULL)
        {
            temp1 = temp1->Next;
        }

        temp2 = temp1->Next;
        temp1->Next = NULL;
        free(temp2);
    }
}

template <class T>
void Singly_Linkedlist<T>::DeleteAtPos(int iPos)
{
    if ((Head == NULL) || (iPos > Count()) || (iPos <= 0))
    {
        cout << "Linked list is empty or you have entered invalid position...\n";
        return;
    }
    else if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == (Count()))
    {
        DeleteLast();
    }
    else
    {
        struct SLLnode<T> *temp1 = Head, *temp2 = NULL;

        for (int i = 1; i <= (iPos - 2); i++)
        {
            temp1 = temp1->Next;
            ++i;
        }

        temp2 = temp1->Next;
        temp1->Next = temp2->Next;
        delete temp2;
    }
}
// end of Singly Linear Linked List
////////////////////////////////////////////////////////

///////////////////////////////////////////////////////

// Singly Circular Linked List

template <class T>
struct SCLLnode
{
    T data;
    struct SCLLnode *next;
};

template <class T>
class SinglyCLL
{
private: //            Characteristics
    struct SCLLnode<T> *Head;
    struct SCLLnode<T> *Tail;

public:          //              Behaviours
    SinglyCLL(); //              Constructor
    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no, int ipos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);
    void Display();
    int Count();
};

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    Head = NULL;
    Tail = NULL;
}

template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct SCLLnode<T> *newn = NULL;

    newn = new SCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if ((Head == NULL) && (Tail == NULL)) //    if LL is empty
    {
        Head = newn;
        Tail = newn;
    }
    else //            if LL contains atleast one node
    {
        newn->next = Head;
        Head = newn;
    }
    Tail->next = Head; //           imp
}

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct SCLLnode<T> *newn = NULL;

    newn = new SCLLnode<T>; //    malloc i C

    newn->data = no;
    newn->next = NULL;

    if ((Head == NULL) && (Tail == NULL)) //    if LL is empty
    {
        Head = newn;
        Tail = newn;
    }
    else //            if LL contains atleast one node
    {
        Tail->next = newn;
        Tail = newn;
    }
    Tail->next = Head; //      imp
}

template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int ipos)
{
    int iSize = Count();

    if ((ipos < 1) || (ipos > iSize + 1))
    {
        cout << "You have entered invalid position\n";
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(no); //         method is from same class so no need of object
    }
    else if (ipos == iSize + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct SCLLnode<T> *newn = NULL;
        newn = new SCLLnode<T>;

        newn->data = no;
        newn->next = NULL;

        struct SCLLnode<T> *temp = Head;
        int iCnt = 0;

        for (iCnt = 1; iCnt < (ipos - 1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if (Head == NULL && Tail == NULL) //    If LL is empty
    {
        cout << "Linked list is empty...\n";
        return;
    }
    else if (Head == Tail) //       If LL contains 1 node
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else //        If LL contains more than 1 node
    {
        Head = Head->next;

        delete Tail->next;

        Tail->next = Head;
    }
}

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    if (Head == NULL && Tail == NULL) //    If LL is empty
    {
        cout << "Linked list is empty...\n";
        return;
    }
    else if (Head == Tail) //       If LL contains 1 node
    {
        delete Head; //  Intead of Head we can write Tail also
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        struct SCLLnode<T> *temp = Head;

        while (temp->next != Tail)
        {
            temp = temp->next;
        }
        delete Tail;
        Tail = temp;
        Tail->next = Head;
    }
}

template <class T>
void SinglyCLL<T>::DeleteAtPos(int ipos)
{
    int iSize = Count();

    if ((ipos < 1) || (ipos > iSize))
    {
        cout << "Invalid position\n";
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst(); //         method is from same class so no need of object
    }
    else if (ipos == iSize + 1)
    {
        DeleteLast();
    }
    else
    {
        struct SCLLnode<T> *temp1 = Head;
        int iCnt = 0;
        struct SCLLnode<T> *temp2 = NULL;

        for (iCnt = 1; iCnt < ipos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
}

template <class T>
void SinglyCLL<T>::Display()
{
    struct SCLLnode<T> *temp = Head;

    if ((Head == NULL) && (Tail == NULL)) //         if LL is empty. Filter is imp otherwise it will give segmentation fault.
    {
        cout << "Linked list is empty...\n";
        return;
    }

    do
    {
        cout << "[ " << temp->data << " ]->";
        temp = temp->next;
    } while (temp != Head);

    cout << endl;
}

template <class T>
int SinglyCLL<T>::Count()
{
    int iCnt = 0;
    struct SCLLnode<T> *temp = Head;

    if ((Head == NULL) && (Tail == NULL)) //         if LL is empty. Filter is imp otherwise it will give segmentation fault.
    {
        return 0;
    }

    do
    {
        iCnt++;
        temp = temp->next;
    } while (temp != Head);

    return iCnt;
}
// End of Singly Circular Linked List
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
// Generic Doubly Linear Linked List
template <class T>
struct DLLnode
{
    T data;
    DLLnode *next;
    DLLnode *prev;
};

template <class T>
class Doubly_linkedList
{
private:
    struct DLLnode<T> *Head;

public:
    Doubly_linkedList();
    ~Doubly_linkedList();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    void Display();
    int Count();
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
Doubly_linkedList<T>::Doubly_linkedList()
{
    Head = NULL;
}

template <class T>
Doubly_linkedList<T>::~Doubly_linkedList()
{
    struct DLLnode<T> *temp = Head;

    if (Head != NULL)
    {
        while (Head != NULL)
        {
            Head = Head->next;
            delete temp;
            temp = Head;
        }
    }
}

template <class T>
void Doubly_linkedList<T>::InsertFirst(T iNo)
{
    struct DLLnode<T> *newn = NULL;

    newn = new DLLnode<T>;
    if (newn == NULL)
    {
        cout << "Unable to allocate new node memory..\n";
        return;
    }

    newn->next = NULL;
    newn->prev = NULL;
    newn->data = iNo;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        Head->prev = newn;
        newn->next = Head;
        Head = newn;
    }
}

template <class T>
void Doubly_linkedList<T>::InsertLast(T iNo)
{
    struct DLLnode<T> *newn = NULL, *temp = Head;
    newn = new DLLnode<T>;

    if (newn == NULL)
    {
        cout << "Unable to allocate new node memory..\n";
        return;
    }

    newn->next = NULL;
    newn->prev = NULL;
    newn->data = iNo;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
}

template <class T>
void Doubly_linkedList<T>::InsertAtPos(T iNo, int iPos)
{
    if ((iPos > Count() + 1) || (iPos <= 0))
    {
        cout << "You have entered invalid postion..\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == (Count()) + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        struct DLLnode<T> *newn = NULL, *temp = Head;

        newn = new DLLnode<T>;

        newn->next = NULL;
        newn->prev = NULL;
        newn->data = iNo;

        for (int i = 1; i <= (iPos - 2); i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;
    }
}

template <class T>
void Doubly_linkedList<T>::Display()
{
    struct DLLnode<T> *temp = Head;

    while (temp != NULL)
    {
        cout << "[ " << temp->data << " ]->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

template <class T>
int Doubly_linkedList<T>::Count()
{
    struct DLLnode<T> *temp = Head;
    int iCnt = 0;

    while (temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}

template <class T>
void Doubly_linkedList<T>::DeleteFirst()
{
    struct DLLnode<T> *temp = Head;

    if (Head == NULL)
    {
        cout << "Linked list is already empty...\n";
        return;
    }
    else
    {
        Head = Head->next;
        Head->prev = NULL;

        delete temp;
    }
}

template <class T>
void Doubly_linkedList<T>::DeleteLast()
{
    if (Head == NULL)
    {
        cout << "Linked list is already empty...\n";
        return;
    }
    else if (Head->next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct DLLnode<T> *temp = Head;

        while ((temp->next) != NULL)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        delete temp;
    }
}

template <class T>
void Doubly_linkedList<T>::DeleteAtPos(int iPos)
{
    if ((Head == NULL) || (iPos > Count()) || (iPos <= 0))
    {
        cout << "Linked list is already empty or you have entered invalid position...\n";
        return;
    }
    else if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == (Count()))
    {
        DeleteLast();
    }
    else
    {
        struct DLLnode<T> *temp = Head;

        for (int i = 1; i <= (iPos - 2); i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}
// End of Generic Doubly Linear Linked List
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
// Generic Doubly Circular Linked List

template <class T>
struct DCLLnode
{
    T data;
    struct DCLLnode *next;
    struct DCLLnode *prev;
};

template <class T>
class DoublyCLL
{
private: //  Characteristics
    struct DCLLnode<T> *Head;
    struct DCLLnode<T> *Tail;
    int CountNode;

public: // behaviour
    DoublyCLL();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    int Count();
    void Display();
};

template <class T>
DoublyCLL<T>::DoublyCLL()
{
    Head = NULL;
    Tail = NULL;
    CountNode = 0;
}

template <class T>
void DoublyCLL<T>::InsertFirst(T iNo)
{
    struct DCLLnode<T> *newn = NULL;

    newn = new DCLLnode<T>;

    newn->next = NULL;
    newn->prev = NULL;
    newn->data = iNo;

    if ((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Tail->next = newn;
        newn->prev = Head;
        Head = newn;
    }
    CountNode++;
}

template <class T>
void DoublyCLL<T>::InsertLast(T iNo)
{
    struct DCLLnode<T> *newn = new DCLLnode<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if ((Head == NULL) && (Tail == NULL)) //    if LL is empty
    {
        Head = newn;
        Tail = newn;
    }
    else //      if CLL contains atleast one node
    {
        newn->prev = Tail;
        newn->next = Head;
        Tail->next = newn;
        Tail = newn;
        Head->prev = Tail;
    }
    CountNode++;
}

template <class T>
void DoublyCLL<T>::InsertAtPos(T iNo, int iPos)
{
    if ((iPos > CountNode + 1) || (iPos <= 0))
    {
        cout << "You have entered invalid position...\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == CountNode + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        struct DCLLnode<T> *newn = NULL;
        struct DCLLnode<T> *temp = Head;

        newn = new DCLLnode<T>;

        newn->next = NULL;
        newn->prev = NULL;
        newn->data = iNo;

        for (int i = 1; i <= (iPos - 2); i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        CountNode++;
    }
}

template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    if (Head == NULL && Tail == NULL) //    If LL is empty
    {
        cout << "Linked list is already empty...\n";
        return;
    }
    else if (Head == Tail) //       If LL contains 1 node
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        delete Tail->next;
        Tail->next = Head;
    }
    CountNode--;
}

template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if (Head == NULL && Tail == NULL) //    If LL is empty
    {
        cout << "Linked list is already empty...\n";
        return;
    }
    else if (Head == Tail) //       If LL contains 1 node
    {
        delete Head; //  Intead of Head we can write Tail also
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        struct DCLLnode<T> *temp = Head;

        while (temp->next != Head)
        {
            temp = temp->next;
        }

        temp->prev->next = Head;
        temp->prev = Tail;
        delete temp;
    }

    CountNode--;
}

template <class T>
void DoublyCLL<T>::DeleteAtPos(int iPos)
{
    if ((Head == NULL) || (iPos > CountNode) || (iPos <= 0))
    {
        cout << "Linked list is already empty or you have entered invalid position...\n";
        return;
    }
    else if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == (Count()))
    {
        DeleteLast();
    }
    else
    {
        struct DCLLnode<T> *temp = Head;

        for (int i = 1; i <= (iPos - 2); i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        CountNode--;
    }
}

template <class T>
void DoublyCLL<T>::Display()
{
    struct DCLLnode<T> *temp = Head;

    if ((Head == NULL) && (Tail == NULL)) //         if LL is empty. Filter is imp otherwise it will give segmentation fault.
    {
        cout << "Linked list is already empty...\n";
        return;
    }

    do //          drawback: LL should atleast contain 2 nodes to use display
    {
        cout << "[ " << temp->data << " ]->";
        temp = temp->next;
    } while (temp != Head);

    cout << endl;
}

template <class T>
int DoublyCLL<T>::Count()
{
    return CountNode;
}
// End of Generic Doubly Circular Linked List
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
// Generic Stack
template <class T>
struct Stacknode
{
    T data;
    struct Stacknode *next;
};

template <class T>
class Stack
{
public:
    struct Stacknode<T> *Head;
    int Count;

    Stack();
    void Push(T); //  InsertFirst
    void Pop();   //   DeleteFirst
    void Display();
    int CountNode();
};

template <class T>
Stack<T>::Stack()
{
    Head = NULL;
    Count = 0;
}

template <class T>
void Stack<T>::Push(T no)
{
    struct Stacknode<T> *newn = NULL;
    newn = new Stacknode<T>;

    newn->data = no;
    newn->next = NULL;

    newn->next = Head; // if empty= NULL; if not empty= first element address
    Head = newn;

    Count++;
}

template <class T>
void Stack<T>::Pop()
{
    T no; // to display deleting element.

    if (Count == 0)
    {
        cout << "Stack is empty" << endl;
        return;
    }

    no = Head->data;
    struct Stacknode<T> *temp = Head;
    Head = Head->next;
    delete temp;

    Count--;
    cout << "Removed element is : " << no << endl;
}

template <class T>
void Stack<T>::Display()
{
    cout << "Elements in Stack are: " << endl;
    struct Stacknode<T> *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}

template <class T>
int Stack<T>::CountNode()
{
    return Count;
}
// End of Generic Stack
//////////////////////////////////////////////////////

///////////////////////////////////////////////////////
// Generic Queue

template <class T>
struct Qnode
{
    T data;
    struct Qnode *next;
};

template <class T>
class Queue
{
public:
    struct Qnode<T> *Head;
    int Count;

    Queue();
    void Enqueue(T); // InsertLast
    void Dequeue();  //  DeleteFirst
    void Display();
    int CountNode();
};

template <class T>
Queue<T>::Queue()
{
    Head = NULL;
    Count = 0;
}

template <class T>
void Queue<T>::Enqueue(T no)
{
    struct Qnode<T> *newn = NULL;
    newn = new Qnode<T>;

    newn->data = no;
    newn->next = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        struct Qnode<T> *temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    Count++;
}

template <class T>
void Queue<T>::Dequeue()
{
    T no;

    if (Count == 0)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    no = Head->data;
    struct Qnode<T> *temp = Head;
    Head = Head->next;
    delete temp;

    Count--;
    cout << "Removed element is : " << no << endl;
}

template <class T>
void Queue<T>::Display()
{
    cout << "Elements in Queue are: " << endl;
    struct Qnode<T> *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}

template <class T>
int Queue<T>::CountNode()
{
    return Count;
}
// End of Generic Queue
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
// Generic Binary Search Tree

template <class T>
struct BSTnode
{
    T data;
    struct BSTnode<T> *Lchild;
    struct BSTnode<T> *Rchild;
};

template <class T>
class BSTree
{
public:
    struct BSTnode<T> *Head;

public:
    BSTree();
    void Insert(struct BSTnode<T> **, T);
    void Inorder(struct BSTnode<T> *);
    void Preorder(struct BSTnode<T> *);
    void PostOrder(struct BSTnode<T> *);
};

template <class T>
BSTree<T>::BSTree()
{
    Head = NULL;
}

template <class T>
void BSTree<T>::Insert(struct BSTnode<T> **root, T iNo)
{
    struct BSTnode<T> *temp = Head;
    struct BSTnode<T> *newn = new BSTnode<T>;

    newn->data = iNo;
    newn->Lchild = NULL;
    newn->Rchild = NULL;

    if (Head == NULL) // if BST is empty
    {
        Head = newn;
        *root = Head;
    }
    else
    {
        while (1)
        {
            if (iNo > temp->data) //     greater than move to right
            {
                if (temp->Rchild == NULL)
                {
                    temp->Rchild = newn;
                    break;
                }
                temp = temp->Rchild;
            }
            else if (iNo < temp->data) //  less than move to left
            {
                if (temp->Lchild == NULL)
                {
                    temp->Lchild = newn;
                    break;
                }
                temp = temp->Lchild;
            }
            else if (iNo == temp->data)
            {
                free(newn);
                cout << "Same data already exists \n";
                break;
            }
        }
    }
}

template <class T>
void BSTree<T>::Inorder(struct BSTnode<T> *temp)
{
    if (temp != NULL)
    {
        Inorder(temp->Lchild);
        cout << temp->data << "\n";
        Inorder(temp->Rchild);
    }
}

template <class T>
void BSTree<T>::Preorder(struct BSTnode<T> *temp)
{
    if (temp != NULL)
    {
        cout << temp->data << "\n";
        Preorder(temp->Lchild);
        Preorder(temp->Rchild);
    }
}

template <class T>
void BSTree<T>::PostOrder(struct BSTnode<T> *temp)
{
    if (temp != NULL)
    {
        PostOrder(temp->Lchild);
        PostOrder(temp->Rchild);
        cout << temp->data << "\n";
    }
}
//  End of Generic Binary Search Tree
/////////////////////////////////////////////////////////////

int main()
{

    // 3487
    // BST root pointer
    struct BSTnode<int> *iFirst = NULL;
    struct BSTnode<float> *fFirst = NULL;
    struct BSTnode<char> *chFirst = NULL;
    struct BSTnode<double> *dFirst = NULL;

    // Objects of Singly Linear Linked List
    Singly_Linkedlist<int> SLLobj1;
    Singly_Linkedlist<float> SLLobj2;
    Singly_Linkedlist<char> SLLobj3;
    Singly_Linkedlist<double> SLLobj4;

    // Objects of Singly Circular Linked List
    SinglyCLL<int> SCLobj1;
    SinglyCLL<float> SCLobj2;
    SinglyCLL<char> SCLobj3;
    SinglyCLL<double> SCLobj4;

    // Objects of Doubly Linear Linked List
    Doubly_linkedList<int> DLLobj1;
    Doubly_linkedList<float> DLLobj2;
    Doubly_linkedList<char> DLLobj3;
    Doubly_linkedList<double> DLLobj4;

    // Objects of Doubly Circular Linked List
    DoublyCLL<int> DCLobj1;
    DoublyCLL<float> DCLobj2;
    DoublyCLL<char> DCLobj3;
    DoublyCLL<double> DCLobj4;

    // Objects of Stack
    Stack<int> stkobj1;
    Stack<float> stkobj2;
    Stack<char> stkobj3;
    Stack<double> stkobj4;

    // Objects of Queue
    Queue<int> qobj1;
    Queue<float> qobj2;
    Queue<char> qobj3;
    Queue<double> qobj4;

    // Object of BST
    BSTree<int> tobj1;
    BSTree<float> tobj2;
    BSTree<char> tobj3;
    BSTree<double> tobj4;

    int iSelect = 1;
    int iChoice = 1;
    int iPos = 0;
    int iNo = 0;
    float fNo = 0.0;
    char chNo = '\0';
    double dNo = 0.0;
    int iDataType = 0;

    while (iChoice != 0)
    {
        cout << "Generic Data Structure Menu...\n";
        cout << "Choose a Data Structure:\n";
        cout << "1. Singly Linear Linked List\n";
        cout << "2. Singly Circular Linked List\n";
        cout << "3. Doubly Linear Linked List\n";
        cout << "4. Doubly Circular Linked List\n";
        cout << "5. Stack\n";
        cout << "6. Queue\n";
        cout << "7. Binary Search Tree \n";

        cin >> iChoice;

        switch (iChoice)
        {
        case 1:
            cout << "You have selected Singly Linear Linked List...\n";
            cout << "Enter Linked list's data type: \n";
            cout << "1 : Integer\n";
            cout << "2 : Float\n";
            cout << "3: Character\n";
            cout << "4: Double\n";
            cin >> iDataType;

            switch (iDataType)
            {
            case 1:
                cout << "You have selected Integer data type...\n";
                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1  : Insert at first position \n";
                    cout << "2  : Insert at last position \n";
                    cout << "3  : Insert at given position \n";
                    cout << "4  : Delete first node \n";
                    cout << "5  : Delete last node \n";
                    cout << "6  : Delete node at give position \n";
                    cout << "7  : Display elements \n";
                    cout << "8  : Count number of nodes \n";

                    cin >> iSelect;

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to Insert first : \n";
                        cin >> iNo;
                        SLLobj1.InsertFirst(iNo);
                        break;

                    case 2:
                        cout << "Enter data to Insert last : \n";
                        cin >> iNo;
                        SLLobj1.InsertLast(iNo);
                        break;

                    case 3:
                        cout << "Enter data to Insert at position: \n";
                        cin >> iNo;
                        cout << "Enter a position: \n";
                        cin >> iPos;
                        SLLobj1.InsertAtPos(iNo, iPos);
                        break;

                    case 4:
                        SLLobj1.DeleteFirst();
                        break;

                    case 5:
                        SLLobj1.DeleteLast();
                        break;

                    case 6:
                        cout << "Enter a position of element to delete: \n";
                        cin >> iPos;
                        SLLobj1.DeleteAtPos(iPos);
                        break;

                    case 7:
                        SLLobj1.Display();
                        break;

                    case 8:
                        iNo = SLLobj1.Count();
                        cout << "Number of Nodes are : " << iNo << "\n";
                        break;

                    case 0:
                        cout << "Exiting Singly Linear Linked List\n";
                        break;

                    default:
                        cout << "Please enter valid choice\n";
                        break;
                    }
                }
                break;
                iSelect = 1;

            case 2:
                cout << "You have selected Float data Type...\n";
                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1  : Insert at first position \n";
                    cout << "2  : Insert at last position \n";
                    cout << "3  : Insert at given position \n";
                    cout << "4  : Delete first node \n";
                    cout << "5  : Delete last node \n";
                    cout << "6  : Delete node at give position \n";
                    cout << "7  : Display elements \n";
                    cout << "8  : Count number of nodes \n";

                    cin >> iSelect;

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to Insert first : \n";
                        cin >> fNo;
                        SLLobj2.InsertFirst(fNo);
                        break;

                    case 2:
                        cout << "Enter data to Insert last : \n";
                        cin >> fNo;
                        SLLobj2.InsertLast(fNo);
                        break;

                    case 3:
                        cout << "Enter data to Insert at position: \n";
                        cin >> fNo;
                        cout << "Enter a position: \n";
                        cin >> iPos;
                        SLLobj2.InsertAtPos(fNo, iPos);
                        break;

                    case 4:
                        SLLobj2.DeleteFirst();
                        break;

                    case 5:
                        SLLobj2.DeleteLast();
                        break;

                    case 6:
                        cout << "Enter a position of element to delete: \n";
                        cin >> iPos;
                        SLLobj2.DeleteAtPos(iPos);
                        break;

                    case 7:
                        SLLobj2.Display();
                        break;

                    case 8:
                        fNo = SLLobj2.Count();
                        cout << "Number of Nodes are : " << fNo << "\n";
                        break;

                    case 0:
                        cout << "Exiting Singly Linear Linked List\n";
                        break;

                    default:
                        cout << "Please enter valid choice\n";
                        break;
                    }
                }
                break;
                iSelect = 1;

            case 3:
                cout << "You have selected character data type...\n";

                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1  : Insert at first position \n";
                    cout << "2  : Insert at last position \n";
                    cout << "3  : Insert at given position \n";
                    cout << "4  : Delete first node \n";
                    cout << "5  : Delete last node \n";
                    cout << "6  : Delete node at give position \n";
                    cout << "7  : Display elements \n";
                    cout << "8  : Count number of nodes \n";

                    cin >> iSelect;

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to Insert first : \n";
                        cin >> chNo;
                        SLLobj3.InsertFirst(chNo);
                        break;

                    case 2:
                        cout << "Enter data to Insert last : \n";
                        cin >> chNo;
                        SLLobj3.InsertLast(chNo);
                        break;

                    case 3:
                        cout << "Enter data to Insert at position: \n";
                        cin >> chNo;
                        cout << "Enter a position: \n";
                        cin >> iPos;
                        SLLobj3.InsertAtPos(chNo, iPos);
                        break;

                    case 4:
                        SLLobj3.DeleteFirst();
                        break;

                    case 5:
                        SLLobj3.DeleteLast();
                        break;

                    case 6:
                        cout << "Enter a position of element to delete: \n";
                        cin >> iPos;
                        SLLobj3.DeleteAtPos(iPos);
                        break;

                    case 7:
                        SLLobj3.Display();
                        break;

                    case 8:
                        iNo = SLLobj3.Count();
                        cout << "Number of Nodes are : " << iNo << "\n";
                        break;

                    case 0:
                        cout << "Exiting Singly Linear Linked List\n";
                        break;

                    default:
                        cout << "Please enter valid choice\n";
                        break;
                    }
                }
                break;
                iSelect = 1;

            case 4:
                cout << "You have entered double data type...\n";

                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1  : Insert at first position \n";
                    cout << "2  : Insert at last position \n";
                    cout << "3  : Insert at given position \n";
                    cout << "4  : Delete first node \n";
                    cout << "5  : Delete last node \n";
                    cout << "6  : Delete node at give position \n";
                    cout << "7  : Display elements \n";
                    cout << "8  : Count number of nodes \n";

                    cin >> iSelect;

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to Insert first : \n";
                        cin >> dNo;
                        SLLobj4.InsertFirst(dNo);
                        break;

                    case 2:
                        cout << "Enter data to Insert last : \n";
                        cin >> dNo;
                        SLLobj4.InsertLast(dNo);
                        break;

                    case 3:
                        cout << "Enter data to Insert at position: \n";
                        cin >> dNo;
                        cout << "Enter a position: \n";
                        cin >> iPos;
                        SLLobj4.InsertAtPos(dNo, iPos);
                        break;

                    case 4:
                        SLLobj4.DeleteFirst();
                        break;

                    case 5:
                        SLLobj4.DeleteLast();
                        break;

                    case 6:
                        cout << "Enter a position of element to delete: \n";
                        cin >> iPos;
                        SLLobj4.DeleteAtPos(iPos);
                        break;

                    case 7:
                        SLLobj4.Display();
                        break;

                    case 8:
                        dNo = SLLobj4.Count();
                        cout << "Number of Nodes are : " << dNo << "\n";
                        break;

                    case 0:
                        cout << "Exiting Singly Linear Linked List\n";
                        break;

                    default:
                        cout << "Please enter valid choice\n";
                        break;
                    }
                }
                break;
            }

            break;
            iSelect = 1;
            ///////////////////////////////////////
        case 2:

            cout << "You have selected Singly Circular Linked List...\n";

            cout << "Enter Linked list's data type: \n";
            cout << "1 : Integer\n";
            cout << "2 : Float\n";
            cout << "3: Character\n";
            cout << "4: Double\n";
            cin >> iDataType;

            switch (iDataType)
            {
            case 1:
                cout << "You have selected Integer data type....\n";
                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1  : Insert at first position \n";
                    cout << "2  : Insert at last position \n";
                    cout << "3  : Insert at given position \n";
                    cout << "4  : Delete first node \n";
                    cout << "5  : Delete last node \n";
                    cout << "6  : Delete node at give position \n";
                    cout << "7  : Display elements \n";
                    cout << "8  : Count number of nodes \n";

                    cin >> iSelect;
                    cout << "\n";

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to Insert First : \n";
                        cin >> iNo;
                        SCLobj1.InsertFirst(iNo);
                        break;

                    case 2:
                        cout << "Enter data to insert last : \n";
                        cin >> iNo;
                        SCLobj1.InsertLast(iNo);
                        break;

                    case 3:
                        cout << "Enter data to Insert at position: \n";
                        cin >> iNo;
                        cout << "Enter a position: \n";
                        cin >> iPos;
                        SCLobj1.InsertAtPos(iNo, iPos);
                        break;

                    case 4:
                        SCLobj1.DeleteFirst();
                        break;

                    case 5:
                        SCLobj1.DeleteLast();
                        break;

                    case 6:
                        cout << "Enter a position of element to delete: \n";
                        cin >> iPos;
                        SCLobj1.DeleteAtPos(iPos);
                        break;

                    case 7:
                        SCLobj1.Display();
                        break;

                    case 8:
                        iNo = SCLobj1.Count();
                        cout << "Number of Nodes are : " << iNo << "\n";
                        break;

                    case 0:
                        cout << "Exiting Singly Circular Linked List\n";
                        break;

                    default:
                        cout << "Please enter valid choice \n";
                        break;
                    }
                }
                break;
                iSelect = 1;

            case 2:
                cout << "You have selected Float data type....\n";
                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1  : Insert at first position \n";
                    cout << "2  : Insert at last position \n";
                    cout << "3  : Insert at given position \n";
                    cout << "4  : Delete first node \n";
                    cout << "5  : Delete last node \n";
                    cout << "6  : Delete node at give position \n";
                    cout << "7  : Display elements \n";
                    cout << "8  : Count number of nodes \n";

                    cin >> iSelect;
                    cout << "\n";

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to Insert first : \n";
                        cin >> fNo;
                        SCLobj2.InsertFirst(fNo);
                        break;

                    case 2:
                        cout << "Enter data to Insert last : \n";
                        cin >> fNo;
                        SCLobj2.InsertLast(fNo);
                        break;

                    case 3:
                        cout << "Enter data to Insert at position: \n";
                        cin >> fNo;
                        cout << "Enter a position: \n";
                        cin >> iPos;
                        SCLobj2.InsertAtPos(fNo, iPos);
                        break;

                    case 4:
                        SCLobj2.DeleteFirst();
                        break;

                    case 5:
                        SCLobj2.DeleteLast();
                        break;

                    case 6:
                        cout << "Enter a position of element to delete: \n";
                        cin >> iPos;
                        SCLobj2.DeleteAtPos(iPos);
                        break;

                    case 7:
                        SCLobj2.Display();
                        break;

                    case 8:
                        fNo = SCLobj2.Count();
                        cout << "Number of Nodes are : " << fNo << "\n";
                        break;

                    case 0:
                        cout << "Exiting Singly Circular Linked List\n";
                        break;

                    default:
                        cout << "Please enter valid choice\n";
                        break;
                    }
                }
                break;
                iSelect = 1;

            case 3:
                cout << "You have selected character data type...\n";
                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1  : Insert at first position \n";
                    cout << "2  : Insert at last position \n";
                    cout << "3  : Insert at given position \n";
                    cout << "4  : Delete first node \n";
                    cout << "5  : Delete last node \n";
                    cout << "6  : Delete node at give position \n";
                    cout << "7  : Display elements \n";
                    cout << "8  : Count number of nodes \n";

                    cin >> iSelect;
                    cout << "\n";

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to Insert first : \n";
                        cin >> chNo;
                        SCLobj3.InsertFirst(chNo);
                        break;

                    case 2:
                        cout << "Enter data to Insert last : \n";
                        cin >> chNo;
                        SCLobj3.InsertLast(chNo);
                        break;

                    case 3:
                        cout << "Enter data to insert at specified position: \n";
                        cin >> chNo;
                        cout << "Enter a position : \n";
                        cin >> iPos;
                        SCLobj3.InsertAtPos(chNo, iPos);
                        break;

                    case 4:
                        SCLobj3.DeleteFirst();
                        break;

                    case 5:
                        SCLobj3.DeleteLast();
                        break;

                    case 6:
                        cout << "Enter a position of element to delete: \n";
                        cin >> iPos;
                        SCLobj3.DeleteAtPos(iPos);
                        break;

                    case 7:
                        SCLobj3.Display();
                        break;

                    case 8:
                        iNo = SCLobj3.Count();
                        cout << "Number of nodes present in linked list are : " << iNo << "\n";
                        break;

                    case 0:
                        cout << "Exiting Singly Circular Linked List\n";
                        break;

                    default:
                        cout << "Please enter valid choice\n";
                        break;
                    }
                }
                break;
                iSelect = 1;

            case 4:
                cout << "You have selected double data type...\n";
                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1  : Insert at first position \n";
                    cout << "2  : Insert at last position \n";
                    cout << "3  : Insert at given position \n";
                    cout << "4  : Delete first node \n";
                    cout << "5  : Delete last node \n";
                    cout << "6  : Delete node at give position \n";
                    cout << "7  : Display elements \n";
                    cout << "8  : Count number of nodes \n";

                    cin >> iSelect;
                    cout << "\n";

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to Insert first : \n";
                        cin >> dNo;
                        SCLobj4.InsertFirst(dNo);
                        break;

                    case 2:
                        cout << "Enter data to Insert last : \n";
                        cin >> dNo;
                        SCLobj4.InsertLast(dNo);
                        break;

                    case 3:
                        cout << "Enter data to Insert at position: \n";
                        cin >> dNo;
                        cout << "Enter a position: \n";
                        cin >> iPos;
                        SCLobj4.InsertAtPos(dNo, iPos);
                        break;

                    case 4:
                        SCLobj4.DeleteFirst();
                        break;

                    case 5:
                        SCLobj4.DeleteLast();
                        break;

                    case 6:
                        cout << "Enter a position of element to delete: \n";
                        cin >> iPos;
                        SCLobj4.DeleteAtPos(iPos);
                        break;

                    case 7:
                        SCLobj4.Display();
                        break;

                    case 8:
                        iNo = SCLobj4.Count();
                        cout << "Number of Nodes are : " << iNo << "\n";
                        break;

                    case 0:
                        cout << "Exiting Singly Circular Linked List\n";
                        break;

                    default:
                        cout << "Please enter valid choice\n";
                        break;
                    }
                }
                break;
                iSelect = 1;
                ////
            default:
                cout << "Please enter valid choice\n";
                break;
            }
            break;

        case 3:
            cout << "You have selected Doubly Linear Linked List...\n";

            cout << "Enter Linked list's data type: \n";
            cout << "1 : Integer\n";
            cout << "2 : Float\n";
            cout << "3: Character\n";
            cout << "4: Double\n";
            cin >> iDataType;

            switch (iDataType)
            {
            case 1:
                cout << "You have selected integer data type...\n ";
                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1  : Insert at first position \n";
                    cout << "2  : Insert at last position \n";
                    cout << "3  : Insert at given position \n";
                    cout << "4  : Delete first node \n";
                    cout << "5  : Delete last node \n";
                    cout << "6  : Delete node at give position \n";
                    cout << "7  : Display elements \n";
                    cout << "8  : Count number of nodes \n";

                    cin >> iSelect;
                    cout << "\n";
                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to Insert first : \n";
                        cin >> iNo;
                        DLLobj1.InsertFirst(iNo);
                        break;

                    case 2:
                        cout << "Enter data to Insert last : \n";
                        cin >> iNo;
                        DLLobj1.InsertLast(iNo);
                        break;

                    case 3:
                        cout << "Enter data to insert at specified postion :\n";
                        cin >> iNo;
                        cout << "Enter a position : \n";
                        cin >> iPos;
                        DLLobj1.InsertAtPos(iNo, iPos);
                        break;

                    case 4:
                        DLLobj1.DeleteFirst();
                        break;

                    case 5:
                        DLLobj1.DeleteLast();
                        break;

                    case 6:
                        cout << "Enter a position of element to delete: \n";
                        cin >> iPos;
                        DLLobj1.DeleteAtPos(iPos);
                        break;

                    case 7:
                        DLLobj1.Display();
                        break;

                    case 8:
                        iNo = DLLobj1.Count();
                        cout << "Number of Nodes in doubly linked list are : " << iNo << "\n";
                        break;

                    case 0:
                        cout << "Exixting Doubly Linear Linked List \n";
                        break;

                    default:
                        cout << "Please enter valid choice\n";
                        break;
                    }
                }
                break; // break of Integer
                iSelect = 1;

            case 2:
                cout << "You have selected float data type...\n";
                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1  : Insert at first position \n";
                    cout << "2  : Insert at last position \n";
                    cout << "3  : Insert at given position \n";
                    cout << "4  : Delete first node \n";
                    cout << "5  : Delete last node \n";
                    cout << "6  : Delete node at give position \n";
                    cout << "7  : Display elements \n";
                    cout << "8  : Count number of nodes \n";

                    cin >> iSelect;
                    cout << "\n";
                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to Insert first : \n";
                        cin >> fNo;
                        DLLobj2.InsertFirst(fNo);
                        break;

                    case 2:
                        cout << "Enter data to Insert last : \n";
                        cin >> fNo;
                        DLLobj2.InsertLast(fNo);
                        break;

                    case 3:
                        cout << "Enter data to insert at specified postion :\n";
                        cin >> fNo;
                        cout << "Enter a position : \n";
                        cin >> iPos;
                        DLLobj2.InsertAtPos(fNo, iPos);
                        break;

                    case 4:
                        DLLobj2.DeleteFirst();
                        break;

                    case 5:
                        DLLobj2.DeleteLast();
                        break;

                    case 6:
                        cout << "Enter a position of element to delete: \n";
                        cin >> iPos;
                        DLLobj2.DeleteAtPos(iPos);
                        break;

                    case 7:
                        DLLobj2.Display();
                        break;

                    case 8:
                        iNo = DLLobj2.Count();
                        cout << "Number of Nodes in doubly linked list are : " << iNo << "\n";
                        break;

                    case 0:
                        cout << "Exixting Doubly Linear Linked List \n";
                        break;

                    default:
                        cout << "Please enter valid choice\n";
                        break;
                    }
                }
                break;
                iSelect = 1;

            case 3:
                cout << "You have selected character data type...\n";
                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1  : Insert at first position \n";
                    cout << "2  : Insert at last position \n";
                    cout << "3  : Insert at given position \n";
                    cout << "4  : Delete first node \n";
                    cout << "5  : Delete last node \n";
                    cout << "6  : Delete node at give position \n";
                    cout << "7  : Display elements \n";
                    cout << "8  : Count number of nodes \n";

                    cin >> iSelect;
                    cout << "\n";
                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to Insert first : \n";
                        cin >> chNo;
                        DLLobj3.InsertFirst(chNo);
                        break;

                    case 2:
                        cout << "Enter data to Insert last : \n";
                        cin >> iNo;
                        DLLobj3.InsertLast(chNo);
                        break;

                    case 3:
                        cout << "Enter data to insert at specified postion :\n";
                        cin >> chNo;
                        cout << "Enter a position : \n";
                        cin >> iPos;
                        DLLobj3.InsertAtPos(chNo, iPos);
                        break;

                    case 4:
                        DLLobj3.DeleteFirst();
                        break;

                    case 5:
                        DLLobj3.DeleteLast();
                        break;

                    case 6:
                        cout << "Enter a position of element to delete: \n";
                        cin >> iPos;
                        DLLobj3.DeleteAtPos(iPos);
                        break;

                    case 7:
                        DLLobj3.Display();
                        break;

                    case 8:
                        iNo = DLLobj3.Count();
                        cout << "Number of Nodes in doubly linked list are : " << iNo << "\n";
                        break;

                    case 0:
                        cout << "Exixting Doubly Linear Linked List \n";
                        break;

                    default:
                        cout << "Please enter valid choice\n";
                        break;
                    }
                }
                break;
                iSelect = 1;

            case 4:
                cout << "You have selected double data type...\n";
                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1  : Insert at first position \n";
                    cout << "2  : Insert at last position \n";
                    cout << "3  : Insert at given position \n";
                    cout << "4  : Delete first node \n";
                    cout << "5  : Delete last node \n";
                    cout << "6  : Delete node at give position \n";
                    cout << "7  : Display elements \n";
                    cout << "8  : Count number of nodes \n";

                    cin >> iSelect;
                    cout << "\n";
                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to Insert first : \n";
                        cin >> dNo;
                        DLLobj4.InsertFirst(dNo);
                        break;

                    case 2:
                        cout << "Enter data to Insert last : \n";
                        cin >> dNo;
                        DLLobj4.InsertLast(dNo);
                        break;

                    case 3:
                        cout << "Enter data to insert at specified postion :\n";
                        cin >> dNo;
                        cout << "Enter a position : \n";
                        cin >> iPos;
                        DLLobj4.InsertAtPos(dNo, iPos);
                        break;

                    case 4:
                        DLLobj4.DeleteFirst();
                        break;

                    case 5:
                        DLLobj4.DeleteLast();
                        break;

                    case 6:
                        cout << "Enter a position of element to delete: \n";
                        cin >> iPos;
                        DLLobj4.DeleteAtPos(iPos);
                        break;

                    case 7:
                        DLLobj4.Display();
                        break;

                    case 8:
                        iNo = DLLobj4.Count();
                        cout << "Number of Nodes in doubly linked list are : " << iNo << "\n";
                        break;

                    case 0:
                        cout << "Exixting Doubly Linear Linked List \n";
                        break;

                    default:
                        cout << "Please enter valid choice\n";
                        break;
                    }
                }
                break;
                iSelect = 1;
            }
            break; ///   break of Type of LL

        case 4:
            cout << "You have selected Doubly Circular Linked List..\n";

            cout << "Enter Linked list's data type: \n";
            cout << "1 : Integer\n";
            cout << "2 : Float\n";
            cout << "3: Character\n";
            cout << "4: Double\n";
            cin >> iDataType;

            switch (iDataType)
            {
            case 1:
                cout << "You have selected integer data type...\n";
                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1  : Insert at first position \n";
                    cout << "2  : Insert at last position \n";
                    cout << "3  : Insert at given position \n";
                    cout << "4  : Delete first node \n";
                    cout << "5  : Delete last node \n";
                    cout << "6  : Delete node at give position \n";
                    cout << "7  : Display elements \n";
                    cout << "8  : Count number of nodes \n";

                    cin >> iSelect;
                    cout << "\n";

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to Insert First : \n";
                        cin >> iNo;
                        DCLobj1.InsertFirst(iNo);
                        break;

                    case 2:
                        cout << "Enter data to insert last : \n";
                        cin >> iNo;
                        DCLobj1.InsertLast(iNo);
                        break;

                    case 3:
                        cout << "Enter data to Insert at position: \n";
                        cin >> iNo;
                        cout << "Enter a position: \n";
                        cin >> iPos;
                        DCLobj1.InsertAtPos(iNo, iPos);
                        break;

                    case 4:
                        DCLobj1.DeleteFirst();
                        break;

                    case 5:
                        SCLobj1.DeleteLast();
                        break;

                    case 6:
                        cout << "Enter a position of element to delete: \n";
                        cin >> iPos;
                        DCLobj1.DeleteAtPos(iPos);
                        break;

                    case 7:
                        DCLobj1.Display();
                        break;

                    case 8:
                        iNo = DCLobj1.Count();
                        cout << "Number of Nodes are : " << iNo << "\n";
                        break;

                    case 0:
                        cout << "Exiting Singly Circular Linked List\n";
                        break;

                    default:
                        cout << "Please enter valid choice \n";
                        break;
                    }
                }
                break;
                iSelect = 1;

            case 2:
                cout << "You have selected float data type....\n";
                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1  : Insert at first position \n";
                    cout << "2  : Insert at last position \n";
                    cout << "3  : Insert at given position \n";
                    cout << "4  : Delete first node \n";
                    cout << "5  : Delete last node \n";
                    cout << "6  : Delete node at give position \n";
                    cout << "7  : Display elements \n";
                    cout << "8  : Count number of nodes \n";

                    cin >> iSelect;
                    cout << "\n";

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to Insert first : \n";
                        cin >> fNo;
                        DCLobj2.InsertFirst(fNo);
                        break;

                    case 2:
                        cout << "Enter data to Insert last : \n";
                        cin >> fNo;
                        DCLobj2.InsertLast(fNo);
                        break;

                    case 3:
                        cout << "Enter data to Insert at position: \n";
                        cin >> fNo;
                        cout << "Enter a position: \n";
                        cin >> iPos;
                        DCLobj2.InsertAtPos(fNo, iPos);
                        break;

                    case 4:
                        DCLobj2.DeleteFirst();
                        break;

                    case 5:
                        DCLobj2.DeleteLast();
                        break;

                    case 6:
                        cout << "Enter a position of element to delete: \n";
                        cin >> iPos;
                        DCLobj2.DeleteAtPos(iPos);
                        break;

                    case 7:
                        DCLobj2.Display();
                        break;

                    case 8:
                        iNo = SCLobj2.Count();
                        cout << "Number of Nodes are : " << iNo << "\n";
                        break;

                    case 0:
                        cout << "Exiting Singly Circular Linked List\n";
                        break;

                    default:
                        cout << "Please enter valid choice\n";
                        break;
                    }
                }
                break;
                iSelect = 1;

            case 3:
                cout << "You have selected character data type...\n";
                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1  : Insert at first position \n";
                    cout << "2  : Insert at last position \n";
                    cout << "3  : Insert at given position \n";
                    cout << "4  : Delete first node \n";
                    cout << "5  : Delete last node \n";
                    cout << "6  : Delete node at give position \n";
                    cout << "7  : Display elements \n";
                    cout << "8  : Count number of nodes \n";

                    cin >> iSelect;
                    cout << "\n";

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to Insert first : \n";
                        cin >> chNo;
                        DCLobj3.InsertFirst(chNo);
                        break;

                    case 2:
                        cout << "Enter data to Insert last : \n";
                        cin >> chNo;
                        DCLobj3.InsertLast(chNo);
                        break;

                    case 3:
                        cout << "Enter data to insert at specified position: \n";
                        cin >> chNo;
                        cout << "Enter a position : \n";
                        cin >> iPos;
                        DCLobj3.InsertAtPos(chNo, iPos);
                        break;

                    case 4:
                        DCLobj3.DeleteFirst();
                        break;

                    case 5:
                        DCLobj3.DeleteLast();
                        break;

                    case 6:
                        cout << "Enter a position of element to delete: \n";
                        cin >> iPos;
                        DCLobj3.DeleteAtPos(iPos);
                        break;

                    case 7:
                        DCLobj3.Display();
                        break;

                    case 8:
                        iNo = DCLobj3.Count();
                        cout << "Number of nodes present in linked list are : " << iNo << "\n";
                        break;

                    case 0:
                        cout << "Exiting Singly Circular Linked List\n";
                        break;

                    default:
                        cout << "Please enter valid choice\n";
                        break;
                    }
                }
                break;
                iSelect = 1;

            case 4:
                cout << "You have selected double data type..\n";
                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1  : Insert at first position \n";
                    cout << "2  : Insert at last position \n";
                    cout << "3  : Insert at given position \n";
                    cout << "4  : Delete first node \n";
                    cout << "5  : Delete last node \n";
                    cout << "6  : Delete node at give position \n";
                    cout << "7  : Display elements \n";
                    cout << "8  : Count number of nodes \n";

                    cin >> iSelect;
                    cout << "\n";

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to Insert first : \n";
                        cin >> dNo;
                        DCLobj4.InsertFirst(dNo);
                        break;

                    case 2:
                        cout << "Enter data to Insert last : \n";
                        cin >> dNo;
                        DCLobj4.InsertLast(dNo);
                        break;

                    case 3:
                        cout << "Enter data to Insert at position: \n";
                        cin >> dNo;
                        cout << "Enter a position: \n";
                        cin >> iPos;
                        DCLobj4.InsertAtPos(dNo, iPos);
                        break;

                    case 4:
                        DCLobj4.DeleteFirst();
                        break;

                    case 5:
                        DCLobj4.DeleteLast();
                        break;

                    case 6:
                        cout << "Enter a position of element to delete: \n";
                        cin >> iPos;
                        DCLobj4.DeleteAtPos(iPos);
                        break;

                    case 7:
                        DCLobj4.Display();
                        break;

                    case 8:
                        iNo = DCLobj4.Count();
                        cout << "Number of Nodes are : " << iNo << "\n";
                        break;

                    case 0:
                        cout << "Exiting Singly Circular Linked List\n";
                        break;

                    default:
                        cout << "Please enter valid choice\n";
                        break;
                    }
                }
                break;

            default:
                cout << "Please enter valid choice\n";
                break;
            }
            break;

        case 5:
            cout << "You have selected Stack...\n";

            cout << "Enter Stack data type: \n";
            cout << "1 : Integer\n";
            cout << "2 : Float\n";
            cout << "3 : Character\n";
            cout << "4 : Double\n";
            cin >> iDataType;
            cout << "\n";
            iSelect = 1;

            switch (iDataType)
            {
            case 1:
                cout << "You have selected integer data type...\n";

                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice :\n";
                    cout << "1 : Push \n";
                    cout << "2 : Pop  \n";
                    cout << "3 : Display elements of Stack\n";
                    cout << "4 : Count number of elements in Stack \n";

                    cin >> iSelect;

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to push in stack: \n";
                        cin >> iNo;
                        stkobj1.Push(iNo);
                        break;

                    case 2:
                        cout << "\n";
                        stkobj1.Pop();
                        break;

                    case 3:
                        cout << "\n";
                        stkobj1.Display();
                        break;

                    case 4:
                        iNo = stkobj1.CountNode();
                        cout << "Number of elements in Stack are : " << iNo << "\n";
                        break;

                    case 0:
                        cout << "Exiting STack \n";
                        break;

                    default:
                        break;
                    }
                }
                break;
                iSelect = 1;

            case 2:
                cout << "You have selected float data type...\n";
                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice :\n";
                    cout << "1 : Push \n";
                    cout << "2 : Pop  \n";
                    cout << "3 : Display elements of Stack\n";
                    cout << "4 : Count number of elements in Stack \n";

                    cin >> iSelect;

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to push in stack: \n";
                        cin >> fNo;
                        stkobj2.Push(fNo);
                        break;

                    case 2:
                        cout << "\n";
                        stkobj2.Pop();
                        break;

                    case 3:
                        cout << "\n";
                        stkobj2.Display();
                        break;

                    case 4:
                        iNo = stkobj2.CountNode();
                        cout << "Number of elements in Stack are : " << iNo << "\n";
                        break;

                    case 0:
                        cout << "Exiting STack \n";
                        break;

                    default:
                        break;
                    }
                }
                break;
                iSelect = 1;

            case 3:
                cout << "You have selected character data type..\n";
                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice :\n";
                    cout << "1 : Push \n";
                    cout << "2 : Pop  \n";
                    cout << "3 : Display elements of Stack\n";
                    cout << "4 : Count number of elements in Stack \n";

                    cin >> iSelect;

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to push in stack: \n";
                        cin >> chNo;
                        stkobj3.Push(chNo);
                        break;

                    case 2:
                        cout << "\n";
                        stkobj3.Pop();
                        break;

                    case 3:
                        cout << "\n";
                        stkobj3.Display();
                        break;

                    case 4:
                        iNo = stkobj3.CountNode();
                        cout << "Number of elements in Stack are : " << iNo << "\n";
                        break;

                    case 0:
                        cout << "Exiting STack \n";
                        break;

                    default:
                        break;
                    }
                }
                break;
                iSelect = 1;

            case 4:
                cout << "You have selected double data type....\n";
                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice :\n";
                    cout << "1 : Push \n";
                    cout << "2 : Pop  \n";
                    cout << "3 : Display elements of Stack\n";
                    cout << "4 : Count number of elements in Stack \n";

                    cin >> iSelect;

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to push in stack: \n";
                        cin >> dNo;
                        stkobj4.Push(dNo);
                        break;

                    case 2:
                        cout << "\n";
                        stkobj4.Pop();
                        break;

                    case 3:
                        cout << "\n";
                        stkobj4.Display();
                        break;

                    case 4:
                        iNo = stkobj4.CountNode();
                        cout << "Number of elements in Stack are : " << iNo << "\n";
                        break;

                    case 0:
                        cout << "Exiting STack \n";
                        break;

                    default:
                        break;
                    }
                }
                break;
                iSelect = 1;
            }
            break;
        case 6:
            cout << "You have selected Queue \n";

            cout << "Enter Linked list's data type: \n";
            cout << "1 : Integer\n";
            cout << "2 : Float\n";
            cout << "3 : Character\n";
            cout << "4 : Double\n";
            cin >> iDataType;

            switch (iDataType)
            {
            case 1:
                cout << "You have selected integer data type : \n";
                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1 : Enqueue \n";
                    cout << "2 : Dequeue \n";
                    cout << "3 : Display\n";
                    cout << "4 : Count number of elements in queue \n";

                    cin >> iSelect;
                    cout << "\n";

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to enqueue: \n";
                        cin >> iNo;
                        qobj1.Enqueue(iNo);
                        break;

                    case 2:
                        qobj1.Dequeue();
                        break;

                    case 3:
                        qobj1.Display();
                        break;

                    case 4:
                        iNo = qobj1.CountNode();
                        cout << "Number of elements in queue are : " << iNo << "\n";
                        break;

                    case 0:
                        cout << "Exiting Queue \n";
                        break;

                    default:
                        cout << "Please enter valid choice \n";
                        break;
                    }
                }
                break;
                iSelect = 1;

            case 2:
                cout << "You have selected float data type : \n";
                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1 : Enqueue \n";
                    cout << "2 : Dequeue \n";
                    cout << "3 : Display\n";
                    cout << "4 : Count number of elements in queue \n";

                    cin >> iSelect;
                    cout << "\n";

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to enqueue: \n";
                        cin >> fNo;
                        qobj2.Enqueue(fNo);
                        break;

                    case 2:
                        qobj2.Dequeue();
                        break;

                    case 3:
                        qobj2.Display();
                        break;

                    case 4:
                        iNo = qobj2.CountNode();
                        cout << "Number of elements in queue are : " << iNo << "\n";
                        break;

                    case 0:
                        cout << "Exiting Queue \n";
                        break;

                    default:
                        cout << "Please enter valid choice \n";
                        break;
                    }
                }
                break;
                iSelect = 1;

            case 3:
                cout << "You have selected character data type : \n";
                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1 : Enqueue \n";
                    cout << "2 : Dequeue \n";
                    cout << "3 : Display\n";
                    cout << "4 : Count number of elements in queue \n";

                    cin >> iSelect;
                    cout << "\n";

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to enqueue: \n";
                        cin >> chNo;
                        qobj3.Enqueue(chNo);
                        break;

                    case 2:
                        qobj3.Dequeue();
                        break;

                    case 3:
                        qobj3.Display();
                        break;

                    case 4:
                        iNo = qobj3.CountNode();
                        cout << "Number of elements in queue are : " << iNo << "\n";
                        break;

                    case 0:
                        cout << "Exiting Queue \n";
                        break;

                    default:
                        cout << "Please enter valid choice \n";
                        break;
                    }
                }
                break;
                iSelect = 1;

            case 4:
                cout << "You have selected double data type : \n";
                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1 : Enqueue \n";
                    cout << "2 : Dequeue \n";
                    cout << "3 : Display\n";
                    cout << "4 : Count number of elements in queue \n";

                    cin >> iSelect;
                    cout << "\n";

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to enqueue: \n";
                        cin >> dNo;
                        qobj4.Enqueue(dNo);
                        break;

                    case 2:
                        qobj4.Dequeue();
                        break;

                    case 3:
                        qobj4.Display();
                        break;

                    case 4:
                        iNo = qobj4.CountNode();
                        cout << "Number of elements in queue are : " << iNo << "\n";
                        break;

                    case 0:
                        cout << "Exiting Queue \n";
                        break;

                    default:
                        cout << "Please enter valid choice \n";
                        break;
                    }
                }
                break;
                iSelect = 1;
            }
            break;

        case 7:
            cout << "You have selected Binary Search Tree\n";

            cout << "Enter data type: \n";
            cout << "1 : Integer\n";
            cout << "2 : Float\n";
            cout << "3 : Character\n";
            cout << "4 : Double\n";
            cin >> iDataType;

            switch (iDataType)
            {
            case 1:

                cout << "You have selected Integer data type: \n";

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1 : Insert an element in BST\n";
                    cout << "2 : Display In-order\n";
                    cout << "3 : Display Pre-order\n";
                    cout << "4 : Display Post-order\n";
                    cout << "\n";

                    cin >> iSelect;

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to Insert first : \n";
                        cin >> iNo;
                        tobj1.Insert(&iFirst, iNo);
                        break;

                    case 2:
                        cout << "Inorder display of elements: \n";
                        tobj1.Inorder(iFirst);
                        break;

                    case 3:
                        cout << "Preorder display of elements: \n";
                        tobj1.Preorder(iFirst);
                        break;

                    case 4:
                        cout << "Postorder display of elements: \n";
                        tobj1.PostOrder(iFirst);
                        break;

                    default:
                        cout << "Invalid choice \n";
                        break;
                    }
                }
                break;

            case 2:
                cout << "You have selected Float data type: \n";

                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1 : Insert an element in BST\n";
                    cout << "2 : Display In-order\n";
                    cout << "3 : Display Pre-order\n";
                    cout << "4 : Display Post-order\n";
                    cout << "\n";

                    cin >> iSelect;

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to Insert first : \n";
                        cin >> fNo;
                        tobj2.Insert(&fFirst, fNo);
                        break;

                    case 2:
                        tobj2.Inorder(fFirst);
                        break;

                    case 3:
                        tobj2.Preorder(fFirst);
                        break;

                    case 4:
                        tobj2.PostOrder(fFirst);
                        break;

                    default:
                        cout << "Invalid choice \n";
                        break;
                    }
                }
                break;

            case 3:
                cout << "You have selected character data type: \n";

                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1 : Insert an element in BST\n";
                    cout << "2 : Display In-order\n";
                    cout << "3 : Display Pre-order\n";
                    cout << "4 : Display Post-order\n";
                    cout << "\n";

                    cin >> iSelect;

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to Insert first : \n";
                        cin >> chNo;
                        tobj3.Insert(&chFirst, chNo);
                        break;

                    case 2:
                        tobj3.Inorder(chFirst);
                        break;

                    case 3:
                        tobj3.Preorder(chFirst);
                        break;

                    case 4:
                        tobj3.PostOrder(chFirst);
                        break;

                    default:
                        cout << "Invalid choice \n";
                        break;
                    }
                }
                break;

            case 4:
                cout << "You have selected Double data type: \n";

                iSelect = 1;

                while (iSelect != 0)
                {
                    cout << "Enter your choice : \n";
                    cout << "1 : Insert an element in BST\n";
                    cout << "2 : Display In-order\n";
                    cout << "3 : Display Pre-order\n";
                    cout << "4 : Display Post-order\n";
                    cout << "\n";

                    cin >> iSelect;

                    switch (iSelect)
                    {
                    case 1:
                        cout << "Enter data to Insert first : \n";
                        cin >> dNo;
                        tobj4.Insert(&dFirst, dNo);
                        break;

                    case 2:
                        tobj4.Inorder(dFirst);
                        break;

                    case 3:
                        tobj4.Preorder(dFirst);
                        break;

                    case 4:
                        tobj4.PostOrder(dFirst);
                        break;

                    default:
                        cout << "Invalid choice \n";
                        break;
                    }
                }
                break;

            default:
                cout << "Enter right data type: \n";
                break;
            }
            break;

        default:
            cout << "Please enter valid choice\n";
            break;
        }
    }

    return 0;
}