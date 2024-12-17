cmake_minimum_required (VERSION 3.11)
set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "--coverage -g -O0")
include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)

ADD_SUBDIRECTORY(test/googletest)

FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG main # Important: Specify a version or a commit hash here.
)
FetchContent_MakeAvailable(ftxui)
 
project(asciimon LANGUAGES CXX VERSION 1.0.0)
add_executable(asciimon
  src/main.cpp
  src/Move.cpp
  src/Trainer.cpp
  src/BattleSimulator.cpp
  src/BattleMechanics.cpp
  src/BattleResults.cpp
  src/HitDetails.cpp
  src/Asciimon.cpp
  src/Move.cpp
  src/Statistics.cpp
  src/ComputerPlayer.cpp
  src/HumanPlayer.cpp
  src/Terminal.cpp
  src/Stats.cpp
  src/PlayerMove.cpp
  src/AsciimonCodex.cpp
  src/StatGenerator.cpp
  src/TrainerGenerator.cpp
)
target_link_libraries(asciimon
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component # Not needed for this example.
)
add_compile_options(--coverage -g -O0)

add_executable(tests
  src/Move.cpp
  src/Trainer.cpp
  src/BattleSimulator.cpp
  src/BattleMechanics.cpp
  src/BattleResults.cpp
  src/HitDetails.cpp
  src/Asciimon.cpp
  src/Move.cpp
  src/Statistics.cpp
  src/ComputerPlayer.cpp
  src/HumanPlayer.cpp
  src/Terminal.cpp
  src/Stats.cpp
  src/PlayerMove.cpp
  src/AsciimonCodex.cpp
  src/StatGenerator.cpp
  test/BattleTester.cpp
  test/AsciimonTester.cpp
  test/BattleResultsTester.cpp
  test/ComputerPlayerTester.cpp
  test/PlayerMoveTester.cpp
  test/MechanicsTester.cpp
  test/HitDetailsTester.cpp
  test/MoveTester.cpp
  test/TrainerTester.cpp
  test/MainTester.cpp
  test/TerminalTester.cpp
  src/TrainerGenerator.cpp
)
target_link_libraries(tests
  PRIVATE gtest
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component # Not needed for this example.
)
TARGET_COMPILE_DEFINITIONS(tests PRIVATE gtest_disable_pthreads=ON)
