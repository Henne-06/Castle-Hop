cmake_minimum_required(VERSION 3.14)

#Name des Projekts: 2D-Game
project(2D-Game)

#C++ Standard festlegen
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Erlaubt ältere Richtlinien für Bibliotheken wie Freetype (SFML)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)


#SFML über GitHub einbinden
include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        3.0.0
)
FetchContent_MakeAvailable(SFML)

#Das eigentliche Programm (Executable) definieren
add_executable(2D-Game src/main.cpp)

#SFML-Module verknüpfen
target_link_libraries(2D-Game PRIVATE SFML::Graphics SFML::Window SFML::System)
