//---------------------------------------------------------------------------
//
// Very naive circular buffer of lines of text
//
//---------------------------------------------------------------------------
#include <stdio.h>
#include "circularbuf.h"
//---------------------------------------------------------------------------

void CircularLineBuffer_initialiseBuffer(CircularLineBuffer * buffer)
{
   buffer->front = 0;
   buffer->back = 0;
   buffer->numOfLines = 0;
}

size_t CircularLineBuffer_getCurrentNumOfLines(const CircularLineBuffer * const buffer)
{
   return buffer->numOfLines;
}

size_t CircularLineBuffer_writeNextLine(const char * const line, CircularLineBuffer * const buffer)
{
   const size_t BUFFER_FULL_OR_ERROR = 0;
   const size_t ONE_LINE_WRITTEN = 0;

   if (CircularLineBuffer_getCurrentNumOfLines(buffer) >= CIRCULAR_LINE_BUFFER__NUM_OF_LINES) {
      return BUFFER_FULL_OR_ERROR;
   }

   snprintf((char *)buffer->buffer[buffer->front], CIRCULAR_LINE_BUFFER__CHRS_PER_LINE, "%s", line);

   buffer->front++;

   if (buffer->front == CIRCULAR_LINE_BUFFER__NUM_OF_LINES) {
      buffer->front = 0;
   }

   buffer->numOfLines++;

   return ONE_LINE_WRITTEN;
}

const char * CircularLineBuffer_readNextLine(CircularLineBuffer * const buffer)
{
   const char * const nextLine = (const char*)buffer->buffer[buffer->back];

   if (!CircularLineBuffer_getCurrentNumOfLines(buffer)) {
      return NULL;
   }

   buffer->back++;

   if (buffer->back == CIRCULAR_LINE_BUFFER__NUM_OF_LINES) {
      buffer->back = 0;
   }

   buffer->numOfLines--;

   return nextLine;
}
