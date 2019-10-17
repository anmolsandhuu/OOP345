// Workshop 6 - STL Containers
// iProduct.cpp
// Anmol Singh Sandhu
// 2019/03/04
#include <iostream>
#include <iomanip>
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
		os << std::setw(FW) << dm_productNo << std::setw(FW) << std::fixed << std::setprecision(2) << dm_price;
		
	}

	TaxableProduct::TaxableProduct(int ProdNo, double price, char tax) : Product(ProdNo, price) {
		dm_type = tax;
	}

	double TaxableProduct::price() const {
		double pr;

		if (dm_type == 'H') {
			pr = Product::price() * tax[HST] + Product::price();
		}
		else {
			pr = Product::price() * tax[PST] + Product::price();
		}
		return pr;
	}

	void TaxableProduct::display(std::ostream& os) const {
		Product::display(os);
		os << (dm_type == 'H' ? " HST" : " PST");
	}

	iProduct* readRecord(std::ifstream& file) {
		iProduct* iprod = nullptr;
		int productNo;
		double price;
		char tax;

		file >> productNo >> price;
		tax = file.get();

		if (tax == '\n') {
			iprod = new Product(productNo, price);
		}
		else {
			file >> tax;
			iprod = new TaxableProduct(productNo, price, tax);
		}

		return iprod;

	}


	
}
