#ifndef __CValue_h__
#define __CValue_h__

#include "cocos2d.h"
#include "json.h"
#include "ILogable.h"
#include <map>

using namespace cocos2d;

class CBufferReader;
class CBufferWriter;
class CValue;

#define READ_Value_STRING(dic, key, var) \
{ \
    CValue* tmp = 0; \
    tmp = dynamic_cast<CValue*>(dic->objectForKey(key)); \
    if(tmp && tmp->type() == CValue::CValueTypeString) \
    { \
        var = tmp->toString(); \
    } \
}
#define CAST_TO_Value(x) (dynamic_cast<CValue*>(x))

typedef CCArray CValueArray;

//
// CValueDictionary
//

class CValueDictionary : public CCDictionary
{
public:
    static CValueDictionary* dictionary()
    {
        CValueDictionary* d = new CValueDictionary();
        d->autorelease();
        return d;
    }
};

//
// CValue
//
class CValue
    : public CCObject
    , public ILogable
{
public:

	enum CValueType
	{
		CValueTypeNone = 0,
		CValueTypeInt,
		CValueTypeFloat,
		CValueTypeDouble,
		CValueTypeString,
		CValueTypeArray,
		CValueTypeDictionary,
        CValueTypeLongLong
	};
    	
    static CValue* ValueFromValue(CValue* aValue);
    static CValue* ValueFromLongLong(long long value);
	static CValue* ValueFromInt(int value);
	static CValue* ValueFromFloat(float value);
	static CValue* ValueFromDouble(double value);
	static CValue* ValueFromString(const std::string& value);
	// Array must contain only CValue objects type 
	static CValue* ValueFromArray(CValueArray* value); 
	static CValue* ValueFromDictionary(CValueDictionary* value);
	static CValue* ValueFromDictionary(const std::map< std::string, std::string >& value);
	static CValue* ValueFromBuffer(CBufferReader* reader);
    static CValue* ValueFromJson(Json::Value aObject);
	
    long long                               toLongLong();
	int 									toInt();
	float 									toFloat();
	double 									toDouble();
	std::string&	 						toString();
	CValueArray* 							toArray();
	CValueDictionary* 					toDictionary();
    
    Json::Value                             jsonRepresentation();
    std::string                             stringJsonRepresentation();
    std::string                             stringStyledJsonRepresentation();

	inline CValueType type() { return mType; }
	
	void saveToBuffer(CBufferWriter* writer);

    // ILogable
    virtual void log();

private:
	CValue();
	virtual ~CValue();

	void readFromBuffer(CBufferReader* reader);
	
	union _Value
	{
		int						_int;
		float					_float;
		double					_double;
		std::string*			_string;
		CValueArray*			_array;
		CValueDictionary*		_dictionary;
        long long               _longlong;
	};
	
	_Value mValue;
	CValueType mType;
};

#endif //__CValue_h__

