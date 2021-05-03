//---------------------------------------------------------------------------
//
// Very naive circular buffer of lines of text
//
//---------------------------------------------------------------------------
#ifndef circularbufH
#define circularbufH
//---------------------------------------------------------------------------
#include <stddef.h>
//---------------------------------------------------------------------------

#define CIRCULAR_LINE_BUFFER__NUM_OF_LINES 16
#define CIRCULAR_LINE_BUFFER__CHRS_PER_LINE 256

typedef volatile struct {
   size_t front;
   size_t back;
   size_t numOfLines;
   char buffer[CIRCULAR_LINE_BUFFER__NUM_OF_LINES][CIRCULAR_LINE_BUFFER__CHRS_PER_LINE];
} CircularLineBuffer;

void CircularLineBuffer_initialiseBuffer(CircularLineBuffer * buffer);
size_t CircularLineBuffer_getCurrentNumOfLines(const CircularLineBuffer * const buffer);
size_t CircularLineBuffer_writeNextLine(const char * const line, CircularLineBuffer * const buffer);
const char * CircularLineBuffer_readNextLine(CircularLineBuffer * const buffer);

//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------