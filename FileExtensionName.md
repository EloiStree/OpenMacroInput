## Linear file and XSD/XML
I am using two type of file XSD and linear file builder.
- Linear is file where every line are creating something based on the file extension.
- XSD/XML are file that are more readable and allows better but slower configuration.
In resume, Linear are quick but "dirty" and XSD/XML are clear but take time to define.


#Linear
## Simple
### .apptoboolean
This file allows you to define a boolean value based on the focus of an application.
Example:
```
Apex♦ Apex Legends
VisualStudio♦\s-\sMicrosoft\sVisual\sStudio
Ninja♦AND♦Ninja♦Fruit
Chess♦OR♦Chess♦Echec
```

### .boolstobool
This file allows you to quickly convert a boolean condition to a new boolean. 
Example: 
```
FootLeftRelease + FootRightRelease ♦  FeetRelease
```
### .keyboardtoboolean
This file allow you to name the keyboard key to a boolean value independently of the platform (Mac, Window, Linux, Android...) (The read of the keyboard work  only on Window for the moment)
```
Z♦MoveForward
S♦MoveBackward
Q♦MoveLeft
D♦MoveRight

```
### .windowkeytoboolean
This file allow you to name the keyboard key of a window keyboard to a boolean.
```
volume_up♦VolumeUp
media_next_track♦NextSong
oem_8♦PowerUp
f20♦RequestScreenshot


```


### .filetobool
This file allows you to create boolean that you just change once in a while. 
Example:
```
Healer♦false
Tank♦false
DPS♦true
```

### .morsecondition
This file allow you to create morse sequence to be listened.
Example:
```
Shift♦...♦ ☗ExitTime 400 ☗TriggerOnFound ♦macro:window:nextmusic
Shift♦--♦ ☗ExitTime 1500 ☗TriggerOnExit ♦macro:window:pausemusic
Shift♦---♦ ☗ExitTime 1500 ☗TriggerOnExit ♦macro:window:restartmusic
```

#### doublemorsecondition
This file allow you to create morse sequence to be listened to but instead of using time as short or long, you defined two conditions.
Example:
```
Ctrl♦Space♦.--♦macro:csharp:createclass♦ ☗ExitTime 800 ☗TriggerOnExit
ScrollUp♦ScrollDown♦.--♦macro:photoshop:selection♦ ☗ExitTime 800 ☗TriggerOnExit

```


### .stringtocommands
This tools allow to create a groupe or macro to be call based on a sentence
Example:
```
agame:jump♦jomi:Space↓ Space↑
agame:slide♦jomi:Shift↓ Shift↑
agame:rush♦agame:slide♦In 0.3s|agame:jump

```
### .regextocommands
Allows you to define a regex that will trigger some actions if found.
See: https://regexr.com/ for more information on Regex
Example:
```
[Hh]ello♦debuglog Hello guys♦In 0.2s|debuglog How are you going? 

```


### .screenzonetoboolean
Allows to named a part of screen as a boolean value. (The values are in pourcent)
Example:
```
//Set boolean to true if the mouse cursor is in the following zone of the screen
//Square:MinLeftRight:MaxLefRight:MinBotTop:MaxBotTop ♦ BooleanName
Square:0.45:0.55:0.45:0.55 ♦ ScreenCenter 

```

## Can be complexe

### .simplecondition
Allows you to do action based on condition entry.
Example:
```
//When requested, start aiming and fire every 800ms until not requested
UseGun ♦ macro:thegame:starttoaim ♦ ☗TriggerOnTrue
UseGun ♦ macro:thegame:fire ♦ ☗LoopOnTrue 800
UseGun ♦ macro:thegame:stoptoaim ♦  ☗TriggerOnFalse
```

### .timecondition
Allows you to do action if a condition is use for an specific amount of time
Example:
```
// If the user press control and space for 800 ms then use the tool paint in photoshop
Ctrl+Space ♦macro:photoshop:select ♦ ☗Time 0   ☗TriggerOnRange
Ctrl+Space ♦macro:photoshop:paint ♦ ☗Time 800   ☗TriggerOnRange
Ctrl+Space ♦macro:photoshop:shape ♦ ☗Time 1600   ☗TriggerOnRange

// if user press shortly the key 'G' then use frag, for short time a smoke grenade and more time a mine.
G ♦macro:game:fraggrenade ♦ ☗MinTime 0 ☗MaxTime 500 ☗TriggerOnReleaseInRange 
G ♦macro:game:smokegrenade ♦ ☗MinTime 500 ☗MaxTime 1500 ☗TriggerOnReleaseInRange 
G ♦macro:game:mine ♦ ☗Time 1500 ☗TriggerOnRange
```

## Hard to use
### .linearcondition
This file allows you to create quickly line condition state machine. Basically it is a tool that check that some condition are following one after an other in a amount of time.
Example
```
//If the user press escape then control then space under 2 seconds and under 0.5s between action then go in map.
Escape↓ ➤ Control↓ ➤ Space↓ ♦ macro:game:map ♦ ☗BreakTime 500 ☗StepExitTime 2000 
Escape↓ ➤ Control↓ ➤ Ship↓ ♦ macro:game:shop ♦ ☗BreakTime 500 ☗StepExitTime 2000
```


### .booleanregexcondition
This file is a bit complexe to explain. In resume it allow you to make a regex based on the apparition of boolean that your observe. 
Example: 
```
A↓.*B↑.*A↑♦NewToOld♦1000♦A B C D♦debuglog hello
```

If button A was pressed and button B was released between in the last 1000 second could you send hello to the debug window.



# XSD / XML

## .portnomenclature
Allows to use Arduino input, or other ,in the project by renaming them and listen to them at the app launch.
See [tutorial on how to use Arduino with the project](ArduinoWithOMI) 





# Other File
## .copypastfile
Allows you to set some text to copy past when your request it.


## .jomimacro
This file allows you to store actions to send at Java Open Macro Input (JOMI) a port of the software that execute what you request it. And here you can give precise timing in MS to be executed.

```
☗name SOS with Gun
☗callid sosfire
☗description Do the SOS morse sound with the shot of your gun in game
500♦ms:l
1000♦ms:l
1500♦ms:l
2000♦ms:l
2200♦ms:l
2500♦ms:l
2700♦ms:l
3000♦ms:l
3200♦ms:l
3500♦ms:l
4000♦ms:l
4500♦ms:l
```
