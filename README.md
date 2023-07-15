# Sport Games Management System
It will provide input,exame,write to file,read form file,find,modify,sorting  
This is my freshman year data structure course design, I will add some features according my mator guidance  
We will put the saved data file on F: for you  

Introduction to project features
================================

<!--ts-->
   * [Input-School-Project-Data](#Input-School-Project-Data)
   * [Input-Credit-Data](#Input-Credit-Data)
   * [Read-Data-From-File](#Read-Data-From-File)
   * [Input-Data-To-File](#Input-Data-To-File)
   * [Inquiry-Data](#Inquiry-Data)
   * [Modify-Data](#Modify-Data)
   * [Find-School-Sorting](#Find-School-Sorting)
<!--te-->

## Input-School-Project-Data
   - you need to use this function to record school and project data when you use this system for the first time
   
   - *In this function* you can select Input-School-Data or Input-Project-Data or Input-Project-Participating-School

   - *Input-School-Data* 
      - you need to enter the number of school firstly
      - you will need to enter the name of the school according to the number provided by the system  

   - *Input-Project-Data*
      - First we ask about the number of Man-Project and Woman-Project
      - we need to input Man-Project-Data firstly
      - you will need to enter the name of the project according to the number provided by the system
      - What's more you will need to enter the position of project
      - Considering that man and woman have common project, we will ask you if this project is both male and female. We will show the project number in Woman-Project if this project is both male and female
      
   - *Input-Participating-School*
      - User can choose to enter the participating school by entering project name or project number according to their own needs in the main function
      - First of all, we will ask the number of participating school for the project in this function
      - User can choose to enter by entering school number or shcool name according to their own needs

## Input-Credit-Data
   - *In main function*
      - We will show the project that have not yet been credited
      - We can Input-Credit-Data according to the number of project or the name of project
      - Depend on user's input, the system will return the number of project in [Examine-Project-Data](#examine-data) function
    
   - *In this function*
       - Firstly, we will not allow the credits to be entered for the project if the project don't to enter participating shcool
       - We will show the number ,name ,position and participating school of project
       - We can Input-Credit-data according to the number of school or the name of school
       - The user will be re-entered the point if the user enters a point that is greater than the previous credit

## Read-Data-From-File
   - In order to avoid conflict. We suggest to not use the function if you use the system firstly

## Input-Data-To-File
   - Please remember to save your data when you modify data
   - you can not to save data to file if you don't want to save current data

## Inquiry-Data
   - *In main function*
      - We can inquiry the number ,name ,total score ,total score of man's project and total score of woman's project of all schools
      - We can inquiry the winning school of all projects
      
   - *In this function*
      - We can inquiry the total score ,total score of man's project and total score of woman's project of the school according to entering school name or school number by user
      - We can inquiry the credit of project which the school participating
      - We can inquiry the project that the school has earned credit
      - We can inquiry the credit of a certain project in the school
      - We can inquiry the project that have been carried out or the project that have not been carried out
      - We can inquiry the participating school for each project
      
## Modify-Data
   - We can modify the name of school or project
   - We cam modify the position ,progress ,credit and participating school of project
   
## Find-School-Sorting
   - We can sort according to school number ,total score ,totao score of man's project and total score of woman's project

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

