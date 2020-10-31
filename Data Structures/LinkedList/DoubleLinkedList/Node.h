#pragma once

class Node
{
public:
    Node();
    Node( int inValue );
    void SetValue( int inValue );
    void SetPrev( Node* prevNode );
    void SetNext( Node* nextNode );
    int GetValue();
    Node* GetPrev();
    Node* GetNext();
private:
    Node* prev;
    Node* next;
    int value;
};