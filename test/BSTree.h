#pragma once
#include <iostream>
#include <fstream>
#include "BSTreeException.h"

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
	~BSTree() { if (root!=nullptr) remove(root->key); }
	Node<T>* search(const T &k) const;
	Node<T>* next(Node<T>* node) const;
	Node<T>* prev(Node<T>* node) const;
	Node<T>* min(Node<T>* node) const;
	Node<T>* max(Node<T>* node) const;
	void insert(const T &k);
	void deletetree(const T &k);
	void remove(const T &k);
	//auto begin() { return &root; };
	//auto end() { return &root + sizeof(root)*_size+sizeof(_size); };
	size_t size() { return _size; };
	void printBSTree(std::ostream &os/*=std::cout*/) const;
	friend std::ostream & operator << <>(std::ostream &output, BSTree &);
	friend std::istream & operator >> <>(std::istream &input, BSTree &);
	friend std::fstream & operator << <>(std::fstream &file, BSTree<T> &);
	friend std::fstream & operator >> <>(std::fstream &file, BSTree<T> &);
private:
	Node<T>* search(Node<T>* node, const T &k) const;
	void printBSTree(Node<T>*, std::ostream &) const;
	Node<T>* root;
	size_t _size;
};
