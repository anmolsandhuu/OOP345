// Workshop 4 - Containers
// MessagePack.cpp
// Anmol Singh Sandhu
#include <iostream>
#include <string>
#include "MessagePack.h"
#include "Message.h"
using namespace std;
namespace sict {
	// 0 arg constructor
	MessagePack::MessagePack() {
		msgptr = nullptr;
		dmp_noOfElem = 0u;
	}

	// destructor
	MessagePack::~MessagePack() {
		delete[] msgptr;
	}

	// copy constructor
	MessagePack::MessagePack(const MessagePack& src) {
		*this = src;
	}

	// move constructor
	MessagePack::MessagePack(MessagePack&& src) {
		*this = std::move(src);
	}

	// copy assignment operator
	MessagePack& MessagePack::operator=(const MessagePack& src) {
		if (this != &src) {
			delete[] msgptr;
			msgptr = new Message[src.dmp_noOfElem];
			for (size_t i = 0; i < src.dmp_noOfElem; i++) {
				msgptr[i] = src.msgptr[i];
			}
			dmp_noOfElem = src.dmp_noOfElem;
//			msgptr = new Message(*src.msgptr);
		}
		return *this;
	}

	// move assignment operator
	MessagePack& MessagePack::operator=(MessagePack&& src) {
		if (this != &src) {
			delete[] msgptr;
			msgptr = src.msgptr;
			src.msgptr = nullptr;
			dmp_noOfElem = src.dmp_noOfElem;
			src.dmp_noOfElem = 0;
		}
		return *this;
	}
	
	MessagePack::MessagePack(Message** msg, int noOfElem) {
		if ((msg) && noOfElem > 0) {
			msgptr = new Message[noOfElem];

			int x = 0;
			for (int i = 0; i < noOfElem; i++) {
				if (!msg[i]->empty()) {
					msgptr[x] = *msg[i];
					x++;
				}
			}
			dmp_noOfElem = x;
		}
	}

	void MessagePack::display(std::ostream& os) const {
		for (size_t i = 0; i < size(); i++) { 
			if (!msgptr[i].empty()) {
				os << ">User : " << msgptr[i].getUser() << endl; 
				if (msgptr[i].getReply().length() > 0) { 
					os << "Reply : " << msgptr[i].getReply() << endl; 
				}
				os << "Tweet : " << msgptr[i].getTweet() << endl; 
			}
		}
	}


	size_t MessagePack::size() const {
		return dmp_noOfElem;
	}


	Message* MessagePack::getMsgptr() const {
		return msgptr;

	}


	std::ostream& operator<<(std::ostream& os, const MessagePack& msgpk) {
		msgpk.display(os);
		return os;
	}

}


