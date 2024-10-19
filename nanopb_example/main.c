#include <stdio.h>
#include "pb_encode.h"
#include "pb_decode.h"
#include "message.pb.h"

int main()
{
   Example mymessage = {42};
uint8_t buffer[10];
pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));
pb_encode(&stream, Example_fields, &mymessage);

}