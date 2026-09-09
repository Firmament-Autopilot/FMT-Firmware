import os
import SCons
import shutil

FMU_ROOT = os.path.normpath(os.getcwd() + '/../../..')

# DRONECAN DSDL
DSDLC_GEN_ROOT = os.path.normpath(os.getcwd() + '/build/dronecan_dsdlc_generated')

# DRONECAN LIB
DRONECAN_ROOT = FMU_ROOT + "/src/lib/dronecan"

def remove_files_by_suffix(root, suffix):
    for dir_path, dir_names, file_names in os.walk(root):
        for file_name in file_names:
            if file_name.endswith('.' + suffix):
                file_path = os.path.join(dir_path, file_name)
                os.remove(file_path)
                print("Removed ", file_path)

        for dir_name in dir_names:
            remove_files_by_suffix(os.path.join(dir_path, dir_name), suffix)

def delete_dronecan_dsdl():
    if not os.path.exists(DSDLC_GEN_ROOT):
        return
    remove_files_by_suffix(DSDLC_GEN_ROOT, 'c')
    remove_files_by_suffix(DSDLC_GEN_ROOT, 'h')
    shutil.rmtree(DSDLC_GEN_ROOT)



def generated_dronecan_dsdl():
    if not os.path.exists(DSDLC_GEN_ROOT):
        os.system("python " + DRONECAN_ROOT + "/dsdlc/dronecan_dsdlc.py -O " + DSDLC_GEN_ROOT + "  " + DRONECAN_ROOT + "/dsdl/uavcan " +  DRONECAN_ROOT + "/dsdl/ardupilot")
