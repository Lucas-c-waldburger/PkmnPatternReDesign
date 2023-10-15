cmake_minimum_required(VERSION 3.24)
project(PkmnPatternReDesign)

set(CMAKE_CXX_STANDARD 17)

add_executable(PkmnPatternReDesign main.cpp include/IdentitiesBase.h CData/CDataIdentities.cpp CData/CDataIdentities.h Utils/CNameHash.cpp Utils/CNameHash.h CData/CardData.cpp CData/CardData.h Attacking/Attack.cpp Attacking/Attack.h Utils/Rand.cpp Utils/Rand.h Attacking/AttacksInterface.cpp Attacking/AttacksInterface.h Handler/Cost.cpp Handler/Cost.h Handler/ActiveHandler.cpp Handler/ActiveHandler.h Handler/ETypeModifiers.cpp Handler/ETypeModifiers.h CData/CDataEnums.h Handler/HitPoints.cpp Handler/HitPoints.h Player.cpp Player.h Zones/Zone.cpp Zones/Zone.h Card.cpp Card.h
        ProtoCD.cpp
        ProtoCD.h
        CardIDMaker.cpp
        CardIDMaker.h)
