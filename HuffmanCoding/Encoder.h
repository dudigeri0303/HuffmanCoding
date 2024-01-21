#pragma once
#include <string>;
#include <iostream>;
#include <fstream>;


class Encoder {
private:
	TreeNode* rootNode;
	std::string textSrting;
	std::string path;

public:
	Encoder(TreeNode* root, std::string text, std::string outputPath) {
		textSrting = text;
		rootNode = root;
		path = outputPath;
	}
private:
	void WriteCodeToFile(std::ofstream& outStream, std::string code) {
		outStream << code << std::endl;
	}


	void GetCharCode(TreeNode* node, char c, std::ofstream& outStream) {
		if (node == nullptr) {
			return;
		}
		
		if (node->character == c) {
			WriteCodeToFile(outStream, node->code);
		}

		if (node->leftNode != nullptr) {
			GetCharCode(node->leftNode, c, outStream);
		}

		if (node->rightNode != nullptr) {
			GetCharCode(node->rightNode, c, outStream);
		}
	}
public:
	void Encode() {
		std::ofstream output(path, std::ofstream::out);

		for (char c : textSrting) {
			GetCharCode(rootNode, c, output);
		}

		output.close();
	}
};