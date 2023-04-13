#pragma once
#include <vector>
#include <string>
#include "Node.h"

class Tree {
public:
	Tree();
	Tree(Node* root);
	static Node* rotateLeft(Node* root);
	static Node* rotateRight(Node* root);
	Node* root;
	Node* search(string);
	void insert(string);
	void insert(Node*);
	int height();
	vector<string> getNodesAtDepth(int);
	void print();
	void printNodeInTree(Node*);
	void deleteNode(string);
	bool isBalanced();
	void rebalance();
};