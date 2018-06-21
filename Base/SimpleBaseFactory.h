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

#ifndef SIMPLEBASEFACTORY_H
#define SIMPLEBASEFACTORY_H

#include "../Interfaces/IBase16.h"
#include "../Interfaces/IBase32.h"
#include "../Interfaces/IBase32Alphabet.h"
#include "../Interfaces/IBase58.h"
#include "../Interfaces/IBase58Alphabet.h"
#include "../Interfaces/IBase64.h"
#include "../Interfaces/IBase64Alphabet.h"

class SimpleBaseFactory
{
public:
	// ================== Base16 =================
	static IBase16 CreateBase16();

	// ================== Base32 =================
	static IBase32 CreateBase32(const IBase32Alphabet alphabet);

	static IBase32 CreateBase32Crockford();

	static IBase32 CreateBase32Rfc4648();

	static IBase32 CreateBase32ExtendedHex();

	// ================== Base58 =================
	static IBase58 CreateBase58(const IBase58Alphabet alphabet);

	static IBase58 CreateBase58BitCoin();

	static IBase58 CreateBase58Flickr();

	static IBase58 CreateBase58Ripple();

	// ================== Base64 =================
	static IBase64 CreateBase64(const IBase64Alphabet alphabet);

	static IBase64 CreateBase64Default();

	static IBase64 CreateBase64DefaultNoPadding();

	static IBase64 CreateBase64FileEncoding();

	static IBase64 CreateBase64RegExEncoding();

	static IBase64 CreateBase64UrlEncoding();

	static IBase64 CreateBase64XmlEncoding();

private:
	SimpleBaseFactory() {};

	static void Boot();

	static bool isBoot;

}; // end class SimpleBaseFactory

#endif //!SIMPLEBASEFACTORY_H
