#pragma once
#include <string>;

class Decoder {
private:
	TreeNode* rootNode;
	std::string fileName;
	std::string textString;
public:
	Decoder(TreeNode* root, std::string file) {
		rootNode = root;
		textString = "";
		fileName = file;
	}

private:
	void ReadFile(std::string file) {
		std::ifstream InputFile(file);
		std::string line;

		while (getline(InputFile, line)) {
			textString += line;
		}

		InputFile.close();
	}

	void WriteToOutput(char c) {
		std::cout << c;
	}


	void GetCharCode(TreeNode* node, std::string c) {
		if (node == nullptr) {
			return;
		}

		if (node->code == c) {
			WriteToOutput(node->character);
		}

		if (node->leftNode != nullptr) {
			GetCharCode(node->leftNode, c);
		}

		if (node->rightNode != nullptr) {
			GetCharCode(node->rightNode, c);
		}
	}

public:
	void Decode() {
		std::ifstream InputFile(fileName);
		std::string line;

		while (getline(InputFile, line)) {
			GetCharCode(rootNode, line);
		}
	}

};