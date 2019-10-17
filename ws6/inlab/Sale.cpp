// Workshop 6 - STL Containers
// Sale.cpp
// Anmol Singh Sandhu
// 2019/03/04
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include "Sale.h"

extern int FW;
const char REC_DELIMITER = '\n';

namespace sict {
	Sale::Sale(const char* fileName) {
		std::ifstream ifile(fileName);
		if (!ifile) {
			throw "***   Fail to open Sale file   ***";
		}

		iProduct* p;
		while (ifile) {
			p = readRecord(ifile);
			if (ifile) {
				products.push_back(p);
			}
		}
	}

	void Sale::display(std::ostream& os) const {
		double total = 0;

		os << std::setw(FW) << endl << "Product No" << std::setw(FW) << "Cost" << std::endl;

		for (auto i : products) {
			i->display(os);
			total += i->price();
		}

		os << std::setw(FW) << "Total" << std::fixed << std::setprecision(2) << std::setw(FW) << total << std::endl;
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& p) {
		p.display(os);
		return os;
	}
}
