cmake_minimum_required(VERSION 3.17)
project(css_verbalizer C)

set(CMAKE_C_STANDARD 11)

include_directories("CSS manipulator")

add_executable(css_verbalizer
    anubhavDS-C/helpers.c
    "CSS manipulator/color.c"
    "CSS manipulator/manipulator.c"
    "CSS manipulator/RulesSelectors.c"
    "CSS manipulator/token_DS.c"
    "CSS manipulator/tokenizer.c"
    "CSS manipulator/tokenizer.h"
    "CSS manipulator/verbalizer.c")
