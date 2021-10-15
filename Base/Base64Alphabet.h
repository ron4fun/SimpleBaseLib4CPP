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

#ifndef BASE64ALPHABET_H
#define BASE64ALPHABET_H

#include "../Utils/SimpleBaseLibTypes.h"
#include "../Interfaces/IBase64Alphabet.h"

class Base64Alphabet : public IIBase64Alphabet
{
public:
	Base64Alphabet(const string &chars, const char plusChar, const char slashChar, const bool PaddingEnabled);

	static inline IBase64Alphabet GetDefault()
	{
		return Default;
	}

	static inline IBase64Alphabet GetDefaultNoPadding()
	{
		return DefaultNoPadding;
	}

	static inline IBase64Alphabet GetFileEncoding()
	{
		return FileEncoding;
	}

	static inline IBase64Alphabet GetRegExEncoding()
	{
		return RegExEncoding;
	}

	static inline IBase64Alphabet GetUrlEncoding()
	{
		return UrlEncoding;
	}

	static inline IBase64Alphabet GetXmlEncoding()
	{
		return XmlEncoding;
	}

	virtual inline bool GetPaddingEnabled() const
	{
		return PaddingEnabled;
	}

	virtual inline SimpleBaseLibCharArray GetEncodingTable() const
	{
		return EncodingTable;
	}

	virtual inline SimpleBaseLibByteArray GetDecodingTable() const
	{
		return DecodingTable;
	}

	static void Boot();

private:
	inline void CreateDecodingTable(const SimpleBaseLibCharArray &chars);

private:
	bool PaddingEnabled;
	SimpleBaseLibCharArray EncodingTable;
	SimpleBaseLibByteArray DecodingTable;

	static const string B64CharacterSet;

	static IBase64Alphabet Default, DefaultNoPadding, UrlEncoding, XmlEncoding, RegExEncoding, FileEncoding;

}; // end class Base64Alphabet

#endif // !BASE64ALPHABET_H
