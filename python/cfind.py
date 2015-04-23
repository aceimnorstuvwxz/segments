#!/usr/bin/python
#-*-coding:utf-8-*-

import sys,random,os

cpright = '''cfind v0.1 A customed find tool
Usage: cfind.py keyword
It will find all files and lines in the current and inner directories.'''

keyword = ""

def myDealFile(fn):
    if keyword in fn:
        print "FILE NAME", fn

    f = open(fn, "r")
    lines = f.readlines()
    lno = 1
    for _line in lines:
        if keyword in _line:
            if len(_line) > 0:
                print "FILE LINE", fn, "(%d)"%lno, _line[:-1]
        lno = lno + 1
    f.close()

def myDealDir(fn):
    if keyword in fn:
        print "DIRECTORY", fn


def walk(fn, deep, dealFile, dealDir):
    '''walk down the directories'''
    list =  os.listdir(fn)
    for line in list:
        fileDir = os.path.join(fn, line)
        if os.path.isdir(fileDir):
        	dealDir(fileDir)
        	walk(fileDir, deep + 1, dealFile, dealDir)
        else:
        	dealFile(fileDir)

if __name__ == '__main__':
	if len(sys.argv) != 2 :
		print cpright
	else :
		keyword = sys.argv[1]
		print 'keyword is "%s", result is :'%keyword
		walk('.', 0, myDealFile, myDealDir)



    