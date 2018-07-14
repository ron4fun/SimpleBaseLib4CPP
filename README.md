# SimpleBaseLib4CPP
**`SimpleBaseLib4CPP`** is a simple C++11 Base Encoding library that provides at the moment support for encoding and decoding various bases such as Base16, Base32 (various variants), Base58 (various variants) and Base64 (various variants).

**Supported Encodings:**

    Base64: Default, DefaultNoPadding, UrlEncoding, XmlEncoding, RegExEncoding and FileEncoding alphabets 
    (and any custom alphabet you might have)
    
    Base58: Bitcoin, Ripple and Flickr alphabets (and any custom alphabet you might have)

	Base32: RFC 4648, Crockford and Extended Hex (BASE32-HEX) alphabets with Crockford character substitution 
    (or any other custom alphabets you might want to use)   
    
    Base16: An experimental hexadecimal encoder/decoder.

**Tested Enviroments:**
     
    Visual Studio 2015.

    
**Usage Examples.**

    #include "Base/SimpleBaseFactory.h"
	#include "Utils/Utilities.h"

    int main()
    {
        IBase32 base32 = SimpleBaseFactory::CreateBase32Crockford();
        string rawData = "foobar";
		string result;

        SimpleBaseLibByteArray bytes = Utilities::convertASCIIStringToByteArray(rawData);

		result = base32->Encode(bytes);
		        
        return 0;
    }

 **Unit Tests:**

To run the unit tests, you should have [boost library](http://www.boost.org/) installed in your workstation.
    
**License**

This "Software" is Licensed Under  **`MIT License (MIT)`** .

#### Tip Jar
* :dollar: **Bitcoin**: `1Mcci95WffSJnV6PsYG7KD1af1gDfUvLe6`


Conclusion
--------------------------------------------------

   Special thanks to [Xor-el](https://github.com/xor-el) for making this library available in the first place.
