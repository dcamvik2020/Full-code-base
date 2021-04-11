TEMPLATE = app
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ells.c


win32: LIBS += -lgdi32

win32: LIBS += -lcomctl32

OBJECTS += iconres.o
