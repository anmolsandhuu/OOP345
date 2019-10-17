// Workshop 2 - Copy and Move Semantics
// Text.h
// Anmol Singh Sandhu
// 2019/01/21
#ifndef _OOP345_TEXT_H_
#define _OOP345_TEXT_H_
#include <string>

namespace sict {

	class Text {
	private:
		std::string* strArray;
		size_t countRec;
		
	public:
		Text();
		Text(const std::string&);
		Text(const Text& rhs);
		Text& operator=(const Text& rhs);
		~Text();
		size_t size() const;
	};
}

#endif