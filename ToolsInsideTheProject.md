# Open Macro Input toolbox
The main project is compose of several open source toolbox that I am crafting with the project.
The idea is that if you don't like the way I am coding it, you can create your own.

## Used in the main project
_Updated: 2020-10-23_

- https://gitlab.com/eloistree/2020_05_05_BooleanStateMachines.git
  - Manage a register of boolean that allows you to make actions linked to condition with state machine pattern ways. Very useful to manage the input of a project.
- https://gitlab.com/EloiStree/2020_09_29_BooleanStateMachineToJomi.git
  - Us the a boolean state machine to trigger actions on your computer by using JOMI a runtime outside the app.
- https://gitlab.com/EloiStree/2020_09_23_SerialPortToBooleanStateMachines.git
  - Convert your SerialPort (Arduino for me) to convert them to boolean usable in the project.
- https://gitlab.com/eloistree/2020_05_05_BooleanHistory.git
  - Toolbox that allows to manipulate boolean state through time. 
- https://gitlab.com/eloistree/2020_04_28_UnityDirectoryStorageUtility
  - Toolbox that manage the storage of the files and directory through different platform to store information that stay when reinstalling the application.
- https://github.com/EloiStree/2020_04_10_JavaOpenMacroInput.git
  - An adaptator that allows to send with classic C# message to JOMI to make action on the computer target by UDP message.
- https://gitlab.com/eloistree/2020_04_09_WinApplicationContext.git
  - An tool that allows the application to know what application the user is using in aim to change it behavior based on what the user is doing.
- https://gitlab.com/eloistree/2020_04_06_compressdigitalandanalog.git
  - Convert #0001011#30216549 value from 0-9 or 0-1 in boolean value in C# to be use with the boolean state machine.
- https://gitlab.com/eloistree/2020_03_22_LaunchBatAndAhk.git
  - Allow to launch window executable files when the user request it. 
- https://gitlab.com/eloistree/2020_02_13_ReadSerialPort.git
  - Simple tool to read and write on te serial port with C#.
- https://gitlab.com/eloistree/2019_12_11_MorseDetector.git
  - Allow to listen from boolean value about morse combination to trigger actions.
- https://gitlab.com/eloistree/2019_12_11_KeystrokeUtility.git
  - Allow to listen to the use of the mouse and keyboard outside of the application to associate action to it. (WARNING: don't trust application using this toolbox blindly, because that very dangerous. It is also why my project will always be open source and controllable by the community)

### Used as a Runtime
The application OMI is a software that try to understand what the user want and send 80% of the actions to do to a receiver call JOMI for Java Open Macro Input.
This application listen to network request to do action on the device. 
You can find the code of it here.
- https://github.com/EloiStree/2020_04_10_JavaOpenMacroInputRuntime