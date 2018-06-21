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

#ifndef CROCKFORDBASE32ALPHABET_H
#define CROCKFORDBASE32ALPHABET_H

#include "Base32Alphabet.h"
#include "../Interfaces/ICrockfordBase32Alphabet.h"

class CrockfordBase32Alphabet : public Base32Alphabet, public IICrockfordBase32Alphabet
{
public:
	CrockfordBase32Alphabet()
		: Base32Alphabet("0123456789ABCDEFGHJKMNPQRSTVWXYZ")
	{
		map(DecodingTable, 'O', '0');
		map(DecodingTable, 'I', '1');
		map(DecodingTable, 'L', '1');
	}

private:
	static inline void map(SimpleBaseLibByteArray &buffer, const char source, char destination)
	{
		uint8_t result;
		
		result = buffer[destination];
		buffer[source] = result;
		buffer[LowCase(source)] = result;
	}

};

#endif // !CROCKFORDBASE32ALPHABET_H

