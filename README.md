# FoxDot to openFrameworks

A simple way to create sound-driven visuals by connecting [FoxDot](https://foxdot.org/) to [openFrameworks](https://openframeworks.cc/).
## Setup
1) If needed, install [FoxDot](https://foxdot.org/installation/) and [openFrameworks](https://openframeworks.cc/download/)
2) Start the FoxDot editor and open [foxdot-openframeworks.py](https://github.com/feature-creature/foxdotExample1/blob/master/foxdot-to-openframeworks.py)
3) Start your favorite code editor for openFrameworks and open [foxdotExample1](https://github.com/feature-creature/foxdotExample1) 
4) In the FoxDot editor, have FoxDot send data (OSC messages) to the openFrameworks app by activating line 1
    
    Server.add_forward("localhost",12345)
    
5) Run the openFrameworks app 
    
## Iterate
- Edit + activate the FoxDot code
- Edit + rerun the openFrameworks code
