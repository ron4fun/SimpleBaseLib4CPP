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

#ifndef POINTERUTILS_H
#define POINTERUTILS_H

#include "SimpleBaseLibTypes.h"

using namespace std;

class PointerUtils
{
public:
	static inline uint8_t * Offset(uint8_t * ptr, int32_t length)
	{
		uint8_t * result = ptr + length;
		if ((length < 0) || (result < ptr)) 
			throw InvalidOperationSimpleBaseLibException(BufferOverFlow);

		return result;
	}

	static inline char * Offset(char * ptr, int32_t length)
	{
		char * result = ptr + length;
		if ((length < 0) || (result < ptr)) 
			throw InvalidOperationSimpleBaseLibException(BufferOverFlow);

		return result;
	}

private:
	static const char * BufferOverFlow;

};

#endif // !POINTERUTILS_H
