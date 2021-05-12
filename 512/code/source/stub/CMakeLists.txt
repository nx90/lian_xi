include_directories(${ROOT_PATH}/code/include)
aux_source_directory(. STUB_SOURCE)
add_library(STUB ${STUB_SOURCE})