/* 
 * dayspeed.c --
 *
 * $Id$
 */

#include <string.h>
#include "dayspeed.h"

int
c_follow_feed_async (ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const *objv) {
    Tcl_Namespace *nsPtr;
    ItclObjectInfo * infoPtr = NULL;
    ItclClass *iclsPtr = NULL;
    ItclClass * classPtr;
    FOREACH_HASH_DECLS;
    int i;

    ItclShowArgs(0, "cObjFunc called", objc, objv);
fprintf(stderr, "objv: %d %p\n", objc, objv);
for(i = 0; i<objc;i++) {
    fprintf(stderr, "arg:%d:%s:\n", i, Tcl_GetString(objv[i]));
}
    nsPtr = Tcl_GetCurrentNamespace(interp);
fprintf(stderr, "IP:%p %p %p !%s!\n",interp, clientData, nsPtr, nsPtr->fullName);
    infoPtr = (ClientData)Tcl_GetAssocData(interp, ITCL_INTERP_DATA, NULL);
    FOREACH_HASH_VALUE(classPtr,&infoPtr->nameClasses) {
        if (strcmp(Tcl_GetString(objv[1]), Tcl_GetString(classPtr->fullNamePtr)) == 0 ||
                strcmp(Tcl_GetString(objv[2]), Tcl_GetString(classPtr->fullNamePtr)) == 0) {
           iclsPtr = classPtr;
       break;
        }
    }
fprintf(stderr, "IP2:%p %p %p\n",interp, clientData, iclsPtr);
    return TCL_OK;
}




// vim: set ts=4 sw=4 sts=4 noet :
