#include <stdio.h>
#include </home/asyaakkus/protobuf_c_example/nanopb_example/pb_encode.h>
#include </home/asyaakkus/protobuf_c_example/nanopb_example/pb_decode.h>
#include "pres.pb.h"
#include "nanopb_example/pb.h"

/*This is the encoding script for the proof-of-concept method using netcat.*/
int main() {

//create buffer where message is stored
uint8_t pressure_buffer[5]; 

//boolean that stores status of decoding operation
bool status; 

{
    //allocate space to stack 
    PressureMeasurements pressuremeasurements = PressureMeasurements_init_zero; 

    //stream writing to the pressure buffer
    pb_ostream_t stream = pb_ostream_from_buffer(pressure_buffer, sizeof(pressure_buffer)); 
    
    //assign a value to the pressure variable in baromeasurements 
    //set the has_pressure boolean nanopb provides to true to ensure data transmission 
    pressuremeasurements.pressure = 23.12; 
    pressuremeasurements.has_pressure = true; 

    //encode the message 
    status = pb_encode(&stream, PressureMeasurements_fields, &pressuremeasurements); 

    //check to ensure that encoding succeeded. Nothing should print from here if pb_encode succeeded
    if (!status)
        {
            printf("Encoding failed: %s\n", PB_GET_ERROR(&stream));
            return 1;
        }

    //write binary output into a file named output.bin 
    FILE *f = fopen("output.bin", "wb"); 
    fwrite(pressure_buffer, 1, stream.bytes_written, f); 
    fclose(f); 

}
return 0; 

}