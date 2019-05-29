cmake_minimum_required(VERSION 3.5)
project(RRS_Clion)

message(STATUS "start running cmake...")
#Boost libraries finding
find_package(Boost 1.58.0 COMPONENTS system filesystem unit_test_framework REQUIRED)

if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})

endif()

#UHD libraries finding

find_package(UHD)
if(UHD_FOUND)

    message(STATUS "UHD_INCLUDE_DIRS: ${UHD_INCLUDE_DIRS}")
    message(STATUS "UHD_LIBRARIES: ${UHD_LIBRARIES}")
    message(STATUS "UHD_VERSION: ${UHD_VERSION}")

    include_directories(${UHD_INCLUDE_DIRS})

endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
enable_testing()

add_executable(RRS_Clion ETSI_RRS_SpectrumControlServices.cpp ETSI_RRS_SpectrumControlServices.h ETSI_RRS_PowerControlServices.cpp ETSI_RRS_PowerControlServices.h ETSI_RRS_AntennaManagementServices.cpp ETSI_RRS_AntennaManagementServices.h ETSI_RRS_RRFI.cpp ETSI_RRS_RRFI.h ETSI_RRS_TxRxChainControlServices.cpp ETSI_RRS_TxRxChainControlServices.h ETSI_RRS_USRP_Device.cpp ETSI_RRS_USRP_Device.h ETSI_RRS_RRFITests.cpp)

if(UHD_FOUND)

    target_link_libraries(RRS_Clion ${UHD_LIBRARIES})

endif()

if(Boost_FOUND)

    target_link_libraries(RRS_Clion ${Boost_LIBRARIES})

endif()

target_link_libraries(RRS_Clion ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test(NAME Test COMMAND RRS_Clion)
