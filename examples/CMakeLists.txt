include_directories (
    ${libseek-thermal_SOURCE_DIR}/src
    ${libseek-thermal_SOURCE_DIR}/examples
    ${OpenCV_INCLUDE_DIRS}
    /usr/include/libusb-1.0
    /home/bart/bebop_install/include
)

link_libraries (
    seek_static
#    -lboost_program_options
    ${OpenCV_LIBRARIES}
    /home/bart/bebop_install/lib/libusb-1.0.so
    /home/bart/bebop_install/lib/libnng.a
    pthread
)

#add_executable (seek_test seek_test.cpp)
#add_executable (seek_test_pro seek_test_pro.cpp)
#add_executable (seek_viewer seek_viewer.cpp args.h)
#add_executable (seek_create_flat_field seek_create_flat_field.cpp)
add_executable (seek_test_save seek_test_save.cpp publisher.cpp)

install (TARGETS
#    seek_test
#    seek_test_pro
#    seek_viewer
#    seek_create_flat_field
    seek_test_save
    DESTINATION "bin"
)
