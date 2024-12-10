# 5-DOF Robotic Arm Forward Kinematics

This repository contains the implementation of forward kinematics for a 5-DOF robotic arm, including individual link transformations and the overall end-effector position and orientation calculations. The arm is modeled using Denavit-Hartenberg (D-H) parameters, and the kinematics are derived step-by-step to obtain precise results for each link and the final transformation matrix.

## Features
- **Homogeneous Transformation Matrices**: Computed for each joint using D-H parameters.
- **Forward Kinematics**: Calculation of the end-effector pose in 3D space.
- **MATLAB Implementation**: All calculations and visualizations are implemented in MATLAB.
- **Visualization**: The robotic arm's movement and pose are visualized using the MATLAB `plot` function.

---

## Project Overview
The 5-DOF robotic arm consists of:
1. **5 Revolute Joints**: Provides rotational motion for the arm's links.
2. **D-H Parameter Modeling**: Used to calculate the forward kinematics matrices step-by-step.
3. **MATLAB Simulation**: Enables the visualization of the arm's pose for given joint angles.

---

## Denavit-Hartenberg Parameters

| Joint | \(a_i\) (link length) | \($\alpha_i$) (link twist) | \(d_i\) (link offset) | \($\theta $) (joint angle)|
|-------|-----------------------|---------------------------|-----------------------|---------------------------|
| 1     | 0                     | \(\pi/2\)                 | 6.5                   | \($\theta_1$)              |
| 2     | -10                   | 0                         | 0                     | \($\theta_2 + 3\pi/2$)     |
| 3     | -14.6                 | 0                         | 0                     | \($\theta_3 + 3\pi/2$)     |
| 4     | 0                     | \(-\pi/2\)                | -1                    | \($\theta_4 + 132^\circ$)  |
| 5     | 0                     | 0                         | 18.2                  | \($\theta_5$)              |

---
