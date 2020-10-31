#include <iostream>
#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList()
    :
    head( nullptr ),
    tail( nullptr ),
    size( 0 )
{
}

DoubleLinkedList::DoubleLinkedList( int inSize )
    :
    head( nullptr ),
    tail( nullptr ),
    size( 0 )
{
    for( int i = 0; i < inSize; i++ )
    {
        Push( 0 );
    }
}
DoubleLinkedList::~DoubleLinkedList()
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

bool DoubleLinkedList::Search( int value )
{
    Node* iter = this->head;

    for( int i = 0; i < this->size; i++ )
    {
        if( iter->GetValue() == value ) return true;
        iter = iter->GetNext();
    }

    return false;
}

bool DoubleLinkedList::IsEmpty()
{
    return this->size == 0;
}

void DoubleLinkedList::Push( int value )
{
    Node* node = new Node( value );

    if( this->head == nullptr )
    {
        this->head = node;
        this->tail = node;
    }
    else
    {
        Node* tmp = this->tail;
        this->tail->SetNext( node );
        this->tail = node;
        this->tail->SetPrev( tmp );
    }

    this->size++;
}

void DoubleLinkedList::AddAt( int index, int value )
{
    if( index >= size )
    {
        std::cout << "Index is larger than the size of list. Size : " << this->size << std::endl;
        return;
    }

    Node* node = new Node( value );

    if( index == 0 )
    {
        node->SetNext( this->head );
        this->head = node;
    }
    else
    {
        /*
          전체 리스트 사이즈 중간 기준으로 주어진 인덱스의 위치를 파악.
          해당 인덱스가 사이즈 중간값 보다 작으면 head 부터 getNext로 증가.
          크면 tail 부터 getNext로 감소해가면서 위치를 찾아 새 노드를 삽입.
        */
        Node* tmp = nullptr;

        if( index <= this->size / 2 )
        {
            tmp = this->head;
            for( int i = 0; i < index; i++ )
            {
                tmp = tmp->GetNext();
                //std::cout << tmp->GetValue() << std::endl;
            }
            /*
              삽입 노드와 이전 노드 관계 부터 설정
            */
            node->SetPrev( tmp->GetPrev() );
            tmp->GetPrev()->SetNext( node );
            /*
              삽입 노드와 다음 노드 관계 설정
            */
            node->SetNext( tmp );
            tmp->SetPrev( node );
        }
        else
        {
            tmp = this->tail;
            for(int i = size - 1; i > index; i--)
            {
                tmp = tmp->GetPrev();
            }
            node->SetPrev( tmp->GetPrev() );
            tmp->GetPrev()->SetNext( node );
            node->SetNext( tmp );
            tmp->SetPrev( node );
        }
    }
    this->size++;
}

int DoubleLinkedList::Pop()
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

void DoubleLinkedList::RemoveAt( int index )
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
        Node* tmp = nullptr;
        Node* removeNode = nullptr;

        if( index <= this->size / 2 )
        {
            tmp = this->head;
            for( int i = 0; i < index; i++ )
            {
                tmp = tmp->GetNext();
            }
            removeNode = tmp;
            tmp->GetPrev()->SetNext( tmp->GetNext() );
            tmp->GetNext()->SetPrev( tmp->GetPrev() );
        }
        else
        {
            tmp = this->tail;
            for( int i = size - 1; i > index; i-- )
            {
                tmp = tmp->GetPrev();
            }
            removeNode = tmp;
            tmp->GetPrev()->SetNext( tmp->GetNext() );
            tmp->GetNext()->SetPrev( tmp->GetPrev() );
        }

        delete removeNode;
    }

    this->size--;
}

void DoubleLinkedList::Show()
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

void DoubleLinkedList::SetValueAt( int index, int value )
{
    if( index >= this->size )
    {
        std::cout << "Index is larger than the size of list. Size : " << this->size << std::endl;
        return;
    }

    Node* tmp = nullptr;

    if( index <= this->size / 2 )
    {
        tmp = this->head;
        for( int i = 0; i < index; i++ )
        {
            tmp = tmp->GetNext();
        }
    }
    else
    {
        tmp = this->tail;
        for( int i = size - 1; i > index; i-- )
        {
            tmp = tmp->GetPrev();
        }
    }
    tmp->SetValue( value );
}

int DoubleLinkedList::GetValueAt( int index )
{
    if( index >= this->size )
    {
        std::cout << "Index is larger than the size of list. Size : " << this->size << std::endl;
        exit( 1 );
    }

    Node* tmp = nullptr;

    if( index <= this->size / 2 )
    {
        tmp = this->head;
        for( int i = 0; i < index; i++ )
        {
            tmp = tmp->GetNext();
        }
    }
    else
    {
        tmp = this->tail;
        for( int i = size - 1; i > index; i-- )
        {
            tmp = tmp->GetPrev();
        }
    }

    return tmp->GetValue();
}

int DoubleLinkedList::GetSize()
{
    return this->size;
}