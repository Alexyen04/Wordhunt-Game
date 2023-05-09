[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10951477&assignment_repo_type=AssignmentRepo)

# Modded Word Hunt

> Authors: [Alex Yen](https://github.com/Alexyen04) [Freddy Song](https://github.com/MrFrooty) [Michael Chen](https://github.com/mchen04) [Sazen Shakya](https://github.com/sshakya03)

## Project Description
### Purpose
Our project is a modified version of a word hunt game implemented in C++ to create a satisfying experience for all levels of players. The objective of the game is to find all the words hidden in a grid of random letters. The words can be placed horizontally, vertically, or diagonally and in both forward and backward directions. The game is popular for word puzzle enthusiasts and is commonly played on the app GamePigeon. 

### Importance/Significance
We were drawn to this project due to its engaging and thought-provoking nature, which blends language skills and logical reasoning. As avid players of this game for several years, we recognized its popularity and complexity, yet noticed a lack of user control and basic features in existing Word Hunt applications. Our goal was to develop a program that caters to fellow Word Hunt enthusiasts, while also providing the flexibility to simplify the game for beginners.

### Languages, Tools, and Technologies
* **C++**
   * The backend of the project
* **CMake**
   * Linux tool which allows us to compile C++ code into executable programs 
* **Git**
   * This version control system will be used to track changes to the project codebase and facilitate collaboration among team members
* **Microsoft Visual Studio Code**
   * This will be the integrated development environment (IDE) used by all project members for editing and debugging code
* **Ncurses**
   * This library will be used to create text-based user interfaces within a terminal environment, making it a suitable choice for implementing the user interface of the word hunt game
* **Valgrind**
   * Linux tool to detects errors and memory management issues including memory leaks

### Input/Output
The game input is a customizable grid of letters, with parameters like dimensions, time limit, and word length specified by the user. Features like custom word lists, power-ups, and score multipliers make the game challenging and exciting. The game's output includes the game board, timer, and score, along with immediate feedback on word selection and progress tracking. The output is highly interactive and engaging, providing a personalized and addictive gaming experience for all players.

### Added Features
* **Customization**
    * Choose the dimensions of the game board
    * Only Allowing Certain Length Words
    * Setting timer
    * Custom word lists
* **Challenge**
    * Score multiplier
    * Power-ups
* **Enhancements**
    * Hint system
    * Custom Sound effects

## User Interface Specification

### Navigation Diagram
![Navigation Diagram](https://github.com/cs100/final-project-fsong009-mchen356-ayen019-sshak015/blob/1f12729eee9c3d89ce5278ec466aca401d6be23c/Navigation_Diagram.png)
The main purpose of this navigational diagram is to provide a visual map of the user's journey through the game. There consists of multiple screens, with lines showing how to move between them. The contents of each screen are listed in each rectangle. 

### Screen Layouts
![Screen Layout Diagram](https://github.com/cs100/final-project-fsong009-mchen356-ayen019-sshak015/blob/9c7fb67238540d7e6033ec9ce54fd0e0f603e365/SCREEN_LAYOUT.png)
* Menu Screen (Top-Left) has buttons which allow one to play or access the settings screen
* Settings Screen (Top-Right) has buttons and input boxes which allow one to change various settings. Has a return button to go back to Menu Screen.
* Word Hunt Screen (Bottom-Left) has the game board where user will play
* Score Screen (Bottom-Right) has user total score and a list of words with their point values. Has two buttons, one to return to the Menu screen and one to quit the applicaiton


## Class Diagram
![UML Class Diagram](https://github.com/cs100/final-project-fsong009-mchen356-ayen019-sshak015/blob/9d57500334373082892e32a1b3661abc9e8ec1ea/UML_DIAGRAM.png)
The UML Class diagram represents the main components of the Word Hunt game, including the Word Hunt Board and Settings. The Word Hunt Board connects to other important aspects of the game, such as the Dictionary and Scoreboard. Meanwhile, the Settings class offers a range of customizable features that can affect different parts of the game.

For example, settings related to the creation of the board (such as dimensions) are passed to the Word Hunt Board class, while settings related to the Dictionary and Scoreboard (such as custom words and score multipliers) are passed to those respective classes. The Settings class serves as a central hub for managing and applying these settings across the game.

Overall, the UML Class diagram provides a clear visualization of the key classes and their relationships within the Word Hunt game.
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
