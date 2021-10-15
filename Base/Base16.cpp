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

#include "Base16.h"

const string Base16::lowerAlphabet = "0123456789abcdef";
const string Base16::upperAlphabet = "0123456789ABCDEF";
const string Base16::InvalidHexCharacter = "Invalid hex character: ";
const string Base16::InvalidTextLength = "Text cannot be odd length";

void Base16::ValidateHex(const char c)
{
	if (!(((c >= '0') && (c <= '9')) || ((c >= 'A') && (c <= 'F')) ||
		((c >= 'a') && (c <= 'f'))))
		throw InvalidOperationSimpleBaseLibException(InvalidHexCharacter + c);
			
}

int32_t Base16::GetHexByte(const int32_t character)
{
	int32_t c;
	
	c = character - numberOffset;
	if (c < 10) // is number?
		return c;
	
	c = c - upperNumberDiff;
	if (c < 16) // is uppercase?
		return c;
	
	return c - lowerUpperDiff;
}

string Base16::Encode(const SimpleBaseLibByteArray &_bytes, const string &_alphabet)
{
	SimpleBaseLibByteArray bytes = _bytes;
	string alphabet = _alphabet;
	int32_t bytesLen, b;
	char * resultPtr, * alphabetPtr, * pResult, * pAlphabet;
	uint8_t * bytesPtr, * pInput, * pEnd;
	
	string result = "";
	bytesLen = bytes.size();
	if (bytesLen == 0) return result;

	result.resize(bytesLen * 2);
	for (register size_t i = 0; i < size_t(bytesLen * 2); i++)
		result[i] = char(0);

	resultPtr = &result[0];
	bytesPtr = &bytes[0];
	alphabetPtr = &alphabet[0];

	pResult = resultPtr;
	pAlphabet = alphabetPtr;
	pInput = bytesPtr;
	pEnd = PointerUtils::Offset(pInput, bytesLen);
	while (pInput != pEnd)
	{
		b = *pInput;
		*pResult = pAlphabet[Bits::Asr32(b, 4)];
		pResult++;
		*pResult = pAlphabet[b & 0x0F];
		pResult++;
		pInput++;
	}

	return result;
}

string Base16::EncodeUpper(const SimpleBaseLibByteArray &bytes) const
{
	return Encode(bytes, upperAlphabet);
}

string Base16::EncodeLower(const SimpleBaseLibByteArray &bytes) const
{
	return Encode(bytes, lowerAlphabet);
}

SimpleBaseLibByteArray Base16::Decode(const string &_text) const
{
	string text = _text;
	int32_t textLen, b1, b2;
	uint8_t * resultPtr, * pResult;
	char * textPtr, * pInput, * pEnd;
	char c1, c2;
	
	SimpleBaseLibByteArray result;
	textLen = text.size();
	if (textLen == 0) return result;

	if (textLen % 2 != 0) 
		throw InvalidArgumentSimpleBaseLibException(InvalidTextLength);
	
	result.resize(textLen / 2);
	resultPtr = &result[0];
	textPtr = &text[0];

	pResult = resultPtr;
	pInput = textPtr;
	pEnd = PointerUtils::Offset(pInput, textLen);
	while (pInput != pEnd)
	{
		c1 = *pInput;
		pInput++;
		ValidateHex(c1);
		b1 = GetHexByte(c1);
		c2 = *pInput;
		pInput++;
		ValidateHex(c2);
		b2 = GetHexByte(c2);
		*pResult = (uint8_t)(b1 << 4 | b2);
		pResult++;
	}

	return result;
}
