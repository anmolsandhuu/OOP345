// Workshop 4 - Containers
// Message.cpp
// Anmol Singh Sandhu
// 2019/02/05
#ifndef _345_MESSAGE_H_
#define _345_MESSAGE_H_
#include <iostream>
using namespace std;
namespace sict {

	class Message {
		std::string dm_user;
		std::string dm_reply;
		std::string dm_tweet;

	public :
		Message();
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;

	};


}



#endif // !_345_MESSAGE_H_
