// Assembly Line Project
// CustomerOrder.h
//  Anmol Singh Sandhu
// 2019/03/17
#ifndef _345_CUSTOMER_ORDER_H_
#define _345_CUSTOMER_ORDER_H_
#include <iostream>
#include <string>
#include <vector>
#include "ItemSet.h"
using namespace std;

namespace sict {

	class CustomerOrder {
		std::string dm_cust_name = "";
		std::string dm_prod_assembled = "";
		int countItem = 0;

		struct ItemInfo
		{
			std::string it_name;
			int it_serial_number;
			bool it_filled_status;
		} info;

		ItemInfo* ptrItemInfo = nullptr;

	public:
		CustomerOrder();								// Default Constructor
		CustomerOrder(std::string);						// One-argument Constructor
		~CustomerOrder();								// Destructor
		void fillItem(ItemSet& item, std::ostream& os);
		bool isFilled() const;
		bool isItemFilled(const std::string& item) const;
		std::string getNameProduct() const;
		void display(std::ostream& os, bool showDetail = false) const;
		CustomerOrder(CustomerOrder &&) noexcept;
		CustomerOrder & operator=(CustomerOrder &&) noexcept;
		CustomerOrder(const CustomerOrder &) = delete;
		CustomerOrder & operator=(const CustomerOrder &) = delete;
	};
}
#endif