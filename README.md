# Protobuf C Investigation



## What is this Repository? 

This is an investigation into the capabilities of nanopb. Thus far, there are three folders in this repository:

1. The ```nanopb_example``` folder runs through the simple example found at the following [link](https://github.com/nanopb/nanopb/blob/master/docs/index.md). 
It includes all the source and header files from the nanopb repository that are necessary for encoding and decoding operations using nanopb. 

2. The ```pressure_example``` folder executes a more complex encoding/decoding operation on a pressure float variable. It serves as the beginning of a proof-of-concept to encode and decode a message over 
a network. The ```encode.c``` script writes the binary message to a file, while the ```decode.c``` script 
reads from that file and successfully decodes it using nanopb methods. 

3. The ```array_example``` folder executes an encoding/decoding operation on an array of pressure float variables in order to demonstrate that nanopb can encode, 
transport, and decode larger streams of data values. 

4. The ```submessages_example``` folder executes an encoding/decoding operation on a "master" ```pressure``` message that is made up of ```number_moles```, 
```volume```, ```r_constant```, and ```temperature``` submessages.

## Getting started 

In order to create a .proto file, follow these steps: 
1. clone the nanopb repository from [this link](https://github.com/nanopb/nanopb). You will need to clone with https. 
2. create a .proto file with the messages you desire. 
3. ```cd``` into the directory that contains the .proto file that you created. 
4. run the following command to compile the .proto file to produce its source and header c files: ```python /path-to-your-nanopb/nanopb/generator/nanopb_generator.py *protofilename*.proto```. 

The ```meson.build``` file runs the scripts mentioned above and creates executables for them. In order to run a script you created based on your .proto files, follow these steps: 
1. add an executable block to the end of the meson.build file with the following information and format: 

```
*name of executable* = executable('*name of executable*',
                            ['*path to the c script you want to run*'], 
                            dependencies : [nanopb_dep])
```
2. Upon running ```meson setup build``` and ```ninja -C build```, the executables should be found in the build folder. 
3. The executables can be run in the terminal in the ```protobuf_c_example``` directory using the following syntax: ```./build/*name of executable*```
4. Change the include in the generated ```.h``` file to point to the ```pb.h``` file in the nanopb_example folder. 