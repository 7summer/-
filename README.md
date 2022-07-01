# -Sport Games Management System
It will provide input,exame,write to file,read form file,find,modify,sorting  
This is my freshman year data structure course design, I will add some features according my mator guidance  

Introduction to project features
================================

<!--ts-->
   * [Input-School-Project-Data](#Input-School-Project-Data)
   * [Input-Credit-Data](#Input-Credit-Data)
<!--te-->

## Input-School-Project-Data
   - you need to use this function to record school and project data when you use this system for the first time
   
   - *In this function* you can select Input-School-Data or Input-Project-Data  

   - *Input-School-Data* 
      - you need to enter the number of school firstly
      - you will need to enter the name of the school according to the number provided by the system  

   - *Input-Project-Data*
      - First we ask about the number of Man-Project and Woman-Project
      - we need to input Man-Project-Data firstly
      - you will need to enter the name of the school according to the number provided by the system
      - What's more you will need to enter the position of project
      - Considering that man and woman have common project, we will ask you if this project is both male and female. We will show the project number if this project is both male and female

## Input-Credit-Data
   - *In main function*
      - We will show the project that have not yet been credited 
      - We can Input-Credit-Data according to the number of project or the name of project
      - Depend on user's input, the system will return the number of project in [Examine-Data](#Examine-Data) function

## Examine-Data
   - *Examine-Name-Project*
      - We will ask whether it is a male or female project
      - We will search project data for an item that maches the user data and return to the location where the project is located
   - *Examine-Number-Project*
      - We will check that the number of project entered by the user is reasonable
