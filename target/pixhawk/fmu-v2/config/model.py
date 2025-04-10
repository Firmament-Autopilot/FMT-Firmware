# Modify this file to decide which model are compiled
from building import *

vehicle_type = GetOption('vehicle')
sim_mode = GetOption('sim')

if vehicle_type == 'Multicopter':
    if sim_mode == 'HIL':
        MODELS = [
            'plant/template_plant',
            'ins/external_ins',
            'fms/mc_fms',
            'control/mc_controller',
        ]
    else:
        MODELS = [
            'plant/multicopter',
            'ins/cf_ins',
            'fms/mc_fms',
            'control/mc_controller',
        ]
elif vehicle_type == 'Fixwing':
    if sim_mode == 'HIL':
        MODELS = [
            'plant/template_plant',
            'ins/external_ins',
            'fms/fw_fms',
            'control/fw_controller',
        ]
    else:
        MODELS = [
            'plant/fixwing',
            'ins/cf_ins',
            'fms/fw_fms',
            'control/fw_controller',
        ]
elif vehicle_type == 'Boat':
    if sim_mode == 'HIL':
        MODELS = [
            'plant/template_plant',
            'ins/external_ins',
            'fms/boat_fms',
            'control/boat_controller',
        ]
    else:
        MODELS = [
            'plant/boat',
            'ins/cf_ins',
            'fms/boat_fms',
            'control/boat_controller',
        ]
elif vehicle_type == 'Car':
    if sim_mode == 'HIL':
        MODELS = [
            'plant/template_plant',
            'ins/external_ins',
            'fms/car_fms',
            'control/car_controller',
        ]
    else:
        MODELS = [
            'plant/template_plant',
            'ins/cf_ins',
            'fms/car_fms',
            'control/car_controller',
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