
#if defined(_MSC_VER)
	//disble vector assert for nullstring converted to byte array
	#define _HAS_ITERATOR_DEBUGGING 0
#endif

#include "Unittest\Base16.h"
#include "Unittest\Base32Crockford.h"
#include "Unittest\Base32ExtendedHex.h"
#include "Unittest\Base32Rfc4648.h"
#include "Unittest\Base58.h"
#include "Unittest\Base64.h"