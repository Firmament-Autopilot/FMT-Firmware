import os
import string

def get_git_version(gitPath):
    gitVersion = int(0)
    if os.path.isfile(os.path.join(gitPath, ".git")):
        f = file(os.path.join(gitPath, ".git"), "r")
        path = f.read()
        f.close()
        gitPath = os.path.join(gitPath, os.path.normpath(path.split()[1]))
        try:
            f = file(os.path.join(gitPath, 'HEAD'), "r")
            version = f.read()
            f.close()
            if 'ref' in version:
                gitPath = os.path.join(gitPath, os.path.normpath(version.split()[1]))
                f = file(gitPath, "r")
                version = f.read()
                f.close()
            gitVersion = string.atoi(version[0:8], 16)
            print('git version %x' %gitVersion)
        except:
            print('get git version error.')
            exit(-1)
    else:
        gitPath = os.path.join(gitPath, ".git")

        try:
            f = file(os.path.join(gitPath, 'HEAD'), "r")
            head = f.read()
            f.close()
            gitf = file(os.path.join(gitPath, os.path.normpath(head.split()[1])), "rb")
            version = gitf.read()
            gitf.close()
            gitVersion = string.atoi(version[0:8], 16)
            print('git version %x' %gitVersion)
        except:
            print('get git version error.')
            exit(-1)

    return gitVersion

def gen_header_file(gitVersion, filePath):
    try:
        f = file(filePath, 'wb')
        f.write('/* This file is auto generated, do not modify it! */\n')
        f.write('\n')
        f.write('#ifndef __FW_VERSION_H__\n')
        f.write('#define __FW_VERSION_H__\n')
        f.write('\n#define FW_VERSION 0x%x\n' %gitVersion)
        f.write('#define FW_VERSION_STR "%x"\n' %gitVersion)
        f.write('\n#endif\n')
        f.close()
    except:
        print('Generate %s file failed.' % filePath)
        exit(-1)


