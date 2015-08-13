/*****************************************************************************

	RdPage()

	This function reads a page from the current input file into the
edit buffer.

*****************************************************************************/

#include "zport.h"		/* define portability identifiers */
#include "tecoc.h"		/* define general identifiers */
#include "defext.h"		/* define external global variables */
#include "deferr.h"		/* define identifiers for error messages */

integer RdPage()		/* read a page */
{
	bool EBfFul;

	DBGFEN(2,"RdPage",NULL);

/*
 * loop,  reading until end-of-file or a form feed is encountered, or the
 * edit buffer fills up
 */

	EBfFul = false;
	do {
		if (RdLine(&EBfFul) == FAILURE) {
			DBGFEX(2,DbgFNm,"FAILURE");
			return FAILURE;
		}
	} while (!IsEofI[CurInp] && !FFPage && !EBfFul);

	DBGFEX(2,DbgFNm,"SUCCESS");

	return SUCCESS;
}
