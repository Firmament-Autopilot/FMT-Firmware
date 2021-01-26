cmake_policy(SET CMP0048 NEW)
project(unitary_tests LANGUAGES C CXX)

macro(unitary_test TEST_NAME TEST_SOURCE)
    set(SRCS ${TEST_SOURCE})

    add_executable(${TEST_NAME} ${TEST_SOURCE})

    set_common_compile_options(${TEST_NAME})

    if(MSVC OR MSVC_IDE)
        target_compile_options(${TEST_NAME} PRIVATE /wd4996)
    endif()

    add_gtest(${TEST_NAME} SOURCES ${TEST_SOURCE})

    get_target_property(CLIENT_INCLUDES microxrcedds_client INCLUDE_DIRECTORIES)
    include_directories(SYSTEM ${PROJECT_SOURCE_DIR}/../../src)

    target_link_libraries(${TEST_NAME}
        PRIVATE
            microcdr
            ${GTEST_BOTH_LIBRARIES}
            ${CMAKE_THREAD_LIBS_INIT}
        )

    target_include_directories(${TEST_NAME}
        PUBLIC
            ${PROJECT_SOURCE_DIR}
        PRIVATE
            ${GTEST_INCLUDE_DIRS}
            ${CLIENT_INCLUDES}
        )

    set_target_properties(${TEST_NAME} PROPERTIES
        CXX_STANDARD
            11
        CXX_STANDARD_REQUIRED
            YES
        )

endmacro()

unitary_test(StreamId               session/streams/StreamId.cpp)
unitary_test(SeqNum                 session/streams/SeqNum.cpp)
unitary_test(InputBestEffortStream  session/streams/InputBestEffortStream.cpp)
unitary_test(OutputBestEffortStream session/streams/OutputBestEffortStream.cpp)
unitary_test(CommonReliableStream   session/streams/CommonReliableStream.cpp)
unitary_test(InputReliableStream    session/streams/InputReliableStream.cpp)
unitary_test(OutputReliableStream   session/streams/OutputReliableStream.cpp)
unitary_test(StreamStorage          session/streams/StreamStorage.cpp)

unitary_test(ObjectId           session/ObjectId.cpp)
unitary_test(Submessage         session/Submessage.cpp)
unitary_test(SessionInfo        session/SessionInfo.cpp)
unitary_test(Session            session/Session.cpp)
unitary_test(WriteReadAccess    session/WriteReadAccess.cpp)

