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
		std::string* strArray = nullptr;
		size_t countRec = 0;
		
	public:
		Text();
		Text(const std::string&);
		Text(const Text& rhs);
		Text& operator=(const Text& rhs);
		~Text();
		size_t size() const;
		Text(Text&&);						// Move constructor
		Text& operator=(Text&&);			// Move assignment
	};
}

#endif