cmake_minimum_required(VERSION 2.8 )
PROJECT(stl)
SET(sampleName stl)
include_directories("../inc")
include_directories("../src")

add_executable (stl 
                ../src/stl.cpp  
		../inc/stl.h )

TARGET_LINK_LIBRARIES(${sampleName}
"" # Optional extra libs...
)
# End of CMakeLists.Txt file. Save it as a plain text file and the name should be exactly CMakeLists.Txt
