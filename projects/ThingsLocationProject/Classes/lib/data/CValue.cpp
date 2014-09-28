#include "CValue.h" 
#include "CBufferReader.h"
#include "CBufferWriter.h"
#include "Log.h"
#include "Utils.h"

//
// CValue
//

CValue::CValue()
:mType(CValueTypeNone)
{
	
}

CValue::~CValue()
{
	switch(mType)
	{
	case CValueTypeString:
		delete mValue._string;
		break;

	case CValueTypeArray:
		mValue._array->release();
		break;

	case CValueTypeDictionary:
		mValue._dictionary->release();
		break;
            
    default:
        break;
	};

}

CValue* CValue::ValueFromValue(CValue* aValue)
{
    CBufferWriter writer;
    aValue->saveToBuffer(&writer);
    CBufferReader reader(writer.getData(), writer.getCurrentPos());
    return CValue::ValueFromBuffer(&reader);
}

CValue* CValue::ValueFromInt( int value )
{
	CValue* res = new CValue;
	res->autorelease();
	
	res->mType = CValueTypeInt;
	res->mValue._int = value;

	return res;
}

CValue* CValue::ValueFromLongLong ( long long value )
{
    CValue* res = new CValue;
	res->autorelease();
	
	res->mType = CValueTypeLongLong;
	res->mValue._longlong = value;
    
	return res;
}

CValue* CValue::ValueFromFloat( float value )
{
	CValue* res = new CValue;
	res->autorelease();

	res->mType = CValueTypeFloat;
	res->mValue._float = value;

	return res;
}

CValue* CValue::ValueFromDouble( double value )
{
	CValue* res = new CValue;
	res->autorelease();

	res->mType = CValueTypeDouble;
	res->mValue._double = value;

	return res;
}

CValue* CValue::ValueFromString( const std::string& value )
{
	CValue* res = new CValue;
	res->autorelease();

	res->mType = CValueTypeString;
	res->mValue._string = new std::string(value);

	return res;
}

CValue* CValue::ValueFromArray( CValueArray* value )
{
	CValue* res = new CValue;
	res->autorelease();

	res->mType = CValueTypeArray;
	res->mValue._array = value;
	res->mValue._array->retain();

	return res;
}

CValue* CValue::ValueFromDictionary( CValueDictionary* value )
{
	CValue* res = new CValue;
	res->autorelease();

	res->mType = CValueTypeDictionary;
	res->mValue._dictionary = value;
	res->mValue._dictionary->retain();

	return res;
}

CValue* CValue::ValueFromDictionary(const std::map< std::string, std::string >& value)
{
	CValueDictionary* dict = CValueDictionary::dictionary();

	std::map< std::string, std::string >::const_iterator it = value.begin();
	
    for(it; it != value.end(); it++)
	{
		CValue* val = CValue::ValueFromString(it->second);

		dict->setObject(val, it->first);
	}

	return ValueFromDictionary(dict);
}

CValue* CValue::ValueFromBuffer( CBufferReader* reader )
{
	CValue* res = new CValue;
	res->readFromBuffer(reader);
    res->autorelease();
	
	return res;
}

void CValue::readFromBuffer(CBufferReader* reader)
{
	reader->read(&mType, sizeof(mType));

	switch(mType)
	{
	case CValueTypeInt:
		reader->read(&mValue._int, sizeof(int));
		break;

	case CValueTypeFloat:
		reader->read(&mValue._float, sizeof(float));
		break;
            
    case CValueTypeLongLong:
        reader->read(&mValue._longlong, sizeof(long long));
        break;

	case CValueTypeDouble:
		reader->read(&mValue._double, sizeof(double));
		break;

	case CValueTypeString:
		{
            std::string buff;
			unsigned len = 0;
			reader->read(&len, sizeof(unsigned));
            buff.resize(len+1);
			reader->read((void*)buff.c_str(), len);
            buff[len] = '\0';
            mValue._string = new std::string(buff.c_str());
		}
		break;

	case CValueTypeArray:
		{
			unsigned count = 0;
			reader->read(&count, sizeof(unsigned));
			mValue._array = CValueArray::createWithCapacity(count);
			mValue._array->retain();

			for(unsigned i = 0; i < count; ++i)
			{
				CValue* res = new CValue;
				res->readFromBuffer(reader);
				mValue._array->addObject(res);
				res->release();
			}
		}
		break;

	case CValueTypeDictionary:
		{
			unsigned count = 0;
			reader->read(&count, sizeof(unsigned));

			mValue._dictionary = new CValueDictionary;

			char keyBuffer[256];
			for(unsigned i = 0; i < count; ++i)
			{
				unsigned len = 0;
				reader->read(&len, sizeof(unsigned));
                CCAssert(len < 255, "CValue::readFromBuffer -> Key longer then 255");
                
				reader->read(keyBuffer, len);
                keyBuffer[len] = '\0';
                
				CValue* res = new CValue;
				res->readFromBuffer(reader);
				mValue._dictionary->setObject(res, keyBuffer);
				res->release();
			}
		}
		break;
    default:
        break;
	};
}

