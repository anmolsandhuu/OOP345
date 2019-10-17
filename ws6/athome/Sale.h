#pragma once
// Workshop 6 - STL Containers
// Sale.h
// Anmol Singh Sandhu
// 2019/03/04
#ifndef _345_SALE_H_
#define _345_SALE_H_
//#include "iProduct.h"
#include "Product.h"
#include <vector>

namespace sict {

	class Sale {
		std::vector<iProduct*> products;

	public:
		Sale(const char* fileName);
		void display(std::ostream& os) const;
	};
}

#endif

