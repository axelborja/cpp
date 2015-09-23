/*
  File:        trim.cpp
  Description: C++ functions to easily trim std:string
  Author:      Axel BORJA
  mail:        axel.borja.pro@gmail.com
*/

#ifndef _TRIM_H_
#define _TRIM_H_

#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <string>


//
// Trim the given string from begin
//
inline std::string& ltrim(std::string& iStringToTrim)
{
    iStringToTrim.erase(iStringToTrim.begin(),
                        std::find_if(iStringToTrim.begin(),
                                     iStringToTrim.end(),
                                     std::not1(std::ptr_fun<int, int>(std::isspace))));
    return iStringToTrim;
}

//
// Trim the given string from end
//
inline std::string& rtrim(std::string& iStringToTrim)
{
    iStringToTrim.erase(std::find_if(iStringToTrim.rbegin(),
                                     iStringToTrim.rend(),
                                     std::not1(std::ptr_fun<int, int>(std::isspace))).base(),
                        iStringToTrim.end());
    return iStringToTrim;
}

//
// Trim the given string from begin and end
//
inline std::string& trim(std::string& iStringToTrim)
{
    return ltrim(rtrim(iStringToTrim));
}


#endif // _TRIM_H_
