cmake_minimum_required(VERSION 2.8 )
PROJECT(AdvancedCPP)
SET(sampleName AdvancedCPP)
include_directories("../inc")
include_directories("../src")

add_executable (AdvancedCPP 
                ../src/AdvancedCPP.cpp  
		../inc/AdvancedCPP.h )

TARGET_LINK_LIBRARIES(${sampleName}
"" # Optional extra libs...
)
# End of CMakeLists.Txt file. Save it as a plain text file and the name should be exactly CMakeLists.Txt
