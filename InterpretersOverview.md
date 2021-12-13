
### I: Macro

- macro:nameofthemacro
- macro:regexofthemacro
- macro:jomiofthemacro

See: [.stringtocommands](.stringtocommands) - [.regextocommands](.regextocommands)

### I: JomiMacro

- jomimacro:nameofthefile

See: [.jomimacro](.jomimacro)

### I: DebugLog

- debuglog Text to display

### I: Time 

- In time|command

### I: Sound

With name:
- sound:shotplay:filename
- sound:play:filename
- sound:pause:filename
- sound:stop:filename

Without name:
- sound:switchpause
- sound:play
- sound:pause
- sound:stop

### I: Boolean

Value as: 1,true
- bool:nameoftheboolean:value
- boolswitch:nameoftheboolean

### I: Executable

- exefile:nameofthefile

### I: Screen Recorder

- screenrec:save:givenname
- screenrec:recover:givenname

### I: Key recorder

- keyrecord:saveasfile:filename
- keyrecord:play:name  
- keyrecord:playback
- keyrecord:save:name
- keyrecord:stop
- keyrecord:resume
- keyrecord:pause
- keyrecord:start

### I: Stacker

- stack:remove:name
- stack:append:name
- stack:clear:name
- stack:gonext:name
- stack:goprevious:name
- stack:do:name
- stack:doandgonext:name
- stack:doandgoprevious:name
- stack:moveat:name:5        
- stack:movetostart:name
- stack:movetoend:name
- stack:docurrent:name





### I: Looper

From file:
- loop:set:name:[true|false]
- loop:on:name
- loop:off:name
- loop:restart:name
- loop:time:name:value

Created on the fly:
- tloop:remove:name
- tloop:set:
- tloop:on:
- tloop:off:
- tloop:restart:
- tloop:time:
- tloop:create:
- tloop:createandstart:

### I: Copypast

- copypast:device:past
- copypast:device:copy
- copypast:device:cut
- copypast:device:file:filename
- copypast:jomi:file:filename

### I: Ricochet

- ricochet 30 45ms 800ms 1.5s 5.0: debuglog Hello


### I: Womi

- winkey:press:keyname
- winkey:release:keyname
- winkey:stroke:keyname
---------
# Legacy

### I: Wait

- Wait time command 
