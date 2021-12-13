
## Text Recognition

Import a text input that can trigger action based on context
```
textemitted♦condition♦macro1♦macro2
reloadlevel♦doom♦doom:reloadlevel
reloadlevel♦unity♦unity:play
shutdown computer♦♦window:shutdown
```

Action to manager the text listener
```
textlistener:start //start to listen to incoming text from keyboard
textlistener:stop // stop to listen to incoming text from keyboard
textlistener:push  // try to trigger actions based on recorded text
textlistener:clear // remove the text recorded by listener
textlistener:pushandclear  //push and clear the input recorder by the keyboard
textlistener:fullstop  // push + clear + stop 
```
## Speech Recognition

Action to manager the speech recognition listener
```
speechlistener:start
speechlistener:stop
speechlistener:push
speechlistener:clear
speechlistener:pushandclear
speechlistener:fullstop
```             
                