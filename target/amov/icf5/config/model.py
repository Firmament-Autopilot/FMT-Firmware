# Modify this file to decide which model are compiled
from building import *

vehicle_type = GetOption('vehicle')

if vehicle_type == 'Multicopter':
    MODELS = [
        'plant/multicopter',
        'ins/base_ins',
        'fms/base_fms',
        'control/base_controller',
    ]
elif vehicle_type == 'Fixwing':
    MODELS = [
        'plant/fixwing',
        'ins/base_ins',
        'fms/fw_fms',
        'control/fw_controller',
    ]
elif vehicle_type == 'Template':
    MODELS = [
        'plant/template_plant',
        'ins/template_ins',
        'fms/template_fms',
        'control/template_controller',
    ]
else:
    raise Exception("Wrong VEHICLE_TYPE %s defined" % vehicle_type)