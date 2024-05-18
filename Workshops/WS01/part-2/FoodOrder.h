#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H
#include <iostream>
	extern double g_taxrate;
	extern double g_dailydiscount;
namespace seneca {
	const int MAX_NAME_SIZE = 10;
	class FoodOrder
	{
		char m_name[MAX_NAME_SIZE]{};
		char* m_foodDesc{};
		double m_foodPrice{};
		bool m_dailySpecial{};
	public:
		FoodOrder();
		FoodOrder(const FoodOrder& other);
		FoodOrder& operator=(const FoodOrder& other);
		std::istream& read(std::istream& istr = std::cin);
		std::ostream& display(std::ostream& ostr = std::cout)const;
		virtual ~FoodOrder();
	};
}
#endif
