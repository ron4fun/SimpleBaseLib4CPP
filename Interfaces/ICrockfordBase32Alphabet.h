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

#ifndef ICROCKFORDBASE32ALPHABET_H
#define ICROCKFORDBASE32ALPHABET_H

#include "../Utils/SimpleBaseLibTypes.h"
#include "IBase32Alphabet.h"

class IICrockfordBase32Alphabet //: public virtual IIBase32Alphabet
{}; // end class IICrockfordBase32Alphabet

typedef shared_ptr<IICrockfordBase32Alphabet> ICrockfordBase32Alphabet;

#endif // !ICROCKFORDBASE32ALPHABET_H
