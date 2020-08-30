obj-m += us_driver.o

KDIR := /work/achroimx6q/achroimx_kernel

all:
	make -C $(KDIR) SUBDIRS=$(PWD) modules

app:
	arm-none-linux-gnueabi-gcc us_app.c -o us_test -static
install:
	cp -a *.ko /nfsroot/
	cp -a *test /nfsroot/
clean:
	rm -rf *.ko
	rm -rf *.mod*
	rm -rf .*.cmd
	rm -rf *.o 
	rm -rf Module.symvers
	rm -rf modules.order
	rm -rf us_test
