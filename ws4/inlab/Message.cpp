// Workshop 4 - Containers
// Message.cpp
// Anmol Singh Sandhu
// 2019/02/05
#include <iostream>
#include <string>
#include "Message.h"
using namespace std;
namespace sict {

	Message::Message() {
		dm_user  = '\0';
		dm_reply = '\0';
		dm_tweet = '\0';
	}


	Message::Message(const std::string& str) {
		size_t pos = 0u;

		if (!str.empty()) {
			string aux = str;
			string auxuser;
			string auxreply;
			string auxtweet;
//     F I R S T    P A R T
			auxuser = aux.substr(0, aux.find(" "));		//look for first space 
			pos = auxuser.length() + 1;					//positioning 
			aux.erase(0, pos);							//erase first part
//     S E C O N D     P A R T
			if (aux[0] == '@') {						//is there "@" 
				auxreply = aux.substr(1, aux.find(" "));    //look for space
				pos = auxreply.length() + 1;			//positioning
				aux.erase(0, pos);						//erase second part
			}
//     T H I R D     P A R T 
			auxtweet = aux.substr(0, aux.npos);			//third part
//     O K     N O K
			if (auxtweet.length() != 0) {				//is there tweet 
				dm_user = auxuser;
				dm_reply = auxreply;
				dm_tweet = auxtweet;
			}
		}
	}


	bool Message::empty() const {
		bool ret = false;
		if (dm_user.empty() && dm_reply.empty() && dm_tweet.empty()) {
			ret = true;
		}
		return ret;
	}


	void Message::display(std::ostream& os) const {
		if (!empty()) {
			os << ">User : " << dm_user << endl;

			if (dm_reply.length() > 0) {
				os << "Reply : " << dm_reply << endl;
			}

			os << "Tweet : " << dm_tweet << endl;
		}
	}
}
