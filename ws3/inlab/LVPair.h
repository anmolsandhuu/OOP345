// Workshop 3 - Templates
// LVPair.h
// Anmol Singh Sandhu
// 2019/01/29
#ifndef _OOP345_LVPAIR_H_
#define _OOP345_LVPAIR_H_
#include <iostream>
using namespace std;

namespace sict {
	template <typename L, typename V>
	class LVPair {
		L dm_lable;
		V dm_value;

	public:
//                C O N S T R U C T O R
		LVPair() : dm_lable{}, dm_value{} {}
//
//               OVERLOADED CONSTRUCTOR - 2 PARAMETERS
		LVPair(const L& label, const V& value) : dm_lable(label), dm_value(value) {}
//
//               DISPLAY FUNCTION
		void display(std::ostream& os) const {
			os << dm_lable << " : " << dm_value << std::endl;
		}
	};
//
//               NON-FRIEND HELPER FUNCTION
	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L,V>& pair) {
		pair.display(os);
		return os;
	}	
}
#endif