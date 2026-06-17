from building import *
import rtconfig
Import('RTT_ROOT')

# get current directory
cwd = GetCurrentDir()
src = []
path = []

if GetDepend(['RT_USING_SERIAL']):
    src = ['cy_retarget_io.c']
    path = [cwd]


group = DefineGroup('Libraries', src, depend=[''], CPPPATH=path)
Return('group')
