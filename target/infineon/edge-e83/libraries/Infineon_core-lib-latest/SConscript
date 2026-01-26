from building import *
import rtconfig
Import('RTT_ROOT')

# get current directory
cwd = GetCurrentDir()
path = [cwd + '/include']
src = []

group = DefineGroup('Libraries', src, depend=[''], CPPPATH=path)
Return('group')
