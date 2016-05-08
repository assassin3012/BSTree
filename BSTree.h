#pragma once
#include <iostream>
#include <fstream>

template <typename T>
class BSTree;

template <typename T>
struct Node;

template <typename T>
std::ostream & operator  << (std::ostream &output, BSTree<T> &);

template <typename T>
std::istream & operator >> (std::istream &input, BSTree<T> &);

template <typename T>
std::fstream & operator << (std::fstream &file, BSTree<T> &);

template <typename T>
std::fstream & operator >> (std::fstream &file, BSTree<T> &);

template <class T>
struct Node
{
	Node<T>() : key(0), left(nullptr), right(nullptr) {};
	Node<T>(const T &k) : key(k), left(nullptr), right(nullptr) {};
	~Node<T>() { if (left) delete left; if (right) delete right; };

	T key;
	Node<T>* left;
	Node<T>* right;
	Node<T>* parent;
};

template <typename T>
class BSTree
{
public:
	BSTree<T>() : root(nullptr), _size(0) {};
	BSTree<T>(const std::initializer_list<T> &);
	~BSTree<T>() { delete root; };

	Node<T>* search(const T &k);
	void insert(const T &k);
	void remove(const T &k);
	auto begin() { return &root; };
	auto end() { return &root + sizeof(root)*_size; };
	size_t size() { return _size; };
	void printBSTree(std::ostream &);
	friend std::ostream & operator << <>(std::ostream &output, BSTree &);
	friend std::istream & operator >> <>(std::istream &input, BSTree &);
	friend std::fstream & operator << <>(std::fstream &file, BSTree<T> &);
	friend std::fstream & operator >> <>(std::fstream &file, BSTree<T> &);
private:
	Node<T>* search(Node<T>* node, const T &k);
	void printBSTree(Node<T>*, std::ostream &);
	Node<T>* root;
	size_t _size;
};