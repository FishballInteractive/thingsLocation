
#include "ExtensionUtils_ios.h"
#include "CValue.h"
#include "Log.h"
#include "Utils.h"

id EUNSObjectFromCValue( CValue* aObject )
{
    id result = 0;

    if( aObject->type() == CValue::CValueTypeArray )
    {
        NSMutableArray* newArray = [[NSMutableArray alloc] autorelease];
        
        for(int i = 0; i < aObject->toArray()->count(); i++)
        {
            CValue* obj = dynamic_cast<CValue*>(aObject->toArray()->objectAtIndex(i));
            
            if(obj)
            {
                id tmp = EUNSObjectFromCValue(obj);
                
                if(tmp)
                {
                    [newArray addObject:tmp];
                }
            }
            
        }
        
        result = newArray;
    }
    else if ( aObject->type() == CValue::CValueTypeDictionary )
    {
        NSDictionary* newDic = [[NSDictionary alloc] autorelease];
        cocos2d::CCArray* all_keys = aObject->toDictionary()->allKeys();
        
        for(int i = 0; i < all_keys->count(); i++)
        {
            cocos2d::CCString* key = dynamic_cast<CCString*>(all_keys->objectAtIndex(i));
            CValue* obj = dynamic_cast<CValue*>(aObject->toDictionary()->objectForKey(key->getCString()));
            
            if(obj)
            {
                id tmp = EUNSObjectFromCValue(obj);
                
                if(tmp)
                {
                    NSString* nskey = [NSString stringWithUTF8String:key->getCString()];
                    [newDic setValue:tmp forKey:nskey];
                }
            }
        }
        
        result = newDic;
    }
    else if ( aObject->type() == CValue::CValueTypeString )
    {
        NSString* str = [NSString stringWithUTF8String:aObject->toString().c_str()];
        result = str;
    }
    else if(aObject->type() == CValue::CValueTypeInt)
    {
        NSNumber* tmp = [NSNumber numberWithInt: aObject->toInt()];
        result = tmp;
    }
    else if ( aObject->type() == CValue::CValueTypeFloat )
    {
        NSNumber* tmp = [NSNumber numberWithFloat: aObject->toFloat()];
        result = tmp;
    }
    else if ( aObject->type() == CValue::CValueTypeDouble )
    {
        NSNumber* tmp = [NSNumber numberWithDouble: aObject->toDouble()];
        result = tmp;
    }
    
    return result;

}

CValue* EUValueFromNSObject( id aObject )
{
    CValue* result = 0;
    
    if( [aObject isKindOfClass:[NSArray class]] )
    {
        CValueArray* newArray = CValueArray::create();
        
        for (id obj in aObject)
        {
            CValue* tmp = EUValueFromNSObject(obj);
            if(tmp)
                newArray->addObject(tmp);
        }
        
        result = CValue::ValueFromArray(newArray);
    }
    else if ( [aObject isKindOfClass:[NSDictionary class]] )
    {
        CValueDictionary* newDic = new CValueDictionary;
        
        [aObject  enumerateKeysAndObjectsUsingBlock:^(id key, id object, BOOL *stop) {
            
            CValue* tmp = EUValueFromNSObject(object);
            if(tmp)
                newDic->setObject(tmp, [key UTF8String]);
            
        }];
        
        result = CValue::ValueFromDictionary(newDic);
        newDic->release();
    }
    else if ( [aObject isKindOfClass:[NSString class]] )
    {
        std::string str = [aObject UTF8String];
        result = CValue::ValueFromString( str );
    }
    else if ( [aObject isKindOfClass:[NSDecimalNumber class]] )
    {
        std::string str = [[aObject stringValue] UTF8String];
        result = CValue::ValueFromString( str );
    }
    else if ( [aObject isKindOfClass:[NSNumber class]] )
    {
        CFNumberType numberType = CFNumberGetType((CFNumberRef)aObject);
        
        switch (numberType) {
            case kCFNumberSInt8Type:
            case kCFNumberSInt16Type:
            case kCFNumberSInt32Type:
            case kCFNumberCharType:
            case kCFNumberShortType:
            case kCFNumberIntType:
            case kCFNumberLongType:
                
                result = CValue::ValueFromInt([aObject intValue]);
                
                break;
                
            case kCFNumberSInt64Type:
            case kCFNumberLongLongType:
            {
                long long value = [aObject longLongValue];
                
                result = CValue::ValueFromLongLong(value);
            }
                break;
                
            case kCFNumberFloat32Type:
            case kCFNumberFloatType:
                
                result = CValue::ValueFromFloat([aObject floatValue]);
                
                break;
                
            case kCFNumberFloat64Type:
            case kCFNumberDoubleType:
                
                result = CValue::ValueFromDouble([aObject doubleValue]);
                
                break;
                
            default:
                
                TRACE("UNDEFINED TYPE %d", numberType)
                
                break;
        }
    }
    
    return result;
}
