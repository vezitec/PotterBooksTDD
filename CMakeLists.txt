cmake_minimum_required(VERSION 3.12)
project(PotterBooksTDD CXX)

SET(SRCS
        src/basket.cpp
)
SET(UTS
        ut/basketTests.cpp
)

add_compile_options(-Wall -Wextra -pedantic -Werror)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

FetchContent_MakeAvailable(googletest)
add_library(potterBooks ${SRCS})
target_compile_features(potterBooks PUBLIC cxx_std_20)
target_include_directories(potterBooks PUBLIC include)

add_executable(potterBooks_tests ${UTS} )
target_link_libraries(potterBooks_tests potterBooks gmock_main gtest gmock)
target_compile_features(potterBooks_tests PUBLIC cxx_std_20)
target_include_directories(potterBooks_tests PUBLIC include)


add_custom_target(run_tests
                  COMMAND potterBooks_tests
                  DEPENDS potterBooks_tests)

enable_testing()
add_test(tests potterBooks_tests)
