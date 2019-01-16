cmake_minimum_required(VERSION 3.4)
project(port)

set(BOOST_ROOT "/usr/lib64")

set(SOURCE_FILES
	src/Place.cpp
		include/RenterType.hpp src/Yacht.cpp include/Yacht.hpp src/Motorboat.cpp include/Motorboat.hpp src/Renter.cpp include/Renter.hpp src/RentersManager.cpp include/RentersManager.hpp src/Rent.cpp include/Rent.hpp include/RentsManager.hpp src/RentsManager.cpp include/Repo.hpp src/Repo.cpp src/PlaceManager.cpp include/PlaceManager.hpp src/RentException.cpp include/RentException.hpp)

find_package(Boost 1.60 REQUIRED)

add_library(port ${SOURCE_FILES} ${Boost_LIBRARIES})

target_include_directories(port PUBLIC include ${Boost_INCLUDE_DIRS})

enable_testing()

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
 ${CMAKE_CURRENT_SOURCE_DIR}/include
 ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_HUMAN_FILES
 test/master.cpp
 test/PlaceTest.cpp
 include/RenterType.hpp src/Yacht.cpp include/Yacht.hpp src/Motorboat.cpp include/Motorboat.hpp src/Renter.cpp include/Renter.hpp
 src/RentersManager.cpp include/RentersManager.hpp src/Rent.cpp include/Rent.hpp include/RentsManager.hpp src/RentsManager.cpp include/Repo.hpp src/Repo.cpp src/PlaceManager.cpp include/PlaceManager.hpp
		test/RenterTest.cpp test/RentTest.cpp test/RepoTest.cpp test/ManagerTest.cpp)

add_executable (Tests ${SOURCE_TEST_HUMAN_FILES})

target_link_libraries (Tests
 port
 boost_date_time
 ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
 )

#dodaj test Tests. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(TestPortu Tests
 --report_level=detailed
 --log_level=all
 --color_output=yes
 --show_progress=true
 )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
