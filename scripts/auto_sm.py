#!/usr/bin/env python

import rospy
from transitions import Machine

class AutonomousStateMachine():
    states = ['Loiter', 'Avoid', 'Traverse', 'Search', 'Destroy']
    
    def __init__(self):
        transitions = [

        {'trigger':'abortMission', 'source':'*', 'dest':'Loiter'},
        {'trigger':'startMission', 'source':'Loiter', 'dest':'Traverse'},
        {'trigger':'obsDetected', 'source':'Traverse', 'dest':'Auto'},
        {'trigger':'obsClear', 'source':'Auto', 'dest':'Traverse'},
        {'trigger':'routeComplete', 'source':'Traverse', 'dest':'Search'},
        {'trigger':'ballDetected', 'source':'Search', 'dest':'Destroy'},
        {'trigger':'ballLost', 'source':'Destroy', 'dest':'Search'},
        {'trigger':'ballFound', 'source':'Destroy', 'dest':'Loiter'}

        ]

        self.mach = Machine(model = self, states = AutonomousStateMachine.states, initial = 'Traverse', transitions = transitions, ignore_invalid_triggers=True)

    

    
