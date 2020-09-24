#include <iostream>
#include "Node.h"
#include "SingleLinkedList.h"

int main()
{
	// Create LinkedList
	SingleLinkedList ListA;
	SingleLinkedList ListB( 8 );

	// Check list creation
	std::cout << "<Inital statement>" << std::endl;
	std::cout << "A : ";
	ListA.Show();
	std::cout << "B : ";
	ListB.Show();

	// Add nodes to lists
	ListA.Add( 10 );
	ListA.Add( 20 );
	ListA.Add( 30 );

	ListB.Add( 10 );

	std::cout << "<Add>" << std::endl;
	std::cout << "A : ";
	ListA.Show();
	std::cout << "B : ";
	ListB.Show();

	ListA.AddAt( 1, 22 );
	ListA.AddAt( 2, 33 );

	ListB.AddAt( 0, 100 );

	std::cout << "<AddValueAt>" << std::endl;
	std::cout << "A : ";
	ListA.Show();
	std::cout << "B : ";
	ListB.Show();

	// Change value of nodes in lists
	ListA.SetValueAt( 0, 50 );
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

	std::cout << "<Remove>" << std::endl;
	std::cout << "A : ";
	ListA.Show();
	std::cout << "B : ";
	ListB.Show();

}