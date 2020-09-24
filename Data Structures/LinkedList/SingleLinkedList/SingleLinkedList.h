#pragma once

#include "Node.h"

class SingleLinkedList
{
public:
    SingleLinkedList();
    SingleLinkedList( int inSize );
    ~SingleLinkedList();

    bool Search( int value );
    bool IsEmpty();
    void Add( int value );              // push back
    void AddAt( int index, int value ); // add by index
    int Pop();                          // pop
    void RemoveAt( int index );         // remove by index
    void Show();
    void SetValueAt( int index, int value );
    int GetValueAt( int index );
    int GetSize();
public:
    Node* head;
    Node* tail;
    int size;
};