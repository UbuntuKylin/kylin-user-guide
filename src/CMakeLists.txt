project(kylin-user-guide C CXX)

#add_subdirectory(ipc)
add_subdirectory(resources)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

if (CMAKE_BUILD_TYPE MATCHES Debug)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Werror -Wextra")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Werror -Wextra -fno-exceptions")
  # Enable Qt builtin debug mode
  add_definitions("-DQT_MESSAGELOGCONTEXT")
else()
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O2 -Wl,-O1 -Wl,--gc-sections")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2 -Wl,-O1 -Wl,--gc-sections")
endif()

find_package(PkgConfig REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5DBus REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5LinguistTools)
find_package(Qt5Sql REQUIRED)
find_package(Qt5WebChannel REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5LinguistTools REQUIRED)
pkg_search_module(QCef REQUIRED libqcef)
include_directories(${QCef_INCLUDE_DIRS})

set(LINK_LIBS
    Qt5::Core
    Qt5::DBus
    Qt5::Sql
    Qt5::Widgets
    Qt5::WebChannel
    ${QCef_LDFLAGS}
    )


#https://blog.csdn.net/qq_38410730/article/details/102797448
#add_custom_command(OUTPUT _update-search-db
 #                  COMMAND pwd
#                   COMMAND ${CMAKE_CURRENT_BINARY_DIR}/generate-search-db
 #                  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/
#                   )
#add_custom_target(update-search-db DEPENDS _update-search-db)
#add_dependencies(update-search-db generate-search-db)

add_executable(kylin-user-guide
               main.cpp
               )
## Installation
install(TARGETS dman DESTINATION ${CMAKE_INSTALL_PREFIX}/share/kylin-user-guide)

