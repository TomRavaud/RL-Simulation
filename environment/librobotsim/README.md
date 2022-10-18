# Robotsim Library

## About

Source code of a custom library which allows to simulate a mobile robot (it can move forward, and turn left and right) and a laser sensor on a pre-defined 2D map.



Notes :

* the map is represented as a constant 2D array of boolean values (1 for an obstacle, else 0)

* the rays' synthesis is obtained using ray-casting techniques (DDA algorithm)



Possible improvements to the simulation environment are :

- adding noise to the laser measurements
- taking into account the maximum and minimum distances the laser can reach
- simplifying the process of creating world maps
