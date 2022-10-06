## Setup 

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

df = pd.read_csv('Ecommerce Customers.csv')
df.head()

df.describe(include ='all')

print('----------------------\n\n data columns\n\n-------------------')
print(df.columns)
print('----------------------\n\n data info\n\n-------------------')
print(df.info())


# Missing Values
df.isnull().sum() 

df.drop(columns=['Email','Avatar', 'Address'], axis=1, inplace=True)

df

### Outlinears

f, (ax1, ax2, ax3, ax4) = plt.subplots(1, 4, figsize=(20,5))
ax1.boxplot(df['Time on App'])
ax1.set_title('Time on App')
ax2.boxplot(df['Time on Website'])
ax2.set_title('Time on Website')
ax3.boxplot(df['Yearly Amount Spent'])
ax3.set_title('Yearly Amount Spent')
ax4.boxplot(df['Avg. Session Length'])
ax4.set_title('Avg. Session Length')
plt.show()

df['Length of Membership'].plot(kind='box', vert=False)

#Outlinears review
Q1 = df.quantile(0.25)
Q3 = df.quantile(0.75)
IQR = Q3 - Q1

df = df[~((df < (Q1 - 1.5 * IQR)) |(df > (Q3 + 1.5 * IQR))).any(axis=1)]
df

### Effect of removing outlinears

f, (ax1, ax2, ax3, ax4) = plt.subplots(1, 4, figsize=(20,5))
ax1.boxplot(df['Time on App'])
ax1.set_title('Time on App')
ax2.boxplot(df['Time on Website'])
ax2.set_title('Time on Website')
ax3.boxplot(df['Yearly Amount Spent'])
ax3.set_title('Yearly Amount Spent')
ax4.boxplot(df['Avg. Session Length'])
ax4.set_title('Avg. Session Length')
plt.show()

df['Length of Membership'].plot(kind='box', vert=False)

## Visiluzation 

f, ax = plt.subplots(1, 5, figsize=(20,6))
sns.histplot(df['Time on Website'], ax= ax[0])
sns.histplot(df['Time on App'], ax= ax[1])
sns.histplot(df['Yearly Amount Spent'], ax= ax[2])
sns.histplot(df['Avg. Session Length'], ax= ax[3])
sns.histplot(df['Length of Membership'], ax= ax[4])


sns.pairplot(df)
plt.show()

f, (ax1, ax2, ax3) = plt.subplots(1, 3, sharey=True, figsize =(15,3)) #sharey -> share 'Price' as y
ax1.scatter(df['Time on App'],df['Yearly Amount Spent'])
ax1.set_title('Yearly Amount Spent and Time on App')
ax2.scatter(df['Time on Website'],df['Yearly Amount Spent'])
ax2.set_title('Yearly Amount Spent and Time on Website')
ax3.scatter(df['Length of Membership'],df['Yearly Amount Spent'])
ax3.set_title('Yearly Amount Spent and Length of Membership')

plt.show()

### corelation 

df.corr()

sns.heatmap(df.corr(),cmap="YlGnBu", annot=True)

# Conclusion 

 # The co-relation between the app and yearly amount spent on app is 48% while comparing to corelation between amount spent on website and time spent on website is > 1 to be exact (0.00058) so Company should more focus on the mobile App instead of investing on Website
