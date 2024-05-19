

#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H

	extern double g_taxrate;
	extern double g_dailydiscount;
namespace seneca {
	const int SIZE = 10;
	class FoodOrder
	{
		char m_name[SIZE]{};
		char* m_Description{};
		double m_Price{};
		bool m_Special{};
	public:
		FoodOrder();
		// 1 - Copy Constructor
		FoodOrder(const FoodOrder& other);
		// 2 - Copy Assignement
		FoodOrder& operator=(const FoodOrder& other);
		// Read and Write
		std::istream& read(std::istream& istr = std::cin);
		std::ostream& display(std::ostream& ostr = std::cout)const;
		// 3 - Destructor
		virtual ~FoodOrder();
	};
}
#endif
