from random import seed
from random import random
import time
import math

current_milli_time = lambda: int(round(time.time() * 1000))
seed(current_milli_time)

count = 0
val = 10000000
for i in range(val):
    x = int(random() * val)
    y = int(random() * val)
    if (math.gcd(x, y) == 1):
        count += 1
print(math.sqrt(6 / (count / val)))