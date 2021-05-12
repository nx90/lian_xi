
set(CMAKE_CXX_STANDARD 14)

aux_source_directory(./ TEST_SOURCE)
#add_library(TEST ${TEST_SOURCE})
add_executable(client test_client.cpp ../code/include/protobufs.pb.cc)
add_executable(server test_server.cpp ../code/include/protobufs.pb.cc)
TARGET_LINK_LIBRARIES(client pthread protobuf)
TARGET_LINK_LIBRARIES(server pthread protobuf)