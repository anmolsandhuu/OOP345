// Workshop 3 - Templates
// List.h
// Anmol Singh Sandhu
// 2019/01/29
#ifndef _OOP345_LIST_H_
#define _OOP345_LIST_H_

namespace sict {
	template <typename T, int Q>
	class List {
		T dm_type[Q];
		int dm_max_array = Q;
		size_t dm_ix_array  { 0u };		//number of elements stored in the array

	public:
//      query that returns the number of elements stored in the array
		size_t size() const {
			return dm_ix_array;
		}
		
//               OVERLOAD OPERATOR []
		const T& operator[](size_t i) const {
			return dm_type[i];
		}
//
//               OVERLOAD OPERATOR +=
		void operator+=(const T& t) {
			if (dm_ix_array < Q) {
				dm_type[dm_ix_array] = t;
				dm_ix_array++;
			}
		}

	};
}

#endif