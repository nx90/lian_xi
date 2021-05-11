
set(CMAKE_CXX_STANDARD 14)

aux_source_directory(./ TEST_SOURCE)
#add_library(TEST ${TEST_SOURCE})
add_executable(myRPC ${TEST_SOURCE})
