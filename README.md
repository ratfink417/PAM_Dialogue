# PAM_Dialogue
PAM modules and libraries to make it easier to make login prompts more interactive.

#Introduction
PAM (Pluggable Authentication Modules) is a *nix application that allows administrators
to control access to resources on their machine or network using a framework that allows
you to stack modules that handle your access differently depending on the results of the
requesting user/service against each module. PAM is used for a lot of applications as a
default.

#Configuration

**install the pam-dev libraries**

`apt-get update                               `

`apt-get install build-essential libpam0g-dev `

#Using the libraries

 download the header files and add them to your path, include it in your next pam module
 call dialog function in your module and base your pam config on how a correct or wrong answer to the question asked
 by the dialog should be processed.

#To Do

1:add links to module writing guides

2:create a debug branch

3:write a configure script that installs libpam and essentials if needed
