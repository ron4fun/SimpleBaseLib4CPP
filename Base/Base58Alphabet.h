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

#ifndef BASE358ALPHABET_H
#define BASE358ALPHABET_H

#include <map>
#include "../Interfaces/IBase58Alphabet.h"

using namespace std;

class Base58Alphabet : public IIBase58Alphabet
{
public:
	Base58Alphabet(const string &text);

	virtual inline string GetValue() const
	{
		return value;
	}

	virtual inline int32_t GetSelf(const char c) const;
	
	static IBase58Alphabet GetBitCoin()
	{
		return BitCoin;
	}

	static IBase58Alphabet GetFlickr()
	{
		return Flickr;
	}

	static IBase58Alphabet GetRipple()
	{
		return Ripple;
	}

	static void Boot();

private:
	static IBase58Alphabet BitCoin, Ripple, Flickr;

	static const string EmptyAlphabet;
	static const string InvalidAlphabetLength;
	static const string InvalidCharacter;

	static const int32_t length = 58;

	map<char, int32_t> reverseLookupTable;
	string value;

};

#endif // !BASE358ALPHABET_H

