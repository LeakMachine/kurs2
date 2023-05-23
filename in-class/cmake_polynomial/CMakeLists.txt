cmake_minimum_required(VERSION 3.6 FATAL_ERROR)


project(LabPolynomial)


include(cmake/function.cmake)    
                                 
								 


add_subdirectory(lib_list)
add_subdirectory(lib_polynomial)
add_subdirectory(main)

option(BTEST "build test?" ON)   

if(BTEST)                        
    add_subdirectory(gtest)      
    add_subdirectory(tests)      
endif()
