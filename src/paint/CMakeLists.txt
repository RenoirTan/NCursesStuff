add_executable(paint main.c paint.c)
target_link_libraries(paint ${ncurses_LIBRARIES})
install(
    TARGETS paint
    EXPORT paint
    DESTINATION bin
)