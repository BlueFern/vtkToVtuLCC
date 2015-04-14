cmake_minimum_required (VERSION 2.6)

project (vtkToVtu)

find_package (VTK REQUIRED)
include (${VTK_USE_FILE})

set (TIME_IT_OR_NOT 0 CACHE BOOL "Print timing information?" FORCE) 

#foreach (lib ${VTK_LIBRARIES}) 
#    message (STATUS "==>> " ${lib} " <<++") 
#endforeach (lib)

configure_file (
    "${PROJECT_SOURCE_DIR}/src/TimeIt.h.in"
    "${PROJECT_BINARY_DIR}/TimeIt.h"
    )

include_directories ("${PROJECT_BINARY_DIR}")

add_executable (ConvertVtkToVtu src/vtkToVtu.cxx)
target_link_libraries(ConvertVtkToVtu vtkIOXML vtkIOMPIParallel)

add_executable(CheckVTKVersion src/CheckVTKVersion.cxx)

