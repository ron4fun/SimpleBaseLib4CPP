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

#ifndef IBASE32ALPHABET_H
#define IBASE32ALPHABET_H

#include "../Utils/SimpleBaseLibTypes.h"

class IIBase32Alphabet
{
public:
	virtual SimpleBaseLibCharArray GetEncodingTable() const = 0;
	virtual SimpleBaseLibByteArray GetDecodingTable() const  = 0;
	
}; // end class IIBase32Alphabet

typedef shared_ptr<IIBase32Alphabet> IBase32Alphabet;

#endif // !IBASE32ALPHABET_H