long long CValue::toLongLong()
{
    long long res = 0;
    
    switch(mType)
	{
        case CValueTypeInt:
            res = (long long)mValue._int;
            break;
            
        case CValueTypeFloat:
            res = (long long)mValue._float;
            break;
            
        case CValueTypeLongLong:
            res = (long long)mValue._longlong;
            break;
            
        case CValueTypeDouble:
            res = (long long)mValue._double;
            break;
            
        default:
            CCAssert(0, "CValue::toLongLong() -> Can't convert to long long");
            break;
    }
    
	return res;
}

int CValue::toInt()
{    
    int res = 0;
    
    switch(mType)
	{
        case CValueTypeInt:
            res = (int)mValue._int;
            break;
            
        case CValueTypeFloat:
            res = (int)mValue._float;
            break;
            
        case CValueTypeLongLong:
            res = (int)mValue._longlong;
            break;
            
        case CValueTypeDouble:
            res = (int)mValue._double;
            break;
            
        default:
            CCAssert(0, "CValue::toInt() -> Can't convert to int");
            break;
    }
    
	return res;
}

float CValue::toFloat()
{
    float res = 0;
    
    switch(mType)
	{
        case CValueTypeInt:
            res = (float)mValue._int;
            break;
            
        case CValueTypeFloat:
            res = (float)mValue._float;
            break;
            
        case CValueTypeLongLong:
            res = (float)mValue._longlong;
            break;
            
        case CValueTypeDouble:
            res = (float)mValue._double;
            break;
            
        default:
            CCAssert(0, "CValue::toFloat() -> Can't convert to float");
            break;
    }
    
	return res;
}

double CValue::toDouble()
{
    double res = 0;
    
    switch(mType)
	{
        case CValueTypeInt:
            res = (double)mValue._int;
            break;
            
        case CValueTypeFloat:
            res = (double)mValue._float;
            break;
            
        case CValueTypeLongLong:
            res = (double)mValue._longlong;
            break;
            
        case CValueTypeDouble:
            res = (double)mValue._double;
            break;
            
        default:
            CCAssert(0, "CValue::toDouble() -> Can't convert to double");
            break;
    }
    
	return res;
}

std::string& CValue::toString()
{
    static std::string sResult;
    
    switch(mType)
	{
        case CValueTypeInt:
            sResult = utils::stringWithFormat("%d", mValue._int);
            break;
            
        case CValueTypeFloat:
            sResult = utils::stringWithFormat("%f", mValue._float);
            break;
            
        case CValueTypeLongLong:
            sResult = utils::stringWithFormat("%lld", mValue._longlong);
            break;
            
        case CValueTypeDouble:
            sResult = utils::stringWithFormat("%lf", mValue._double);
            break;
            
        case CValueTypeString:
            sResult = *(mValue._string);
            break;
        
        default:
            CCAssert(0, "CValue::toString() -> Can't convert to string");
            break;
    }
    
	return sResult;
}

CValueArray* CValue::toArray()
{
	CCAssert(mType == CValueTypeArray, "CValue::toArray() -> Wrong type");
    
    if(mType != CValueTypeArray)
        return 0;
    
	return mValue._array;
}

CValueDictionary* CValue::toDictionary()
{
	CCAssert(mType == CValueTypeDictionary, "CValue::toDictionary() -> Wrong type");
    
    if(mType != CValueTypeDictionary)
        return 0;
    
	return mValue._dictionary;
}

void CValue::saveToBuffer( CBufferWriter* writer )
{
	writer->write(&mType, sizeof(mType));

	switch(mType)
	{
	case CValueTypeInt:
		writer->write(&mValue._int, sizeof(int));
		break;

	case CValueTypeFloat:
		writer->write(&mValue._float, sizeof(float));
		break;
            
    case CValueTypeLongLong:
        writer->write(&mValue._longlong, sizeof(long long));
        break;

	case CValueTypeDouble:
		writer->write(&mValue._double, sizeof(double));
		break;

	case CValueTypeString:
		{
			unsigned len = mValue._string->size();
			writer->write(&len, sizeof(unsigned));
			writer->write(mValue._string->c_str(), len);
		}
		break;

	case CValueTypeArray:
		{
			unsigned count = mValue._array->count();
			writer->write(&count, sizeof(unsigned));
			for(unsigned i = 0; i < count; ++i)
			{
				CValue* var = dynamic_cast<CValue*>(mValue._array->objectAtIndex(i));
				CCAssert(var, "CValue::saveToBuffer( CBufferWriter* writer ) -> object is not QValue type");
				if(var)
					var->saveToBuffer(writer);
			}
		}
		break;

	case CValueTypeDictionary:
		{
			unsigned count = mValue._dictionary->count();
			writer->write(&count, sizeof(unsigned));
            
            CCDictElement* pElement = NULL;
            CCDictionary* dict = mValue._dictionary;
            CCDICT_FOREACH(dict, pElement)
            {
                std::string key = pElement->getStrKey();
                CValue* object = (CValue*)pElement->getObject();
                unsigned len = key.size();
                writer->write(&len, sizeof(unsigned));
                writer->write(key.c_str(), len);
                object->saveToBuffer(writer);
            }
		}
		break;
    default:
            TRACE("CValue bed type!!!!!")
        break;
	};
}

