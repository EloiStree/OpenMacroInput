➤ ☗ | ↓ ↑  _ ‾ ∨ ∧ ¬ ⊗ ≡ ≤ ≥ ⌃ ⌄ ⊓⇅ ⊔⇵ ⊏ ⊐  ↱↳ ∑  -no unity  ⤒ ⤓ ⌈ ⌊  🀲 🀸  ⌛ ⏰ 

I am bad at documenting...
But "it is by forging that one becomes a blacksmith".
![image](https://user-images.githubusercontent.com/20149493/108693658-5f0af180-74fe-11eb-8316-79a332ea911f.png)
So if you need help, ping me on Discord:
https://eloistree.page.link/discord


------------------

Also.  
Before we start:  
![image](https://user-images.githubusercontent.com/20149493/108714894-6dff9d00-751a-11eb-873a-1b5ff3075286.png)
PS: I know what I want to create... But I have not idea of what it will look like in the future and what is the best shape for it. Meaning that the architecture of the software can be raw and seem quite random.
- If you think you can do better, feel free to give it a try. (Code(s) are Open Source on demand) 
- If you think I can do better, feel free to talk with me.  (I am on [Discord](eloistree.page.link/discord))
- If you think my way of coding is shit, feel free to help me (It is my first big software)
- If you think my software is not good for professional use,... (o_O') Yes... obviously... it is unstable like 'shit' as it is in a research and development state. Thank captain obvious. 

------------------

------------------

Hello !!!  
Welcome to you.   

The idea of my tool is simple:
1. Play your game / be productive with your software
1. Create & Modify files in the folder 'configuration' of the application to tweak your wish and desire
2. The application detect modified files and load the new configuration.
3. Do that until your happy with your configuration.
4. Share your files with the community when you are proud of it.


----------------------------

# Basic you need to know
Before you start you need to understand:
- "Every situation can be resume in a 'true' or 'false' statement(s)"
  - So my programme is at 80% composed of tools to manage Boolean(true or false) only situation.
- Based on those named 1 and 0 you can make condition statement
  - Is the player jumping and firing ->  ````juming + firing```
  - Is the player not running  and firing ->  ````!running + firing```
  - Is the player is in game or in photoshop ->  ````!gamename + photoshop```
- Those condition will help you to do two main actions
  - Create new named Boolean
    - juming + firing -> epicmoveincoming
    - !left + !right + !up + !down -> notmoving
  - Throw new request to do stuffs: "command line"
    - epicmoveincomming -> macro:startrecordingwithobs
    - notmoving -> macro:stoprecordingwithobs
- Those line(s) of text will do action based on the interpreter you have:
  - Macro interpreter: will try to do several actions when call
  - Mouse Utility interpreter: will try to simulate mouse click and move
  - Copy past interpreter: will copy past as text you stored previously
  - ...

**So... How do I configure that?**  
So let's overmatch all that with this Wiki Git and videos.


## Boolean
In my application a Boolean value is a true or false state linked to a referential name. This is 80% of the application.

## Condition
Small text that ask the state of several Booleans state through the recent past time.

## Command line
One line of text that design something to do. It does know how to do it but it just request to do it. 

## Interpreter
Some codes of the application that a programmer added to the app for you that can understand some command line you can send. For the moment, the first interpreter that understand a command line claimed it and it responsible of executing it.

## Files configuration

Large range of files type that give the shape of how you want the software to assiste your in your daily life.
It only work for files in the configuration folder. An option will be add to import them from an/some URL in the future.

----------------------

# Files
## Used frequently
All the files in this list are regularly used in my everyday life testing.
Meaning they can have issue but they mainly works as intended and are good enought to be used.
|  File | Difficulty   |  What it does ?|
|---|---|---|
Setter *||
[.keyboardtoboolean](.keyboardtoboolean)|*|Listen to keyboard in general.
[.windowkeytoboolean](.windowkeytoboolean)|*|Listen to window keyboard specificly.
[.winxboxtoboolean](.winxboxtoboolean)|*|Listen to Xbox Controller on Window.
[.apptoboolean](.apptoboolean)|*|Listen the focus of an application.
[.boolstobool](.boolstobool)|*|Convert conditions to a boolean.
[.filetobool](.filetobool)|*|Defined boolean that need to exist and set them to a default value.
Setter **||
[.audiointensity](.audiointensity)|***|Allow to convert the intencity of microphon (window) to a boolean value
[.screenzonetoboolean](.screenzonetoboolean)|*|Allow to defined a screenzone and convert it as a boolean value when the mouse enter and exit the zone
[.portnomenclature](.portnomenclature)|***|Allow to listen to Arduino (or else) and convert them to boolean to be used.
Storage||
[.stringtocommands](.stringtocommands)|**|Create actions to be call based on a given name.
Condition Trigger||
[.morsecondition](.morsecondition)|**|Listen to a morse sequence to linked it to actions.
[.doublemorsecondition](.doublemorsecondition)|**|Listen to a morse combination of boolean to linked it to actions.
[.timeofdaytocommands](.timeofdaytocommands)|**|Call action at specific moment of the day or frequence of the day.
[.simplecondition](.simplecondition)|***|Link condition to actions to be call based on switch or maintaining.
[.timecondition](.timecondition)|***|Link condition to an action based on a range of time to be trigger.
Utility||
[.spliter.xml](.spliter.xml) |**| Allows to convert a group of boolean to more booleans to make your avoid thinking about the logic behind a frequently used pattern.
[.booleangroup](.booleangroup)|**|Allow to make group of boolean to make group change and selection.
[.screenlocations](.screenlocations)|**|Defined some screen location that can be used by some interpretors or directly convert to boolean

## Complexe
The following files are technicly in my application but they are too hard to explain simply of how they work. If you are challagened enough, feel free to overwatch how to use them.

|  File | Difficulty   |  What it does ?|
|---|---|---|
[.booleanregexcondition](.booleanregexcondition)|***|Allow to trigger actions based on boolean change with Regex detection. Powerfull but very hard to use without knowedlge and training. 

## Check if finish
They are in the program... but I did not tested since a long time and I am not sure they are still working or finished

|  File | Difficulty   |  What it does ?|
|---|---|---|
[.copypastfile](.copypastfile)|*|Allow to have some text that can be copy pasted on command.
[.linearcondition](.linearcondition)|***|Allow to quickly associate an action based on a sequence of conditions
[.jomimacro](.jomimacro)|***|Store some actions that need to be precisely executed with 1-10 milliseconds precision
[.regextocommands](.regextocommands)|***|Give flexibility compare to 'stringtocommands' by using regex instead of string.
[.stack](.stack)|**|This file allow you to stack actions to be call one after an other for the stack interpretor
[.timedcommandlines](.timedcommandlines)|**|Allow to associate actions to some specific amount of time
[.sequencedcommandlines](.sequencedcommandlines)|**|Allow to list some actions that need to be executed one after an other with some same delay between them.
[.relativetimedcommdlines](.relativetimedcommdlines)|**|Allow to associate actions with time relative to the previous and next one.
[.wowfishingsetting](.wowfishingsetting)|**|A file specific to World of Warcaft to fish automaticaly based on sound.
[.reimportcommands](.reimportcommands)|**| Allow to associate actions in the software each time it import the new configuration or when the application start.


## Interpreter
The interpreter are some code that based on the structure of your "command line" will claimed the responsibility and do some action or/and trigger some other command line to be interpreted.

For example: `In 500|macro:Sayhello`
- The interpreter of time will recognize that the line start with "In 500|" 
  - It will send in 500 milliseconds the following command line `macro:Sayhello`
- The interpretor of macros will recognize that the line start with "macro:"
  - It will check for a macro save under the name "SayHello"
  - "SayHello" is store by the user as such in a .stringcommands file: ```jomi: enter↓ enter↑ [[Hello Guys !]] enter↓ enter↑``` 
- The interpreter of JOMI will recognize that the line start with "jomi:"
  - It will send to the JOMI app the request to execute the following command ```enter↓ enter↑ [[Hello Guys !]] enter↓ enter↑```
- The JOMI app will convert the shortcut text as soon as it received it by:
  - Stroke enter and copy past "Hello guys!" then stroke enter

It seem a bit complicated for nothing. 
But that very powerfull.
(And very not good if you want nanoseconds action or 1-3 milliseconds precision.)

More documentation on that later.  
Go here until I have some more documentation on the subject:  
https://github.com/EloiStree/OpenMacroInput/wiki/InterpretersOverview


## Java Open Macro Input
Open Macro Input are some tools that together make a software to listen to the user and do actions based on it.
But as there are thousand of ways to do it. 
I did a software call JOMI in java that received request by UDP and execute them.

Meaning that you can design your own version of the tool by just using JOMI.

Here is a guide of the basic you can use:
[JOMI Basic Commmands](JomiBasicCommands)

**Why in Java ?**
- Because I want to have a tool that works on many platform: Mac, Linux, Window...
- Because some game and software don't detect native simulation of keystroke when other does... So I have both. Java outside my app and native inside my app.
- Because if you have the executable in your app, you are linked to the computer it runs on.
- Because if the code is in your app, you have to share the resource with it. 
- Plenty of bullshit other reasons to avoid to say that I did a experiment and it works and so I continued with it until I code something that is significantly better.
- ... 


More information on this part of the tool on this GitHub repository:  
https://github.com/EloiStree/2020_04_10_JavaOpenMacroInputRuntime

 
------------------------------

## Could help until the doc is more clear
 
- https://github.com/EloiStree/OpenMacroInput/wiki/InterpretersOverview
- https://github.com/EloiStree/OpenMacroInput/wiki/FileExtensionName
