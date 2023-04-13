#pragma once
#include <cmath>
#include <iostream>
#include <vector>
#include "Node.h"
#include "Tree.h"

using namespace std;

Node::Node(string data) {
	this->data = data;
	left = nullptr;
	right = nullptr;
}

Node* Node::search(string target) {
	if (data == target)
		return this;
	else if (left && data > target)
		return left->search(target);
	else if (right && data < target)
		return right->search(target);
	else
		return nullptr;
}

void Node::insert(string data) {
	if (this->data == data)
		return;
	else if (left && this->data > data)
		left->insert(data);
	else if (right && this->data < data)
		right->insert(data);
	else if (this->data > data)
		left = new Node(data);
	else if (this->data < data)
		right = new Node(data);
}

void Node::insert(Node* node) {
	if (data == node->data)
		return;
	else if (left && data > node->data)
		left->insert(node);
	else if (right && data < node->data)
		right->insert(node);
	else if (data > node->data)
		left = node;
	else if (data < node->data)
		right = node;
}

int Node::height(int height) {
	int leftHeight = left ? left->height(height + 1) : height;
	int rightHeight = right ? right->height(height + 1) : height;
	return max(leftHeight, rightHeight);
}

vector<string>* Node::getNodesAtDepth(int depth, vector<string>* nodes) {
	if (depth == 0) {
		nodes->push_back(data);
		return nodes;
	}

	if (left) {
		left->getNodesAtDepth(depth - 1, nodes);
	}
	else {
		for (int i = (int)pow(2, depth - 1); i > 0; i--)
			nodes->push_back("X");
	}

	if (right) {
		right->getNodesAtDepth(depth - 1, nodes);
	}
	else {
		for (int i = (int)pow(2, depth - 1); i > 0; i--)
			nodes->push_back("X");
	}

	return nodes; // Did not reach depth
}

Node* Node::deleteNode(string target) {
	if (data == target) {
		// Two children
		// One or no children
		if (left && right) {
			string min = right->getMinValue();
			data = min;
			right = right->deleteNode(min);
			return this;
		}
		else {
			if (left)
				return left;
			else if (right)
				return right;
			else
				delete this;
			return nullptr;
		}
	}
	else if (left && target < data) {
		left = left->deleteNode(target);
	}
	else if (right && target > data) {
		right = right->deleteNode(target);
	}

	return this;
}

string Node::getMinValue() {
	return left ? left->getMinValue() : data;
}

bool Node::isBalanced() {
	return abs(getLRHeightDifference()) < 2;
}

int Node::getLRHeightDifference() {
	int leftHeight = left ? left->height(0) + 1 : 0;
	int rightHeight = right ? right->height(0) + 1 : 0;
	return leftHeight - rightHeight;
}

Node* Node::fixImbalance() {
	if (getLRHeightDifference() > 1) {
		// left imbalance
		if (left->getLRHeightDifference() > 0) {
			// left left
			return Tree::rotateRight(this);
		}
		else {
			// left right
			left = Tree::rotateLeft(left);
			return Tree::rotateRight(this);
		}
	}
	if (getLRHeightDifference() < -1) {
		// right imbalance
		if (right->getLRHeightDifference() < 0) {
			// right right
			return Tree::rotateLeft(this);
		}
		else {
			// right left
			right = Tree::rotateRight(right);
			return Tree::rotateLeft(this);
		}
	}

	return this;
}

void Node::rebalance() {
	if (left) {
		left->rebalance();
		left = left->fixImbalance();
	}
	if (right) {
		right->rebalance();
		right = right->fixImbalance();
	}
}