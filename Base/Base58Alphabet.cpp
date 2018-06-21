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

#include "Base58Alphabet.h"

IBase58Alphabet Base58Alphabet::BitCoin = nullptr;
IBase58Alphabet Base58Alphabet::Ripple = nullptr;
IBase58Alphabet Base58Alphabet::Flickr = nullptr;
const char * Base58Alphabet::EmptyAlphabet = "Base58 alphabets cannot be empty \"%s\"";
const char * Base58Alphabet::InvalidAlphabetLength = "Base58 alphabets need to be 58-characters long \"%s\"";
const char * Base58Alphabet::InvalidCharacter = "Invalid character \"%s\"";


Base58Alphabet::Base58Alphabet(const string &text)
{
	int32_t idx, LowPoint, HighPoint;
	
	if (text.size() == 0) 
		throw ArgumentNullSimpleBaseLibException(EmptyAlphabet);
	
	if (text.size() != length) 
		throw InvalidArgumentSimpleBaseLibException(InvalidAlphabetLength);
	
	value = text;
	LowPoint = 0;
	HighPoint = text.size();
	
	for (idx = LowPoint; idx < HighPoint; idx++)
	{
		reverseLookupTable[text[idx]] =  idx;
	}
}

int32_t Base58Alphabet::GetSelf(const char c) const
{
	try {
		return reverseLookupTable.at(c);
	}
	catch (const exception &e)
	{
		//pass
	}

	throw InvalidOperationSimpleBaseLibException(InvalidCharacter);
}

void Base58Alphabet::Boot()
{
	BitCoin = make_shared<Base58Alphabet>("123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz");
	Ripple = make_shared<Base58Alphabet>("rpshnaf39wBUDNEGHJKLM4PQRST7VWXYZ2bcdeCg65jkm8oFqi1tuvAxyz");
	Flickr = make_shared<Base58Alphabet>("123456789abcdefghijkmnopqrstuvwxyzABCDEFGHJKLMNPQRSTUVWXYZ");
}

