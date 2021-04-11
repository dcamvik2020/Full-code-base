#! /bin/sh

readelf -e -W $1
# symbols:
#readelf -s $1
#objdump -t $1
#nm $1
objdump -d -M intel -w $1
gdb -q $1
