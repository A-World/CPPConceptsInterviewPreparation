cmake_minimum_required(VERSION 2.8 )
PROJECT(CPP_Understading)
SET(sampleName CPP_Understading)
include_directories("../inc")
include_directories("../src")

add_executable (CPP_Understading 
                ../src/Test.cpp  
				../src/Class1.cpp 
				../src/Class2.cpp 
				../src/Friend1.cpp 
				../src/Sample.cpp 
				../src/Inheritance.cpp 
				../src/FunctionOverloading.cpp 
				../inc/Generic.h )

TARGET_LINK_LIBRARIES(${sampleName}
"" # Optional extra libs...
)
# End of CMakeLists.Txt file. Save it as a plain text file and the name should be exactly CMakeLists.Txt