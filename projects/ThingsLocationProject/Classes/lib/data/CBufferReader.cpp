#include "CBufferReader.h"
#include <memory.h>
#include "cocos2d.h"

CBufferReader::CBufferReader(const unsigned char* data, const unsigned int size)
:mData(data)
,mDataSize(size)
,mCurrentPos(0)
{

}

CBufferReader::~CBufferReader()
{
	
}

void CBufferReader::read( void* data, unsigned size )
{	
	if( mDataSize < mCurrentPos + size )
	{
		CCAssert(0, "void CBufferWriter::read( void* data, unsigned size ) ---> mDataSize > mCurrentPos + size  ");
		return;
	}

	memcpy(data, &mData[mCurrentPos], size);
	mCurrentPos += size;
}
