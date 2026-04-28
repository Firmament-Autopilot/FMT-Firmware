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
elif vehicle_type == 'VTOL':
    if sim_mode == 'HIL':
        MODELS = [
            'plant/template_plant',
            'ins/external_ins',
            'fms/vtol_fms',
            'control/vtol_controller',
        ]
    else:
        MODELS = [
            'plant/vtol',
            'ins/cf_ins',
            'fms/vtol_fms',
            'control/vtol_controller',
        ]
else:
    MODELS = []
