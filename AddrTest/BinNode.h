#ifndef BIN_NODE_H
#define BIN_NODE_H
namespace AddrTestLib
{
	template<class T>
	class BinTree;
	/*
	BinNode Template Class - Item for BinaryTree collection
	A BinNode has a data object and a link to the left and right BinNode.
	The BinNode class needs constructors (default and a constructor that will set the data)
	The BinNode class is NOT dynamic
	Make sure the class is a template and there is NO references to Name, Address, Contact,1 CategorizedContact
	The BinNode class is a helper class to BinaryTree and is only utilized in BinaryTree.
	*/
	template<class T>
	class BinNode
	{
	private:
		BinNode(T initialData = T())
		{
			data = initialData;
			left = nullptr;
			right = nullptr;
		}


		T data;
		BinNode<T>* left;
		BinNode<T>* right;
		friend class BinTree;
	};
}

#endif
