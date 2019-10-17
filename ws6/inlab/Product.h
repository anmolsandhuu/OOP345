#pragma once
// Workshop 6 - STL Containers
// iProduct.h
// Anmol Singh Sandhu
// 2019/03/04
#ifndef _345_PRODUCT_H_
#define _345_PRODUCT_H_
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
}

#endif

