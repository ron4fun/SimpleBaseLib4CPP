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

#ifndef IBASE16_H
#define IBASE16_H

#include "../Utils/SimpleBaseLibTypes.h"

class IIBase16
{
public:
	/// <summary>
	/// Encode to Base16 representation using uppercase lettering
	/// </summary>
	/// <param name="bytes">Bytes to encode</param>
	/// <returns>Base16 string</returns>
	virtual string EncodeUpper(const SimpleBaseLibByteArray &bytes) const = 0;

	/// <summary>
	/// Encode to Base16 representation using lowercase lettering
	/// </summary>
	/// <param name="bytes">Bytes to encode</param>
	/// <returns>Base16 string</returns>
	virtual string EncodeLower(const SimpleBaseLibByteArray &bytes) const = 0;

	virtual SimpleBaseLibByteArray Decode(const string &text) const = 0;

}; // end class IIBase16

typedef shared_ptr<IIBase16> IBase16;

#endif // !IBASE16_H
