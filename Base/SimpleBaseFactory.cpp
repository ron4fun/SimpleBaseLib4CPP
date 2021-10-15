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
#include "Base32.h"
#include "Base32Alphabet.h"
#include "Base58.h"
#include "Base58Alphabet.h"
#include "Base64.h"
#include "Base64Alphabet.h"
#include "SimpleBaseFactory.h"

bool SimpleBaseFactory::isBoot = false;

IBase16 SimpleBaseFactory::CreateBase16()
{
	Boot();
	return make_shared<Base16>();
}

IBase32 SimpleBaseFactory::CreateBase32(const IBase32Alphabet alphabet)
{
	Boot();
	return make_shared<Base32>(alphabet);
}

IBase32 SimpleBaseFactory::CreateBase32Crockford()
{
	Boot();
	return make_shared<Base32>(Base32Alphabet::GetCrockford());
}

IBase32 SimpleBaseFactory::CreateBase32ExtendedHex()
{
	Boot();
	return make_shared<Base32>(Base32Alphabet::GetExtendedHex());
}

IBase32 SimpleBaseFactory::CreateBase32Rfc4648()
{
	Boot();
	return make_shared<Base32>(Base32Alphabet::GetRfc4648());
}

IBase58 SimpleBaseFactory::CreateBase58(const IBase58Alphabet alphabet)
{
	Boot();
	return make_shared<Base58>(alphabet);
}

IBase58 SimpleBaseFactory::CreateBase58BitCoin()
{
	Boot();
	return make_shared<Base58>(Base58Alphabet::GetBitCoin());
}

IBase58 SimpleBaseFactory::CreateBase58Flickr()
{
	Boot();
	return make_shared<Base58>(Base58Alphabet::GetFlickr());
}

IBase58 SimpleBaseFactory::CreateBase58Ripple()
{
	Boot();
	return make_shared<Base58>(Base58Alphabet::GetRipple());
}

IBase64 SimpleBaseFactory::CreateBase64(const IBase64Alphabet alphabet)
{
	Boot();
	return make_shared<Base64>(alphabet);
}

IBase64 SimpleBaseFactory::CreateBase64Default()
{
	Boot();
	return make_shared<Base64>(Base64Alphabet::GetDefault());
}

IBase64 SimpleBaseFactory::CreateBase64DefaultNoPadding()
{
	Boot();
	return make_shared<Base64>(Base64Alphabet::GetDefaultNoPadding());
}

IBase64 SimpleBaseFactory::CreateBase64FileEncoding()
{
	Boot();
	return make_shared<Base64>(Base64Alphabet::GetFileEncoding());
}

IBase64 SimpleBaseFactory::CreateBase64RegExEncoding()
{
	Boot();
	return make_shared<Base64>(Base64Alphabet::GetRegExEncoding());
}

IBase64 SimpleBaseFactory::CreateBase64UrlEncoding()
{
	Boot();
	return make_shared<Base64>(Base64Alphabet::GetUrlEncoding());
}

IBase64 SimpleBaseFactory::CreateBase64XmlEncoding()
{
	Boot();
	return make_shared<Base64>(Base64Alphabet::GetXmlEncoding());
}

void SimpleBaseFactory::Boot()
{
	if (isBoot) return;

	Base32Alphabet::Boot();
	Base58Alphabet::Boot();
	Base64Alphabet::Boot();

	isBoot = true;
}
