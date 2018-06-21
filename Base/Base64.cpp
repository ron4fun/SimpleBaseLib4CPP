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

#include "stdafx.h"
#include "Base64.h"
#include "Base64Alphabet.h"
#include "../Utils/PointerUtils.h"
#include "../Utils/Bits.h"

const char * Base64::AlphabetNull = "Alphabet Instance cannot be Null \"%s\"";

Base64::Base64(const IBase64Alphabet _alphabet)
{
	if (!_alphabet)
		throw ArgumentNullSimpleBaseLibException(AlphabetNull);

	alphabet = _alphabet;
}

string Base64::Encode(const SimpleBaseLibByteArray &_bytes) const
{
	SimpleBaseLibByteArray bytes = _bytes;
	int32_t bytesLen, padding, blocks, l, i;
	uint8_t b1, b2, b3;
	uint8_t * _d, * d;
	char * _cs, * _sp, * sp;
	SimpleBaseLibCharArray _s, EncodingTable;
	bool pad2, pad1;

	bytesLen = bytes.size();
	if (bytesLen == 0) return "";

	_d = &bytes[0];
	EncodingTable = alphabet->GetEncodingTable();
	_cs = &EncodingTable[0];

	d = _d;

	padding = bytesLen % 3;
	if (padding > 0) 
		padding = 3 - padding;
	
	blocks = (bytesLen - 1) / 3 + 1;

	l = blocks * 4;

	_s.resize(l);

	_sp = &_s[0];
	sp = _sp;

	i = 1;

	while (i < blocks)
	{
		b1 = *d;
		d++;
		b2 = *d;
		d++;
		b3 = *d;
		d++;

		*sp = _cs[Bits::Asr32((b1 & 0xFC), 2)];
		sp++;
		*sp = _cs[Bits::Asr32((b2 & 0xF0), 4) | (b1 & 0x03) << 4];
		sp++;
		*sp = _cs[Bits::Asr32((b3 & 0xC0), 6) | (b2 & 0x0F) << 2];
		sp++;
		*sp = _cs[b3 & 0x3F];
		sp++;

		i++;
	}

	pad2 = padding == 2;
	pad1 = padding > 0;

	b1 = *d;
	d++;
	if (pad2) b2 = 0;
	else
	{
		b2 = *d;
		d++;
	}

	if (pad1) b3 = 0;
	else
	{
		b3 = *d;
		d++;
	}

	*sp = _cs[Bits::Asr32((b1 & 0xFC), 2)];
	sp++;
	*sp = _cs[Bits::Asr32((b2 & 0xF0), 4) | (b1 & 0x03) << 4];
	sp++;
	if (pad2) *sp = '=';
	else
		*sp = _cs[Bits::Asr32((b3 & 0xC0), 6) | (b2 & 0x0F) << 2];
	
	sp++;

	if (pad1) *sp = '=';
	else
		*sp = _cs[b3 & 0x3F];
		
	sp++;

	string result(_s.begin(), _s.end());

	if (!alphabet->GetPaddingEnabled())
	{
		if (pad2) l--;
		if (pad1) l--;

		result.resize(l);
	}

	return result;
}

SimpleBaseLibByteArray Base64::Decode(const string &text) const
{
	int32_t Idx, textLen, LowPoint, HighPoint, blocks, bytes, padding, i;
	uint8_t temp1, temp2;
	SimpleBaseLibCharArray tempArray;
	SimpleBaseLibByteArray _data, DecodingTable, result;
	char * _p, * p2, * pEnd;
	uint8_t * dp, * _d, * p_decode;
	

	textLen = text.size();
	if (textLen == 0) return result;

	tempArray.resize(textLen);
	LowPoint = 0;
	HighPoint = textLen;

	for (Idx = LowPoint; Idx < HighPoint; Idx++)
		tempArray[Idx] = text[Idx];

	_p = &tempArray[0];
	DecodingTable = alphabet->GetDecodingTable();
	p_decode = &DecodingTable[0];
	pEnd = PointerUtils::Offset(_p, tempArray.size());

	p2 = _p;

	blocks = (textLen - 1) / 4 + 1;
	bytes = blocks * 3;

	padding = blocks * 4 - textLen;

	if ((textLen > 2) && (p2[textLen - 2] == paddingChar)) 
		padding = 2;
	else if ((textLen > 1) && (p2[textLen - 1] == paddingChar)) 
		padding = 1;

	_data.resize(bytes - padding);

	_d = &_data[0];

	dp = _d;

	i = 1;

	while (i < blocks)
	{
		temp1 = Process(&p2, pEnd, p_decode);

		temp2 = Process(&p2, pEnd, p_decode);

		*dp = uint8_t((temp1 << 2) | (Bits::Asr32(temp2 & 0x30, 4)));
		dp++;

		temp1 = Process(&p2, pEnd, p_decode);

		*dp = uint8_t((Bits::Asr32(temp1 & 0x3C, 2)) | ((temp2 & 0x0F) << 4));
		dp++;

		temp2 = Process(&p2, pEnd, p_decode);

		*dp = uint8_t(((temp1 & 0x03) << 6) | temp2);
		dp++;

		i++;
	}

	temp1 = Process(&p2, pEnd, p_decode);

	temp2 = Process(&p2, pEnd, p_decode);

	*dp = uint8_t((temp1 << 2) | (Bits::Asr32(temp2 & 0x30, 4)));
	dp++;

	temp1 = Process(&p2, pEnd, p_decode);

	if (padding != 2) 
	{
		*dp = uint8_t((Bits::Asr32(temp1 & 0x3C, 2) | ((temp2 & 0x0F) << 4)));
		dp++;
	}

	temp2 = Process(&p2, pEnd, p_decode);
	if (padding == 0)
	{
		*dp = uint8_t(((temp1 & 0x03) << 6) | temp2);
		dp++;
	}

	return _data;
}

uint8_t Base64::Process(char ** pInput, const char * pEnd, const uint8_t * decode_table)
{
	char c = *(*pInput);
	(*pInput)++;

	return decode_table[c];
}
