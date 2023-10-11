cmake_minimum_required(VERSION 3.24)
project(PkmnPatternReDesign)

set(CMAKE_CXX_STANDARD 17)

add_executable(PkmnPatternReDesign main.cpp include/IdentitiesBase.h src/CDataIdentities.cpp include/CDataIdentities.h Utils/CNameHash.cpp Utils/CNameHash.h)
