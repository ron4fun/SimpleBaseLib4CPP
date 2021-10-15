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

#ifndef IBASE58ALPHABET_H
#define IBASE58ALPHABET_H

#include "../Utils/SimpleBaseLibTypes.h"

class IIBase58Alphabet
{
public:
	virtual string GetValue() const  = 0;
	virtual int32_t GetSelf(const char c) const = 0;

}; // end class IIBase58Alphabet

typedef shared_ptr<IIBase58Alphabet> IBase58Alphabet;

#endif // !IBASE58ALPHABET_H
