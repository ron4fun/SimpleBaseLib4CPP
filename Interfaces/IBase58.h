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

#ifndef IBASE58_H
#define IBASE58_H

#include "../Utils/SimpleBaseLibTypes.h"

class IIBase58
{
public:
	/// <summary>
	/// Encode to Base58 representation
	/// </summary>
	/// <param name="bytes">Bytes to encode</param>
	/// <returns>Encoded string</returns>
	virtual string Encode(const SimpleBaseLibByteArray &bytes) const = 0;

	/// <summary>
	/// Decode a Base58 representation
	/// </summary>
	/// <param name="text">Base58 encoded text</param>
	/// <returns>Array of decoded bytes</returns>
	virtual SimpleBaseLibByteArray Decode(const string &text) const = 0;

}; // end class IIBase58

typedef shared_ptr<IIBase58> IBase58;

#endif // !IBASE58_H
