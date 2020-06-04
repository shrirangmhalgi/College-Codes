import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import odeint

def vehicle(v, t, u, load):
    # v = vehicle velocity (m/s)
    # t = time (s)
    # u = gas pedel position (-50% to 100%)
    # load = passenger load + cargo (kg)
    Cd = 0.24 # coefficient of drag
    A = 5.0 # cross sectional area (m^2)
    rho = 1.225 # density of air (kg/m^3)
    Fp = 30 # Thrust parameter (N/%pedel)
    # m = 500 # mass of vehicle (kg)

    # calculate the derivative of velocity
    dv_dt = (1.0 / load) * ((Fp * u) - (0.5 * rho * Cd * A * v ** 2))
    return dv_dt

def start(tf, load, breakpoint1, breakpoint2, breakpoint3, breakpoint4, terrain1, terrain2, terrain3, terrain4):
    # tf = time for simulation
    nsteps = tf + 1 # number of time steps
    delta_t = tf / (nsteps - 1) # how long is each step
    ts = np.linspace(0, tf, nsteps) # linearly spaced time vector

    # Simulate the step test operation 
    step = np.zeros(nsteps) # u = valve % open

    # passenger(s) + cargo load
    # load = 200.0 # kg
    v0 = 0.0 # initial velocity

    # for storing the results
    vs = np.zeros(nsteps)

    # PI controller
    ubias = 0.0
    Kc = 1.0 / 1.2
    taui = 20.0
    sum_int = 0.0
    es = np.zeros(nsteps) # error
    ies = np.zeros(nsteps) # integral of error
    sp_store = np.zeros(nsteps) # set point store
    sp = 25

    # simulate with odeint
    for i in range(nsteps - 1):
        # Schedule changes in set point
        if i == breakpoint1:
            sp = terrain1
        elif i == breakpoint2:
            sp = terrain2
        elif i == breakpoint3:
            sp = terrain3
        elif i == breakpoint4:
            sp = terrain4
        
        sp_store[i + 1] = sp
        error = sp - v0
        es[i + 1] = error
        sum_int = sum_int + error * delta_t
        u = ubias + (Kc * error) + ((Kc / taui) * sum_int)

        # clip the inputs to -50% to 100%
        if u >= 100.0:
            u = 100.0
            sum_int = sum_int - error * delta_t
        elif u <= -50.0:
            u = -50.0
            sum_int = sum_int - error * delta_t
        ies[i + 1] = sum_int
        step[i + 1] = u
        v = odeint(vehicle, v0, [0, delta_t], args=(u, load))
        v0 = v[-1] # take the last value
        vs[i + 1] = v0 # store for plotting 

    # plot the results
    plt.figure()
    plt.subplot(2,2,1)
    plt.plot(ts, vs, 'b-', linewidth=3)
    plt.plot(ts, sp_store, 'k--', linewidth=2)
    plt.ylabel("Velocity (m/s)")
    plt.legend(["Velocity", "Set Point"], loc='best')
    plt.subplot(2,2,2)
    plt.plot(ts, step, 'r--', linewidth=3)
    plt.ylabel("Gas Pedel")
    plt.legend(["Gas Pedel (%)"], loc='best')
    plt.subplot(2,2,3)
    plt.plot(ts, es, 'b-', linewidth=3)
    plt.legend(["Error (SP - PV)"])
    plt.xlabel("Time (sec)")
    plt.subplot(2,2,4)
    plt.plot(ts, ies, 'k--', linewidth=2)
    plt.legend(["Integral of Error"])
    plt.xlabel("Time (sec)")
    plt.show()