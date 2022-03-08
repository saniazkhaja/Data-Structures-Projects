cmake_minimum_required(VERSION 3.20)
project(Project4_LabyrinthMazeGame)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

#ADD_SUBDIRECTORY (gtest-1.6.0)
#enable_testing()
#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(Project4_LabyrinthMazeGame tests.cpp)

#add_executable(Project4_LabyrinthMazeGameGDB ExploreTheRegularLabyrinth.cpp)
target_link_libraries(Project4_LabyrinthMazeGame gtest gtest_main)
#add_test(Project4_LabyrinthMazeGame Project4_LabyrinthMazeGame)
add_test(NAME Project4_LabyrinthMazeGame_test COMMAND Project4_LabyrinthMazeGame)


