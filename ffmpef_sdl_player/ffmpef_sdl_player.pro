TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        demuxthread.cpp \
        log.cpp \
        main.cpp \
        thread.cpp


# MacOS 下导入库
# 设置头文件路径
INCLUDEPATH += /usr/local/ffmpeg/include

# 设置库文件路径
LIBS += -L /usr/local/ffmpeg/lib \
        -lavcodec \
        -lavdevice \
        -lavfilter \
        -lavformat \
        -lavutil \
        -lpostproc \
        -lswscale \
        -lswresample

HEADERS += \
    demuxthread.h \
    log.h \
    thread.h
