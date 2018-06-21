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

#ifndef SIMPLEBASELIBTYPES_H
#define SIMPLEBASELIBTYPES_H

#include <memory>
#include <utility>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

class SimpleBaseLibException //: public runtime_error
{
public:
	SimpleBaseLibException(const char * text)
		: msg_(text)
	{
		// empty
	}  // end constructor

	const char* what() const throw ()
	{
		return msg_.c_str();
	} // end function what

private:
	string msg_;

}; // end class SimpleBaseLibException

class InvalidArgumentSimpleBaseLibException : public SimpleBaseLibException
{
public:
	InvalidArgumentSimpleBaseLibException(const char * text)
		: SimpleBaseLibException(text)
	{}
}; // end class InvalidArgumentSimpleBaseLibException

class ArgumentNullSimpleBaseLibException : public SimpleBaseLibException
{
public:
	ArgumentNullSimpleBaseLibException(const char * text)
		: SimpleBaseLibException(text)
	{}
}; // end class ArgumentNullSimpleBaseLibException

class InvalidOperationSimpleBaseLibException : public SimpleBaseLibException
{
public:
	InvalidOperationSimpleBaseLibException(const char * text)
		: SimpleBaseLibException(text)
	{}
}; // end class InvalidOperationSimpleBaseLibException


/// <summary>
/// Represents a dynamic array of Byte.
/// </summary>
typedef vector<uint8_t> SimpleBaseLibByteArray;

/// <summary>
/// Represents a dynamic array of Char.
/// </summary>
typedef vector<char> SimpleBaseLibCharArray;

/// <summary>
/// Represents a dynamic array of String.
/// </summary>
typedef vector<string> SimpleBaseLibStringArray;

#endif // !SIMPLEBASELIBTYPES_H
