#include "Utils.h"
#include "cocos2d.h"
#include "cocoa/CCNS.h"
#include "Log.h"
#include "AppMacros.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include <CoreFoundation/CoreFoundation.h>
#endif

USING_NS_CC;

namespace utils
{

int hash(std::string const& key)
{
	int hashVal = 0;

	int len = key.length();
	const char* bytes = key.c_str();

	for(int x = 0; x < len; ++x)
	{
		hashVal ^= (hashVal << 5) + (hashVal >> 2) + bytes[x];
	}

	if(hashVal == -1)
		hashVal <<= 2;


	return hashVal;
}

short byteToShort(unsigned const char* aByte)
{
   return ((aByte[1] << 8) | aByte[0]);
}

unsigned int byteToInt8(unsigned const char* aByte)
{
    //unsigned int val = (unsigned char)aByte[0] << CHAR_BIT | (unsigned char)aByte[1];
   
    unsigned int val = 0;
    
    for (int n = 0; n >= 0; n--)
        val = (val << 8) + aByte[ n ];
    
    return val;
}
    
int byteToInt(unsigned const char* aByte)
{
    int i = (aByte[3] << 24) | (aByte[2] << 16) | (aByte[1] << 8) | (aByte[0]);

    return i;
}
    
unsigned char* intToByte(int aValue)
{
    unsigned char* arrayOfByte = new unsigned char(4);
    for (int i = 0; i < 4; i++)
        arrayOfByte[i] = (aValue >> (i * 8));
    
    return arrayOfByte;
}

unsigned char* shortToByte(short aValue)
{
    unsigned char* arrayOfByte = new unsigned char(2);
    
    arrayOfByte[0] = ((aValue & 0xFF00) >> 8);
    arrayOfByte[1] = (aValue & 0x00FF);
    
    return arrayOfByte;
}
    
inline void split(std::string src, const char* token, std::vector<std::string>& vect)
{
    int nend=0;
    int nbegin=0;
    while(nend != -1)
    {
        nend = src.find(token, nbegin);
        if(nend == -1)
            vect.push_back(src.substr(nbegin, src.length()-nbegin));
        else
            vect.push_back(src.substr(nbegin, nend-nbegin));
        nbegin = nend + strlen(token);
    }
}
    
bool splitWithForm(const char* pStr, std::vector<std::string>& strs)
{
    bool bRet = false;
    
    do
    {
        CC_BREAK_IF(!pStr);
        
        // string is empty
        std::string content = pStr;
        CC_BREAK_IF(content.length() == 0);
        
        int nPosLeft  = content.find('{');
        int nPosRight = content.find('}');
        
        // don't have '{' and '}'
        CC_BREAK_IF(nPosLeft == (int)std::string::npos || nPosRight == (int)std::string::npos);
        // '}' is before '{'
        CC_BREAK_IF(nPosLeft > nPosRight);
        
        std::string pointStr = content.substr(nPosLeft + 1, nPosRight - nPosLeft - 1);
        // nothing between '{' and '}'
        CC_BREAK_IF(pointStr.length() == 0);
        
        int nPos1 = pointStr.find('{');
        int nPos2 = pointStr.find('}');
        // contain '{' or '}'
        CC_BREAK_IF(nPos1 != (int)std::string::npos || nPos2 != (int)std::string::npos);
        
        split(pointStr, ",", strs);
        if (strs.size() != 2 || strs[0].length() == 0 || strs[1].length() == 0)
        {
            if (strs.size() != 3 || strs[0].length() == 0 || strs[1].length() == 0 || strs[2].length() == 0)
            {
                strs.clear();
                break;
            }
        }
        
        bRet = true;
    } while (0);
    
    return bRet;
}
    
double clockTick()
{
    double result = 0;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
    result = ((double)clock() / (double)CLOCKS_PER_SEC);
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    result = CFAbsoluteTimeGetCurrent();
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    result = ((double)clock() / (double)CLOCKS_PER_SEC);
#endif
    return result;
}

double nowTime()
{
    struct timeval tm;
    gettimeofday(&tm,  0);
    double t = (double)tm.tv_sec + ((double)tm.tv_usec / 1000000.0);
    return t;
}

long long nowTimeInMs()
{
    double loc_time = utils::nowTime();
    long long local_time_in_ms = loc_time * 1000.0f;
    return local_time_in_ms;
}


ccColor3B ccColor3BFromString(const char* pszContent)
{
    cocos2d::ccColor3B ret = {0,0,0};
    
    do
    {
        std::vector<std::string> strs;
        CC_BREAK_IF(!splitWithForm(pszContent, strs));
        
        
        ret.r = (GLubyte) atof(strs[0].c_str());
        ret.g = (GLubyte) atof(strs[1].c_str());
        ret.b = (GLubyte) atof(strs[2].c_str());
        
    } while (0);
    
    return ret;
}

std::string stringWithFormat(const char * pszFormat, ...)
{
    char szBuf[1024];
    
	va_list ap;
	va_start(ap, pszFormat);
	vsprintf(szBuf, pszFormat, ap);
	va_end(ap);

	return szBuf;
}

std::string valueToString(const int aValue)
{
    char szBuf[32];
    
	sprintf(szBuf, "%i", aValue);
	return szBuf;
}

std::string valueToString(const unsigned aValue)
{
    char szBuf[32];
	sprintf(szBuf, "%u", aValue);
	return szBuf;
}

std::string valueToString(const float aValue)
{
    char szBuf[32];
	sprintf(szBuf, "%.1f", aValue);
	return szBuf;
}

std::string valueToString(const double aValue)
{
    char szBuf[32];
	sprintf(szBuf, "%.1lf", aValue);
	return szBuf;
}

std::string valueToString(const long long aValue)
{
    char szBuf[64];
	sprintf(szBuf, "%lld", aValue);
	return szBuf;
}

CCRect cutRectByRect(const CCRect& aMainRect, const CCRect& aCutRect)
{
    float mx1 = aMainRect.origin.x;
    float my1 = aMainRect.origin.y;
    
    float mx2 = aMainRect.origin.x + aMainRect.size.width;
    float my2 = aMainRect.origin.y + aMainRect.size.height;
    
    
    float cx1 = aCutRect.origin.x;
    float cy1 = aCutRect.origin.y;
    
    float cx2 = aCutRect.origin.x + aCutRect.size.width;
    float cy2 = aCutRect.origin.y + aCutRect.size.height;
    
    float rx1 = mx1 < cx1 ? cx1 : mx1;
    float rx2 = mx2 > cx2 ? cx2 : mx2;
    
    float ry1 = my1 < cy1 ? cy1 : my1;
    float ry2 = my2 > cy2 ? cy2 : my2;
    
    float w = rx2 - rx1;
    
    if(w < 0)
    {
        w = 0;
    }
    
    float h = ry2 - ry1;
    
    if(h < 0)
    {
        h = 0;
    }
    
    CCRect res(rx1,ry1, w, h);
    
    return res;
}
    
}
