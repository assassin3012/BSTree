#include "BSTree.h"
#include <initializer_list>

template <typename T>
BSTree<T>::BSTree(const std::initializer_list<T> &list)
{
	root = nullptr;
	for (auto i : list)
	{
		this->insert(i);
	}
}
template <typename T>
void BSTree<T>::insert(const T &k)
{
	if (root == nullptr)
	{
		root = new Node<T>(k);
		root->parent = nullptr;
		this->_size += 1;
	}
	else
	{
		Node<T>* p = root;
		Node<T>* prev = nullptr;
		while (p != nullptr)
		{
			prev = p;
			if (p->key > k)
			{
				p = p->left;
			}
			else
			{
				p = p->right;
			}
		}
		if (search(k) != nullptr)
		{
		//	throw "copy key";
		}
		else
		{
			this->_size += 1;
			if (prev->key > k)
			{
				prev->left = new Node<T>(k);
				prev->left->parent = prev;
			}
			else
			{
				prev->right = new Node<T>(k);
				prev->right->parent = prev;
			}
		}
	}
}
template <typename T>
Node<T>* BSTree<T>::search(const T &k)
{
	if (root == nullptr)
	{
		throw EmptyException();
	}
	else
	{
		Node<T>* node = root;
		search(node, k);
	}
}
template <typename T>
Node<T>* BSTree<T>::search(Node<T>* node, const T &k)
{
	if (node->key == k)
	{
		return node;
	}
	else if (node->key > k)
	{
		if (node->left != nullptr)
		{
			return search(node->left, k);
		}
		else
		{
			return nullptr;
		}
	}
	else
	{
		if (node->right != nullptr)
		{
			return search(node->right, k);
		}
		else
		{
			return nullptr;
		}
	}
}
template <typename T>
void BSTree<T>::remove(const T &k)
{
	if (root == nullptr)
	{
		throw EmptyException();
	}
	else if (search(k) == nullptr)
	{
		//throw "Empty";
	}
	else
	{
		Node<T>* node = search(k);
		if (node->left != nullptr)
		{
			remove(node->left->key);
		}
		if (node->right != nullptr)
		{
			remove(node->right->key);
		}
		if (node->parent->left == nullptr)
		{
			if (node->parent->left == node)
			{
				node->parent->left = nullptr;
			}
			else
			{
				node->parent->right = nullptr;
			}
		}
		this->_size -= 1;
		delete node;
	}
}
template <typename T>
void BSTree<T>::printBSTree(std::ostream &os/* = std::cout*/)
{
	if (root == nullptr)
	{
		throw EmptyException();
	}
	else
	{
		Node<T>* node = root;
		{
			printBSTree(node, os);
		}
	}
}
template <typename T>
void BSTree<T>::printBSTree(Node<T>* node, std::ostream &os)
{
	if (node->left != nullptr)
	{
		printBSTree(node->left, os);
	}
	std::cout<< node->key << std::endl;
	if (node->right != nullptr)
	{
		printBSTree(node->right, os);
	}
}
template <typename T>
std::ostream & operator << (std::ostream &os, BSTree<T> &out)
{
	out.printBSTree(os);
	return os;
}
template <typename T>
std::istream & operator >> (std::istream &input, BSTree<T> &in)
{
	unsigned int n;
	input >> n;
	T temp;
	for (unsigned int i = 0; i < n; ++i)
	{
		if (input >> temp)
		{
			in.insert(temp);
		}
		else {
			throw InputException();
		}
	}
	return input;
}
template <typename T>
std::fstream & operator << (std::fstream &file, BSTree<T> &out)
{
	out.printBSTree(file);
	return file;
}
template <typename T>
std::fstream & operator >> (std::fstream &file, BSTree<T> &in)
{
	unsigned int n;
	file >> n;
	T temp;
	for (unsigned int i = 0; i < n; ++i)
	{
		if (file >> temp)
		{
			in.insert(temp);
		}
		else {
			throw InputFileException();
		}
	}
	return file;
}
