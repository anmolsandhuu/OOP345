// Workshop 6 - STL Containers
// iProduct.cpp
// Anmol Singh Sandhu
// 2019/03/04
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Product.h"
using namespace std;
extern int FW;

namespace sict {
	Product::Product(int ProdNo, double price) {
		dm_productNo = ProdNo;
		dm_price = price;
	}

	double Product::price() const {
		return dm_price;
	}

	void Product::display(std::ostream& os) const {
		os << std::setw(FW) << dm_productNo << std::setw(FW) << std::fixed << std::setprecision(2) << dm_price << std::endl;
	}

	iProduct* readRecord(std::ifstream& file) {
		iProduct* iprod = nullptr;
		int productNo;
		double price;

		file >> productNo >> price;
		Product* prod = new Product(productNo, price);
		iprod = prod;

		return iprod;

	}


}