Json::Value CValue::jsonRepresentation()
{
    switch(mType)
	{
        case CValueTypeInt:
            return Json::Value(mValue._int);
            break;
            
        case CValueTypeFloat:
            return Json::Value(mValue._float);
            break;
            
        case CValueTypeLongLong:
            return Json::Value(mValue._longlong);
            break;
            
        case CValueTypeDouble:
            return Json::Value(mValue._double);
            break;
            
        case CValueTypeString:
            return Json::Value(mValue._string->c_str());
            break;
            
        case CValueTypeArray:
		{
			unsigned count = mValue._array->count();
			Json::Value jsonArray(Json::arrayValue);
			for(unsigned i = 0; i < count; ++i)
			{
				CValue* var = dynamic_cast<CValue*>(mValue._array->objectAtIndex(i));
				CCAssert(var, "CValue::jsonRepresentation( CBufferWriter* writer ) -> object is not QValue type");
				if(var)
                    jsonArray.append(var->jsonRepresentation());
			}
            return jsonArray;
		}
            break;
            
        case CValueTypeDictionary:
		{
            Json::Value jsonDic(Json::objectValue);
			
            
            CCDictElement* pElement = NULL;
            CCDictionary* dict = mValue._dictionary;
            CCDICT_FOREACH(dict, pElement)
            {
                std::string key = pElement->getStrKey();
                CValue* object = (CValue*)pElement->getObject();
                jsonDic[key] = object->jsonRepresentation();
            }
            
            return jsonDic;
		}
            break;
            
        default:
            return Json::Value(Json::nullValue);
            break;
	};
    
    return Json::Value(Json::nullValue);
}

std::string CValue::stringJsonRepresentation()
{
    Json::FastWriter jsonWriter;

    return jsonWriter.write(jsonRepresentation());
}

std::string CValue::stringStyledJsonRepresentation()
{
    Json::StyledWriter jsonWriter;
    
    return jsonWriter.write(jsonRepresentation());
}

void CValue::log()
{
    TRACE("%s", this->stringStyledJsonRepresentation().c_str());
}

CValue* CValue::ValueFromJson(Json::Value aObject)
{
    CValue* result = 0;

    if (aObject.type() == Json::arrayValue)
    {

        CValueArray* newArray = CValueArray::create();

        for (int i = 0; i < aObject.size(); i++)
        {
            Json::Value obj = aObject[i];
            CValue* tmp = ValueFromJson(obj);
            if (tmp)
                newArray->addObject(tmp);
        }

        result = CValue::ValueFromArray(newArray);
    }
    else if (aObject.type() == Json::objectValue)
    {
        CValueDictionary* newDic = new CValueDictionary;

        for (Json::Value::iterator it = aObject.begin(); it != aObject.end(); it++)
        {
            const char* key = it.memberName();

            CValue* tmp = ValueFromJson((*it));
            if (tmp)
                newDic->setObject(tmp, key);

        }

        result = CValue::ValueFromDictionary(newDic);
        newDic->release();
    }
    else if (aObject.type() == Json::stringValue)
    {
        std::string strTmp(aObject.asString());

        result = CValue::ValueFromString(strTmp);

    }
    else if (aObject.type() == Json::uintValue)
    {

        long long tmp = aObject.asLargestUInt();

        if (tmp < aObject.maxUInt)
        {
            result = CValue::ValueFromInt(aObject.asLargestInt());
        }
        else
        {
            result = CValue::ValueFromLongLong(tmp);
        }
    }
    else if (aObject.type() == Json::intValue)
    {
        long long tmp = aObject.asLargestInt();

        if (tmp < aObject.maxInt)
        {
            result = CValue::ValueFromInt(aObject.asLargestInt());
        }
        else
        {
            result = CValue::ValueFromLongLong(tmp);
        }

    }
    else if (aObject.type() == Json::realValue)
    {
        result = CValue::ValueFromDouble(aObject.asDouble());

    }
    else if (aObject.type() == Json::booleanValue)
    {
        result = CValue::ValueFromInt((int) aObject.asBool());

    }

    return result;
}
