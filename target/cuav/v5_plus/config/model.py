# Modify this file to decide which model are compiled
from building import *

vehicle_type = GetOption('vehicle')

if vehicle_type == 'Multicopter':
    MODELS = [
        'plant/multicopter',
        'ins/cf_ins',
        'fms/mc_fms',
        'control/mc_controller',
    ]
elif vehicle_type == 'Fixwing':
    MODELS = [
        'plant/fixwing',
        'ins/cf_ins',
        'fms/fw_fms',
        'control/fw_controller',
    ]
elif vehicle_type == 'Submarine':
    MODELS = [
        'plant/template_plant',
        'ins/cf_ins',
        'fms/submarine_fms',
        'control/submarine_controller',
    ]
elif vehicle_type == 'Boat_HIL':
    MODELS = [
        'plant/template_plant',
        'ins/external_ins',
        'fms/boat_fms',
        'control/boat_controller',
    ]
elif vehicle_type == 'Car_HIL':
    MODELS = [
        'plant/template_plant',
        'ins/external_ins',
        'fms/car_fms',
        'control/car_controller',
    ]
elif vehicle_type == 'Submarine_HIL':
    MODELS = [
        'plant/template_plant',
        'ins/external_ins',
        'fms/submarine_fms',
        'control/submarine_controller',
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