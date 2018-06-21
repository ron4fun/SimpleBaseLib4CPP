// ///////////////////////////////////////////////////////////////// //
// *C++ 11 HashFactory Library                                 
// *Copyright(c) 2018  Mbadiwe Nnaemeka Ronald                 
// *Github Repository <https://github.com/ron4fun>             

// *Distributed under the MIT software license, see the accompanying file LICENSE 
// *or visit http ://www.opensource.org/licenses/mit-license.php.           

// *Acknowledgements:                                  
// ** //
// *Thanks to Ugochukwu Mmaduekwe (https://github.com/Xor-el) for his creative        
// *development of this library in Pascal/Delphi                         

// ////////////////////////////////////////////////////// ///////////////

#pragma once

#ifndef UTILITIES_H
#define UTILITIES_H

#include <sstream>
#include <iomanip>
#include "SimpleBaseLibTypes.h"

using namespace std;


class Utilities
{
public:
	static inline string TrimRight(const string &S, const SimpleBaseLibCharArray &trimchars)
	{
		size_t len = S.size();
		int64_t i = len - 1;
		
		while (i >= 0 && HaveChar(S[i], trimchars))
		{
			i--;
		}

		if (i < 0) return "";
		else if (i == len) return S;
		
		return S.substr(0, i + 1);
	}
	
	static inline string toUpper(const string &s)
	{
		string result;
		result.resize(s.size());
		for (register uint32_t i = 0; i < s.size(); i++)
			result[i] = toupper(s[i]);

		return result;
	}

	static inline string toLower(const string &s)
	{
		string result;
		result.resize(s.size());
		for (register uint32_t i = 0; i < s.size(); i++)
			result[i] = tolower(s[i]);

		return result;
	}

	static inline string convertByteArrayToHexString(const SimpleBaseLibByteArray &arr, const bool upperCase = true)
	{
		string result;
		stringstream stream;
		int temp;
		for (register uint32_t i = 0; i < arr.size(); i++)
		{
			temp = arr[i];
			stream << setfill('0') << setw(2) << hex << temp;
		}

		return upperCase ? toUpper(stream.str()) : toLower(stream.str());
	}

	static inline string convertByteArrayToASCIIString(const SimpleBaseLibByteArray &arr, const bool upperCase = true)
	{
		string result(arr.begin(), arr.end());
		return upperCase ? toUpper(result) : toLower(result);
	}

	static inline SimpleBaseLibByteArray convertASCIIStringToByteArray(const string &s)
	{
		SimpleBaseLibByteArray result(s.begin(), s.end());
		return result;
	}

private:
	static inline bool HaveChar(const char c, const SimpleBaseLibCharArray &list)
	{
		register size_t i = 0;
		bool result = false;
		while (!result && (i < list.size()))
		{
			result = list[i] == c;
			i++;
		}

		return result;
	}

};

#endif // !UTILITIES_H
