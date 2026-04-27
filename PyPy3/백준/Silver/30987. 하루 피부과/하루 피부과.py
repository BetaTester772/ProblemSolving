x1, x2 = map(int, input().split())
a, b, c, d, e = map(int, input().split())

a_integral = a / 3
b_d_integral = (b - d) / 2
c_e_integral = c - e

integral_x1 = a_integral * x1**3 + b_d_integral * x1**2 + c_e_integral * x1
integral_x2 = a_integral * x2**3 + b_d_integral * x2**2 + c_e_integral * x2

laser_intensity = integral_x2 - integral_x1
print(int(laser_intensity))
