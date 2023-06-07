import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

df_koordinations = pd.read_csv('C:\\Projects\\projects_for_c\\laba_8\\Kepler.csv')

df_Ra = df_koordinations.Ra
df_Va = df_koordinations.Va
df_Vw = df_koordinations.Vw

fig, axes1 = plt.subplots() #добавили к области fig область axes1

axes1.set_xlabel('Ra') #подписали ось х
axes1.set_ylabel('Va', color = 'green') #подписали ось у и сделали надпись зеленой
axes1.plot(df_Ra, df_Va, color = "green")  #соединили точки

axes2=axes1.twinx() #добавили вторую ось у
axes2.set_ylabel('Vw', color = 'pink') #подписали ось у и сделали надпись розовой
axes2.plot(df_Ra, df_Vw, color = "pink") #соединили точки

plt.show() #показали график
