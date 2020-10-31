#include <iostream>
#include "Node.h"
#include "DoubleLinkedList.h"

int main()
{
	// Create LinkedList
	DoubleLinkedList ListA;
	DoubleLinkedList ListB( 8 );
  
	// Check list creation
	std::cout << "<Inital statement>" << std::endl;
	std::cout << "A : ";
	ListA.Show();
	std::cout << "B : ";
	ListB.Show();

  
	// Add nodes to lists
	ListA.Push( 10 );
	ListA.Push( 20 );
	ListA.Push( 30 );

	ListB.Push( 10 );

	std::cout << "<Add>" << std::endl;
	std::cout << "A : ";
	ListA.Show();
	std::cout << "B : ";
	ListB.Show();

	ListA.AddAt( 1, 22 );
	ListA.AddAt( 2, 33 );

	ListB.AddAt( 1, 100 );
  ListB.AddAt( 8, 25 );
  
	std::cout << "<AddValueAt>" << std::endl;
	std::cout << "A : ";
	ListA.Show();
	std::cout << "B : ";
	ListB.Show();

  
	// Change value of nodes in lists
	ListA.SetValueAt( 1, 50 );
  ListA.SetValueAt( 4, 5);
	for( int i = 0; i < ListB.GetSize(); i++ )
	{
		ListB.SetValueAt( i, i );
	}

	std::cout << "<Change value>" << std::endl;
	std::cout << "A : ";
	ListA.Show();
	std::cout << "B : ";
	ListB.Show();

	// Remove nodes
	ListA.Pop();
	ListA.Pop();

	ListB.RemoveAt( 1 );
  ListB.RemoveAt( 8 );

	std::cout << "<Remove>" << std::endl;
	std::cout << "A : ";
	ListA.Show();
	std::cout << "B : ";
	ListB.Show();
  
}