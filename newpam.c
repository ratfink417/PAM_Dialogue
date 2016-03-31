#include "dialog.h"

/* expected hook */
PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) {
        return PAM_SUCCESS;
}

/* customized portion*/
PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) {
return pam_dailog(flags,pamh,1,"how many letters in the word derp: ","derp");
}
