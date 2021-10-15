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

#ifndef IBASE32_H
#define IBASE32_H

#include "../Utils/SimpleBaseLibTypes.h"

class IIBase32
{
public:
	/// <summary>
	/// Encode a byte array into a Base32 string
	/// </summary>
	/// <param name="bytes">Buffer to be encoded</param>
	/// <param name="padding">Append padding characters in the output</param>
	/// <returns>Encoded string</returns>
	virtual string Encode(const SimpleBaseLibByteArray &bytes, const bool padding) const = 0;

	/// <summary>
	/// Decode a Base32 encoded string into a byte array.
	/// </summary>
	/// <param name="text">Encoded Base32 string</param>
	/// <returns>Decoded byte array</returns>
	virtual SimpleBaseLibByteArray Decode(const string &text) const = 0;

}; // end class IIBase32

typedef shared_ptr<IIBase32> IBase32;

#endif // !IBASE32_H
