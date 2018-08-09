ifndef KERNEL
	KERNEL=$(shell uname -r)
endif

obj-m := admp441.o

all:
	make -C /lib/modules/${KERNEL}/build M=$(PWD) modules

clean:
	make -C /lib/modules/${KERNEL}/build M=$(PWD) clean

install:
	sudo cp admp441.ko /lib/modules/${KERNEL}
	sudo depmod -a
