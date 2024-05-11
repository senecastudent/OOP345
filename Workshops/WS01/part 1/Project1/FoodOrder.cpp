#include <iostream>
#include "FoodOrder.h"
using namespace std;
namespace seneca {
	FoodOrder::FoodOrder() : m_name{}, m_foodDesc{}, m_foodPrice{}, m_dailySpecial{} 
	{}
	std::istream& FoodOrder::read(std::istream & istr)
	{
		
	}
}