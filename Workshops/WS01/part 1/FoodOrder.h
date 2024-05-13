#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H
#include <iostream>
	extern double g_taxrate;
	extern double g_dailydiscount;
	extern int cout;
namespace seneca {
	const int MAX_NAME_SIZE = 10;
	const int MAX_DESC = 25;
	class FoodOrder
	{
		char m_name[MAX_NAME_SIZE]{};
		char m_foodDesc[MAX_DESC]{};
		double m_foodPrice{};
		bool m_dailySpecial{};
	public:
		FoodOrder();
		std::istream& read(std::istream& istr = std::cin);
		void display()const;
	};
}
#endif
