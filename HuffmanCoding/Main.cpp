#include <iostream>;
#include <string>;
#include "FileReader.h";
#include "DataProcessor.h";
#include "HuffmanTree.h";
#include "Encoder.h";
#include "Decoder.h";

//You can print out different informations about the process
//by removing the comment signs below.

typedef std::vector<std::tuple<char, int>> tupleList_t;

std::string ReadFileToString(std::string fileName) {
	FileReader fileReader(fileName);
	fileReader.ReadFile();
	//std::cout << fileReader.getTextString();
	return fileReader.getTextString();

}

tupleList_t MakeDataStructure(std::string textString) {
	DataProcessor dataProcessor(textString);
	dataProcessor.FillCharacterMap();
	dataProcessor.FillCharacterTupleList();
	dataProcessor.OrderTupleList();
	//dataProcessor.PrintTupleList();
	return dataProcessor.getTupleList();
}

HuffmanTree MakeHuffmanTree(tupleList_t tupleList, std::string textString) {
	HuffmanTree huffmanTree(tupleList, ReadFileToString(textString));
	huffmanTree.BuildHuffmanTree();
	//huffmanTree.Inorder(huffmanTree.getRootNode());
	return huffmanTree;
}

void EncodeFile(TreeNode* node, std::string fileName, std::string outputPath) {
	Encoder encoder(node, fileName, outputPath);
	encoder.Encode();
}

void DecodeFile(TreeNode* node, std::string text) {
	Decoder decoder(node, text);
	decoder.Decode();
}

int main() {
	std::string fileName = "Text.txt";
	std::string outputFileName = "save.txt";

	std::string textString = ReadFileToString(fileName);
	tupleList_t charTupleList = MakeDataStructure(textString);
	
	HuffmanTree huffmanTree = MakeHuffmanTree(charTupleList, textString);
	TreeNode* root = huffmanTree.getRootNode();

	EncodeFile(root, textString, outputFileName);
	DecodeFile(root, outputFileName);

	delete root;

	return 0;
}



