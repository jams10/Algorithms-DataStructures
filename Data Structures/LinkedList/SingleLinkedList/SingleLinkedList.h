#pragma once

#include "Node.h"

class SingleLinkedList
{
public:
    SingleLinkedList();
    SingleLinkedList(int inSize);
    ~SingleLinkedList();

    bool Search(int value);
    bool IsEmpty();
    void Add(int value);
    void AddAt(int index, int value);
    void Pop();
    void RemoveAt(int index);
    int GetNodeAt(int index);

private:
    Node* head;
    Node* tail;
    int size;
};