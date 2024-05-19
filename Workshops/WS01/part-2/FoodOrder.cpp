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

#include <iostream>
#include <cstring>
#include "FoodOrder.h"
using namespace std;

double g_taxrate = 0.0;
double g_dailydiscount = 0.0;

namespace seneca {
    FoodOrder::FoodOrder() : m_name{}, m_Desc{}, m_Price{}, m_dailySpecial{false}
    {}
    // Copy constructor
    FoodOrder::FoodOrder(const FoodOrder& other)
    {
        strcpy(m_name, other.m_name);
        if (other.m_Desc) {
            m_Desc = new char[strlen(other.m_Desc) + 1];
            strcpy(m_Desc, other.m_Desc);
        }
        m_Price = other.m_Price;
        m_dailySpecial = other.m_dailySpecial;
    }
    // Copy assignment
    FoodOrder& FoodOrder::operator=(const FoodOrder& other)
    {
        if (this != &other) {
            delete[] m_Desc; // Deleting any previously allocated memory
            strcpy(m_name, other.m_name);
            if (other.m_Desc) {
                m_Desc = new char[strlen(other.m_Desc) + 1];
                strcpy(m_Desc, other.m_Desc);
            }
            else {
                m_Desc = nullptr;
            }
            m_Price = other.m_Price;
            m_dailySpecial = other.m_dailySpecial;
        }
        return *this;
    }

    std::istream& FoodOrder::read(std::istream& istr)
    {
        if (istr.good()) {
            istr.getline(m_name, SIZE, ',');

            char temp[100]{};
            delete[] m_Desc;
            m_Desc = nullptr;
            if (istr.getline(temp, 100, ',')) {
                m_Desc = new char[strlen(temp) + 1];
                strcpy(m_Desc, temp);
            }
            istr >> m_Price;
            istr.ignore();
            char special{};
            istr >> special;
            m_dailySpecial = (special == 'Y');
            istr.ignore(1000, '\n');
        }
        return istr;
    }

    std::ostream& FoodOrder::display(ostream& os) const
    {
        static int count = 1;
        double billAmt = m_Price * g_taxrate + m_Price;
        if (m_name[0]) {
            std::cout.width(2);
            std::cout.setf(ios::left);
            std::cout << count++ << ". ";
            std::cout.width(10);
            std::cout << m_name << "|";
            std::cout.width(25);
            std::cout << (m_Desc ? m_Desc : "No Description") << "|";
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
            std::cout << "No Order" << std::endl;
        }
        return os;
    }
    // Destructor
    FoodOrder::~FoodOrder()
    {
        delete[] m_Desc;
        m_Desc = nullptr;
    }
}
