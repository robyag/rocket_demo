# rocket_demo
C++ program wich draw a rocket with a size taken from the input.


# Compile Steps
To compilate the program, you have to download this code, go into the main folder, and execute:
```
cmake . && make
```

This will create the executable file calles "rocket".
Execute it with:
```
./rocket -l 5
./rocket -l 10
./rocket -l 5 -i
```

# Assumptions
* I assume that the size of the -l parameter can't be less than 2, because it wouldn't respect the rocket shape, wich has to have 3 X as the bottom of the rocket.

* I assume that the first two parameters are mandatory, so if any of them is not what the program expects, the program will exit with error value 1 and will print the next message:
```
./rocket -L 4
Invalid input params
./rocket    -l   (number > 1)    [-i]
```

** The first parameter must be -l. Sending -L -2, -j won't work.

** The second parameter has to be a number greater than 1.
1, 0, ten, hello,... aren't valid values.

* I assume that the -i parameter is optional (not like the first two), so if the user sends something other than -i, the rocket will be drawn with its normal orientation, but won't return an error message.

# Tasks To Do
All source code is in the rocket_c.cpp file. 
Structuring the project into different classes is a pending task and will be developed in the coming days.