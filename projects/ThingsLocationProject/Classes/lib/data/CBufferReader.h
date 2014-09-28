#ifndef __CBufferReader_H__
#define __CBufferReader_H__

class CBufferReader
{
public:
	CBufferReader(const unsigned char* data, const unsigned int size);
	virtual ~CBufferReader();

	void read(void* data, unsigned size);
	
protected:
	const unsigned char* mData;
	unsigned int mCurrentPos;
	const unsigned int mDataSize;
};

#endif //__CBUFFER_H__