/*/////////////////////////////////////////////////////////////////////////
						Workshop-1 Part-2
Full Name  : Divyanshu Dugar
Student ID#: 177110210
Email      : ddugar@myseneca.ca
Section    : ZAA
Date       : 17/05/2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

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
