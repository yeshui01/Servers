CMAKE_MINIMUM_REQUIRED(VERSION 2.6.3)
PROJECT(test)

#设置编译选项
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -ggdb -std=c++11 -DBOOST_LOG_DYN_LINK")

#设置头文件包含路径
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})
INCLUDE_DIRECTORIES(/usr/local/include/boost/)
INCLUDE_DIRECTORIES(/usr/local/include/)
INCLUDE_DIRECTORIES(/usr/include/)
INCLUDE_DIRECTORIES(/usr/include/cppconn/)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/ThirdParty/jsoncpp/include/)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/TServerBaseEx/)

#打印消息
MESSAGE(status ,"---设置头文件包含路径----")
MESSAGE(status ,"${PROJECT_SOURCE_DIR}")
MESSAGE(status ,"/usr/local/include/boost/")
MESSAGE(status ,"/usr/local/include/")
MESSAGE(status ,"/usr/include/")
MESSAGE(status ,"/usr/include/cppconn/")
MESSAGE(status ,"${PROJECT_SOURCE_DIR}/ThirdParty/jsoncpp/include/")

#设置库文件包含路径
LINK_DIRECTORIES(/usr/local/lib/)
LINK_DIRECTORIES(/usr/local/lib64/)
LINK_DIRECTORIES(/usr/lib/)
LINK_DIRECTORIES(/usr/lib64/)
#LINK_DIRECTORIES(../ThirdParty/jsoncpp/lib/)

MESSAGE(status ,"---设置库文件包含路径----")
MESSAGE(status ,"/usr/local/lib/")
MESSAGE(status ,"/usr/local/lib64/")
MESSAGE(status ,"/usr/lib/")
MESSAGE(status ,"/usr/lib64/")

#源文件
FILE(GLOB LOG_SRC ${PROJECT_SOURCE_DIR}/TServerBaseEx/tlog/*.cpp)

FILE(GLOB BASE_SERVER_SRC ${PROJECT_SOURCE_DIR}/TServerBaseEx/tbase_server/*.cpp)
FILE(GLOB BASE_CONFIG_SRC ${PROJECT_SOURCE_DIR}/TServerBaseEx/tbase_config/*.cpp)
FILE(GLOB CONFIG_SRC ${PROJECT_SOURCE_DIR}/TServerBaseEx/tconfig/*.cpp)
FILE(GLOB CONNECTION_SRC ${PROJECT_SOURCE_DIR}/TServerBaseEx/tconnection/*.cpp)
FILE(GLOB MYSQLPOOL_SRC ${PROJECT_SOURCE_DIR}/TServerBaseEx/tmysqlpool/*.cpp)
FILE(GLOB PACKET_SRC ${PROJECT_SOURCE_DIR}/TServerBaseEx/tpacket/*.cpp)
FILE(GLOB SERVICEPOOL_SRC ${PROJECT_SOURCE_DIR}/TServerBaseEx/tservice_pool/*.cpp)
FILE(GLOB SINGLETON_SRC ${PROJECT_SOURCE_DIR}/TServerBaseEx/tsingleton/*.cpp)
FILE(GLOB SOCKET_SRC ${PROJECT_SOURCE_DIR}/TServerBaseEx/tsocket/*.cpp)
FILE(GLOB SYNERGYWORKER_SRC ${PROJECT_SOURCE_DIR}/TServerBaseEx/tsynergy_worker/*.cpp)
FILE(GLOB TIMER_SRC ${PROJECT_SOURCE_DIR}/TServerBaseEx/ttimer/*.cpp)
FILE(GLOB TIMETOOL_SRC ${PROJECT_SOURCE_DIR}/TServerBaseEx/ttimetool/*.cpp)
FILE(GLOB UTILITY_SRC ${PROJECT_SOURCE_DIR}/TServerBaseEx/tutility/*.cpp)

#静态库文件
#SET(JSONCPPLIB ../ThirdParty/jsoncpp/lib/libjson_linux-gcc-4.8.5_libmt.a)
FIND_LIBRARY(JSONCPP_LIB libjson_linux-gcc-4.8.5_libmt.a ${PROJECT_SOURCE_DIR}/ThirdParty/jsoncpp/lib/ NO_DEFAULT_PATH)

ADD_SUBDIRECTORY(Test)
