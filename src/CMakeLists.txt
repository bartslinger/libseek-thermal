set (HEADERS
    SeekCam.h
    SeekDevice.h
    seek.h
    SeekLogging.h
    SeekThermal.h
    SeekThermalPro.h
)

set (SOURCES
    SeekCam.cpp
    SeekDevice.cpp
    SeekThermal.cpp
    SeekThermalPro.cpp
)

set (SRC ${SOURCES} ${HEADERS})

include_directories (
    /home/bart/install_bebop/include/libusb-1.0
    ${OpenCV_INCLUDE_DIRS}
)

add_library (seek_static STATIC ${SRC})
add_library (seek SHARED ${SRC})

target_link_libraries (seek
    ${OpenCV_LIBS}
    /home/bart/install_bebop/lib/libusb-1.0.so
)

# install library target and header files
install (TARGETS
    seek
    DESTINATION "lib"
)

install (FILES ${HEADERS}
    DESTINATION "include/seek"
)
