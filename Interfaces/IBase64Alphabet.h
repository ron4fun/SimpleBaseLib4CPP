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

#ifndef IBASE64ALPHABET_H
#define IBASE64ALPHABET_H

#include "../Utils/SimpleBaseLibTypes.h"

class IIBase64Alphabet
{
public:
	virtual SimpleBaseLibCharArray GetEncodingTable() const = 0;
	virtual SimpleBaseLibByteArray GetDecodingTable() const = 0;
	virtual bool GetPaddingEnabled() const = 0;

}; // end class IIBase64Alphabet

typedef shared_ptr<IIBase64Alphabet> IBase64Alphabet;

#endif // !IBASE64ALPHABET_H
