import pandas as pd
print('Start Read')
df = pd.read_csv('D:\Library\Documents\AfterGrad\Dcamp\Panda_Foundation\Airport.csv')
print(df.head())
print(df.info())

df.columns = df.columns.str.strip(' ')
dallas  = df['Destination Airport'].str.contains('DAL')
print(dallas)
print(df[dallas])