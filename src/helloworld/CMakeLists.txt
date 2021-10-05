add_executable(helloworld main.c)
target_link_libraries(helloworld ${ncurses_LIBRARIES})
install(
    TARGETS helloworld
    EXPORT helloworld
    DESTINATION bin
)