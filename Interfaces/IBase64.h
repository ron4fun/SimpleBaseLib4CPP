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

#ifndef IBASE64_H
#define IBASE64_H

#include "../Utils/SimpleBaseLibTypes.h"

class IIBase64
{
public:
	/// <summary>
	/// Encode a byte array into a Base64 string
	/// </summary>
	/// <param name="bytes">Buffer to be encoded</param>
	/// <returns>Encoded string</returns>
	virtual string Encode(const SimpleBaseLibByteArray &bytes) const = 0;

	/// <summary>
	/// Decode a Base64 encoded string into a byte array.
	/// </summary>
	/// <param name="text">Encoded Base64 string</param>
	/// <returns>Decoded byte array</returns>
	virtual SimpleBaseLibByteArray Decode(const string &text) const = 0;

}; // end class IIBase64

typedef shared_ptr<IIBase64> IBase64;

#endif // !IBASE64_H
