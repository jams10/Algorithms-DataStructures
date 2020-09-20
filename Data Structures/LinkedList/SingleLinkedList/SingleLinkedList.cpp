#include <iostream>
#include "SingleLinkedList.h"

SingleLinkedList::SingleLinkedList()
    :
    head(nullptr),
    tail(nullptr),
    size(0)
{    
}

SingleLinkedList::SingleLinkedList(int inSize)
{
    // if can not allocate memory, return nullptr
    Node* nodes = new (std::nothrow) Node[size];
    
    if(!nodes) // check memory allocation error
    {
        std::cout << "MEMORY ALLOCATION ERROR" << std::endl;
    } 
    
    for(int i = 0; i < size - 1; i++)
    {
        nodes->SetNext( &nodes[i + 1] );
    }
    
    this->head = &nodes[0];
    this->tail = &nodes[size - 1];
    size = inSize;
}

SingleLinkedList::~SingleLinkedList()
{
    if(!IsEmpty())
    {
        Node* freeNode = this->head;
        for(int i = 0; i < this->size; i++)
        {
            this->head = this->head->GetNext();
            delete freeNode;
            freeNode = this->head;
        }
    }
}

bool SingleLinkedList::Search(int value)
{
    Node *iter = this->head;

    for(int i = 0; i < this->size; i++)
    {
        if(iter->GetValue() == value) return true;
        iter = iter->GetNext();   
    }

    return false;
}

bool SingleLinkedList::IsEmpty()
{
    return this->size == 0;
}

void SingleLinkedList::Add(int value)
{
    Node* node = new Node(value);

    if(this->head == nullptr)
    {
        this->head = node;
        this->tail = node;
    }
    else
    {
        this->tail->SetNext(node);
        this->tail = node;
    }

    this->size++;
}

void SingleLinkedList::AddAt(int index, int value)
{
    if(index >= size)
    {
        std::cout << "Index is larger than the size of list. Size : "<< this->size << std::endl;
        return;
    }
    
    Node* node = new Node(value);
    Node *tmp = this->head;

    if(index == 0)
    {
        node->SetNext(this->head);
        this->head = node;
    }
    else if(index == this->size - 1)
    {
        this->tail->SetNext(node);
        this->tail = node;
    }
    else
    {
        for(int i = 0; i < index - 1; i++)
        {
            tmp = tmp->GetNext();
        }

        node->SetNext(tmp->GetNext());
        tmp->SetNext(node);
    }

    this->size++;
}

void SingleLinkedList::Pop()
{
    if(IsEmpty())
    {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node* removeNode = this->head;
    this->head = this->head->GetNext();
    delete removeNode;

    this->size--;
}

void SingleLinkedList::RemoveAt(int index)
{
    if(index >= this->size)
    {
        std::cout << "Index is larger than the size of list. Size : "<< this->size << std::endl;
        return;
    }
}


