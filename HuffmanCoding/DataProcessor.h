#pragma once
#include <iostream>;
#include <map>;
#include <vector>;
#include <tuple>;

class DataProcessor {
private:
	typedef std::vector<std::tuple<char, int>> tupleList_t;

	std::string textString;
	std::map<char, int> characterMap;
	tupleList_t characterTupleList;

public:
	DataProcessor(std::string text) {
		textString = text;
		
	}

	tupleList_t getTupleList() {
		return characterTupleList;
	}

	void FillCharacterMap() {
		for (char character : textString) {
			if (characterMap.count(character) == 0) {
				characterMap.insert({ character, 1 });
			}
			else {
				characterMap[character]++;
			}
		}
	}

	void FillCharacterTupleList() {
		for (auto kvp : characterMap)
		{
			characterTupleList.push_back(std::tuple<char, int>(kvp.first, kvp.second));
		}
	}

	void OrderTupleList() {
		for (int i = 1; i < characterTupleList.size(); i++) {
			for (int j = 0; j < characterTupleList.size() - 1; j++) {
				if (std::get<1>(characterTupleList[i]) < std::get<1>(characterTupleList[j])) {
					auto temp = characterTupleList[i];
					characterTupleList[i] = characterTupleList[j];
					characterTupleList[j] = temp;
				}
			}
		}
	}

	void PrintTupleList() {
		for (auto tup : characterTupleList) {
			std::cout << std::get<0>(tup);
			std::cout << std::get<1>(tup) << std::endl;
		}
	}
};