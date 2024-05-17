#include <iostream>
#include <cstring>
#include "FoodOrder.h"
using namespace std;
	double g_taxrate = 0.0;
	double g_dailydiscount = 0.0;
namespace seneca {
	FoodOrder::FoodOrder() : m_name{}, m_foodDesc{}, m_foodPrice{}, m_dailySpecial{} 
	{}

	FoodOrder::FoodOrder(const FoodOrder & other)
	{
			strcpy(m_name, other.m_name);
			if (other.m_foodDesc) {
				m_foodDesc = new char[strlen(other.m_foodDesc) + 1];
				strcpy(m_foodDesc, other.m_foodDesc);
			}
			m_foodPrice = other.m_foodPrice;
			m_dailySpecial = other.m_dailySpecial;
	}

	FoodOrder& FoodOrder::operator=(const FoodOrder& other)
	{
		if (&other != this) {
			delete[] m_foodDesc;
			strcpy(m_name, other.m_name);
			m_foodDesc = new char[strlen(other.m_foodDesc) + 1];
			m_foodPrice = other.m_foodPrice;
			m_dailySpecial = other.m_dailySpecial;
		}
		return *this;
	}

	
	std::istream& FoodOrder::read(std::istream & istr)
	{
		if (istr.good()) {
			istr.getline(m_name, MAX_NAME_SIZE, ',');
			
			char temp[100]{};
			delete[] m_foodDesc;
			if (istr.getline(temp, 100, ',')) {
				m_foodDesc = new char[strlen(temp) + 1];
				strcpy(m_foodDesc, temp);
			}

			istr >> m_foodPrice;
			istr.ignore();

			char special{};
			istr >> special;
			m_dailySpecial = (special == 'Y');

			istr.ignore(1000,'\n');
		}
		return istr;
	}

	void FoodOrder::display() const
	{
		static int count = 1;
		double billAmt = m_foodPrice * g_taxrate + m_foodPrice;
		if (m_name[0]) {
			std::cout.width(2);
			std::cout.setf(ios::left);
			std::cout << count++ << ". ";
			std::cout.width(10);
			std::cout << m_name << "|";
			std::cout.width(25);
			std::cout << m_foodDesc << "|";
			std::cout.width(12);
			std::cout.precision(2);
			std::cout.setf(ios::fixed);
			std::cout << billAmt << "|";
			std::cout.unsetf(ios::left);
			if (m_dailySpecial) {
				std::cout.width(13);
				std::cout.setf(ios::right);
				std::cout << billAmt - g_dailydiscount;
				std::cout.unsetf(ios::right);
			}
			std::cout << std::endl;
		}
		else {
			std::cout.width(2);
			std::cout.setf(ios::left);
			std::cout << count++ << ". ";
			std::cout << "No Order" << endl;
		}
	}

	FoodOrder::~FoodOrder()
	{
		delete[] m_foodDesc;
		m_foodDesc = nullptr;
	}
}