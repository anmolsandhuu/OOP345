// Workshop 7 - STL Algorithms
// DataTable.h
// Anmol Singh Sandhu
// 2019/03/11
#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <numeric>
#include <math.h>
//#include <fstream>
using namespace std;
extern int FW; // field width
extern int ND; // precision for numbers

namespace sict {


	template<class T>

	class DataTable {
		std::vector<T> vx, vy;

	public:
		DataTable(std::ifstream& ifile) {
			T x, y;

			while (ifile) {
				ifile >> x >> y;
				vx.push_back(x);
				vy.push_back(y);
			}
			vx.pop_back();
			vy.pop_back();
		}

		void displayData(std::ostream& os) const {
			os << "Data Values" << endl;
			os << "------------" << endl;
			os << setw(FW) << "x" << setw(FW) << "y" << endl;
			os << setprecision(ND) << fixed;

			for (size_t i = 0; i < vx.size(); i++) {
				os << setw(FW) << vx[i] << setw(FW) << vy[i] << endl;
			}
		}

		void displayStatistics(std::ostream& os) const {
// mean = average of all values
			T accum = accumulate(vy.begin(), vy.end(), (T)0);
			size_t num = vy.size();
			T mean = accum / num;
			
			os << endl << "Statistics" << endl << "----------" << endl;
			os << setw(FW) << "  y mean    = ";
			os << setprecision(ND) << fixed << setw(FW) << mean << endl;

// sigma = standard deviation
			T accum2 = 0, sigma = 0;
			for (size_t i = 0; i < vy.size(); i++) {
				accum2 += (vy[i] - mean) * (vy[i] - mean);
			}			

			sigma = std::sqrt(accum2 / (vy.size() - 1));
			
			os << setw(FW) << "  y sigma   = ";
			os << setprecision(ND) << fixed << setw(FW) << sigma << endl;
			}
	};
}

#endif

