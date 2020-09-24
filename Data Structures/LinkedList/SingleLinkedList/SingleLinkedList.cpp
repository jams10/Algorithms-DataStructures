#include <iostream>
#include "SingleLinkedList.h"

SingleLinkedList::SingleLinkedList()
    :
    head( nullptr ),
    tail( nullptr ),
    size( 0 )
{
}

SingleLinkedList::SingleLinkedList( int inSize )
    :
    head( nullptr ),
    tail( nullptr ),
    size( 0 )
{
    for( int i = 0; i < inSize; i++ )
    {
        Add( 0 );
    }
}
SingleLinkedList::~SingleLinkedList()
{
    if( !IsEmpty() )
    {
        Node* freeNode = this->head;
        for( int i = 0; i < this->size; i++ )
        {
            this->head = this->head->GetNext();
            delete freeNode;
            freeNode = this->head;
        }
    }
}

bool SingleLinkedList::Search( int value )
{
    Node* iter = this->head;

    for( int i = 0; i < this->size; i++ )
    {
        if( iter->GetValue() == value ) return true;
        iter = iter->GetNext();
    }

    return false;
}

bool SingleLinkedList::IsEmpty()
{
    return this->size == 0;
}

void SingleLinkedList::Add( int value )
{
    Node* node = new Node( value );

    if( this->head == nullptr )
    {
        this->head = node;
        this->tail = node;
    }
    else
    {
        this->tail->SetNext( node );
        this->tail = node;
    }

    this->size++;
}

void SingleLinkedList::AddAt( int index, int value )
{
    if( index >= size )
    {
        std::cout << "Index is larger than the size of list. Size : " << this->size << std::endl;
        return;
    }

    Node* node = new Node( value );
    Node* tmp = this->head;

    if( index == 0 )
    {
        node->SetNext( this->head );
        this->head = node;
    }
    else
    {
        for( int i = 0; i < index - 1; i++ )
        {
            tmp = tmp->GetNext();
        }

        node->SetNext( tmp->GetNext() );
        tmp->SetNext( node );
    }

    this->size++;
}

int SingleLinkedList::Pop()
{
    if( IsEmpty() )
    {
        std::cout << "List is empty." << std::endl;
        exit( 1 );
    }

    int value = 0;
    Node* removeNode = this->head;
    value = removeNode->GetValue();
    this->head = this->head->GetNext();
    delete removeNode;

    this->size--;

    return value;
}

void SingleLinkedList::RemoveAt( int index )
{
    if( index >= this->size )
    {
        std::cout << "Index is larger than the size of list. Size : " << this->size << std::endl;
        return;
    }

    if( index == 0 )
    {
        Pop();
    }
    else
    {
        Node* nextNode = this->head;
        Node* removeNode = nullptr;

        for( int i = 0; i < index - 1; i++ )
        {
            nextNode = nextNode->GetNext();
        }

        removeNode = nextNode->GetNext();
        nextNode->SetNext( nextNode->GetNext()->GetNext() );

        delete removeNode;
    }

    this->size--;
}

void SingleLinkedList::Show()
{
    if( IsEmpty() )
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Node* iter = this->head;

    for( int i = 0; i < this->size; i++ )
    {
        std::cout << iter->GetValue() << ' ';
        iter = iter->GetNext();
    }
    std::cout << std::endl;
    return;
}

void SingleLinkedList::SetValueAt( int index, int value )
{
    if( index >= this->size )
    {
        std::cout << "Index is larger than the size of list. Size : " << this->size << std::endl;
        return;
    }

    Node* tmp = this->head;

    for( int i = 0; i < index; i++ )
    {
        tmp = tmp->GetNext();
    }
    tmp->SetValue( value );
}

int SingleLinkedList::GetValueAt( int index )
{
    if( index >= this->size )
    {
        std::cout << "Index is larger than the size of list. Size : " << this->size << std::endl;
        exit( 1 );
    }

    Node* tmp = this->head;

    for( int i = 0; i < index; i++ )
    {
        tmp = tmp->GetNext();
    }
    return tmp->GetValue();
}

int SingleLinkedList::GetSize()
{
    return this->size;
}
