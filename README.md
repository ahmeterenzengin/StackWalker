## StackWalker
**StackWalker** s a software designed to track an object's movements within X-Y coordinate system, with the capability of returning to the origin whenever desired. 
##  Research Problem
Robots are utilized in the warehouses of large corporations (such as Amazon and Trendyol) to transport items from one location to another. These robots generally move along
predetermined tracks or follow Wi-Fi networks. When these robots need to be deployed, their paths are either entered step-by-step or they operate on pre-recorded routes. Thanks to this program, robots
can easily navigate through complex warehouses or return to their starting points in case of any issues. 
##  Motivation
The primary motivation of this project is to maintain a route history using data structures— specifically Stacks—and to flawlessly rewind this route using LIFO (Last-In-First-Out) logic. The
software aims to reduce complex routes into a straightforward backtracking process.
##  Control Flow
1)When the program starts, routeTracker class assigns x and y values as x=0.0,y=0.0
2)User input: Program asks about the choice to user.
1) Add movement 2)Backtrack 3)Exit.
If user choose 1 , program asks user to enter a direction (North, South, East, West) and distance (meter).Also with the directionFormat() function the
input’s first letter be upper character other letters be lower character so we prevent case sensitivity.
Movement Recording: The addMovement() function is triggered. Distance and direction data are encapsulated within a Movement struct and pushed onto the stack data structure.
Coordinate Update: The updateCoordinates() function updates the current X and Y values in realtime based on the input direction.
If user choose 2, Backtrack mechanĜsm just start working,
We get last movement in the stack with stack.top() . With the invertDirection function we get the opposite sites of every movement (e.g. if last movement was North,so invertDirection(North) is South). To return the user to the origin, coordinates
are updated in reverse, and the corresponding movement is popped from the stack. This process continues until the stack is empty, successfully navigating the user back to the (0, 0) point.

##  Implementation Strategy
Data Structure (std::stack): A stack was chosen to store movements. bu ensures that the last movement performed becomes the first step of the return journey (LIFO).
Struct and Class ArchĜtecture: The Movement struct is used for data organization, while the routeTracker class manages logical operations such as backtracking and status reporting.
Error Handling and String Manipulation: Even if the user provides poorly formatted input (e.g., "noRTh"), data cleaning is performed using transform and toupper functions. Additionally, a control mechanism (route.empty()) prevents errors if a backtrack is attempted with an empty stack.

##  Deployment
This project is directly uploaded from github repo(https://github.com/ahmeterenzengin/StackWalker).
