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


BOOST_AUTO_TEST_SUITE(Base58TestCase)

SimpleBaseLibStringArray RawDataInHex = SimpleBaseLibStringArray({ "", "0000010203",
	"009C1CA2CBA6422D3988C735BB82B5C880B0441856B9B0910F",
	"000860C220EBBAF591D40F51994C4E2D9C9D88168C33E761F6",
	"00313E1F905554E7AE2580CD36F86D0C8088382C9E1951C44D010203", "0000000000",
	"1111111111", "FFEEDDCCBBAA", "00", "21",
	// Test cases from https://gist.github.com/CodesInChaos/3175971
	"00000001", "61", "626262", "636363",
	"73696D706C792061206C6F6E6720737472696E67",
	"00EB15231DFCEB60925886B67D065299925915AEB172C06647", "516B6FCD0F",
	"BF4F89001E670274DD", "572E4794", "ECAC89CAD93923C02321", "10C8511E",
	"00000000000000000000"
});

SimpleBaseLibStringArray Base58EncodedData = SimpleBaseLibStringArray({ "", "11Ldp",
	"1FESiat4YpNeoYhW3Lp7sW1T6WydcW7vcE", "1mJKRNca45GU2JQuHZqZjHFNktaqAs7gh",
	"17f1hgANcLE5bQhAGRgnBaLTTs23rK4VGVKuFQ", "11111", "2vgLdhi",
	"3CSwN61PP", "1", "a",
	// Test cases from https://gist.github.com/CodesInChaos/3175971
	"1112", "2g", "a3gV", "aPEr", "2cFupjhnEsSn59qHXstmK2ffpLv2",
	"1NS17iag9jJgTHD1VXjvLCEnZuQ3rJDE9L", "ABnLTmg", "3SEo3LWLoPntC", "3EFU7m",
	"EJDM8drfXA6uyA", "Rt5zm", "1111111111"
});

IBase16 base16 = SimpleBaseFactory::CreateBase16();
IBase58 base58 = SimpleBaseFactory::CreateBase58BitCoin();

BOOST_AUTO_TEST_CASE(Test_Constructor_Null_Alphabet_Raise)
{
	BOOST_CHECK_THROW(SimpleBaseFactory::CreateBase58(nullptr), ArgumentNullSimpleBaseLibException);
}

BOOST_AUTO_TEST_CASE(Test_Decode_Invalid_Character_Raise)
{
	BOOST_CHECK_THROW(base58->Decode("?"), InvalidOperationSimpleBaseLibException);
}

BOOST_AUTO_TEST_CASE(Test_Decode_Empty_String_Returns_Empty_Buffer)
{
	BOOST_CHECK(0 == base58->Decode("").size());
}

BOOST_AUTO_TEST_CASE(Test_Encode_Empty_Buffer_Returns_Empty_String)
{
	BOOST_CHECK("" == base58->Encode(SimpleBaseLibByteArray({})));
}

BOOST_AUTO_TEST_CASE(Test_Decode_Bitcoin_Returns_Expected_Results)
{
	SimpleBaseLibByteArray buffer;
	string result;

	for (register size_t i = 0; i < RawDataInHex.size(); i++)
	{
		buffer = base58->Decode(Base58EncodedData[i]);
		result = base16->EncodeUpper(buffer);
		BOOST_CHECK(RawDataInHex[i] == result, "Decoding Failed at Index %d', [i]");
	}
}

BOOST_AUTO_TEST_CASE(Test_Encode_Bitcoin_Returns_Expected_Results)
{
	SimpleBaseLibByteArray buffer;
	string result;

	for (register size_t i = 0; i < RawDataInHex.size(); i++)
	{
		buffer = base16->Decode(RawDataInHex[i]);;
		result = base58->Encode(buffer);
		BOOST_CHECK(Base58EncodedData[i] == result, "Encoding Failed at Index %d', [i]");
	}
}

BOOST_AUTO_TEST_SUITE_END()
