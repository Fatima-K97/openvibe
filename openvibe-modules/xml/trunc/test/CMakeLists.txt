INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src)
LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})
ADD_DEFINITIONS(-D_CRT_SECURE_NO_DEPRECATE)
ADD_EXECUTABLE(test_xml_write-dynamic test_xml_write.cpp)
ADD_EXECUTABLE(test_xml_read-dynamic test_xml_read.cpp)
TARGET_LINK_LIBRARIES(test_xml_write-dynamic ${PROJECT_NAME})
TARGET_LINK_LIBRARIES(test_xml_read-dynamic ${PROJECT_NAME})
