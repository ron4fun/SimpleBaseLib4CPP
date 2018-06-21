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

#include "stdafx.h"
#include "Base64Alphabet.h"

IBase64Alphabet Base64Alphabet::Default = nullptr;
IBase64Alphabet Base64Alphabet::DefaultNoPadding = nullptr;
IBase64Alphabet Base64Alphabet::UrlEncoding = nullptr;
IBase64Alphabet Base64Alphabet::XmlEncoding = nullptr;
IBase64Alphabet Base64Alphabet::RegExEncoding = nullptr;
IBase64Alphabet Base64Alphabet::FileEncoding = nullptr;
const char * Base64Alphabet::B64CharacterSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

Base64Alphabet::Base64Alphabet(const string &chars, const char plusChar, const char slashChar, const bool _PaddingEnabled)
{
	int32_t idx, LowPoint, HighPoint;
	string newChars;
	
	newChars = chars + plusChar + slashChar;
	EncodingTable.resize(newChars.size());
	
	LowPoint = 0;
	HighPoint = newChars.size();

	for (idx = LowPoint; idx < HighPoint; idx++)
		EncodingTable[idx] = newChars[idx];

	PaddingEnabled = _PaddingEnabled;
	CreateDecodingTable(EncodingTable);
}

void Base64Alphabet::CreateDecodingTable(const SimpleBaseLibCharArray &chars)
{
	SimpleBaseLibByteArray bytes;
	
	bytes.resize(123);
	for (register size_t idx = 0; idx < chars.size(); idx++)
		bytes[uint8_t(chars[idx])] = uint8_t(idx);

	DecodingTable = bytes;
}

void Base64Alphabet::Boot()
{
	Default = make_shared<Base64Alphabet>(B64CharacterSet, '+', '/', true);
	DefaultNoPadding = make_shared<Base64Alphabet>(B64CharacterSet, '+', '/', false);
	UrlEncoding = make_shared<Base64Alphabet>(B64CharacterSet, '-', '_', false);
	XmlEncoding = make_shared<Base64Alphabet>(B64CharacterSet, '_', ':', false);
	RegExEncoding = make_shared<Base64Alphabet>(B64CharacterSet, '!', '-', false);
	FileEncoding = make_shared<Base64Alphabet>(B64CharacterSet, '+', '-', false);
}
