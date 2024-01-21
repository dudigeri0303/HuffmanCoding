#pragma once
#include "TreeNode.h";
#include <vector>;
#include <tuple>;
#include <map>;

class HuffmanTree {
private:
	typedef std::vector<std::tuple<char, int>> tupleList_t;
	typedef std::vector<TreeNode*> rootList_t;
	
	rootList_t nodeList;
	TreeNode* rootNode;

public:
	HuffmanTree(tupleList_t tupleList, std::string textString) {
		FillRootList(tupleList);
		//BuildHuffmanTree();
	}

	TreeNode* getRootNode() {
		return rootNode;
	}

private:
	void FillRootList(tupleList_t tupleList) {
		for (auto tpl : tupleList) {
			TreeNode* newNode = new TreeNode(std::get<0>(tpl), std::get<1>(tpl));
			nodeList.push_back(newNode);
		}
	}

	void MergeNodes() {
		TreeNode* root = new TreeNode('\0', nodeList[0]->probability + nodeList[1]->probability);

		root->setLeftNode(nodeList[0]);
		root->setRightNode(nodeList[1]);

		AddToCode(root->leftNode, "0");
		AddToCode(root->rightNode, "1");

		DeleteUsedAndInsertNewNode(root);
	}

	void DeleteUsedAndInsertNewNode(TreeNode* newNode) {
		for (int i = 0; i < 2; i++) {
			nodeList.erase(nodeList.begin());
		}

		nodeList.push_back(newNode);

		//if there is only one (the last) node we set the rootNode to that and return
		if (nodeList.size() == 1) {
			rootNode = newNode;
			nodeList.erase(nodeList.begin());
			return;
		}

		ReorderNodeList();
	}

	void ReorderNodeList() {
		for (int i = nodeList.size() - 1; i > 0; i--) {
			if (nodeList[i]->probability <= nodeList[i - 1]->probability) {
				auto temp = nodeList[i];
				nodeList[i] = nodeList[i - 1];
				nodeList[i - 1] = temp;
			}
		}
	}

	void AddToCode(TreeNode* node, std::string cd)  {
		if (node == nullptr) {
			return;
		}

		if (node->leftNode != nullptr) {
			AddToCode(node->leftNode, cd);
		}

		node->code.insert(0, cd);

		if (node->rightNode != nullptr) {
			AddToCode(node->rightNode, cd);
		}
	}
public:
	void Inorder(TreeNode* node) {
		if (node == nullptr) {
			return;
		}
		if (node->leftNode != nullptr) {
			Inorder(node->leftNode);
		}
		if (node->character != '\0') {
			std::cout << node->character << ":" << node->probability << " --> " << node->code << std::endl;
		}
		else {
			std::cout << "NULL" << ":" << node->probability << " --> " << node->code << std::endl;
		}
		if (node->rightNode != nullptr) {
			Inorder(node->rightNode);
		}
	}

	void BuildHuffmanTree() {
		while (nodeList.size() > 0) {
			MergeNodes();
		}
	}
};