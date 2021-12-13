
If you want to simulate a Xbox Device you need to install a simulator.
But if the simulator is installed, here is some command line you can use:
```
x360:startsim      //Will create a simulation of a Xbox Controller
x360:startsim:2    //Will create the simulation on a specific slot
x360:aboardall     //Stop all the simulation created previously
x360:jlr:0.5       //Set the left joystick horizontally to 50% of it power
x360:jlr:-0.5
x360:lt:0.5        //Set the left trigger  to 50% of it power
x360:a:true        //Set the 'A' button  to pressed
x360:pr:0          //Set the button pad at right the 'B' to released
x360:al:0          //Set the arrow pad at left to released
x360:sbr:false  
```

# Input name
## Floatable

- TriggerLeft, "tl"
- TriggerRight, "tr"
- JoystickLeftEast, "jlr", "jle"
- JoystickLeftNorth, "jlu", "jln"
- JoystickLeftSouth, "jld", "jls"
- JoystickLeftWest, "jll", "jlw"
- JoystickRightEast, "jrr", "jre"
- JoystickRightNorth, "jru", "jrn"
- JoystickRightSouth, "jrd", "jrs"
- JoystickRightWest, "jrl", "jrw"

## Boolable
- TriggerLeft,  "tl"
- TriggerRight,  "tr"
- SideButtonLeft,  "sbl", "bl"
- SideButtonRight,  "sbr", "br"
- ArrowLeft,  "al"
- ArrowRight,  "ar"
- ArrowDown,  "ad"
- ArrowUp, "au"
- ButtonA,  "a", "ba", "paddown", "pd"
- ButtonB,  "b", "bb", "padright", "pr"
- ButtonX,  "x", "bx", "padleft", "pl"
- ButtonY,  "y", "by", "padup", "pu"
- MenuBackButton, "m", "menu", "b", "back"
- StartButton, "s", "start"
- JoystickLeft,  "jl"
- JoystickRight,  "jr"