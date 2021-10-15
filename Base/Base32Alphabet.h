// ///////////////////////////////////////////////////////////////// //
// *C++ 11 SimpleBaseLib4CPP Library                                 
// *Copyright(c) 2021  Mbadiwe Nnaemeka Ronald                 
// *Github Repository <https://github.com/ron4fun>             

// *Distributed under the MIT software license, see the accompanying file LICENSE 
// *or visit http ://www.opensource.org/licenses/mit-license.php.           

// *Acknowledgements:                                  
// ** //
// *Thanks to Ugochukwu Mmaduekwe (https://github.com/Xor-el) for his creative        
// *development of this library in Pascal/Delphi                         

// ////////////////////////////////////////////////////// ///////////////

#pragma once

#ifndef BASE32ALPHABET_H
#define BASE32ALPHABET_H

#include "../Interfaces/IBase32Alphabet.h"

class Base32Alphabet : public IIBase32Alphabet
{
public:
	Base32Alphabet(const string &chars);

	inline virtual SimpleBaseLibCharArray GetEncodingTable() const
	{
		return EncodingTable;
	}

	inline virtual SimpleBaseLibByteArray GetDecodingTable() const
	{
		return DecodingTable;
	}

	static inline IBase32Alphabet GetCrockford()
	{
		return Crockford;
	}

	static inline IBase32Alphabet GetRfc4648()
	{
		return Rfc4648;
	}

	static inline IBase32Alphabet GetExtendedHex()
	{
		return ExtendedHex;
	}

	static void Boot();

protected:
	SimpleBaseLibByteArray DecodingTable;

	static inline char LowCase(const char ch);

private:
	inline void CreateDecodingTable(const string &chars);

private:
	SimpleBaseLibCharArray EncodingTable;

	static const char HighestAsciiCharSupported = 'z';

	static IBase32Alphabet Crockford, Rfc4648, ExtendedHex;

};

#endif // !BASE32ALPHABET_H

