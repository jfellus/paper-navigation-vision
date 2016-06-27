# Build

just type

````bash
make
````

# Use the web interface

type
````bash
./serve.sh
````
and open a browser to your IP at port 8888

# Structure

* *src/* : Sources for the executables (you should only modify src/algos...)
    * src/algos : Here go your control algorithms source. Each .c file must implement the `control(...)` function (see src/api.h)
* *data/* : Generated data will go here
    * *data/N* : Number of frames captured
    * *data/images* : Captured frames
    * *data/trajectory* : Trajectory informations from the robot (odometry, motor commands, ...)
* *build/* : Built executables (one per navigation algorithm) go here
* *bin/* : Intermediary build files go here

