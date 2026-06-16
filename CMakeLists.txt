cmake_minimum_required(VERSION 4.0)
project(Tarea_5)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tarea_5 main.cpp
        CrearHash.h
        Voto.cpp
        Voto.h
        Block.cpp
        Block.h
        Blockchain.cpp
        Blockchain.h
        CentroElectoralSubject.cpp
        CentroElectoralSubject.h
        MesaElectoral.cpp
        MesaElectoral.h
        MesaElectoralObserver.h

)
