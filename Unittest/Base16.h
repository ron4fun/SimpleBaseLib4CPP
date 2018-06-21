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


BOOST_AUTO_TEST_SUITE(Base16TestCase)

vector<SimpleBaseLibByteArray> testDataBytes = vector<SimpleBaseLibByteArray>({
	SimpleBaseLibByteArray({}), SimpleBaseLibByteArray({0xAB}),
	SimpleBaseLibByteArray({0x00, 0x01, 0x02, 0x03}),
	SimpleBaseLibByteArray({0x10, 0x11, 0x12, 0x13}),
	SimpleBaseLibByteArray({0xAB, 0xCD, 0xEF, 0xBA})
	});

SimpleBaseLibStringArray testDataString = SimpleBaseLibStringArray({ 
	"", "AB", "00010203", "10111213", "ABCDEFBA"
	});

IBase16 base16 = SimpleBaseFactory::CreateBase16();

BOOST_AUTO_TEST_CASE(Test_Decode_Invalid_Char_Raise)
{
	BOOST_CHECK_THROW(base16->Decode("AZ12"), InvalidOperationSimpleBaseLibException);
		
	BOOST_CHECK_THROW(base16->Decode("ZAAA"), InvalidOperationSimpleBaseLibException);
}

BOOST_AUTO_TEST_CASE(Test_Decode_Invalid_Length_Raise)
{
	BOOST_CHECK_THROW(base16->Decode("12345"), InvalidArgumentSimpleBaseLibException);

	BOOST_CHECK_THROW(base16->Decode("ABC"), InvalidArgumentSimpleBaseLibException);	
}

BOOST_AUTO_TEST_CASE(Test_Decode_LowerCase)
{
	SimpleBaseLibByteArray result;
	
	for (register size_t i = 0; i < testDataBytes.size(); i++)
	{
		result = base16->Decode(testDataString[i]);
		BOOST_CHECK(testDataBytes[i] == result,	"Decode_LowerCase Failed at Index %d', [i]");
	}
}

BOOST_AUTO_TEST_CASE(Test_Encode_Lower)
{
	string result;

	for (register size_t i = 0; i < testDataBytes.size(); i++)
	{
		result = base16->EncodeLower(testDataBytes[i]);
		BOOST_CHECK(Utilities::toLower(testDataString[i]) == result, "EncodeLower Failed at Index %d', [i]");
	}
}

BOOST_AUTO_TEST_CASE(Test_Encode_Upper)
{
	string result;

	for (register size_t i = 0; i < testDataBytes.size(); i++)
	{
		result = base16->EncodeUpper(testDataBytes[i]);
		BOOST_CHECK(testDataString[i] == result, "EncodeUpper Failed at Index %d', [i]");
	}
}

BOOST_AUTO_TEST_SUITE_END()
