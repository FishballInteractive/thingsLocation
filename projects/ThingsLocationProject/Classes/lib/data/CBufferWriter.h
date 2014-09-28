#ifndef __CBufferWriter_H__
#define __CBufferWriter_H__

class CBufferWriter
{
public:
	CBufferWriter();
	CBufferWriter(unsigned int initialSize);
	virtual ~CBufferWriter();

	void write(const void* data, unsigned size);
	
	inline const unsigned char* getData() { return mData; }
	inline unsigned int getCurrentPos() { return mCurrentPos; }

protected:
	void createData(unsigned int size);
	void clearData();

	unsigned char* mData;
	unsigned int mCurrentPos;
	unsigned int mDataSize;
};

#endif //__CBUFFER_H__