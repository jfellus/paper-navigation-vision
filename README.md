# Build

just type

````bash
make
````

# Structure

* src/ : Sources for the executables (you should only modify src/algos...)
    * src/algos : Here go your control algorithms source. Each .c file must implement the `control(...)` function (see src/api.h)
* data/ : Generated data will go here
    * data/N : Number of frames captured
    * data/images : Captured frames
    * data/trajectory : Trajectory informations from the robot (odometry, motor commands, ...)
* build : Builded algorithms executables go here
* bin : Intermediary build files go here

