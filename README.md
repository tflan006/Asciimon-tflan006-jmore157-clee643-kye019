
# ASCIIMON

 
 > Authors: [Timothy Flannery](https://github.com/tflan006), [Joshua Moreno](https://github.com/jman0x0), [Cody Lee](https://github.com/clee643), [Kevin Ye](https://github.com/kye019)

 

## Project Description
 Text based Pokémon style game. Player will pick between 3 types of Asciimon at the beginning to use to fight with. Each asciimon has a different type such as fire, water, and air with different effectiveness based on types used as well as a leveling system to unlock different moves. The user will fight against both ASCIIMON trainers and wild ASCIIMON. They will also have the chance to catch the wild ASCIIMON. The game will use C++ and ascii art and all will be displayed in the terminal.

>Features:
>
> -Player can catch various types of ASCIIMON to use in battle
>
> -Player will be able to fight wild ASCIIMON and 3 main ASCIIMON trainers
>
> -Leveling system for ASCIIMON which allows the ASCIIMON to unlock new attacks
>
> -ASCIIMON will have different stats and types.

>The players input will all be typed actions to make decisions such as:
>
>-Deciding to fight the next ASCIIMON trainer or a wild ASCIIMON
>
>-Which attacks to use in combat
>
>-Attempting to catch wild ASCIIMON

>The output of the game will include text in the terminal for:
>
>-A main terminal to prompt the users decision to fight a trainer or wild ASCIIMON
>
>-In combat the names and health of the ASCIIMON will be displayed
>
>-Lists of the users available ASCIIMON
>
>-Lists the current ASCIIMONs attacks


### Navigation Diagram
> Draw a diagram illustrating how the user can navigate from one screen to another. Here is an [example](https://creately.com/diagram/example/ikfqudv82/user-navigation-diagram-classic?r=v). It can be useful to label each symbol that represents a screen so that you can reference the screens in the next section or the rest of the document if necessary. Give a brief description of what the diagram represents.

![map](https://github.com/cs100/final-project-tflan006-jmore157-clee643-kye019/assets/117532660/2e8b0f78-6d91-440e-bfb9-ce706cd5120f)
Description:

>The Navigation Diagram represents the flow of the game. It describes the possible outcomes that a player will experience based on their performance and the options the players can choose to determine gameplay changes. More concretely, from the start of the game we will immediately be given the choice to choose from a set of three starting Asciimon. After a selection is made, the terminal is used to prompt the user with a choice to battle an Asciimon or a Trainer. The battle for a trainer or Asciimon is similar in that losing the battle results in losing the game. However, when fighting an Asciimon the player will have the opportunity to catch whatever Asciimon they are facing. Upon victory in a Trainer/Asciimon battle the game loops back to the terminal and prompts once again. Eventually a final battle with a trainer will occur which will determine victory or ultimate loss.

### Screen Layouts
<img src="https://github.com/cs100/final-project-tflan006-jmore157-clee643-kye019/assets/166083437/27645392-a154-4e67-ba42-2c348540950e" width="500">

>Start Screen:
>The game will begin in the start screen where the user will be introduced to the story then the user is prompted to input their name then will select a starting Asciimon from the list given by typing the name of the Asciimon.

<img src="https://github.com/cs100/final-project-tflan006-jmore157-clee643-kye019/assets/166083437/da297356-a2de-4a38-9c76-506fb65ad8bb" width="300">

>Terminal:
>User is prompted to select whether they want to enter a fight, view a list of Asciimon, or quit the game. These actions are selected by typing 1, 2, or 3.

<img src="https://github.com/cs100/final-project-tflan006-jmore157-clee643-kye019/assets/166083437/ee613acf-3bc5-49ff-a861-f7f2d547a90a" width="300">

>Asciimon List:
>Lists out the Asciimon that the player has.

<img src="https://github.com/cs100/final-project-tflan006-jmore157-clee643-kye019/assets/166083437/6205ad29-f234-45a4-a688-bb93df637d8d" width="300">

> Asciimon Caught Screen:
> After the player successfully catches the Asciimon the information about the Asciimon is displayed to the user and the user is allowed to continue.

<img src="https://github.com/cs100/final-project-tflan006-jmore157-clee643-kye019/assets/166083437/78778d29-35f1-427d-a950-4c92ea79d416" width="300">

> Fight Screen
> The fight screen is where the Asciimon fight occurs. The health of the player's Asccimon and the opponent's Asciimon are displayed. The player will have 4 buttons they can push: Fight, Asciimon, Item, or Run. The user pressing a button will do that action during their turn. For example if Fight is pressed the user will be given options of attacks they can use and will select one to use. All information about each turn will be displayed in the bottom left of the screen informing the player what moves were made and if they are critical hits.

<img src="https://github.com/cs100/final-project-tflan006-jmore157-clee643-kye019/assets/166083437/e8290e40-99ff-486b-8e15-2c31031def3b" width="300">

>Fight Win Screen:
>After the player wins the fight they are congratulated for their victory and allowed to continue.

<img src="https://github.com/cs100/final-project-tflan006-jmore157-clee643-kye019/assets/166083437/d05c665c-b934-4ed9-a56d-8c439b8ec13a" width="300">

>Fight Lose Screen:
> After the player loses the fight the game is over so they are given the option to restart or quit the game by typing their choice.

<img src="https://github.com/cs100/final-project-tflan006-jmore157-clee643-kye019/assets/166083437/85744b2a-255e-4301-8ac5-82e63d0cc8e5" width="300">

>Final Victory Screen
>After the player beats the game they are congratulated for their success.

## Class Diagram
 > Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).

<img src="https://github.com/cs100/final-project-tflan006-jmore157-clee643-kye019/blob/master/class_diagram.png" width="800">

> The diagram illustrates the core classes of ASCIIMON. The Trainer class has a team attribute which contains all captured and available ASCIIMONs. The Trainer class is utilized in the BattleSimulator and AsciiMon controller classes.

> The diagram futher describes how Asciimon's are modeled. An Asciimon has statistics, type, and various potential moves. When an Asciimon gains sufficient EXP then it will level up and its subsequent statistics will be increased. Likewise, an Asciimon can learn or lose moves.

> The Move class illustrates that every move has a name, description, accuracy and power. The accuracy relates to the probability a various move will succeed or fail. The power attribute determines how much damage that move will do to another Asciimon.

> The AsciimonCodex class will be used to build and contain all possible Asciimons and moves. Random and various types of Asciimon will be generated and returned by the Asciimon class. The MoveCodex was removed since it wasn't necessary and added extra code. 

> The Statistics and ElementalType classes are used to construct Asciimon and for battles.

> The BattleSimulator class will control battles between the player and opposing trainers or standalone asciimons.

> The BattleMechanics class implements the core logic surrounding battles such as critical chances, move attempts, and damage computation. It is an addition that stems from the Single Responsibility Principle. The BattleSimulator deals primarily with UI whereas BattleMechanics details and defines the logic surrounding a battle. It helps me write better code because my BattleSimulator no longer deals with both backend and frontend details.

> The BattlePlayer class is an abstract class that is used to implement polymorphism for various types of players. Essentially, a BattlePlayer is represented by a team and a name. Methods such as makeMove and changeAsciimon are pure virtual and so must be implemented by derived classes. From the BattlePlayer class we have child classes ComputerPlayer and HumanPlayer. A HumanPlayer uses a GUI to fetch user input where as the ComputerPlayer simply analyzes the current battle to determine a move.

> The BattleResults class represents the outcome of any Battle between two opponents. There is information pertaining to being a winner, loser, or something else. Moreso, BattleSimulator is dependent upon BattleResults as it the return result for a battle.

> The StatGenerator class is utilized by AsciimonCodex and the random generation of Asciimons. 

> The HitDetails class contains information relating to an attempted move, i.e., information such as the type of move, special effects, and overall damage. This is also a result of the Single Responsibility Principle since the HitDetails deals strictly with attacks and moves made.

> The previous classes such as Statistics, AsciimonCodex, Move, and Trainer didn't need to be changed because they wre not in conflict with SOLID principles. Statistics has the sole responsibility of storing and manipulating data pertaining to basic stat modifiers. The Move class has basic information pertaining to moves. The AsciimonCodex has the single purpose of storing all available Asciimon types which will then be utilized by the AsciimonGame class. The trainer class also had a single responsibility of representing an entity with a team of asciimons. None of the classes have inheritance so the Liskov Substitution Principle was never violated. Likewise, high level modules never depended on low level modules so the DIP principle wasn't violated.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots

 <img src="https://github.com/cs100/final-project-tflan006-jmore157-clee643-kye019/assets/166083437/27645392-a154-4e67-ba42-2c348540950e" width="500">

> User enters their name and presses enter.
-----------------------------------------------------------------------------------------------------------------------------------------------------

<img src="https://github.com/cs100/final-project-tflan006-jmore157-clee643-kye019/assets/166083437/cb3814a3-faa3-468f-9015-6e9d65de47c0" width="500">

> User enters 0, 1, 2 to select their Asciimon
-----------------------------------------------------------------------------------------------------------------------------------------------------


<img src="https://github.com/cs100/final-project-tflan006-jmore157-clee643-kye019/assets/166083437/da297356-a2de-4a38-9c76-506fb65ad8bb" width="500">

> User enters 1 to quit the program, 2 to fight a trainer, 3 to view the players Asciimon list, 4 to fight a wild Asciimon
-----------------------------------------------------------------------------------------------------------------------------------------------------
> Player selects 3 in terminal

<img src="https://github.com/cs100/final-project-tflan006-jmore157-clee643-kye019/assets/166083437/ee613acf-3bc5-49ff-a861-f7f2d547a90a" width="500">

-----------------------------------------------------------------------------------------------------------------------------------------------------
> Player Selects 4 in terminal

<img src="https://github.com/cs100/final-project-tflan006-jmore157-clee643-kye019/assets/166083437/78778d29-35f1-427d-a950-4c92ea79d416" width="500">

> User pushes attack, catch, run, or Asciimon buttons during the fight
-----------------------------------------------------------------------------------------------------------------------------------------------------
Player Selects 2 in terminal

<img src="https://github.com/cs100/final-project-tflan006-jmore157-clee643-kye019/assets/166083437/37ad92f2-1e4d-4a90-bab2-c62f1267230c" width="500">

> User pushes attack, run, or Asciimon buttons during the fight
-----------------------------------------------------------------------------------------------------------------------------------------------------

> User presses catch and successfully catches

<img src="https://github.com/cs100/final-project-tflan006-jmore157-clee643-kye019/assets/166083437/6205ad29-f234-45a4-a688-bb93df637d8d" width="500">

-----------------------------------------------------------------------------------------------------------------------------------------------------
> User wins the fight.

<img src="https://github.com/cs100/final-project-tflan006-jmore157-clee643-kye019/assets/166083437/e8290e40-99ff-486b-8e15-2c31031def3b" width="500">

-----------------------------------------------------------------------------------------------------------------------------------------------------
> User loses the fight.

<img src="https://github.com/cs100/final-project-tflan006-jmore157-clee643-kye019/assets/166083437/d05c665c-b934-4ed9-a56d-8c439b8ec13a" width="500">

-----------------------------------------------------------------------------------------------------------------------------------------------------
> User beats the game

<img src="https://github.com/cs100/final-project-tflan006-jmore157-clee643-kye019/assets/166083437/85744b2a-255e-4301-8ac5-82e63d0cc8e5" width="500">


 ## Installation/Usage
> -To run the program all code in the repositiory must be downloaded using the git clone command with the repository link <https://github.com/cs100/final-project-tflan006-jmore157-clee643-kye019.git> to clone the repositiory into an IDE that can run C++ code. Then use CMake . and make commands to build the game and its executable name asciimon. Once built, use ./asciimon to start the game in the terminal.
> 
>-The program is all ran in the C++ terminal. The input is from the player that will be prompted to choose actions through typing or pushing buttons in the terminal. The output will be in the terminal displaying the results of the users actions as they progress through the game. Once the game is finished the program will stop.
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.

 > Our project was tested/validated via gtest followed by gcov & lcov. However, our testing methodology consisted of testing all entities that were not stricly GUI. We unit tested all methods and classes that had no relation to GUI and dealt strictly with logic. There are unit tests for ComputerPlayer but not HumanPlayer because ComputerPlayer has zero coupling to user input and graphical interface. However, HumanPlayer fetches user input via FTXUI which is a graphical user interface on the terminal so it cannot be tested with unit tests. Likewise, BattleSimulator and Stats.hpp are missing testing because they have components strictly dealing with the screen UI and user input.
<img src="https://github.com/cs100/final-project-tflan006-jmore157-clee643-kye019/blob/master/lcov.JPG" width="900">
