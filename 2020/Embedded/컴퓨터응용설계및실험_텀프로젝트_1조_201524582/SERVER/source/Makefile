#before buildint it don't forget to export ROOTF_DIR and CROSS_COMPILER

APPNAME 		= SVR
TOOLCHAIN		= /opt/toolchains/arm-2014.05
CROSS_COMPILER		= $(TOOLCHAIN)/bin/arm-none-linux-gnueabi-
EXTERNAL_INCLUDE        = /work/achroimx6q/achroimx_kernel/include
CC			= $(CROSS_COMPILE)g++
DEL_FILE		= rm -rf
CP_FILE			= cp -rf      

TARGET_PATH_LIB 	= $(ROOTFS_DIR)/work/achroimx6q/achroimx6q_opencv/build/lib
TARGET_PATH_INCLUDE 	= $(ROOTFS_DIR)/usr/arm-linux-gnueabihf/include

CFLAGS			= -DLINUX -DUSE_SOC_MX6 -Wall -O2 -fpermissive -mfloat-abi=softfp\
			  -DEGL_API_FB -DGPU_TYPE_VIV -DGL_GLEXT_PROTOTYPES -DENABLE_GPU_RENDER_20 \
			  -I../include -I$(ROOTFS_DIR)/usr/src/linux/include -I$(TARGET_PATH_INCLUDE)

LFLAGS			= -Wl,--library-path=$(TARGET_PATH_LIB),-rpath-link=$(TARGET_PATH_LIB) -lm  -lpthread \
			   -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_imgcodecs
			   
OBJECTS			= server.o v4l_wrapper.o

first: all

all: $(APPNAME)

$(APPNAME): $(OBJECTS) 
	$(CC) -I $(EXTERNAL_INCLUDE) $(LFLAGS) -o $(APPNAME) $(OBJECTS) 

server.o: server.c
	$(CC) -I $(EXTERNAL_INCLUDE) $(CFLAGS) -c -o server.o server.c `pkg-config opencv --cflags --libs`

v4l_wrapper.o: v4l_wrapper.c
	$(CC) -I $(EXTERNAL_INCLUDE) $(CFLAGS) -c -o v4l_wrapper.o v4l_wrapper.c 

clean:
	$(DEL_FILE) $(OBJECTS)
	$(DEL_FILE) *~ *.core
	$(DEL_FILE) $(APPNAME)

distclean: clean
	$(DEL_FILE) $(APPNAME)

install: all
	$(DEL_FILE) $(APPNAME)

