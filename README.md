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
      - Lastly, you need to enter the participating school name or school number for the project also
      - Considering that man and woman have common project, we will ask you if this project is both male and female. We will show the project number in Woman-Project if this project is both male and female. Also consider whether the participating school are the same

## Input-Credit-Data
   - *In main function*
      - We will show the project that have not yet been credited
      - We can Input-Credit-Data according to the number of project or the name of project
      - Depend on user's input, the system will return the number of project in [Examine-Project-Data](#examine-data) function
    
   - *In this function*
       - We will show the number ,name ,position and participating school of project
       - We can Input-Credit-data according to the number of school or the name of school
       - Depend on user's input, the system will return the number of school in [Examine-School-Data](#examine-data) function
       - Depend on user's input, we will determine whether the school number entered by the user is reasonable in the [Examine-Participating-School](#examine-data) function
       - The user will be re-entered the point if the user enters a point that is greater than the previous credit

## Read-Data-From-File
   - In order to avoid conflict. We suggest to not use the function if you use the system firstly

## Input-Data-To-File
   - Please remember to save your data when you modify data
   - you can not to save data to file if you don't want to save current data

##

## Examine-Data
   - *Examine-Name-Project*
      - We will ask whether it is a male or female project
      - We will search project data for an item that maches the user's data and return to the location where the project is located
      
   - *Examine-Number-Project*
      - We will check that the number of project entered by the user is reasonable
      
   - *Examine-Name-School*
      - We will search project data for an school that maches the user's data and return to the location where the project is located
      
   - *Examine-Number-School*
      - We will search school data for an shool that maches the user's data and return to the locating where the school is located
   
   - *Examine-Participating-School*
      - Depend on Examine-Name-School function or Exame-Number-School function, we will checked that the participating school number for the project matched the one entered by the user

