// Workshop 4 - Containers
// Notifications.cpp
// Anmol Singh Sandhu
#ifndef _345_MESSAGEPACK_H_
#define _345_MESSAGEPACK_H_
#include <iostream>
#include <string>
#include "Message.h"
using namespace std;

namespace sict {
	class Message;

	class Notifications {
		const Message** msgptrNot = nullptr;
		int dmnot_noOfElem = 0;
		int dmnot_currStored = 0;


	public:
		Notifications();
		Notifications(int);
		Notifications& operator+=(const Message& msg);
		Notifications& operator-=(const Message& msg);
		void display(std::ostream& os) const;
		size_t size() const;
		Notifications(Notifications&&);
		Notifications&& operator=(Notifications&&);
		
	};
	std::ostream& operator<<(std::ostream& os, Notifications& msgNot);
}



#endif // !_345_MESSAGE_H_
