#pragma once

class Node
{
public:
    Node();
    Node( int inValue );
    void SetValue( int inValue );
    void SetNext( Node* nextNode );
    int GetValue();
    Node* GetNext();
private:
    Node* next;
    int value;
};