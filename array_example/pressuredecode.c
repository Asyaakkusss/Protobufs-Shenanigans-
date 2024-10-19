#include <lcm/lcm_coretypes.h>
#include <stdio.h>
#include </home/asyaakkus/protobuf_c_example/nanopb_example/pb_encode.h>
#include </home/asyaakkus/protobuf_c_example/nanopb_example/pb_decode.h>
#include "arrays.pb.h"
#include "arrays.pb.c"
#include "nanopb_example/pb.h"

/*decode message*/
int main() {
{
    uint8_t pressure_buffer[2]; 
    bool pressure_status; 

     //opens file, reads it, and returns length of the message in bytes 
    FILE *f = fopen("output.bin", "rb"); 
    int message_length = fread(pressure_buffer, 1, sizeof(pressure_buffer), f); 
    fclose(f); 

    pb_istream_t stream = pb_istream_from_buffer(pressure_buffer, message_length); 

    Ideal_Pressure idealmeasurements = Ideal_Pressure_init_zero; 
    Pragmatic_VDW_Pressure pragmaticmeasurements = Pragmatic_VDW_Pressure_init_zero;
    
    pressure_status = pb_decode(&stream, Ideal_Pressure_fields, &idealmeasurements); 

    //check to ensure that encoding succeeded. This should not print if the message was properly decoded.
    if (!pressure_status)
        {
            printf("Decoding failed: %s\n", PB_GET_ERROR(&stream)); 
            return 1; 
        }

    //prints baro pressure to console

    for (int i = 0; i < 4; i++) {
        fprintf(stdout, "The current variable is %f\n", idealmeasurements.volume, 
                                                                       idealmeasurements.num_moles, 
                                                                       idealmeasurements.r_constant, 
                                                                       idealmeasurements.temperature); 
    }
}
}