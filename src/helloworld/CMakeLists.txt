add_executable(helloworld main.c)
install(
    TARGETS helloworld
    EXPORT helloworld
    DESTINATION bin
)