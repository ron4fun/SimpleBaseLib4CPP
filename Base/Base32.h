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

#ifndef BASE32_H
#define BASE32_H

#include "../Interfaces/IBase32.h"
#include "../Interfaces/IBase32Alphabet.h"

class Base32 : public IIBase32
{
public:
	Base32(const IBase32Alphabet alphabet);
	
	virtual string Encode(const SimpleBaseLibByteArray &bytes, const bool padding) const;

	virtual SimpleBaseLibByteArray Decode(const string &text) const;
	
private:
	static const int32_t bitsPerByte = 8;
	static const int32_t bitsPerChar = 5;
	static const char paddingChar = '=';
	
	static inline void InvalidInput(const char c)
	{
		throw InvalidArgumentSimpleBaseLibException(InvalidCharacter);
	}
	
	IBase32Alphabet alphabet = nullptr;

private:
	static const string AlphabetNull;
	static const string InvalidCharacter;

};

#endif // !BASE32_H

