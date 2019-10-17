// Workshop 2 - Copy and Move Semantics
// Timekeeper.h
// Anmol Singh Sandhu
// 2019/01/21
#ifndef _OOP345_TIMEKEEPER_H_
#define _OOP345_TIMEKEEPER_H_
#include<iostream>
#include <chrono>

namespace sict {
	const int noObjs = 10;

	class Timekeeper {
	private:
		int ixArr { 0 };
		std::chrono::steady_clock::time_point dm_start;
		std::chrono::steady_clock::time_point dm_stop;
		struct {
			const char* dm_msg;
			const char* dm_unitsOfTime;
			std::chrono::steady_clock::duration dm_duration;
		} record[noObjs];

	public:
		Timekeeper();
		void start();
		void stop();
		void recordEvent(const char* descrEvent);
		void report(std::ostream& os) const;
	};
}

#endif