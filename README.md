# Antagonistic Tendon Driven Continuum Robot
***A continuum robot for research with 4 DOF and tendon force measurement.***

![robot_image](https://raw.githubusercontent.com/ChristianMarzi/Tendon-Driven-Continuum-Robot/main/images/tdcr.png)

# Contents 
In this repository you will find all necessary step files to build your own continuum robot. It drives 2 tendons with a single servo to provide a simple and cost efficient setup for continuum robot research. The tendons are routed via load cells to provide tendon force measurement. The focus of this repository is the mechanical setup but basic interfacing software/information to the Robot Operating System (ROS) is provided. All 3D-printed parts are designed for SLS printing. The files are created using Autodesk Inventor 2022, for versatility step files are provided. Software and information to interface the robot to (ROS) is provided.  

## Robot System
The robot consists of 4 modules
* **Substruction**: Containing power supply, Arduino and Measurement Hardware for the load cells.
* **Base**: Base plate with mount for robot, servos and tendon pulleys.
* **Force Measurement**	: Mounts for load cells. Pulleys mounted on load cells and tensioning mechanism
* **Robot Body**: The actual robot, consisting of Nitinol backbone and spacer disks.

Off-the-shelf parts are the following:
* **Servo Motors:** [SunFounder SF3218MG](https://www.sunfounder.com/products/20kg-high-torque-servo)
* **Load Cells:** [5kg TAL220B](https://www.sparkfun.com/products/14729)
* **Tendons:** Shimano BeastMaster AX Round Dyneema
* **Bearings:** 683ZZ ball bearings 3 mm x 7 mm x 3 mm
* **Arduino Uno**
* **Various Blots and Nuts** 

## Software

### Arduino / Servo Control
The Arduino uses [rosserial](http://wiki.ros.org/rosserial) to provide topics to the ROS-network. The firmware is found in `firmware/motor_driver/motor_driver.ino`. The robot subscribes to a topic for each motor and sets the motor position with every newly arriving message. For help on setting up the [Arduino](https://www.arduino.cc/en/Guide/Introduction) refer to the Arduino and [rosserial](http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup) documentation. 

### Load Cells
For digitizing the load cell values [Phidget 4-Input Bridges](https://www.phidgets.com/?tier=3&catid=98&pcid=78&prodid=1027) are used. A suitable ROS package is provided [here](http://wiki.ros.org/phidgets_drivers). It publishes the values to individual topics.

# Setup
As a reference, the whole System is provided as step file in full_robot.stp. It includes screws and bought parts. The `Modules_and_BOM.pdf` provides some info on assembly and required materials.   

# Paper
The paper describing this work is currently under review. As soon as it is publish info will be update here

# Authors
Contributers of this work are
* Felix Buck
* Thomas Scherr
* [Maximilian Themistocli](https://github.com/Maxcode28)

It is maintained by Christian Marzi. The files are licensed und CERN Open Hardware Licence Version 2, see `LICENSE` for details


