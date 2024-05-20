
set(PROJECT_SRC
        greeter/greet.cpp
        factorial/factorial.c
)



add_library(core STATIC ${PROJECT_SRC})



target_include_directories(core PUBLIC ${CMAKE_SOURCE_DIR}/include)



target_compile_options(core PRIVATE ${WARNING_FLAGS} ${SUPPRESS_WARNING_FLAGS} ${OPTIMIZE_FLAGS})

if(DEBUG_INFO)
    target_compile_options(core PRIVATE ${DEBUG_FLAGS})
endif()



add_executable(${PROJECT_NAME} main.cpp)


target_link_libraries(core PRIVATE Threads::Threads)

target_link_libraries(${PROJECT_NAME} PRIVATE core)


target_compile_options(${PROJECT_NAME} PRIVATE ${WARNING_FLAGS} ${SUPPRESS_WARNING_FLAGS} ${OPTIMIZE_FLAGS})



set(DEFAULT_INSTALL_DIR ${CMAKE_SOURCE_DIR}/bin)        
set(INSTALL_DIR .)      
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT) 
        set(INSTALL_DIR ${DEFAULT_INSTALL_DIR})
endif()

install(TARGETS ${PROJECT_NAME}
        DESTINATION ${INSTALL_DIR}
        )
