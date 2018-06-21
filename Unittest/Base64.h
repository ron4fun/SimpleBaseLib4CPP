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


BOOST_AUTO_TEST_SUITE(Base64TestCase)

SimpleBaseLibStringArray RawData = SimpleBaseLibStringArray({ "", "f", "fo", "foo", "foob",
	"fooba", "foobar", "1234567890123456789012345678901234567890"
});

SimpleBaseLibStringArray EncodedDataBase64Default = SimpleBaseLibStringArray({ "", "Zg==", "Zm8=", "Zm9v",
	"Zm9vYg==", "Zm9vYmE=", "Zm9vYmFy",
	"MTIzNDU2Nzg5MDEyMzQ1Njc4OTAxMjM0NTY3ODkwMTIzNDU2Nzg5MA=="
});

IBase64 base64 = nullptr;

BOOST_AUTO_TEST_CASE(Test_Decode_DefaultNoPadding_ReturnsExpectedValues)
{
	base64 = SimpleBaseFactory::CreateBase64DefaultNoPadding();
	SimpleBaseLibByteArray bytes;
	string result;
	
	for (register size_t i = 0; i < EncodedDataBase64Default.size(); i++)
	{
		bytes = base64->Decode(Utilities::TrimRight(EncodedDataBase64Default[i], SimpleBaseLibCharArray({ '=' })));
		result = Utilities::convertByteArrayToASCIIString(bytes, false);
		BOOST_CHECK(RawData[i] == result, "Decoding Failed at Index %d', [i]");
	}
}

BOOST_AUTO_TEST_CASE(Test_Decode_Default_ReturnsExpectedValues)
{
	base64 = SimpleBaseFactory::CreateBase64Default();
	SimpleBaseLibByteArray bytes;
	string result;

	for (register size_t i = 0; i < EncodedDataBase64Default.size(); i++)
	{
		bytes = base64->Decode(EncodedDataBase64Default[i]);
		result = Utilities::convertByteArrayToASCIIString(bytes, false);
		BOOST_CHECK(RawData[i] == result, "Decoding Failed at Index %d', [i]");
	}
}

BOOST_AUTO_TEST_CASE(Test_Dog_Food_Default)
{
	base64 = SimpleBaseFactory::CreateBase64Default();
	SimpleBaseLibByteArray bytes;

	for (register size_t i = 0; i < RawData.size(); i++)
	{
		bytes = Utilities::convertASCIIStringToByteArray(RawData[i]);
		BOOST_CHECK(base64->Decode(base64->Encode(bytes)) == bytes, "Encoding & Decoding Failed at Index %d', [i]");
	}
}

BOOST_AUTO_TEST_CASE(Test_Dog_Food_DefaultNoPadding)
{
	base64 = SimpleBaseFactory::CreateBase64DefaultNoPadding();
	SimpleBaseLibByteArray bytes;

	for (register size_t i = 0; i < RawData.size(); i++)
	{
		bytes = Utilities::convertASCIIStringToByteArray(RawData[i]);
		BOOST_CHECK(base64->Decode(base64->Encode(bytes)) == bytes, "Encoding & Decoding Failed at Index %d', [i]");
	}
}

BOOST_AUTO_TEST_CASE(Test_Dog_Food_FileEncoding)
{
	base64 = SimpleBaseFactory::CreateBase64FileEncoding();
	SimpleBaseLibByteArray bytes;

	for (register size_t i = 0; i < RawData.size(); i++)
	{
		bytes = Utilities::convertASCIIStringToByteArray(RawData[i]);
		BOOST_CHECK(base64->Decode(base64->Encode(bytes)) == bytes, "Encoding & Decoding Failed at Index %d', [i]");
	}
}

BOOST_AUTO_TEST_CASE(Test_Dog_Food_RegExEncoding)
{
	base64 = SimpleBaseFactory::CreateBase64RegExEncoding();
	SimpleBaseLibByteArray bytes;

	for (register size_t i = 0; i < RawData.size(); i++)
	{
		bytes = Utilities::convertASCIIStringToByteArray(RawData[i]);
		BOOST_CHECK(base64->Decode(base64->Encode(bytes)) == bytes, "Encoding & Decoding Failed at Index %d', [i]");
	}
}

BOOST_AUTO_TEST_CASE(Test_Dog_Food_UrlEncoding)
{
	base64 = SimpleBaseFactory::CreateBase64UrlEncoding();
	SimpleBaseLibByteArray bytes;

	for (register size_t i = 0; i < RawData.size(); i++)
	{
		bytes = Utilities::convertASCIIStringToByteArray(RawData[i]);
		BOOST_CHECK(base64->Decode(base64->Encode(bytes)) == bytes, "Encoding & Decoding Failed at Index %d', [i]");
	}
}

BOOST_AUTO_TEST_CASE(Test_Dog_Food_XmlEncoding)
{
	base64 = SimpleBaseFactory::CreateBase64XmlEncoding();
	SimpleBaseLibByteArray bytes;

	for (register size_t i = 0; i < RawData.size(); i++)
	{
		bytes = Utilities::convertASCIIStringToByteArray(RawData[i]);
		BOOST_CHECK(base64->Decode(base64->Encode(bytes)) == bytes, "Encoding & Decoding Failed at Index %d', [i]");
	}
}

BOOST_AUTO_TEST_CASE(Test_Encode_DefaultNoPadding_ReturnsExpectedValues)
{
	base64 = SimpleBaseFactory::CreateBase64DefaultNoPadding();
	SimpleBaseLibByteArray bytes;
	string result, temp;

	for (register size_t i = 0; i < RawData.size(); i++)
	{
		bytes = Utilities::convertASCIIStringToByteArray(RawData[i]);;
		result = base64->Encode(bytes);
		temp = Utilities::TrimRight(EncodedDataBase64Default[i], SimpleBaseLibCharArray({ '=' }));
		
		BOOST_CHECK(temp == result,	"Encoding Failed at Index %d', [i]");
	}
}

BOOST_AUTO_TEST_CASE(Test_Encode_Default_ReturnsExpectedValues)
{
	base64 = SimpleBaseFactory::CreateBase64Default();
	SimpleBaseLibByteArray bytes;
	string result;

	for (register size_t i = 0; i < RawData.size(); i++)
	{
		bytes = Utilities::convertASCIIStringToByteArray(RawData[i]);;
		result = base64->Encode(bytes);
		BOOST_CHECK(EncodedDataBase64Default[i] == result, "Encoding Failed at Index %d', [i]");
	}
}

BOOST_AUTO_TEST_SUITE_END()
