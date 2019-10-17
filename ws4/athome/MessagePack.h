// Workshop 4 - Containers
// MessagePack.cpp
// Anmol Singh Sandhu
// 2019/02/09
//#ifndef _345_MESSAGEPACK_H_
//#define _345_MESSAGEPACK_H_
#include <iostream>
#include <string>

using namespace std;

namespace sict {
	class Message;

	class MessagePack {
//		Message message;
		Message* msgptr = nullptr;
		size_t dmp_noOfElem;


	public:
		MessagePack();								// 0 arg constructor
		~MessagePack();								// destructor
		MessagePack(const MessagePack&);			// copy constructor
		MessagePack(MessagePack&&);					// move constructor
		MessagePack& operator=(const MessagePack&);	// copy assignment operator
		MessagePack& operator=(MessagePack&&);		// move assignment operator
		
		MessagePack(Message** msg, int noOfElem);
		void display(std::ostream& os) const;
		size_t size() const;

		Message* getMsgptr() const;

	};
	std::ostream& operator<<(std::ostream& os, const MessagePack& msgpk);
}



//#endif // !_345_MESSAGE_H_
