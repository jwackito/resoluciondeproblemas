#!/usr/bin/python
# -*- coding: utf-8 -*-

#  JBC - Joaquin Bogado Cypher
#  Copyright 2011 Joaquín I. Bogado García
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see
#    <http://www.gnu.org/licenses/>.

from sys import *
from struct import *


def lfsrotate():
	global lfsr
	# poly x³² + x²² + x² + x + 1
	bit  = ((lfsr >> 0) ^ (lfsr >> 10) ^ (lfsr >> 30) ^ (lfsr >> 31)) & 1
	#print "bit = " + str(bit) + "\n"
	lfsr = (lfsr >> 1) | (bit << 31)
	return lfsr

def hex2str(s):
	res = ""
	for i in range(len(s)/2):
		realIdx = i*2
		res = res + chr(int(s[realIdx:realIdx+2],16))
	return res

def str2hex(s):
	res = "" 
	for i in range(len(s)):
		res = res + "%02x" %ord(s[i])
	return res

def encrypt(ifile, ofile):
	global lfsr
	#ifile and ofile must be opened
	lfsr = lfsrotate()
	chunk=ifile.read(4)
	while (chunk != ""):
		echunk=(lfsr ^ int(str2hex(chunk),16))
		ofile.write("%08x" %echunk)#split 0x
		lfsrotate()
		chunk=ifile.read(4)
	print "Done"

def decrypt(ifile, ofile):
	global lfsr
	#ifile and ofile must be opened
	lfsr = lfsrotate()
	chunk=ifile.read(8)
	while (chunk != ""):
		#print int(chunk,16)
		echunk=(lfsr ^ int(chunk,16))
		ofile.write(hex2str("%04x" %echunk))
		lfsr = lfsrotate()
		chunk=ifile.read(8)
	print "Done"

def printusage():
	print "Usage:\tjbc.py input_file output_file [-c|-d]"
	print "\t\tjbc.py -h"
	print "\t-c crypt"
	print "\t-d decrypt"
	print "\t-h show this help"

if (len(argv) != 4):
	printusage()
	exit(1)

#input file to crypt/decrypt
ifile=open(argv[1], 'rb')
#output file 
ofile=open(argv[2], 'wb')
#password (max 4 chars)
print "Enter the password to for " + argv[1]
passfrase=stdin.read(4)

seed=int(str2hex(passfrase),16)
lfsr=seed
for i in range(10):
	lfsr = lfsrotate()
b=False
if argv[3] == "-c":
	encrypt(ifile, ofile)
	b=True
if argv[3] == "-d":
	decrypt(ifile, ofile)
	b=True
if not b:
	printusage()
