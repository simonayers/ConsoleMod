# ConsoleMod
Test RISC OS module for writing console.log()-type messages

The module will have the following SWIs


##Console_GetLinesFull

This returns whether the console line buffer is full and can therefore
not receive any more lines of data.

###On entry
-

###On exit
R0 returns 1 if the line buffer is full or 0 if it is empty.



##Console_ClearLines

This empties any lines of data from the internal buffer.

###On entry
-

###On exit
-



##Console_WriteLine

This SWI writes a line of data/text to the console buffer.
The line is a zero-terminated string and the maximum length
is 255 characters + zero character.

###On entry

R0 - Pointer to the first character of a zero-terminated string
     to copy in to the buffer.  The max length of the string
     is 255 characters + 1 zero character.

###On exit

R0 - Number of bytes copied.  This will be zero if no bytes are
     copied due to the line buffer being full.



##Console_ReadLine

This SWI copies the next line of data in the line buffer into the
character buffer passed in by the caller.  If the line buffer is
empty then no characters will be copied into the caller's buffer.

###On entry

R0 - Pointer to the receiving buffer.  This must be large enough
     to receive up to 256 bytes of data.  The string written will
     be null-terminated.

###On exit

R0 - This will contain the number of characters written to the
     caller's buffer.  If the internal line buffer is empty then
     no characters are written into the caller's buffer and R0 is
     set to zero on exit.

