#设置编译选项
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -ggdb -std=c++11 -DBOOST_LOG_DYN_LINK")

#设置头文件包含路径
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})
#INCLUDE_DIRECTORIES(/usr/local/include/boost/)
#INCLUDE_DIRECTORIES(/usr/local/include/)
#INCLUDE_DIRECTORIES(/usr/include/)
#INCLUDE_DIRECTORIES(/usr/include/cppconn/)

#打印消息
#MESSAGE(status ,"---设置头文件包含路径----")
#MESSAGE(status ,"${PROJECT_SOURCE_DIR}")
#MESSAGE(status ,"/usr/local/include/boost/")
#MESSAGE(status ,"/usr/local/include/")
#MESSAGE(status ,"/usr/include/")
#MESSAGE(status ,"/usr/include/cppconn/")

#设置库文件包含路径
#LINK_DIRECTORIES(/usr/local/lib/)
#LINK_DIRECTORIES(/usr/local/lib64/)
#LINK_DIRECTORIES(/usr/lib/)
#LINK_DIRECTORIES(/usr/lib64/)

#MESSAGE(status ,"---设置库文件包含路径----")
#MESSAGE(status ,"/usr/local/lib/")
#MESSAGE(status ,"/usr/local/lib64/")
#MESSAGE(status ,"/usr/lib/")
#MESSAGE(status ,"/usr/lib64/")

#源文件
FILE(GLOB MAIN_SRC ${PROJECT_SOURCE_DIR}/Test/*.cpp)

#生成可执行文件
ADD_EXECUTABLE(test.out ${LOG_SRC} ${MAIN_SRC} ${BASE_SERVER_SRC} 
${BASE_CONFIG_SRC} ${CONFIG_SRC} ${CONNECTION_SRC} ${MYSQLPOOL_SRC} 
${PACKET_SRC} ${SERVICEPOOL_SRC} ${SINGLETON_SRC} ${SOCKET_SRC} 
${SYNERGYWORKER_SRC} ${TIMER_SRC} ${TIMETOOL_SRC} ${UTILITY_SRC} ${MYSQLPOOL_SRC})

#链接库文件
TARGET_LINK_LIBRARIES(test.out libboost_system.so libboost_log.so libboost_log_setup.so libboost_thread.so libpthread.so libboost_chrono.so libmysqlcppconn.so)

#设置输出路径
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


