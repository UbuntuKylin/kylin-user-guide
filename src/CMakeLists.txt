project(kylin-user-guide C CXX)

#add_subdirectory(ipc)
#add_subdirectory(resources)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#cmake -D CMAKE_BUILD_TYPE=Debug
#if (CMAKE_BUILD_TYPE MATCHES Debug)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Werror -Wextra")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Werror -Wextra -fno-exceptions")
  # Enable Qt builtin debug mode
  add_definitions("-DQT_MESSAGELOGCONTEXT")
#else()
#  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O2 -Wl,-O1 -Wl,--gc-sections")
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2 -Wl,-O1 -Wl,--gc-sections")
#endif()

find_package(PkgConfig REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5DBus REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5LinguistTools)
find_package(Qt5Sql REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5LinguistTools REQUIRED)
find_package(Qt5WebChannel REQUIRED)
find_package(Qt5WebKitWidgets REQUIRED)
#find_package(Qt5WebEngineWidgets REQUIRED)
#pkg_search_module(QCef REQUIRED libqcef)
#include_directories(${QCef_INCLUDE_DIRS})

#https://blog.csdn.net/qq_38410730/article/details/102797448
#add_custom_command(OUTPUT _update-search-db
 #                  COMMAND pwd
#                   COMMAND ${CMAKE_CURRENT_BINARY_DIR}/generate-search-db
 #                  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/
#                   )
#add_custom_target(update-search-db DEPENDS _update-search-db)
#add_dependencies(update-search-db generate-search-db)

EXECUTE_PROCESS(COMMAND arch OUTPUT_VARIABLE
    DEB_BUILD_GNU_CPU OUTPUT_STRIP_TRAILING_WHITESPACE)

#头文件目录
set(HRADERS_QT
${Qt5DBus_INCLUDE_DIRS}
${Qt5Gui_INCLUDE_DIRS}
${Qt5Quick_INCLUDE_DIRS}
${Qt5QuickWidgets_INCLUDE_DIRS}
${Qt5Widgets_INCLUDE_DIRS}
${Qt5WebChannel_INCLUDE_DIRS}
#${Qt5WebEngineWidgets_INCLUDE_DIRS}//crash
${Qt5WebKitWidgets_INCLUDE_DIRS}
)

#message(${HRADERS_QT})
include_directories(${HRADERS_QT} ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
#库目录
#link_directories("../../lib/Linux/${DEB_BUILD_GNU_CPU}" )

file(GLOB CC_FILES *.cpp common-tool/*.cpp ipc/*.cpp)

add_executable(kylin-user-guide ${CC_FILES})

SET(LIBS_PRIVATE "-lrt -ldl -lpthread")
SET(QT_LIBS
    Qt5::Core
    Qt5::DBus
    Qt5::Sql
    Qt5::Widgets
    Qt5::WebChannel
    Qt5::WebKitWidgets
    )
#    Qt5::WebEngineWidgets
message(${QT_LIBS})
target_link_libraries(kylin-user-guide ${QT_LIBS} ${LIBS_PRIVATE})

set(pkgLibdir 	/usr/lib/${DEB_BUILD_GNU_CPU})
set(pkgbindir 	/usr/bin/)
set(pkgdatadir 	/usr/share/kylin-user-guide)

## Installation
#install(TARGETS kylin-user-guide DESTINATION ${CMAKE_INSTALL_PREFIX}/share/kylin-user-guide)
install(TARGETS kylin-user-guide DESTINATION ${pkgbindir})
