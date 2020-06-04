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
    m = 500 # mass of vehicle (kg)

    # calculate the derivative of velocity
    dv_dt = (1.0 / (m + load)) * ((Fp * u) - (0.5 * rho * Cd * A * v ** 2))
    return dv_dt

tf = 60.0 # time for simulation
nsteps = 61 # number of time steps
delta_t = tf / (nsteps - 1) # how long is each step
ts = np.linspace(0, tf, nsteps) # linearly spaced time vector

# Simulate the step test operation 
step = np.zeros(nsteps) # u = valve % open
step[11:] = 20.0 # step up pedel position

# passenger(s) + cargo load
load = 200.0 # kg
v0 = 0.0 # initial velocity

# for storing the results
vs = np.zeros(nsteps)

# simulate with odeint
for i in range(nsteps - 1):
    u = step[i]
    # clip the inputs to -50% to 100%
    if u >= 100.0:
        u = 100.0
    elif u <= -50.0:
        u = -50.0
    v = odeint(vehicle, v0, [0, delta_t], args=(u, load))
    v0 = v[-1] # take the last value
    vs[i + 1] = v0 # store for plotting 

# plot the results
plt.figure()
plt.subplot(2,1,1)
plt.plot(ts, vs, 'b-', linewidth=3)
plt.plot([0, tf], [25, 25], 'k--', linewidth=2)
plt.ylabel("Velocity (m/s)")
plt.legend(["Velocity", "Set Point"], loc=2)
plt.subplot(2,1,2)
plt.plot(ts, step, 'r--', linewidth=3)
plt.ylabel("Gas Pedel")
plt.legend(["Gas Pedel (%)"], loc=2)
plt.xlabel("Time (sec)")
plt.show()