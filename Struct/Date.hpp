#include "Shuzaei.hpp"

ll day(ll year, ll month) {
    ll d[] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2)
        return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0) ? 29 : 28;
    return d[month - 1];
}