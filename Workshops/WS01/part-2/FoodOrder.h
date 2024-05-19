/*/////////////////////////////////////////////////////////////////////////
						Workshop-1 Part-2
Full Name  : Keshav Bathla
Student ID#: 106268238
Email      : kbathla@myseneca.ca
Section    : ZAA
Date       : 19/05/2024

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
	const int SIZE = 10;
	class FoodOrder
	{
		char m_name[SIZE]{};
		char* m_Desc{};
		double m_Price{};
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
