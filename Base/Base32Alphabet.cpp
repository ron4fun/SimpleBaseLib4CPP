#include "Base32Alphabet.h"
#include "CrockfordBase32Alphabet.h"

IBase32Alphabet Base32Alphabet::Crockford = nullptr;
IBase32Alphabet Base32Alphabet::Rfc4648 = nullptr;
IBase32Alphabet Base32Alphabet::ExtendedHex = nullptr;

Base32Alphabet::Base32Alphabet(const string &chars)
{
	int32_t idx, LowPoint, HighPoint;
	
	EncodingTable.resize(chars.size());
	LowPoint = 0;
	HighPoint = chars.size();

	for (idx = LowPoint; idx < HighPoint; idx++)
		EncodingTable[idx] = chars[idx];

	CreateDecodingTable(chars);
}

char Base32Alphabet::LowCase(const char ch)
{
	switch (ch)
	{
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
		
		return (ch + 'a' - 'A');
		break;
	}
	
	return ch;
}

void Base32Alphabet::CreateDecodingTable(const string &chars)
{
	SimpleBaseLibByteArray bytes;
	char c;
	uint8_t b;
	
	bytes.resize(HighestAsciiCharSupported + 1);
	for (register size_t idx = 0; idx < chars.size(); idx++)
	{
		c = chars[idx];
		b = uint8_t(idx + 1);
		bytes[c] = b;
		bytes[LowCase(c)] = b;
	}

	DecodingTable = bytes;
}

void Base32Alphabet::Boot()
{
	Crockford = make_shared<CrockfordBase32Alphabet>();
	Rfc4648 = make_shared<Base32Alphabet>("ABCDEFGHIJKLMNOPQRSTUVWXYZ234567");
	ExtendedHex = make_shared<Base32Alphabet>("0123456789ABCDEFGHIJKLMNOPQRSTUV");
}