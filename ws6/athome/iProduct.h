#pragma once
// Workshop 6 - STL Containers
// iProduct.h
// Anmol Singh Sandhu
// 2019/03/04
#ifndef _345_IPRODUCT_H_
#define _345_IPRODUCT_H_
#include <iostream>
using namespace std;

namespace sict {

	class iProduct {

	public:
		virtual double price() const = 0;
		virtual void display(std::ostream& os) const = 0 ;
	};

	std::ostream& operator<<(std::ostream& os, const iProduct& p);
	iProduct* readRecord(std::ifstream& file);


}

#endif

