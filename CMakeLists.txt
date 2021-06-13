cmake_minimum_required(VERSION 3.0)

project(hello_world)

include_directories(${PROJECT_SOURCE_DIR} /usr/local/include/ttsmimic)
add_executable(mimic_example main.c)
target_link_libraries(mimic_example
                                    ttsmimic_lang_usenglish
                                    ttsmimic_lang_cmulex
                                    ttsmimic)
