// Workshop 2 - Copy and Move Semantics
// Timekeeper.cpp
// Anmol Singh Sandhu
// 2019/01/21

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include "String.h"
//#include <cstring>
#include <chrono>
#include "Timekeeper.h"
using namespace std;

namespace sict {
	Timekeeper::Timekeeper() { }

	void Timekeeper::start() {
		dm_start = std::chrono::steady_clock::now();
	}

	void Timekeeper::stop() {
		dm_stop = std::chrono::steady_clock::now();
	}

	void Timekeeper::recordEvent(const char* descrEvent) {
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dm_stop - dm_start);
		if (ixArr < noObjs) {
			this->record[ixArr].dm_msg = descrEvent;
			this->record[ixArr].dm_unitsOfTime = " seconds";
			this->record[ixArr].dm_duration = ms;
			ixArr++;
		}
	}

	void Timekeeper::report(std::ostream& os) const {
		os << "\nExecution Times:\n";
		for (int i = 0; i < ixArr; i++) {
			os << record[i].dm_msg << ' ' 
				<< record[i].dm_duration.count() / 1000000 
				<< record[i].dm_unitsOfTime << endl;
		}
	}
}