#include "CBufferWriter.h"
#include <string.h>
#include <stdlib.h>

const unsigned DEFAULT_INITIAL_BUFF_SIZE = 1024 * 50;
const unsigned INCREMENTAL_PICE = 1024 * 50;

CBufferWriter::CBufferWriter()
:mData(0)
{
	createData(DEFAULT_INITIAL_BUFF_SIZE);
}

CBufferWriter::CBufferWriter( unsigned int initialSize )
:mData(0)
{
	createData(initialSize);
}

CBufferWriter::~CBufferWriter()
{
	clearData();
}

void CBufferWriter::write( const void* data, unsigned size )
{
	while( (mCurrentPos + size) > mDataSize  )
	{
		mDataSize += INCREMENTAL_PICE;
		mData = (unsigned char*)realloc(mData, mDataSize);
	}

	memcpy(&mData[mCurrentPos], data, size);
	mCurrentPos += size;
}

void CBufferWriter::createData( unsigned int size )
{
	clearData();

	mDataSize = size;
	if( mDataSize <= 0 )
		return;

	mData = (unsigned char*)malloc( size * sizeof(unsigned char));
}

void CBufferWriter::clearData()
{
	if ( mData )
	{
		free(mData);
		mData = 0;
	}

	mCurrentPos = 0;
	mDataSize = 0;
}
