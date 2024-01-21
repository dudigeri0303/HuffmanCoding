#pragma once;
#include <string>;

class TreeNode {
public:
	char character;
	int probability;
	std::string code;

	TreeNode* leftNode;
	TreeNode* rightNode;

	TreeNode(char character_p, double probability_p ) {
		character = character_p;
		probability = probability_p;
		code = "";
		leftNode = nullptr;
		rightNode = nullptr;
	}

	void setLeftNode(TreeNode* node) {
		leftNode = node;
	}

	void setRightNode(TreeNode* node) {
		rightNode = node;
	}

	~TreeNode() {	
		if (leftNode != nullptr) {
			delete leftNode;
		}
		if (rightNode != nullptr) {
			delete rightNode;
		}
	}
};

