#pragma once
// Workshop 6 - STL Containers
// Product.h
// Anmol Singh Sandhu
// 2019/03/04
#ifndef _345_PRODUCT_H_
#define _345_PRODUCT_H_
#include <array>
#include "iProduct.h"

namespace sict {

	class Product : public iProduct { 
		int dm_productNo;
		double dm_price;

	public:
		Product(int ProdNo, double price);
		double price() const;
		void display(std::ostream& os) const;

	};

	class TaxableProduct : public Product {
		enum listOfTaxes { HST, PST, numTax };
		std::array<double, numTax> tax { 0.13, 0.08 };
		char dm_type;

	public:
		TaxableProduct(int ProdNo, double price, char tax);
		double price() const;
		void display(std::ostream& os) const;
	};
}
#endif

