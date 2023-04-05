#ifndef MYDS_H_INCLUDED
#define MYDS_H_INCLUDED

#include<iostream>
using namespace std;
class stack{
int *p,top=-1,size;
    bool is_full(){
    if(top==size-1)
        return true;
    else
        return false;
}
    bool is_emp(){
    if(top==-1)
        return true;
    else
        return false;
}
public:
    stack(int Size){
        size=Size;
        p = new int [Size];
    }
    stack(){
        size=5;
        p = new int[5];
    }
    ~stack(){
        delete[] p;
    }
    void push(int value){
    if(is_full())
        cout<<"stack is full"<<endl;
    else
        p[++top] =value;
}
    void pop(){
    if(is_emp())
        cout<<"stack is empty"<<endl;
    else{

            p[top]=NULL;
            --top;
    }
}
    void display() {
    if(is_emp())
        cout<<"stack is empty"<<endl;
    else
        for(int i=top ; i>=0 ; i--)
            cout<<p[i]<<"  ";
}
};
class queue{
int *Queue,size;
int rear=-1,front=-1;
public:
     queue(int Size){
        size=Size;
        Queue = new int [Size];
    }
    queue(){
        size=5;
        Queue = new int[5];
    }
    ~queue(){
        delete[] Queue;
    }
void Enqueue(int value)
{
    if(rear==size-1)
        cout<<"Queue is full"<<endl;
    else{
        Queue[++rear]=value;
        if (front==-1)
            front=0;
}
}
void Dequeue()
{
    if(front==-1)
        cout<<"underflow"<<endl;
    else
    {
        if(front==rear)
        {
            Queue[front]=NULL;
            front=-1;
            rear=-1;
        }
        else
        {
            Queue[front]=NULL;
            front++;
        }
    }
}
void Display()
{
    if(front!=-1)
    {
        cout<<"The elements in Queue are: ";
        for(int i=front ; i<=rear; i++)
            cout<<Queue[i]<<" ";
    }
    else
        cout<<"Queue is empty"<<endl;
}

};
class Cqueue{
int *Q,Size;
int Front = -1,Rear = -1;
public:
    Cqueue(int size){
        Size=size;
        Q = new int [Size];
    }
    Cqueue(){
        Size=5;
        Q = new int[5];
    }
    ~Cqueue(){
        delete[] Q;
    }
    void Enqueue(int AddNumber){
        if ((Front == 0 && Rear == Size - 1) || (Front==Rear + 1)) Dequeue();
        if (Front == -1)
        {
            Front = 0;
            Rear = 0;
        }
        else
        {
            if (Rear == Size - 1) Rear = 0;
            else Rear++;
        }
        Q[Rear] = AddNumber;
    }
    void Dequeue(){
    if (Front == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }
        Q[Front]=NULL;
    if (Front == Rear)
    {
        Front = -1;
        Rear = -1;
    }
    else
    {
        if (Front == Size - 1)
        {
            Front = 0;
        }
        else
        {
            Front++;
        }
    }

}
    void Display(){
    int Front_Pos = Front;
    int Rear_Pos = Rear;
    if (Front == -1)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Queue: [";
        if (Front_Pos <= Rear_Pos)
        {
            while (Front_Pos <= Rear_Pos)
            {
                cout << " " << Q[Front_Pos];
                Front_Pos++;
            }
        }
        else
        {
            while (Front_Pos <= Size - 1)
            {
                cout << " " << Q[Front_Pos];
                Front_Pos++;
            }
            Front_Pos = 0;
            while (Front_Pos <= Rear_Pos)
            {
                cout << " " << Q[Front_Pos];
                Front_Pos++;

            }
        }
        cout << " ]"<<"Front="<<Front<<" Rear="<<Rear << endl;
    }
}
};
class linklist {
struct node
{
    int data;
    node *next;
};
node *head=NULL;
public:
void insert_beg(int value)
{
    node *newNode;
    newNode=new node;
    newNode->data=value;
    newNode->next=head;
    head=newNode;
}
void insert_end(int value)
{
    node*new_node,*last;
    new_node=new node;
    new_node->data=value;
    if(head==NULL)
    {
        head=new_node;
        new_node->next=NULL;
    }
    else
    {
        last=head;
        while(last->next!=NULL)
        {
            last=last->next;
        }
        last->next=new_node;
        new_node->next=NULL;
    }
}
void insert_anyPostion(int value,int pos)
{
    node *newNode;
    newNode=new node;
    newNode->data=value;
    if(pos==0)
    {
        newNode->next=head;
        head=newNode;
    }
    else
    {
        node *temp=head;
        for(int i=0 ; i<pos-1 && temp->next!=NULL ; i++)
        {
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}
void display()
{
    node *temp;
    if(head==NULL)
        cout<<"linked list is empty"<<endl;
    else
    {
        cout<<"The linked list= ";
        temp =head;
        while(temp!=NULL)
        {
            cout<< temp ->data<<" ";
            temp = temp ->next;
        }
    }
}
void delete_beg()
{
    if(head==NULL)
        cout<<"linked list is empty"<<endl;
    else
    {
        node *temp;
        temp=head;
        head=temp->next;
        delete temp;
    }
}
void delete_end()
{
    if(head==NULL)
        cout<<"linked list is empty"<<endl;
    else if(head->next==NULL)
    {
        delete head;
        head=NULL;
    }
    else
    {
        node *temp;
        temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
}
void delete_anyPostion(int pos)
{
    if(head==NULL)
        cout<<"linked list is empty"<<endl;
    else if(pos==0)
    {
        node *temp=head;
        head=temp->next;
        delete temp;
    }
    else
    {
        node *temp=head;
        for(int i=0 ; i<pos-1 && temp->next!=NULL ; i++)
        {
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            return;
        }
        node *temp2;
        temp2=temp->next;
        temp->next=temp->next->next;
        delete temp2;
    }
}

};
class Dlinklist{
struct node
{
    int data;
    node *prev;
    node *next;
};
node *head=NULL;
public:
void first_node(int value)
{
    head=new node;
    head->data=value;
    head->prev=NULL;
    head->next=NULL;
}
void insert_beg(int value)
{
    if(head==NULL)
        first_node(value);
    else
    {
        node *new_node,*temp;
        temp=head;
        new_node=new node;
        new_node->data=value;
        new_node->prev=NULL;
        new_node->next=temp;
        temp->prev=new_node;
        head=new_node;
    }
}
void insert_end(int value)
{
    if(head==NULL)
        first_node(value);
    else
    {
        node *temp,*new_node;
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        new_node=new node;
        new_node->data=value;
        new_node->next=NULL;
        new_node->prev=temp;
        temp->next=new_node;
    }
}
void insert_anyPostion(int value,int po)
{
    node *temp,*new_node,*x;
    temp=head;
    for(int i=0; i<po; i++)
    {
        x=temp;
        temp=temp->next;
    }
    if(temp->next!=NULL)
    {
        new_node=new node;
        new_node->data=value;
        new_node->next=temp;
        temp->prev=new_node;
        new_node->prev=x;
        x->next=new_node;
    }
    else
        insert_end(value);
}
void display()
{
    if(head==NULL)
        cout<<"linked list is empty"<<endl;

    else
    {
        node *temp;
        temp=head;
        cout<<"The linked list= ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" --> ";
            temp=temp->next;
        }
    }
}
void delete_beg()
{
    node *temp=head;
    node *temp2=head;
    if (head==NULL)
        cout<<"linked list is empty"<<endl;

    else if((temp->next==NULL)&&(temp->prev==NULL))
    {
        delete temp;
        head=NULL;
    }
    else
    {
        temp=temp->next;
        temp->prev=NULL;
        head=temp;
        delete temp2;
    }
}
void delete_end()
{
    node *temp,*x;
    if(head==NULL)
        cout<<"linked list is empty"<<endl;
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            x=temp;
            temp=temp->next;
        }
        x->next=NULL;
        delete temp;
    }
}
void delete_anyPostion(int po)
{
    node *x,*temp;
    temp=head;
    for(int i=0; i<po; i++)
    {
        x=temp;
        temp=temp->next;
    }
    x->next=temp->next;
    temp->next->prev=x;
    delete temp;
}
};


#endif // MYDS_H_INCLUDED
