#pragma once
#include <iostream>;
#include <fstream>;

class FileReader {
private:
	std::string fileName;
	std::string textString;

public:
	FileReader(std::string textName) {
		fileName = textName;
	}
	
	std::string getTextString() {
		return textString;
	}

	void ReadFile() {
		std::ifstream InputFile(fileName);
		std::string line;

		int lineCount = 1;

		while (getline(InputFile, line)) {
			textString += line;
			if (lineCount > 1) {
				textString += "\n";
			}
			lineCount++;
		}

		InputFile.close();
	}
};