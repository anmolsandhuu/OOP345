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
using namespace std;
extern int FW; // field width
extern int ND; // precision for numbers

namespace sict {

	template<class T>

	class DataTable {
		std::vector<T> vx, vy;
		T mean = 0, sigma = 0, median = 0, slope = 0, intercept = 0, sumx = 0, sumy = 0, accum = 0;

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

			sumy = accumulate(vy.begin(), vy.end(), (T)0);
			sumx = accumulate(vx.begin(), vx.end(), (T)0);

			// mean = average of all values
			mean = sumy / vy.size();

			// sigma = standard deviation
			for (size_t i = 0; i < vy.size(); i++) {
				accum += (vy[i] - mean) * (vy[i] - mean);
			}
			sigma = std::sqrt(accum / (vy.size() - 1));

			// median = the middle number in the sorted set of the values
			vector<T> vaux = vy;
			std::sort(vaux.begin(), vaux.end(), [](T a, T b) { return a < b; });
			median = vaux[vaux.size() / 2];

			// slope = the slope of the line in the x-y plane
			accum = std::inner_product(vx.begin(), vx.end(), vy.begin(), (T)0);							// sum(vx[i] * vy[i])
			T accum2 = accumulate(vx.begin(), vx.end(), (T)0, [](T   x, T   y) { return x + y * y; });	// sum(vx[i]**2)
			slope = (vx.size() * accum - sumx * sumy) / (vx.size() * accum2 - sumx * sumx);

			// intercept = � the y value of the line where it crosses the y-axis in the x-y plane
			intercept = (sumy - slope * sumx) / vx.size();
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
			os << endl << "Statistics" << endl << "----------" << endl;
			
			os << setw(FW) << "  y mean    = ";
			os << setprecision(ND) << fixed << setw(FW) << mean << endl;
			
			os << setw(FW) << "  y sigma   = ";
			os << setprecision(ND) << fixed << setw(FW) << sigma << endl;

			os << setw(FW) << "  y median  = ";
			os << setprecision(ND) << fixed << setw(FW) << median << endl;

			os << setw(FW) << "  slope     = ";
			os << setprecision(ND) << fixed << setw(FW) << slope << endl;

			os << setw(FW) << "  intercept = ";
			os << setprecision(ND) << fixed << setw(FW) << intercept << endl;

			}
	};
}

#endif
