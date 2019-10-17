// Workshop 4 - Containers
// Notifications.cpp
// Anmol Singh Sandhu
// 2019/02/09
#include <iostream>
#include <string>
#include "Notifications.h"
using namespace std;
namespace sict {
	Notifications::Notifications() {
		msgptrNot = nullptr;
		dmnot_noOfElem = 0;
		dmnot_currStored = 0;
	}


	Notifications::Notifications(int no) {
		if (no > 0) {
			msgptrNot = new const Message*[no];
			dmnot_noOfElem = no;
		}
		else {
			*this = Notifications();
		}
	}

	Notifications& Notifications::operator+=(const Message& msg) {
		if (!msg.empty() && dmnot_noOfElem	> 0) {
			msgptrNot[dmnot_currStored++] = &msg;
			}
		return *this;
		}


	Notifications& Notifications::operator-=(const Message& msg) {
		bool found = false;
		int i = 0;

		for (i = 0; i < dmnot_noOfElem && !found; i++) {
			if (msgptrNot[i] == &msg) {
				found = true;
			}
			if (found) {
				for (int i = 0; i < dmnot_currStored; i++) {
					if (i < dmnot_noOfElem)
						msgptrNot[i] = msgptrNot[i + 1];
					else
						msgptrNot[dmnot_currStored] = nullptr;
				}
				dmnot_currStored--;
			}
		} 
		return *this;  
	}


	void Notifications::display(std::ostream& os) const {
		for (size_t i = 0; i < size(); i++) {
			if (!msgptrNot[i]->empty()) {
				os << ">User : " << msgptrNot[i]->getUser() << endl;
				if (msgptrNot[i]->getReply().length() > 0) {
					os << "Reply : " << msgptrNot[i]->getReply() << endl;
				}
				os << "Tweet : " << msgptrNot[i]->getTweet() << endl;
			}
		}
	}


	size_t Notifications::size() const {
		return dmnot_currStored;
	}

	Notifications::Notifications(Notifications&& src) {
		*this = std::move(src);
		src.msgptrNot = nullptr;
	}


	Notifications&& Notifications::operator=(Notifications&& src) {
		if (this != &src) {
			dmnot_currStored = src.dmnot_currStored;
			msgptrNot = src.msgptrNot;
			src.msgptrNot = nullptr;
			src.dmnot_currStored = 0;
		}
		return std::move(*this);
	}


	std::ostream& operator<<(std::ostream& os, Notifications& msgNot) {
		msgNot.display(os);
		return os;
		} 
	}
	
