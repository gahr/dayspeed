/* 
 * dayspeed.h -- flightaware tcl speedup stuff
 *
 */

#include <tcl.h>
#include <tclOO.h>
#include <itclInt.h>

extern const ItclStubs *itclStubsPtr;

extern int
c_follow_feed_async (ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const *objv);
