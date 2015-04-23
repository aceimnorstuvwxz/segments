#!python
#-*-coding:utf-8-*-

import sys,random,os
'''
Generate error code formated Java code
iichenbf@gmail.com
'''

raw = '''ERROR_GENERIC
ERROR_GENERIC
ERROR_PARSE_JSON
'''

codes_line_pat = '''
        case %s:
            return res.getString(android.R.string.%s);'''

def cms_err():
    words = raw.split('\n')
    for word in words:
        name = 'TP_CMS_ERR'+word[5:]
        low_name = name.lower()
        print low_name
    #end

def cms_err_codes():
    words = raw.split('\n')
    for word in words:
        tmp = 'TP_CMS_ERR' + word[5:]
        str_name = tmp.lower()
        print codes_line_pat%(word, str_name)

if __name__ == '__main__':
    cms_err()
    print '\n\n\n'
    cms_err_codes()
