import PySimpleGUI as sg
from vehicle_pid import start

if __name__ == "__main__":
    sg.theme('DarkAmber')   # Add a little color to your windows
    # All the stuff inside your window. This is the PSG magic code compactor...
    layout = [  
                [sg.Text('Enter the load of vehicle'), sg.InputText()],
                [sg.Text('Enter the cargo load'), sg.InputText()],
                [sg.Text('Enter time of Simulation'), sg.InputText()],
                [sg.Text('Breakpoint times should range from 0 to time of simulation')],
                [sg.Text('Breakpoint 1 is the first time when hilly terrain occurs')],
                [sg.Text('Enter the breakpoint 1 in (sec) The position where the velocity of car changes'), sg.InputText()],
                [sg.Text('Enter the terrain value 1 (between 0 to 25) greater value is more steep slope'), sg.InputText()],
                [sg.Text('Breakpoint 2 is the first time when hilly terrain occurs')],
                [sg.Text('Enter the breakpoint 2 in (sec) The position where the velocity of car changes'), sg.InputText()],
                [sg.Text('Enter the terrain value 2 (between 0 to 25) greater value is more steep slope'), sg.InputText()],
                [sg.Text('Breakpoint 3 is the first time when hilly terrain occurs')],
                [sg.Text('Enter the breakpoint 3 in (sec) The position where the velocity of car changes'), sg.InputText()],
                [sg.Text('Enter the terrain value 3 (between 0 to 25) greater value is more steep slope'), sg.InputText()],
                [sg.Text('Breakpoint 4 is the first time when slope occurs')],
                [sg.Text('Enter the breakpoint 4 in (sec) The position where the velocity of car changes'), sg.InputText()],
                [sg.Text('Enter the terrain value 4 (between 0 to 25) greater value is more steep slope'), sg.InputText()],
                [sg.OK(), sg.Cancel()]
            ]

    # Create the Window
    window = sg.Window('Input for the graph', layout)
    # Event Loop to process "events"
    while True:             
        event, values = window.read()
        if event in (None, 'Cancel'):
            break
        else:
            load = int(values[0]) + int(values[1])
            tf = int(values[2])
            breakpoint1 = int(values[3])
            terrain1 = int(values[4])
            breakpoint2 = int(values[5])
            terrain2 = int(values[6])
            breakpoint3 = int(values[7])
            terrain3 = int(values[8])
            breakpoint4 = int(values[9])
            terrain4 = int(values[10])
            start(tf, load, breakpoint1, breakpoint2, breakpoint3, breakpoint4, terrain1, terrain2, terrain3, terrain4)
            print("after start")

    window.close()