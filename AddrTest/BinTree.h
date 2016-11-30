#ifndef BIN_TREE_H
#define BIN_TREE_H
#include "BinNode.h"
namespace AddrBookLib
{
	/*
	BinaryTree Template Class - New Data Structure instead of LinkList
	A BinaryTree is a collection data structure that is dynamic, storing BinNodes.
	Only BinNode pointers will be created in BinaryTree - NO BinNode objects
	A BinaryTree has a root BinNode pointer
	Public Members
	Default Constructor
	Copy Constructor
	Assignment Operator
	Destructor
	Add(Type dataIn)
	Bonus: Remove
	CountItems()
	ReadFile(string fileName)
	WriteFile(string fileName)
	PrintAll()
	inOrderTraverse(void process(Type&, int))
	Private Members
	CopyTree(BinNode*)
	Print(BinNode*, int&)
	WriteFile(BinNode*, ofstream&)
	BinNode* AllocBinNode(Type dataIn)
	FreeAllBinNodes(BinNode*)
	inOrderTraverse(BinNode*, int&, void process(Type&, int))
	Make sure all the member functions move links NOT data around when adding, removing.
	Make sure the class is a template and there is NO references to Name, Address, Contact, CategorizedContact
	*/
	template<class T>
	class BinTree
	{
	public:
		//save some typing.
		typedef const T & crefT;
		typedef (void)(*TraversalCallback)(T&, int);
		//default constructor
		BinTree();
		//copy constructor
		BinTree(const BinTree & source);
		//assignment operator
		BnTree<T> & operator=(const BinTree & source);
		//destructor0
		~BinTree();
		//Add(T dataIn)
		void Add(crefT dataIn);
		//Bonus: Rmove
		void Remove(crefT dataToRemove);
		//countItes()
		int CountItems();
		//ReadFile(string fileName)
		void ReadFile(string fileName);
		//writeFile(string fileName)
		void WriteFile(string fileName);
		//PrintAll()
		void PrintAll();
		//inOrderTraverse(void process(T&, int))
		void inOrderTraverse(TraversalCallback process);


	private:
		//Private Members
		//save more typing
		typedef BinNode<T>* PTBNode;
		//CopyTree(BinNode*)
		void CopyTree(PTBNode rootToCopy);
		//Print(BinNode*, int&)
		void Print(PTBNode aNode, int& number);
		//WriteFile(BinNode*, ofstream&)
		void WriteFile(PTBNode node, ofstream& ofs);
		//BinNode* AllocBinNode(Type dataIn)
		BinNode* AllocBinNode(Type dataIn);
		//FreeAllBinNodes(BinNode*)
		FreeAllBinNodes(PTBNode aNode);
		//inOrderTraverse(BinNode*, int&, void process(Type&, int))
		InOrderTraverse(PTBNode aNode, int&, TraversalCallback process);
		//Make sure all the member functions move links NOT data around when adding, removing.
		//Make sure the class is a template and there is NO references to Name, Address, Contact, CategorizedContact
		PTBNode root;
	};

}
#endif
