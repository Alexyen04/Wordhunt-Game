cmake_minimum_required(VERSION 3.16)
project(WordHunt CXX)

find_package(SFML 2.5.1 REQUIRED COMPONENTS graphics)

add_executable(WordHunt 
    main.cpp 
    ButtonCustom.cpp 
    ButtonRenderer.cpp
    Board.cpp
    Piece.cpp
    Dictionary.cpp
    Settings.cpp
    WordValidator.cpp
    WordScoreCalculator.cpp
    DefaultWordScorer.cpp
    CustomWordList.cpp
    FileLoader.cpp
    TextRenderer.cpp
    Text.cpp
    Slider.cpp
)

target_link_libraries(WordHunt PRIVATE sfml-graphics)
target_compile_features(WordHunt PRIVATE cxx_std_17)