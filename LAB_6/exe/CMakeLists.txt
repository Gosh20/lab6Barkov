add_library(tlib1 STATIC "main.cpp")
target_include_directories(tlib1 PUBLIC "../header")
add_executable (task "main.cpp")
target_link_libraries(task tlib1)