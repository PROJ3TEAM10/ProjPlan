# Project 3

<h3><strong><b> Installation </b></strong></h3>

  Linux Install Instructions

    1. Download AVC_Final_Linux.zip from the Releases Folder of the github
	- https://github.com/PROJ3TEAM10/Project-3-avc-team10/tree/master/Release
    2. Unzip the archive into your home user folder
       - you can unzip the archive into a different location however there will be an extra step later
    3. If it is not installed/pre installed on your system, install GCC (GNU Compiler Collection)
       - This can probably be found in your package manager
       - Open a console
       - For Manjaro/Arch Linux: run the command “sudo pacman -Sy gcc”
       - For Ubuntu/Debian/Mint: run the command “sudo apt update” then “sudo apt install gcc”
       - You can check if installed using the command “gcc --version”
    4. If it is not installed/pre installed on your system, install Make
       - This can probably also be found in your package manager
       - Open a console
       - For Manjaro/Arch Linux: run the command “sudo pacman -Sy make”
       - For Ubuntu/Debian/Mint run the command  “sudo apt update” then “sudo apt install make”
    5. A note for Ubuntu/Debian/Mint users
        - You Should be able to use “sudo apt install build-essential” to install both GCC and Make
    6. In both the AVC_Robot folder and AVC_Sever folder edit the file in a text editor named “makefile”.
       - If you extracted the zip into your user folder then skip this step.
       - find “SFML = ${HOME}/AVC/SFML-2.5.1” then change ${HOME} to the directory you extracted the zip to.
       
    7. Build the AVC Server
       - Run a terminal with the active directory being the AVC_Server folder and run the command “make server3”
    8. Build the AVC Robot
       - Run a terminal with the active directory being the AVC_Robot folder and run the command “make robot”
    9. Run the Server
       In the AVC_Server folder run ‘server3’
    10.  Run the Robot
	In a terminal with the active directory being the AVC_Robot folder run the command “./robot”

<h3><strong><b> Team 10 Members & contact info: </b></strong></h3>

Sophie Banks: email - sophie.h.banks@gmail.com, discord - boringNectarine#1834

Mehma Siddiqui: email - mehma739@gmail.com, discord - mehma739#2175

Nicole Ngata: email - nicolengata1421@gmail.com, discord - Nicole#1784 

Nathanael Graham: email - atomictempest@tutamail.com, discord - AtomicTempest#8114

<h3><strong><b> Communication tool: </b></strong></h3>

<b>Discord:</b> https://discord.gg/MwWsps 

<b>GitHub:</b> https://github.com/PROJ3TEAM10/

<h2><strong><b> Roles:</b></strong></h2>

<b>Sophie</b> - Project Manager (organising team meetings, reporting regularly on progress, debugging)

<b>Nicole</b>- Software Architect (writing initial core code).  Decides what methods/classes are needed and how they communicate.

<b>Nathanael</b> - Software writing, testing and documentation (debugging software and committing to git, writing test cases and documenting performance against milestones)

<b>Mehma</b> - Software writing, testing and documentation (debugging software and committing to git, writing test cases and documenting performance against milestones)

<h1><strong><b>MILESTONE 1</b></strong></h1>

<b>DATE</b> - 29th May

<b>Objectives</b> - Plan Project and ensure software works for entire team using the testing code provided

<b>Due</b> - Plan due under readme by Thurs 4 June 

<b>Conflicts:</b>  

(all)102/112 Assig 

(soph)PHYS lab 

<strong>PLEASE ADD YOUR CONFLICTS HERE</strong>

<b>Tasks:</b>

<b>All</b> - Complete AVC plan

<b>Nat</b> - Tests all installations. Write test cases for the team

<b>Soph</b> - Ensures plan is done and sets up meeting to discuss plan

<b>Nicole</b> - looks into libraries and SFML, writes installation instructions on README for windows as whole team has windows devices
although Nat may use Linux?

<b>Mehma</b> - Screenshots of robot programme running + from robot view virtual camera, added to documentation

<h1><strong><b>MILESTONE 2</b></strong></h1>

<b>Start date</b> - 4th June

<b>Objectives</b> 

- Core and (most of) Completion code done
- Progress documented appropriately on git

<b>Due</b> 
- Core done by 11th June
- Progress documentation checked on 12th June

<b>Conflicts:</b>  

(all) 102/112 Assig 

(soph) algebra test

<strong>PLEASE ADD YOUR CONFLICTS HERE</strong>

<b>Tasks:</b>

<b>All</b>

- Write code so robot moves through core + completion maze, and have discussed and implemented necessary changes

- attend meetings and disc stream when coding for live team input, if other members are free

- Intro & Background for progress report started 

- Ensures individual log and team logs are comprehensive

<b>Nat</b> – ensures completion code is started, checks that github log is up to date, writes small methods as needed by Nicole

<b>Soph</b> - Debugs, writes foundation of the report, plans meetings for following week, fills in outline of github log

<b>Nicole</b> – Ensures core code is started by the 6th, finished by the 11th, has checked with group and recieved and implemented methods written by others

<b>Mehma</b> - Checks code for core enables robot to complete circuit, debug/fix if necessary, writes small methods as needed by Nicole

<h1><strong><b>MILESTONE 3</b></strong></h1>

<b>Start date</b> - 11th June

<b>Objectives</b> 

- All code
- Progress documented appropriately on git

<b>Due</b> 
- Code completed and on git by Weds 17th June
- Code submitted by Fri 19th
- Progress documentation checked on 19th June

<b>Conflicts:</b>  

(all) 102/112 Assig 

<strong>PLEASE ADD YOUR CONFLICTS HERE</strong>

<b>Tasks:</b>

<b>All</b>

- Write code so robot moves through all core completion and challenge mazes and have discussed and implemented necessary changes
- attend meetings and disc stream when coding for live team input, if other members are free
- Bulk of report completed 
- Ensures individual log and team logs are comprehensive and up to date

<b>Nat</b> – helps brainstorm challenge and write methods some methods as needed

<b>Soph</b> - Debugs, edits report, plans meetings for following week, fills in bulk of log, writes methods as needed

<b>Nicole</b> – Brainstorms, outlines possible challenge methods, checked with group and recieved and implemented methods written by others

<b>Mehma</b> - Checks code enables robot to complete circuit in all situations, debug/fix if necessary, writes small methods as needed

<h1><strong><b>MILESTONE 4</b></strong></h1>


<b>Start date</b> - 20th June

<b>Objectives</b> - Reports and logs Completed

<b>Due</b> - 24th june

<b>Conflicts:</b>  

(all) 102/112 Assig 

<strong>PLEASE ADD YOUR CONFLICTS HERE</strong>

<b>Tasks:</b>

<b>All</b>

- Contribute and check report is done, read over and check that all are happy with it

- Ensures individual log and team logs are completed

<b>Nat</b> – Add screenshots to report 

<b>Soph</b> - Edit report & check that report is submitted

<b>Nicole</b> – Check that what is documented is the same as github 

<b>Mehma</b> -  Formatting of report for readability					

<h2>Weekly Discord Meeting Times</h2>

-	Wednesday 11am 

-	Friday 3pm 

