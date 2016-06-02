/*
 * tcldayspeed.c --
 *
 */

#include "dayspeed.h"

#undef TCL_STORAGE_CLASS
#define TCL_STORAGE_CLASS DLLEXPORT


/*
 *----------------------------------------------------------------------
 *
 * Dayspeed_Init --
 *
 *	Initialize the dayspeed extension.  The string "dayspeed" 
 *      in the function name must match the PACKAGE declaration at the top of
 *	configure.in.
 *
 * Results:
 *	A standard Tcl result
 *
 * Side effects:
 *
 *----------------------------------------------------------------------
 */

EXTERN int
Dayspeed_Init(Tcl_Interp *interp)
{
    /*
     * This may work with 8.0, but we are using strictly stubs here,
     * which requires 8.1.
     */
    if (Tcl_InitStubs(interp, "8.6", 0) == NULL) {
		return TCL_ERROR;
    }

	if (Itcl_InitStubs(interp, "4.0.4", 0) == NULL) {
		return TCL_ERROR;
	}

/*
	if (Itcl_Init (interp) == TCL_ERROR) {
		return TCL_ERROR;
	}
*/

    if (Tcl_PkgProvide(interp, "Dayspeed", PACKAGE_VERSION) != TCL_OK) {
		return TCL_ERROR;
    }

    int result = Itcl_RegisterObjC (interp, "c_follow_feed_async", c_follow_feed_async, NULL, NULL);

    return result;
}


/*
 *----------------------------------------------------------------------
 *
 * Dayspeed_SafeInit --
 *
 *	Initialize the dayspeed extension in a safe interpreter.
 *
 * Results:
 *	A standard Tcl result
 *
 * Side effects:
 *	Very little
 *
 *----------------------------------------------------------------------
 */

EXTERN int
Dayspeed_SafeInit(Tcl_Interp *interp)
{
    return Dayspeed_Init (interp);
}

// vim: set ts=4 sw=4 sts=4 noet :
