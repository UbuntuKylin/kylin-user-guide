#daemon ...
file(GLOB CC_FILES *.cpp ../common-tool/*.cpp ipc/*.cpp)

add_executable(user-guide-daemon ${CC_FILES})
set_target_properties(user-guide-daemon PROPERTIES AUTOMOC TRUE)

target_link_libraries(user-guide-daemon ${QT_LIBS})

install(TARGETS user-guide-daemon RUNTIME DESTINATION ${pkgbindir})
