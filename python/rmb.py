#!python  
#-*-coding:utf-8-*-  

import sys,random,os

'''
用来去掉代码红块，用4空格取代TAB，去掉行末空格与TAB。
使用方法：
1,安装python2.7
2,在命令行./rmb.py 文件1 文件2 文件3 。。。 
或
直接运行，则会处理本目录下所有文件。(.h .c .cpp)

release note:
2014年12月23日： 加.cpp支持
'''
def sucks(line):
    '''do the real job'''
    myline = ""
    for ch in line:
        if ord(ch) == 9:
            myline = myline + "    "
        else:
            myline = myline + str(ch)
    imax = 0
    for i in xrange(len(myline)):
        c = myline[i]
        if ord(c) > 33:
            imax = i + 1
    return myline[:imax]

def rmb(fn):
    '''fn: file name'''
    print fn
    #open the file
    f_code = open(fn,'r+')
    lns_bef = []
    lns_aft = []

    lns_bef = f_code.readlines()
    for _line in lns_bef:
        lns_aft.append(sucks(_line))

    #write back
    f_code.seek(0)
    for _line in lns_aft:
        f_code.write(_line)
        f_code.write("\n")
    #f_code.writelines(lns_aft)
    f_code.truncate()
    f_code.flush()
    f_code.close()

if __name__ == '__main__':
    print 'v0.2 2014-5-27'
    if len(sys.argv)>1:
        for _var in sys.argv[1:]:
            print _var
            rmb(_var)
    else:
        _fns_ch = filter(lambda fn:len(fn)>=2 and ( cmp(fn[-2:].upper(),".H")==0 or cmp(fn[-2:].upper(),".C") == 0 or cmp(fn[-4:].upper(),".CPP") == 0), os.listdir(os.getcwd()))
        print _fns_ch

        map(rmb,_fns_ch)
    
    print "DONE"
    
