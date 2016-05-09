#pragma once
#include <exception>
using namespace std;

class BSTreeException : public std::exception
{
public:
	BSTreeException() : std::exception(invalid_argument("Unknown exception")) {};
	BSTreeException(const char *_message) : std::exception(invalid_argument(_message)) {};
};
class EmptyException : public BSTreeException
{
public:
	EmptyTree() : EmptyException("Tree is empty") {};
};
class InputException : public BSTreeException
{
public:
	InputException() : TreeException("Error in input") {};
};
class InputFileException : public BSTreeException
{
public:
	InputFileException() : TreeException("Error in input from file") {};
};
