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

#ifndef BASE64_H
#define BASE64_H

#include "../Interfaces/IBase64.h"
#include "../Interfaces/IBase64Alphabet.h"

class Base64 : public IIBase64
{
public:
	Base64(const IBase64Alphabet alphabet);
	
	virtual string Encode(const SimpleBaseLibByteArray &bytes) const;

	virtual SimpleBaseLibByteArray Decode(const string &text) const;
	
private:
	static inline uint8_t Process(char ** pInput, const uint8_t * decode_table);

private:
	static const char paddingChar = '=';
	
	IBase64Alphabet alphabet = nullptr;

	static const string AlphabetNull;

};

#endif // !BASE64_H

