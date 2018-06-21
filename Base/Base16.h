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

#pragma once

#ifndef BASE16_H
#define BASE16_H

#include "../Interfaces/IBase16.h"
#include "../Utils/Bits.h"
#include "../Utils/PointerUtils.h"
#include "../Utils/SimpleBaseLibTypes.h"

/// <summary>
/// Hexadecimal encoding/decoding
/// </summary>
class Base16 : public virtual IIBase16
{
private:
	static const uint8_t numberOffset = 48;
	static const uint8_t upperNumberDiff = 7;
	static const uint8_t lowerUpperDiff = 32;

	static const char * lowerAlphabet;
	static const char * upperAlphabet;

	static inline void ValidateHex(const char c);

	static inline int32_t GetHexByte(const int32_t character);

	static string Encode(const SimpleBaseLibByteArray &bytes, const string &alphabet);

public:
	/// <summary>
	/// Encode to Base16 representation using uppercase lettering
	/// </summary>
	/// <param name="bytes">Bytes to encode</param>
	/// <returns>Base16 string</returns>
	virtual string EncodeUpper(const SimpleBaseLibByteArray &bytes) const;

	/// <summary>
	/// Encode to Base16 representation using lowercase lettering
	/// </summary>
	/// <param name="bytes">Bytes to encode</param>
	/// <returns>Base16 string</returns>
	virtual string EncodeLower(const SimpleBaseLibByteArray &bytes) const;

	virtual SimpleBaseLibByteArray Decode(const string &text) const;

private:
	static const char * InvalidHexCharacter;
	static const char * InvalidTextLength;

};

#endif // !BASE16_H

