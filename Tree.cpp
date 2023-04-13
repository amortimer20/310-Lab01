#include <iostream>
#include <string>
#include <vector>
#include "Tree.h"

using namespace std;

Tree::Tree() {
	root = nullptr;
}

Tree::Tree(Node* root) {
	this->root = root;
}

Node* Tree::rotateLeft(Node* root) {
	Node* pivot = root->right;
	Node* reattachNode = pivot->left;
	root->right = reattachNode;
	pivot->left = root;
	return pivot;
}

Node* Tree::rotateRight(Node* root) {
	Node* pivot = root->left;
	Node* reattachNode = pivot->right;
	root->left = reattachNode;
	pivot->right = root;
	return pivot;
}

Node* Tree::search(string target) {
	return root->search(target);
}

void Tree::insert(string data) {
	if (root == nullptr)
		root = new Node(data);
	else
		root->insert(data);
}

void Tree::insert(Node* node) {
	if (root == nullptr)
		root = node;
	else
		root->insert(node);
}

int Tree::height() {
	return root->height(0);
}

vector<string> Tree::getNodesAtDepth(int depth) {
	return *root->getNodesAtDepth(depth, new vector<string>);
}

void Tree::print() {
	int height = this->height();
	int spacing = 3;
	int width = (int)((pow(2, height) - 1) * (spacing + 1) + 1);
	int offset = (width - 1) / 2;

	for (int depth = 0; depth <= height; depth++)
	{
		if (depth > 0) {
			cout << string(offset + 1, ' ');

			for (int i = (int)pow(2, depth - 1); i > 0; i--)
				cout << "/" << string(spacing - 2, '-') << '\\' << string(spacing + 2, ' ');
			cout << endl;
		}

		cout << string(offset, ' ');

		for (string node : *root->getNodesAtDepth(depth, new vector<string>)) {
			if (node == "X") {
				cout << "\033[0;90m" << node << string(spacing, ' ');
			}
			else {
				int diffSpacing = (spacing - (int)node.size() + 1) >= 0 ? (spacing - (int)node.size() + 1) : 0;
				search(node)->isBalanced() ? cout << "\033[0;32m" : cout << "\033[0;91m";
				cout << node << string(diffSpacing, ' ');
			}
		}
		cout << "\033[0;37m" << endl;
		spacing = offset + 1;
		offset = offset / 2 - 1;
	}
	cout << endl;
}

void Tree::deleteNode(string target) {
	root = root->deleteNode(target);
}

bool Tree::isBalanced() {
	return root->isBalanced();
}

void Tree::rebalance() {
	root->rebalance();
	root = root->fixImbalance();
}