#include <lcm/lcm_coretypes.h>
#include <stdio.h>
#include </home/asyaakkus/protobuf_c_example/nanopb_example/pb_encode.h>
#include </home/asyaakkus/protobuf_c_example/nanopb_example/pb_decode.h>
#include "baroarrays.pb.h"
#include "nanopb_example/pb.h"

int main() {

/*create buffers where messages are stored*/
uint8_t pressure_buffer[8]; 
//float icd_pressure_buffer[128]; 

size_t message_length; 
//size_t icd_pressure_buffer_length; 

bool pressure_status; 
//bool icd_pressure_status; 

/*encode message*/ 
{
    //allocate space to stack 
    Ideal_Pressure baromeasurements = BarometricPressure_init_zero; 
    Pragmatic_VDW_Pressure positionmeasurements = DeltaPosition1D_init_zero; 

    //ensure that everything is initialized to 0   
    for (size_t j = 0; j < 4; j++) {
        printf("ensuring that everything is initialized to 0: \n"); 
        printf("iteration: %lf\n", baromeasurements.pressure[j]); 
        printf("iteration: %lf\n", baromeasurements.icd_barometricpressure[j]); 
        printf("iteration: %lf\n", positionmeasurements.delta_t[j]); 
        printf("iteration: %lf\n", positionmeasurements.icd_deltaposition1d[j]);
        printf("iteration: %lf\n", positionmeasurements.variance[j]); 
        printf("iteration: %lf\n", positionmeasurements.x[j]); 
    } 

    //stream writing to the pressure buffer
    pb_ostream_t stream = pb_ostream_from_buffer(pressure_buffer, sizeof(pressure_buffer)); 
    
    //assign a value to the pressure variable in baromeasurements 
    float baromeasurements_array[4] = {1.2f, 2.3f, 3.5f, 3.2f}; 
    

    //assign a value to the icd_barometricpressure variable in baromeasurements 
    float icd_barometricpressure_array[4] = {1.3f, 2.1f, 2.2f, 4.5f}; 

    //add values from baromeasurements_array into the pressure array of baromeasurements 
    for (size_t i = 0; i < 4; ++i) {
        baromeasurements.pressure[i] = baromeasurements_array[i]; 
        printf("%f\n", baromeasurements.pressure[i]); 
    }

    for (size_t i = 0; i < 4; ++i) {
        baromeasurements.icd_barometricpressure[i] = icd_barometricpressure_array[i]; 
        printf("%f\n", baromeasurements.icd_barometricpressure[i]); 
    }

    //make the count correspond to the number of values in the array 
    baromeasurements.icd_barometricpressure_count = 4; 
    baromeasurements.pressure_count = 4; 

    //encode the message 
    pressure_status = pb_encode_fixed32(&stream, &baromeasurements); 
    
    message_length = stream.bytes_written; 

    if (!pressure_status) {
        printf("Encoding failed %s\n", PB_GET_ERROR(&stream)); 
    }
    printf("baromeasurements.pressure_count is %i\n", baromeasurements.pressure_count); 
    printf("baromeasurements.icd_barometricpressure_count is %i\n", baromeasurements.icd_barometricpressure_count); 

    int i; 
    for (i = 0; i < (baromeasurements.pressure_count); i++) {
        printf("iteration: %lf\n", ideal[i].volum); 
        printf("iteration: %lf\n", baromeasurements.icd_barometricpressure[i]); 
    }

     //write binary output into a file named output.bin 
    FILE *f = fopen("baro_output.bin", "wb"); 
    fwrite(pressure_buffer, 1, stream.bytes_written, f); 
    fclose(f); 

}

return 0; 

}