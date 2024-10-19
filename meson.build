project('nanopb', 'c', 'cpp',
    default_options : ['c_std=c11', 'cpp_std=c++14'])

nanopb_lib = library('nanopb-lib', 
                      ['nanopb_example/pb_encode.c',
                      'nanopb_example/pb_encode.h',
                      'nanopb_example/pb_decode.c',
                      'nanopb_example/pb_decode.h',
                      'nanopb_example/pb_common.c', 
                      'nanopb_example/pb_common.h', 
                      'nanopb_example/pb.h',
                      'pressure_example/pres.pb.c',
                      'pressure_example/pres.pb.h'], 
                      )

nanopb_dep = declare_dependency(link_with: [nanopb_lib])

#executable('publisher_aspn_c', [srcs,'publisher.c'], include_directories : [incdir], dependencies : [lcm_dep])
main_exec = executable('pressure_example_encode', 
                        ['/home/asyaakkus/protobuf_c_example/pressure_example/encode.c'],
                        dependencies : [nanopb_dep])

array_exec = executable('pressure_example_decode',
                        ['/home/asyaakkus/protobuf_c_example/pressure_example/decode.c'],
                        dependencies : [nanopb_dep])

baroarray_encode_exec = executable('array_encode_example',
                            ['/home/asyaakkus/protobuf_c_example/array_example/pressureencode.c'], 
                            dependencies : [nanopb_dep])


baroarray_decode_exec = executable('array_decode_example', 
                            ['/home/asyaakkus/protobuf_c_example/array_example/pressuredecode.c'],
                            dependencies : [nanopb_dep])