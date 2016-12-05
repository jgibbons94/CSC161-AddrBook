#ifndef BIN_TREE_H
#define BIN_TREE_H
#include "BinNode.h"
#include "BinTreeFriendTests.h"
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
	//Requirement: Make sure the class is a template and there is NO references to Name, Address, Contact, CategorizedContact
	template<class T>
	class BinTree
	{
	public:
		//save some typing.
		//When adding or removing data, pass a constant reference.
		typedef const T & crefT;
		typedef BinTree<T> & refTBinTree;
		//Callback for transversing the binary tree.
		//the T reference refers to the data given in a node
		//the int reference can be used by the traversal callback function to keep track of how many have been successfully processed so far.
		using TraversalCallback = void(*)(refTBinTree, int&);
		//typedef (void)(*TraversalCallback)(T&, int&);
		//Requirement: default constructor
		BinTree();
		//Requirement: copy constructor
		BinTree(const refTBinTree source);
		//Requirement: assignment operator
		refTBinTree operator=(const refTBinTree source);
		//Requirement: destructor
		~BinTree();
		//Requirement: Add(T dataIn)
		void Add(crefT dataIn);
		//Bonus: Rmove
		void Remove(crefT dataToRemove);
		//Requirement: countItes()
		int CountItems();
		//Requirement: ReadFile(string fileName)
		void ReadFile(string fileName);
		//Requirement: writeFile(string fileName)
		void WriteFile(string fileName);
		//Requirement: PrintAll()
		void PrintAll();
		//Requirement: inOrderTraverse(void process(T&, int))
		void inOrderTraverse(TraversalCallback process);


	private:
		//Private Members
		//Requirement: Make sure all the member functions move links NOT data around when adding, removing.
		//save more typing
		typedef BinNode<T> * PTBNode;
		//Requirement: CopyTree(BinNode*)
		void CopyTree(PTBNode rootToCopy);
		//Requirement: Print(BinNode*, int&)
		void Print(PTBNode aNode, int& number);
		//Requirement: WriteFile(BinNode*, ofstream&)
		void WriteFile(PTBNode node, ofstream& ofs);
		//Requirement: BinNode* AllocBinNode(Type dataIn)
		BinNode<T>* AllocBinNode(crefT dataIn);
		//Requirement: FreeAllBinNodes(BinNode*)
		void FreeAllBinNodes(PTBNode aNode);
		//Requirement: inOrderTraverse(BinNode*, int&, void process(Type&, int))
		void InOrderTraverse(PTBNode aNode, int&, TraversalCallback process);

		void AddNode(PTBNode aNode);


		PTBNode root;
#ifdef BIN_TREE_TEST_FRIENDS
		friend void test::TestBinTree_Constructor0_0<T>();
		friend void test::TestBinTree_CopyConstructor<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestBinTree_CopyConstructor_leaks<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestBinTree_Assignment<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestBinTree_Assignment_leaks<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestBinTree_Deconstructor<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
#endif
	};
	//begin BinTree.tem
	template<class T>
	inline BinTree<T>::BinTree()
	{
		this->root = nullptr;
	}

	template<class T>
	inline BinTree<T>::BinTree(const refTBinTree source)
	{
		this->root = nullptr;
		this->CopyTree(source.root);
	}

	template<class T>
	inline BinTree<T>& BinTree<T>::operator=(const refTBinTree source)
	{
		if (this != &source)
			this->CopyTree(source.root);
		return *this;
	}

	template<class T>
	inline BinTree<T>::~BinTree()
	{
		this->FreeAllBinNodes(this->root);
	}
	template<class T>
	inline void BinTree<T>::Add(crefT dataIn)
	{
		PTBNode data = AllocBinNode(dataIn);
		AddNode(data);
	}
	template<class T>
	inline void BinTree<T>::CopyTree(PTBNode rootToCopy)
	{
		if (rootToCopy == nullptr)
			return;
		Add(rootToCopy->data);
		CopyTree(rootToCopy->left);
		CopyTree(rootToCopy->right);

	}
	template<class T>
	inline BinNode<T> * BinTree<T>::AllocBinNode(crefT dataIn)
	{
		return new BinNode<T>(dataIn);//new BinNode<T>();
	}
	template<class T>
	inline void BinTree<T>::FreeAllBinNodes(PTBNode aNode)
	{
		if (aNode == nullptr)
			return;
		FreeAllBinNodes(aNode->left);
		FreeAllBinNodes(aNode->right);
		delete aNode;
	}
	template<class T>
	inline void BinTree<T>::AddNode(PTBNode data)
	{
		if (root == nullptr)
		{
			root = data;
			return;
		}
		//root is not nullptr.
		PTBNode parent = nullptr,
			 * next = &root;
		//pointer to a pointer -- we want to be able to get a pointer that could point to a nullptr, and set the data later.
		do
		{
			parent = *next;
			if (parent->data > data->data)
				*next = parent->left;
			else
				*next = parent->right;

		} while (*next != nullptr);//next is not null; *next is null, **next does not exist.
		*next = data;
	}
}
#endif
