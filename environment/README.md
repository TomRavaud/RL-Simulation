# About

This ROS package contains the source code for the robot simulation. It manages its integration into the ROS environment (the simulator becomes a node that takes ROS type messages as input and output) so that it can interact with the nodes in charge of controlling the robot, and possibly be replaced by a real robot in the future.



### Node(s):

* **environment**: launches a simulation window



Possible improvements to the simulation environment are :

* adding noise to the laser measurements
* taking into account the maximum and minimum distances the laser can reach
* simplifying the process of creating world maps
