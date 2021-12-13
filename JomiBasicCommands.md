If you want to do keyboard and mouse action without more complicate action.

You can send UDP message to the IP and port of the Jar of JOMI:
https://github.com/EloiStree/2020_04_10_JavaOpenMacroInputRuntime
```
// This command request to type some text in your game chat.
sc: enter↓ ⌛20 enter↑ [[Some text to copy past]] enter↓ ⌛20 enter↑

//Make a double jump with some specific delay between the jump. 
sc: jump↓ ⌛100 jump↑ ⌛200 jump↓ ⌛20 jump↑  

//Make a left click with the mouse
ms:l  

// start pressing the right button of the mouse
mp:r  

// release the right button of the mouse
mr:r  

// Move your mouse at 20% from left to right of the screen and 10% from top to bottom of the screen.
jomiraw:mm:0.2p:0.1p  

```


They are some specificity of the tool if you need.

Ability to have password that only let the command you want pass.
If the password is not respected for some amount the jar lock and close to avoid no wanted instruction.
somepasswordjomiraw:mr:r  

The ability to execute the instruction at a specific time of the day or with delay

```

//Will write Yo in the chat of the game at exactly 12h40 30s 150ms based on the computer timer.
// Can have some delay of 1-5 ms based on the thread priority of the computer
t:12-40-30-150:sc:enter↓ ⌛20 enter↑ [[Yo]] enter↓ ⌛20 enter↑

//Will move the character forward in 400 milliseconds for 1 second.
tms:400:sc:Z↓ ⌛1000 Z↑ 

```


I will write the tutorial of it when requested.
Ping me if you need it.




When you use those commands in the OMI application with the JOMI interpreter.  
You need to put ```jomi:enter↓ ⌛20 enter↑ [[Yo]] enter↓ ⌛20 enter↑``` for shortcut message.
And ```jomiraw:sc:enter↓ ⌛20 enter↑ [[Yo]] enter↓ ⌛20 enter↑```  for all direct command.  


