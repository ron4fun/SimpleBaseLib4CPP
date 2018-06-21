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

#define BOOST_TEST_MODULE UNITTESTSIMPLEBASE

#include <boost/test/included/unit_test.hpp>
#include "../Base/SimpleBaseFactory.h"
#include "../Utils/Utilities.h"


BOOST_AUTO_TEST_SUITE(Base32ExtendedHexTestCase)

SimpleBaseLibStringArray RawData = SimpleBaseLibStringArray({ "", "f", "fo", "foo", "foob",
	"fooba", "foobar", "1234567890123456789012345678901234567890"
});

SimpleBaseLibStringArray EncodedData = SimpleBaseLibStringArray({ "", "CO======", "CPNG====", "CPNMU===",
	"CPNMUOG=", "CPNMUOJ1", "CPNMUOJ1E8======",
	"64P36D1L6ORJGE9G64P36D1L6ORJGE9G64P36D1L6ORJGE9G64P36D1L6ORJGE9G"
});

IBase32 base32 = SimpleBaseFactory::CreateBase32ExtendedHex();

BOOST_AUTO_TEST_CASE(Test_Decode_InvalidInput_ThrowsInvalidArgumentException)
{
	BOOST_CHECK_THROW(base32->Decode("!@#!#@!#@#!@"), InvalidArgumentSimpleBaseLibException);

	BOOST_CHECK_THROW(base32->Decode("||||"), InvalidArgumentSimpleBaseLibException);
}

BOOST_AUTO_TEST_CASE(Test_Decode_ReturnsExpectedValues)
{
	SimpleBaseLibByteArray bytes;
	string result;

	for (register size_t i = 0; i < EncodedData.size(); i++)
	{
		bytes = base32->Decode(EncodedData[i]);
		result = Utilities::convertByteArrayToASCIIString(bytes, false);
		BOOST_CHECK(RawData[i] == result, "Decoding Failed at Index %d', [i]");

		bytes = base32->Decode(Utilities::toLower(EncodedData[i]));
		result = Utilities::convertByteArrayToASCIIString(bytes, false);
		BOOST_CHECK(RawData[i] == result, "Decoding Failed at Index %d', [i]");
	}
}

BOOST_AUTO_TEST_CASE(Test_Encode_ReturnsExpectedValues)
{
	SimpleBaseLibByteArray bytes;
	string result;

	for (register size_t i = 0; i < RawData.size(); i++)
	{
		bytes = Utilities::convertASCIIStringToByteArray(RawData[i]);;
		result = base32->Encode(bytes, true);
		BOOST_CHECK(EncodedData[i] == result, "Encoding Failed at Index %d', [i]");
	}
}

BOOST_AUTO_TEST_SUITE_END()
