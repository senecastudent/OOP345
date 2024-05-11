#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H
namespace seneca {
	const int MAX_NAME_SIZE = 10;
	const int MAX_DESC = 25;
	extern double g_taxrate, double g_dailydiscount;
	class FoodOrder
	{
		char m_name[MAX_NAME_SIZE]{};
		char m_foodDesc[MAX_DESC]{};
		double m_foodPrice{};
		bool m_dailySpecial{};
	public:
		FoodOrder();
		std::istream& read(std::istream& istr = cin);
	};
}
#endif;
