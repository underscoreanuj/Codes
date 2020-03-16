"""
#
# Good morning! Here's your coding interview problem for today.
# This problem was asked by Google.
# The area of a circle is defined as PIr^2. Estimate PI to 3 decimal places using a Monte Carlo method.
# Hint: The basic equation of a circle is x2 + y2 = r2.
#
#
# references:
#                https://www.youtube.com/watch?v=VJTFfIqO4TU
#                https://www.youtube.com/watch?v=5cNnf_7e92Q
#
#
# for a circle of radius "r"
# bounded by a square of side "2r"
# ratio of points which will lie within the circle (area of circle [PI*r^2])
# to that of the points which lie within the square (area of square [4r^2])
# PI*r^2/4*r^2 = PI/4
#
# Hence,
#               PI = 4 * (number of points in circle / total number of points)
#
# """

import random
import math


def estimate(num_iterations=1000000, radius=5000):
    total = 0
    within_circle = 0
    PI = 0
    BEST_PI = 0
    BEST_DIFF = 999

    for _ in range(num_iterations):
        x = random.randrange(-radius, radius+1)
        y = random.randrange(-radius, radius+1)
        total += 1
        if x*x + y*y < radius*radius:
            within_circle += 1
        PI = 4.0 * (float(within_circle)/float(total))
        if abs(PI - math.pi) < BEST_DIFF:
            BEST_PI = PI

    print(BEST_PI)


if __name__ == '__main__':
    estimate()
