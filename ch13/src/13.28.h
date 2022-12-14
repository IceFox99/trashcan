#pragma once
#include <string>

class TreeNode {
public:
	TreeNode() :
		value(std::string()), count(new int(1)), left(nullptr), right(nullptr) {}

	TreeNode(const TreeNode& tn) :
		value(tn.value), count(tn.count), left(tn.left), right(tn.right) { ++*count; }

	TreeNode& operator=(const TreeNode& tn) {
		++*tn.count;
		if (--*count == 0) {
			delete count;
			delete left;
			delete right;
		}
		count = tn.count;
		left = tn.left;
		right = tn.right;
		return *this;
	}

	~TreeNode() {
		if (--*count == 0) {
			delete count;
			delete left;
			delete right;
		}
	}
private:
	std::string value;
	int* count;
	TreeNode* left;
	TreeNode* right;
};

class BinStrTree {
public:
	BinStrTree() :
		root(new TreeNode()) {}

	BinStrTree(const BinStrTree& bst) :
		root(new TreeNode(*bst.root)) {}

	BinStrTree& operator=(const BinStrTree& bst) {
		if (this != &bst) {
			delete root;
			root = new TreeNode(*bst.root);
		}
		return *this;
	}

	~BinStrTree() {
		delete root;
	}
private:
	TreeNode* root;
};
