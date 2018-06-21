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

#include "Base32.h"
#include "Base32Alphabet.h"
#include "../Utils/Utilities.h"
#include "../Utils/PointerUtils.h"
#include "../Utils/Bits.h"

const char * Base32::AlphabetNull = "Alphabet Instance cannot be Null \"%s\"";
const char * Base32::InvalidCharacter = "Invalid character value in input: 0x%x \"c\"";

Base32::Base32(const IBase32Alphabet _alphabet)
{
	if (!_alphabet)
		throw ArgumentNullSimpleBaseLibException(AlphabetNull);
	
	alphabet = _alphabet;
}

string Base32::Encode(const SimpleBaseLibByteArray &_bytes, const bool padding) const
{
	SimpleBaseLibByteArray bytes = _bytes;
	int32_t bytesLen, outputLen, bitsLeft, currentByte, outputPad, nextBits;
	SimpleBaseLibCharArray outputBuffer, EncodingTable;
	uint8_t * inputPtr, * pInput, * pEnd;
	char * encodingTablePtr, * outputPtr, * pEncodingTable, * pOutput, * pOutputEnd;
	
	string result = "";
	bytesLen = bytes.size();
	if (bytesLen == 0) return result;

	// we are ok with slightly larger buffer since the output string will always
	// have the exact length of the output produced.
	outputLen = (((bytesLen - 1) / bitsPerChar) + 1) * bitsPerByte;
	outputBuffer.resize(outputLen);

	inputPtr = &bytes[0];
	EncodingTable = alphabet->GetEncodingTable();
	encodingTablePtr = &EncodingTable[0];
	outputPtr = &outputBuffer[0];

	pEncodingTable = encodingTablePtr;
	pOutput = outputPtr;
	pOutputEnd = outputPtr + outputLen;
	pInput = inputPtr;

	bitsLeft = bitsPerByte;
	currentByte = int32_t(uint8_t(*pInput));
	pEnd = PointerUtils::Offset(pInput, bytesLen);
	while (pInput != pEnd)
	{
		if (bitsLeft > bitsPerChar)
		{
			bitsLeft = bitsLeft - bitsPerChar;
			outputPad = Bits::Asr32(currentByte, bitsLeft);
			*pOutput = pEncodingTable[outputPad];
			pOutput++;
			currentByte = currentByte & ((1 << bitsLeft) - 1);
		}

		nextBits = bitsPerChar - bitsLeft;
		bitsLeft = bitsPerByte - nextBits;
		outputPad = currentByte << nextBits;
		pInput++;
		if (pInput != pEnd)
		{
			currentByte = int32_t(uint8_t(*pInput));
			outputPad = outputPad | Bits::Asr32(currentByte, bitsLeft);
			currentByte = currentByte & ((1 << bitsLeft) - 1);
		}

		*pOutput = pEncodingTable[outputPad];
		pOutput++;
	}

	if (padding)
	{
		while (pOutput != pOutputEnd)
		{
			*pOutput = paddingChar;
			pOutput++;
		}
	}

	result.resize(outputLen);
	for (register size_t i = 0; i < size_t(outputLen); i++)
	{
		result[i] = *outputPtr;
		outputPtr++;
	}		

	return result.c_str();
}

SimpleBaseLibByteArray Base32::Decode(const string &text) const
{
	int32_t textLen, decodingTableLen, bitsLeft, outputLen, outputPad, b, shiftBits;
	SimpleBaseLibByteArray decodingTable;
	uint8_t * resultPtr, * decodingPtr, * pResult, * pDecodingTable;
	char * inputPtr, * pInput, * pEnd;
	char c;
	string trimmed;
	
	SimpleBaseLibByteArray result;
	trimmed = Utilities::TrimRight(text, SimpleBaseLibCharArray({ paddingChar }));
	textLen = trimmed.size();
	
	if (textLen == 0) return result;

	 decodingTable = alphabet->GetDecodingTable();
	 decodingTableLen = decodingTable.size();
	 bitsLeft = bitsPerByte;
	 outputLen = textLen * bitsPerChar / bitsPerByte;
		
	 result.resize(outputLen);
	 outputPad = 0;

	 resultPtr = &result[0];
	 inputPtr = &trimmed[0];
	 decodingPtr = &decodingTable[0];

	 pResult = resultPtr;
	 pDecodingTable = decodingPtr;
	 pInput = inputPtr;
	 pEnd = PointerUtils::Offset(inputPtr, textLen);
	
	 while (pInput != pEnd)
	 {
		c = *pInput;
		pInput++;
		if (c >= decodingTableLen) 
			InvalidInput(c);

		b = pDecodingTable[c] - 1;
		if (b < 0)
			InvalidInput(c);

		if (bitsLeft > bitsPerChar)
		{
			bitsLeft = bitsLeft - bitsPerChar;
			outputPad = outputPad | (b << bitsLeft);
			continue;
		}

		shiftBits = bitsPerChar - bitsLeft;
		outputPad = outputPad | (Bits::Asr32(b, shiftBits));
		*pResult = (uint8_t)(outputPad);
		pResult++;
		b = b & ((1 << shiftBits) - 1);
		bitsLeft = bitsPerByte - shiftBits;
		outputPad = b << bitsLeft;
	 }

	 return result;
}


