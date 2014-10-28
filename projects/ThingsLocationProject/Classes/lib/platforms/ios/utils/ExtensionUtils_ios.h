
#ifndef __ExtensionUtils_ios__
#define __ExtensionUtils_ios__

class CValue;

CValue* EUValueFromNSObject( id aObject );

id EUNSObjectFromCValue( CValue* aObject );
#endif 
