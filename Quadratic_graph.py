# Plotting Quadratic graph 

import numpy as np 
import pandas as pd 
import matplotlib.pyplot as plt 
import seaborn as sns

x_value = np.linsapce(-5,5,100)
y_value = x**2

sns.set_style(rc = {"axes.facecolor" : "lavender"})
sns.lineplot(x = x_value , y = y_value , color = "purple")
plt.xlabel("X - Axis")
plt.ylabel("Y - Axis")
plt.show()