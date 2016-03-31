# PAM_Dialogue
PAM modules and libraries to make it easier to make login prompts more interactive.

#Introduction
PAM (Pluggable Authentication Modules) is a *nix application that allows administrators
to control access to resources on their machine or network using a framework that allows
you to stack modules that handle your access differently depending on the results of the
requesting user/service against each module. PAM is used for a lot of applications as a
default.

#Installing

**install the pam-dev libraries**

`apt-get update                               `

`apt-get install build-essential libpam0g-dev `

**Using the libraries**

 download the header files and add them to your path

**Compiling the example modules**

`gcc -fPIC -c my_pam.c`

`ld -x --shared -o /lib/security/mypam.so 2ndfactor.o `

#To Do

1:create the dialog interface with the conversation function

2:add links to module writing guides

3:example modules
