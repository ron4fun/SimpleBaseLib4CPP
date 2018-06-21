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

#ifndef BASE58_H
#define BASE58_H

#include "../Interfaces/IBase58.h"
#include "../Interfaces/IBase58Alphabet.h"

class Base58 : public IIBase58
{
public:
	Base58(const IBase58Alphabet alphabet);

	virtual string Encode(const SimpleBaseLibByteArray &bytes) const;

	virtual SimpleBaseLibByteArray Decode(const string &text) const;
	
private:
	IBase58Alphabet alphabet = nullptr;

	static const char * AlphabetNull;

};

#endif // !BASE58_H

