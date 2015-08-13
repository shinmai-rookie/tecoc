/*****************************************************************************

	TAbort()

	This function cleans up and terminates TECO-C.

*****************************************************************************/

#include "zport.h"		/* define portability identifiers */
#include "tecoc.h"		/* define general identifiers */


void TAbort(tstat)		/* terminate TECO-C */
integer tstat;
{
	DBGFEN(2,"TAbort",NULL);

	ClenUp();			/* close files, memory, etc. */
	ZExit(tstat);			/* terminate with given status */
}
