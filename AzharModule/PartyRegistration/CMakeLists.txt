project(PartyRegistration_by_azhar)

set(CMAKE_CXX_STANDARD 14)

add_executable(PartyRegistration_by_azhar
        main.cpp
        Party.cpp
        Person.cpp
        Address.cpp
        Candidate.cpp
        PartyCandidate.cpp
        PartyRegistration.h
        PartyRegistration.cpp)
