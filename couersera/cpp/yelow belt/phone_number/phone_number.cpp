#include "phone_number.h"
#include <stdexcept>
#include <sstream>

using namespace std;

PhoneNumber::PhoneNumber(const string &number_phone)
{
    if (number_phone.empty())
    {
        throw invalid_argument("empty string");
    }
    if (number_phone.front() != '+')
    {
        throw invalid_argument("invalid number");
    }
    stringstream ss(number_phone);
    ss.ignore(1);
    getline(ss, country_code_, '-');
    getline(ss, city_code_, '-');
    getline(ss, local_number_);
    if (country_code_.empty() || city_code_.empty() || local_number_.empty())
    {
        throw invalid_argument("invalid number");
    }
}
string PhoneNumber::GetCountryCode() const
{
    return country_code_;
}
string PhoneNumber::GetCityCode() const
{
    return city_code_;
}
string PhoneNumber::GetLocalNumber() const
{
    return local_number_;
}
string PhoneNumber::GetInternationalNumber() const
{
    stringstream ss;
    ss << "+" << country_code_ << "-" << city_code_ << "-" << local_number_;
    return ss.str();
}
