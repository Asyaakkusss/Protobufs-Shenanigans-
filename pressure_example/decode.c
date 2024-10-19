#include <stdio.h>
#include </home/asyaakkus/protobuf_c_example/nanopb_example/pb_encode.h>
#include </home/asyaakkus/protobuf_c_example/nanopb_example/pb_decode.h>
#include "pres.pb.h"
#include "nanopb_example/pb.h"

/*decoding script for proof-of-concept using netcat*/
int main() {

//create buffer where message is stored 
uint8_t pressure_buffer[5]; 

//boolean that stores status of decoding operation 
bool status; 

{   
    //opens file, reads it, and returns length of the message in bytes 
    FILE *f = fopen("output.bin", "rb"); 
    int message_length = fread(pressure_buffer, 1, sizeof(pressure_buffer), f); 
    fclose(f); 

    //stream instantiated for message 
    pb_istream_t stream = pb_istream_from_buffer(pressure_buffer, message_length); 
    PressureMeasurements pressuremeasurements = PressureMeasurements_init_zero; 
    
    //message decoded 
    status = pb_decode(&stream, PressureMeasurements_fields, &pressuremeasurements); 
    
    //check to ensure that encoding succeeded. This should not print if the message was properly decoded.
    if (!status)
        {
            printf("Decoding failed: %s\n", PB_GET_ERROR(&stream)); 
            return 1; 
        }

    //prints baro pressure to console and to file 
    fprintf(stdout, "The baro pressure is%f\n", pressuremeasurements.pressure); 
}

}