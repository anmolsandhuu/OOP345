// Workshop 3 - Templates
// LVPair.h
// Anmol Singh Sandhu
// 2019/01/29
#ifndef _OOP345_LVPAIR_H_
#define _OOP345_LVPAIR_H_
#include <iostream>
#include <string>
using namespace std;

namespace sict {
	template <typename L, typename V>
	class LVPair {
		L dm_lable;
		V dm_value;

	public:
//                C O N S T R U C T O R
		LVPair() {}
//
//               OVERLOADED CONSTRUCTOR - 2 PARAMETERS
		LVPair(const L& label, const V& value) : dm_lable(label), dm_value(value) {}
//
//               DISPLAY FUNCTION
		virtual void display(std::ostream& os) const {
			os << dm_lable << " : " << dm_value << std::endl;
		}

		L getL() const {
			return dm_lable;
		}

		V getV() const {
			return dm_value;
		}
	};

//
//               NON-FRIEND HELPER FUNCTION
	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}

//
//   S U M M A B L E L V P A I R   C L A S S 
	template <typename L, typename V>
	class SummableLVPair : public LVPair<L, V> {
		static V dm_initial;
		static size_t dm_minChar;

	public :
		SummableLVPair() {}

		SummableLVPair(const L& label, const V& v) : LVPair<L, V>(label, v) {
			dm_minChar = dm_minChar < label.size() ? label.size() : dm_minChar;
		}

		static const V& getInitialValue() {
			return dm_initial;
		}

		V sum(const L& label, const V& sum) const {
//			return getInitialValue() + sum;
			V ret = LVPair<L, V>::getV() + sum;
			return ret;
		}

		void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(dm_minChar);
			LVPair<L, V>::display(os);
			os.unsetf(std::ios::left);
		}

//		template <>
//			LVPair<std::string, int>(std::string label, int value) {
//			value = 0;
//			}
//
//		template <>
//			LVPair<std::string, std::string>(std::string s1, std::string s2) {
//			s1 = ' ';
//			s2 = ' ';
//		}
//
//		template <>
//		std::string sum(const std::string& s1, const std:string s2) const {
//			return s1 + ' ' + s2;
//		}
	};
		template <>
		std::string SummableLVPair<std::string, std::string>::sum(const std::string& s1, const std::string& s2) const {
			std::string ret;
			if (s2 == " ") {
				ret = s2 + LVPair<std::string, std::string>::getV();
			} 
			else {

				//			std::string ret = s1 + " " + s2;
				ret = s2 + " " + LVPair<std::string, std::string>::getV();
			}
				return ret;
			
	}
}

#endif