
#define GAME_DEBUG_LOG

#ifdef GAME_DEBUG_LOG

#include <typeinfo>
#include "cocos2d.h"
#include "ILogable.h"

#ifdef _MSC_VER

#define TRACE(msg, ...) \
{\
	char* str = (char*)malloc( cocos2d::kMaxLogLen );\
	strcpy_s(str, cocos2d::kMaxLogLen, "GAME: ");\
	strcat_s(str, cocos2d::kMaxLogLen, msg);\
	cocos2d::CCLog(str, ##__VA_ARGS__);\
    free(str);\
}

#else

#define TRACE(msg, ...) \
{\
	char* str = (char*)malloc( cocos2d::kMaxLogLen ); \
	strcpy (str,"GAME: ");\
	strcat (str, msg);\
	cocos2d::CCLog(str, ##__VA_ARGS__);\
    free(str);\
}

#endif


#define TRACE_OBJECT(x) \
{ \
    ILogable* logable = dynamic_cast<ILogable*>(x); \
    if(logable) \
    { \
        cocos2d::CCLog("");\
        cocos2d::CCLog("GAME: %s->log()", #x );\
        logable->log(); \
        cocos2d::CCLog(""); \
    } \
}\
//
#define TRACE_ALLOC cocos2d::CCLog("GAME: constructor: %s", typeid(this).name());
#define TRACE_DEALLOC cocos2d::CCLog("GAME: destructor: %s", typeid(this).name());

#define TRACE_METHOD cocos2d::CCLog("GAME: func call: %s::%s <%x>", typeid(this).name() , __func__, this);
#define TRACE_VAR_INT(x) cocos2d::CCLog("GAME: %s = %d", #x ,x );
#define TRACE_VAR_LONGLONG(x) cocos2d::CCLog("GAME: %s = %lld", #x ,x );
#define TRACE_VAR_STR(x) cocos2d::CCLog("GAME: %s = %s", #x ,x );
#define TRACE_VAR_FLOAT(x) cocos2d::CCLog("GAME: %s = %f", #x ,x );
#define TRACE_VAR_RECT(rect) cocos2d::CCLog( "GAME: %s = {{%g,%g},{%g,%g}}", #rect, rect.origin.x, rect.origin.y, rect.size.width, rect.size.height );
#define TRACE_VAR_POINT(point) cocos2d::CCLog("GAME: %s = {%g,%g}", #point , point.x, point.y );
#define TRACE_VAR_SIZE(size) cocos2d::CCLog("GAME: %s = {%g,%g}", #size , size.width, size.height);

#define BEGIN_PROFILE_TIME(sec_name) { double _____start_time = utils::clockTick(); std::string __section_name = sec_name;
#define END_PROFILE_TIME()  TRACE("%s time:%lf", __section_name.c_str(), (utils::clockTick() - _____start_time) ) }


#else

#define TRACE(...)
#define TRACE_OBJECT(x)
#define TRACE_DEALLOC

#define BEGIN_PROFILE_TIME(sec_name)
#define END_PROFILE_TIME()
#define TRACE_METHOD
#define TRACE_ALLOC
#define TRACE_VAR_INT(x) 
#define TRACE_VAR_LONGLONG(x)
#define TRACE_VAR_STR(x)
#define TRACE_VAR_FLOAT(x) 
#define TRACE_VAR_RECT(rect) 
#define TRACE_VAR_POINT(point)
#define TRACE_VAR_SIZE(size)


#endif




