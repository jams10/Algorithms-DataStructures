#include "Node.h"

Node::Node()
    :
    prev( nullptr ),
    next( nullptr ),
    value( 0 )
{
}

Node::Node( int inValue )
    :
    prev( nullptr ),
    next( nullptr ),
    value( inValue )
{
}

void Node::SetValue( int inValue )
{
    this->value = inValue;
}

void Node::SetPrev( Node* prevNode )
{
    this->prev = prevNode;
}

void Node::SetNext( Node* nextNode )
{
    this->next = nextNode;
}

int Node::GetValue()
{
    return this->value;
}

Node* Node::GetPrev()
{
    return this->prev;
}

Node* Node::GetNext()
{
    return this->next;
}