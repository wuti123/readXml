TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    include/tinystr.cpp \
    include/tinyxml.cpp \
    include/tinyxmlerror.cpp \
    include/tinyxmlparser.cpp \
    src/initialxml.cpp


HEADERS += \
    include/initialxml.h \
    include/tinystr.h \
    include/tinyxml.h

