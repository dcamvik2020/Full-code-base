#! /bin/sh

as --32 -msyntax=intel -mmnemonic=intel -mnaked-reg -a -ad $1.s > $1.lst
