// Workshop 2 - Copy and Move Semantics
// Text.cpp
// Anmol Singh Sandhu
// 2019/01/21

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include "String.h"
//#include <string>
#include <fstream>
#include "Text.h"
using namespace std;

//     D E F A U L T   C O N S T R U C T O R
namespace sict {
	Text::Text() {
		strArray = nullptr;
		countRec = 0;
	}

//     1   A R G   C O N S T R U C T O R
	Text::Text(const std::string& fileName) {
		strArray = nullptr;
		countRec = 0;

		if (!fileName.empty()) {
			std::string readArea;
			std::ifstream fin(fileName);
			std::ifstream fin2(fileName);

			while (std::getline(fin, readArea)) {
				countRec++;
			}

			//     Allocates memory for records
			strArray = new std::string[countRec];

			//     Reads and stores records
			int ct = 0;
			while (std::getline(fin, readArea)) {
				strArray[ct] = readArea;
				ct++;
			}
		}
	}

//     C O P Y   C O N S T R U C T O R
	Text::Text(const Text& rhs) {
		*this = rhs;
	}

//     C O P Y   A S S I G N M E N T   O P E R A T O R
	Text& Text::operator=(const Text& rhs) {
		if (this != &rhs) {
			delete[] strArray;
			countRec = rhs.countRec;
			strArray = new std::string[countRec];

			for (size_t i = 0; i < countRec; i++) {
				strArray[i] = rhs.strArray[i];
			}
		}
		return *this;
	}

//     D E S T R U C T O R
	Text::~Text() {
		delete[] strArray;
		strArray = nullptr;
	}

	size_t Text::size() const {
		return countRec;
	}

//     M O V E   C O N S T R U C T O R
	Text::Text(Text&& src) {
		*this = std::move(src);
	}

//     M O V E   A S S I G N M E N T   O P E R A T O R
	Text& Text::operator=(Text&& src) {
		if (this != &src) {
			delete[] strArray;
			strArray = src.strArray;
			countRec = src.countRec;
			src.strArray = nullptr;
			src.countRec = 0;
		}
		return *this;
	}
}