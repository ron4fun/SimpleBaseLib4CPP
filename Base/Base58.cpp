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

#include "Base58.h"
#include "Base58Alphabet.h"
#include "../Utils/PointerUtils.h"

const char * Base58::AlphabetNull = "Alphabet Instance cannot be Null \"%s\"";

Base58::Base58(const IBase58Alphabet _alphabet)
{
	if (!_alphabet) 
		throw ArgumentNullSimpleBaseLibException(AlphabetNull);
	
	alphabet = _alphabet;
}

string Base58::Encode(const SimpleBaseLibByteArray &_bytes) const
{
	const int32_t growthPercentage = 138;
	SimpleBaseLibByteArray bytes = _bytes;
	int32_t bytesLen, numZeroes, outputLen, Length, carry, i, resultLen;
	uint8_t * inputPtr, * pInput, * pEnd, * outputPtr, * pOutputEnd, * pDigit, * pOutput;
	char * alphabetPtr, * resultPtr, * pResult;
	char firstChar;
	SimpleBaseLibByteArray output;
	string value, result = "";
	
	bytesLen = bytes.size();
	if (bytesLen == 0) return result;

	inputPtr = &bytes[0];
	value = alphabet->GetValue();
	alphabetPtr = &value[0];

	pInput = inputPtr;
	pEnd = PointerUtils::Offset(inputPtr, bytesLen);
	while ((pInput != pEnd) && (*pInput == 0)) 
		pInput++;
	
	numZeroes = int32_t(pInput - inputPtr);
	firstChar = *alphabetPtr;

	if (pInput == pEnd)
	{
		result.resize(numZeroes);
		for (register size_t i = 0; i < size_t(numZeroes); i++)
			result[i] = char(firstChar);

		return result;
	}

	outputLen = bytesLen * growthPercentage / 100 + 1;
	Length = 0;
	output.resize(outputLen);
	outputPtr = &output[0];

	pOutputEnd = outputPtr + outputLen - 1;
	while (pInput != pEnd)
	{
		carry = *pInput;
		i = 0;
		pDigit = pOutputEnd;
		while (((carry != 0) || (i < Length)) && (pDigit >= outputPtr))
		{
			carry = carry + (256 * (*pDigit));
			*pDigit = uint8_t(carry % 58);
			carry = carry / 58;
			pDigit--;
			i++;
		}

		Length = i;
		pInput++;
	}

	pOutputEnd++;
	pOutput = outputPtr;
	while ((pOutput != pOutputEnd) && (*pOutput == 0))
		pOutput++;
	
	resultLen = numZeroes + int32_t(pOutputEnd - pOutput);
	result.resize(resultLen);
	for (register size_t i = 0; i < size_t(resultLen); i++)
		result[i] = char(firstChar);

	resultPtr = &result[0];

	pResult = resultPtr + numZeroes;
	while (pOutput != pOutputEnd)
	{
		*pResult = alphabetPtr[*pOutput];
		pOutput++;
		pResult++;
	}
	
	return result;
}

SimpleBaseLibByteArray Base58::Decode(const string &_text) const
{
	const int32_t reductionFactor = 733;
	string text = _text;
	int32_t textLen, numZeroes, outputLen, carry, resultLen, LowPoint;
	char * inputPtr, * pEnd, * pInput;
	uint8_t * outputPtr, * pOutputEnd, * pDigit, * pOutput;
	char firstChar;
	SimpleBaseLibByteArray output, result;
	
	textLen = text.size();
	if (textLen == 0) return result;

	inputPtr = &text[0];

	pEnd = PointerUtils::Offset(inputPtr, textLen);
	pInput = inputPtr;
	LowPoint = 0;

	firstChar = alphabet->GetValue()[LowPoint];
	while ((*pInput == firstChar) && (pInput != pEnd)) 
		pInput++;
	
	numZeroes = int32_t(pInput - inputPtr);
	if (pInput == pEnd)
	{
		result.resize(numZeroes);
		return result;
	}

	outputLen = textLen * reductionFactor / 1000 + 1;
	output.resize(outputLen);
	outputPtr = &output[0];

	pOutputEnd = outputPtr + outputLen - 1;
	while (pInput != pEnd)
	{
		carry = alphabet->GetSelf(*pInput);
		pInput++;
		pDigit = pOutputEnd;
		while (pDigit >= outputPtr)
		{
			carry = carry + (58 * (*pDigit));
			*pDigit = uint8_t(carry);
			carry = carry / 256;
			pDigit--;
		}
	}

	pOutput = outputPtr;
	while ((pOutput != pOutputEnd) && (*pOutput == 0)) 
		pOutput++;
	
	resultLen = int32_t(pOutputEnd - pOutput) + 1;
	if (resultLen == outputLen)
	{
		return output;
	}

	result.resize(numZeroes + resultLen);
	memmove(&result[numZeroes], &output[int32_t(pOutput - outputPtr)], resultLen);

	return result;
}


