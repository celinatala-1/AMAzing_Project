# AMazing Project
This was a project for a course where my group and I had to write an algorithm for a maze simulation. T user can choose a maze diffiulty up to level 9 and up to 10 avatars. After which, the program will connect to a remote server, which sends back a maze for the program to solve. The maze is "solved" when all avatars end up in the same location. The GUI will print out the maze at each step with the upated avatar locations.

### Requirements
* Access to the remote server

### Implementation

To build, run `make`.

To clean up, run `make clean`.

For instructions on how to run the maze, see the README.md file in the amstartup directory.

Unfortunately my school has closed the server connection, so I am unable to run the program to get example outputs. 

### Code
The `AMStartup.c` file will first establish a connection to the server, and if successful the server will return the dimensions of the maze we are to solve. Since we are only writing the client side of things, we actually don't know what the maze looks like (we are essentially blind). Thus, to solve the maze, we utilized the right-hand rule where all avatars will follow the wall on their right side. Additionally, since we have multiple avatars in our program, meaning that avatars can simultaneously attempt to move, we also have to utilize multithreading. So we create a thread of avatars to deal with this issue. 