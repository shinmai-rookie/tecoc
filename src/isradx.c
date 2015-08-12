/*****************************************************************************

	IsRadx()

	This function returns true if the argument is a valid digit in the
current radix.

*****************************************************************************/

#include "zport.h"		/* define portability identifiers */
#include "tecoc.h"		/* define general identifiers */
#include "defext.h"		/* define external global variables */
#include "chmacs.h"		/* define character processing macros */

bool	IsRadx(Charac)		/* is Charac in the radix set? */
unsigned char Charac;
{
	if (Charac < '0') {
		return false;
	}

	if (Charac <= '9') {
		Charac -= '0';
	} else if (Is_Lower(Charac)) {
		Charac -= ('a' - 10);
	} else if (Is_Upper(Charac)) {
		Charac -= ('A' - 10);
	} else {
		return false;
	}

	return Charac < Radix;
}
