#include "Node.h"

Node::Node()
    :
    next( nullptr ),
    value( 0 )
{
}

Node::Node( int inValue )
    :
    next( nullptr ),
    value( inValue )
{
}

void Node::SetValue( int inValue )
{
    this->value = inValue;
}

void Node::SetNext( Node* nextNode )
{
    this->next = nextNode;
}

int Node::GetValue()
{
    return this->value;
}

Node* Node::GetNext()
{
    return this->next;
}