#pragma once
#include <vector>
#include <string>

using namespace std;

class Node {
public:
	Node(string data);
	string data;
	Node* left;
	Node* right;
	Node* search(string);
	void insert(string);
	void insert(Node*);
	int height(int);
	vector<string>* getNodesAtDepth(int, vector<string>*);
	Node* deleteNode(string);
	bool isBalanced();
	Node* fixImbalance();
	void rebalance();
private:
	int getLRHeightDifference();
	string getMinValue();
};