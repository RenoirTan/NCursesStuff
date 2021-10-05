add_executable(keylogger main.c)
target_link_libraries(keylogger ${ncurses_LIBRARIES})
install(
    TARGETS keylogger
    EXPORT keylogger
    DESTINATION bin
)