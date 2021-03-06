#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<security/pam_modules.h>
#include<security/pam_appl.h>

int pam_dailog(int flags,pam_handle_t *pamh, int nargs,char *question,char *answer){
int retval;
char *input;
struct pam_conv *conv; //gonna need access to a conversation item for the data we will be using in this module
struct pam_message msg[1];
const struct pam_message *pmsg[1];
struct pam_response *resp;

pmsg[0] = &msg[0];
msg[0].msg_style = PAM_PROMPT_ECHO_ON; // messages from the conversation will be echoed out to the screen
msg[0].msg = question;
resp = NULL;//have an empty response at the start of each call to this function


retval = pam_get_item(pamh, PAM_CONV, (const void**) &conv); //populate the handle with data relavant to the application calling this .so

 if(retval==PAM_SUCCESS) //if the shit worked and the pam_conv is populated, then let's also fill the message and response arrays
 {
        retval = conv->conv(1,pmsg,&resp,conv->appdata_ptr);
 }

if(resp)
{
 if( (flags & PAM_DISALLOW_NULL_AUTHTOK) && resp[0].resp == NULL )
 {
  free( resp );
  return PAM_AUTH_ERR;
 }
 input = resp[ 0 ].resp;
 resp[ 0 ].resp= NULL;
}

/* comparing user input with answer*/
if(strcmp(input,answer)==0)
{
 /* good to go! */
 free( answer ) ;
 return PAM_SUCCESS ;
}
else
{
 /* wrong code */
 free( answer ) ;
 return PAM_AUTH_ERR ;
}

return retval;
}

