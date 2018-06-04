obj-m += hid-magicmouse2.o
hid-magicmouse2-objs := ./src/hid-magicmouse2.o ./src/hid-magicmouse2-debug.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
