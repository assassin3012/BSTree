
#include "BSTree.h"
#include "BSTree.cpp"
#include <catch.hpp>
#include <fstream>

SCENARIO("BSTree init", "[init]") 
{
  BSTree<int> Tree;
  REQUIRE(Tree.size() == 0);
}
SCENARIO("BSTree list init", "[list init]") 
{
  BSTree<int> Tree {1,2,3};
  REQUIRE(Tree.size() == 3);
}
SCENARIO("BSTree insert element", "[insert]") 
{
	BSTree<int> Tree;
	Tree.insert(1);
	Tree.insert(3);
	REQUIRE(Tree.size() == 2);
}
SCENARIO("BSTree search", "[search]") 
{
	BSTree<int> Tree {1,2,3};
	REQUIRE(Tree.search(1) != nullptr);
	REQUIRE(Tree.search(2) != nullptr);
	REQUIRE(Tree.search(3) != nullptr);
	REQUIRE(Tree.search(404) == nullptr);
}
SCENARIO("BSTree remove", "[remove]") 
{
	BSTree<int> Tree {1,2,3,4,5};
	Tree.remove(4);
	REQUIRE(Tree.size()==3);
}
SCENARIO("BSTree operator >>", "[file&stream input]") 
{
	BSTree<int> Tree;
	fstream file("Tree.txt");
	file >> Tree;
	file.close();
	REQUIRE(Tree.size() == 5);
	REQUIRE(Tree.search(4) != nullptr);
	REQUIRE(Tree.search(5) != nullptr);
	REQUIRE(Tree.search(2) != nullptr);
	REQUIRE(Tree.search(6) != nullptr);
	REQUIRE(Tree.search(7) != nullptr);
}

SCENARIO("BSTree operator <<", "[file&stream output]") 
{
	BSTree<int> Tree, OutTree;
	fstream file("Tree.txt"), out("out.txt");
	file >> Tree;
	out << Tree;
	out >> OutTree;
	file.close();
	out.close();
	REQUIRE(Tree.search(4) != nullptr);
	REQUIRE(Tree.search(5) != nullptr);
	REQUIRE(Tree.search(2) != nullptr);
	REQUIRE(Tree.search(6) != nullptr);
	REQUIRE(Tree.search(7) != nullptr);
}
SCENARIO("BSTree EmptyException", "[emptyerror]")
{
	bool flagBad=false;
	bool flag=false;
	BSTree<int> Tree;
	try {
	  Tree.search(404);
	}
	catch (EmptyException &ex) {
		flag = true;
	}
	catch (BSTreeException &ex) {
		flagBad = true;
	}
	REQUIRE(flag);
	REQUIRE(!flagBad);
}
SCENARIO("Exception fill", "[fillerror]")
{
	bool flagBad=false;
	bool flag=false;
	BSTree<int> Tree;
	try {
		std::ifstream("404.txt") >> Tree;
	}
	catch (InputException &ex) {
		flag = true;
	}
	catch (BSTreeException &ex) {
		flagBad = true;
	}
	REQUIRE(flag);
	REQUIRE(!flagBad);
}
