

#include <iostream>
#include <cstring>
#include "FoodOrder.h"
using namespace std;

double g_taxrate = 0.0;
double g_dailydiscount = 0.0;

namespace seneca {
    FoodOrder::FoodOrder() : m_name{}, m_Description{}, m_Price{}, m_Special{} {}

    FoodOrder::FoodOrder(const FoodOrder& other)
    {
        operator=(other);
    }

    FoodOrder& FoodOrder::operator=(const FoodOrder& other)
    {
        if (this != &other) {
            delete[] m_Description; 
            strcpy(m_name, other.m_name);
            if (other.m_Description) {
                m_Description = new char[strlen(other.m_Description) + 1];
                strcpy(m_Description, other.m_Description);
            }
            else {
                m_Description = nullptr;
            }
            m_Price = other.m_Price;
            m_Special = other.m_Special;
        }
        return *this;
    }

    std::istream& FoodOrder::read(std::istream& is)
    {
        if (!is.fail()) {
            is.getline(m_name, MAX_SIZE, ',');

            char temp[100]{};
            delete[] m_Description;
            m_Description = nullptr;
            is.getline(temp, 100, ',');
            m_Description = new char[strlen(temp) + 1];
            strcpy(m_Description, temp);
         
            is >> m_Price;
            is.ignore();
            char special{};
            is >> special;
            m_Special = (special == 'Y');
            is.ignore(1000, '\n');
        }
        return is;
    }

    std::ostream& FoodOrder::display(ostream& os) const
    {
        static int c = 1;
        if (m_name[0]) {
            std::cout.width(2);
            std::cout.setf(ios::left);
            std::cout << c++ << ". ";
            std::cout.width(10);
            std::cout << m_name;
            std::cout << "|";
            std::cout.width(25);
            std::cout << (m_Description ? m_Description : "No Description");
            std::cout << "|";
            std::cout.width(12);
            std::cout.precision(2);
            std::cout.setf(ios::fixed);
            std::cout << m_Price * g_taxrate + m_Price << "|";
            std::cout.unsetf(ios::left);
            if (m_Special) {
                std::cout.width(13);
                std::cout.setf(ios::right);
                std::cout << (m_Price * g_taxrate + m_Price) - g_dailydiscount;
                std::cout.unsetf(ios::right);
            }
            std::cout << std::endl;
        }
        else {
            std::cout.width(2);
            std::cout.setf(ios::left);
            std::cout << c++ << ". ";
            std::cout << "No Order" << std::endl;
        }
        return os;
    }
    
    FoodOrder::~FoodOrder()
    {
        delete[] m_Description;
        m_Description = nullptr;
    }
}
